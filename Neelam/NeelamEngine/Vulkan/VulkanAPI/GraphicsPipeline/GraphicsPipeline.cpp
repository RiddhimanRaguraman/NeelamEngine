//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "GraphicsPipeline.h"

namespace Neelam::vk
{
	GraphicsPipeline::GraphicsPipeline()
		: privDevice(VK_NULL_HANDLE),
		  privQueue(VK_NULL_HANDLE),
		  privQueueFamilyIndex(0),
		  privSwapchain(nullptr),
		  privFrames{},
		  privTimelineSemaphore(VK_NULL_HANDLE),
		  privFrameIndex(0),
		  privNextSignalValue(0),
		  privSwapchainStale(false),
		  privDeviceLost(false),
		  privClearColor{}
	{
		// Build-differentiating clear color -- glance at the background and you know
		// which build is running.
#ifdef _DEBUG
		this->privClearColor = Colors::LightGray;
#else
		this->privClearColor = Colors::Wheat;
#endif
	}

	GraphicsPipeline::~GraphicsPipeline()
	{
		this->Destroy();
	}

	void GraphicsPipeline::Create(VkDevice device, VkQueue queue, uint32_t queueFamilyIndex, Swapchain *pSwapchain)
	{
		this->privDevice           = device;
		this->privQueue            = queue;
		this->privQueueFamilyIndex = queueFamilyIndex;
		this->privSwapchain        = pSwapchain;

		this->privFrameIndex      = 0;
		this->privNextSignalValue = MaxFramesInFlight + 1;	// see the wait math in Render
		this->privSwapchainStale  = false;
		this->privDeviceLost      = false;

		this->privCreateSync();
		this->privCreateCommands();

		Debug::out("GraphicsPipeline: created (%u frames in flight)\n", MaxFramesInFlight);
	}

	//-----------------------------------------------------------------
	// One timeline semaphore for pacing + one binary acquire semaphore per
	// frame in flight.
	//-----------------------------------------------------------------
	void GraphicsPipeline::privCreateSync()
	{
		// Timeline starts at MaxFramesInFlight so the first frames' waits
		// (signalValue - MaxFramesInFlight) are already satisfied.
		VkSemaphoreTypeCreateInfo typeInfo = {};
		typeInfo.sType         = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
		typeInfo.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
		typeInfo.initialValue  = MaxFramesInFlight;

		VkSemaphoreCreateInfo timelineInfo = {};
		timelineInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		timelineInfo.pNext = &typeInfo;
		VK_Try(vkCreateSemaphore(this->privDevice, &timelineInfo, nullptr, &this->privTimelineSemaphore));

		for (uint32_t i = 0; i < MaxFramesInFlight; i++)
		{
			VkSemaphoreCreateInfo binaryInfo = {};
			binaryInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
			VK_Try(vkCreateSemaphore(this->privDevice, &binaryInfo, nullptr,
				&this->privFrames[i].imageAcquiredSemaphore));
		}
	}

	//-----------------------------------------------------------------
	// One command pool + primary command buffer per frame in flight.
	//-----------------------------------------------------------------
	void GraphicsPipeline::privCreateCommands()
	{
		for (uint32_t i = 0; i < MaxFramesInFlight; i++)
		{
			VkCommandPoolCreateInfo poolInfo = {};
			poolInfo.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
			poolInfo.queueFamilyIndex = this->privQueueFamilyIndex;
			VK_Try(vkCreateCommandPool(this->privDevice, &poolInfo, nullptr, &this->privFrames[i].commandPool));

			VkCommandBufferAllocateInfo allocInfo = {};
			allocInfo.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
			allocInfo.commandPool        = this->privFrames[i].commandPool;
			allocInfo.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
			allocInfo.commandBufferCount = 1;
			VK_Try(vkAllocateCommandBuffers(this->privDevice, &allocInfo, &this->privFrames[i].commandBuffer));
		}
	}

	//-----------------------------------------------------------------
	// The frame.
	//-----------------------------------------------------------------
	void GraphicsPipeline::Render(const ShaderObject &shader, Camera *pCamera,
								  const GpuBuffer *pVertex, const GpuBuffer *pIndex,
								  uint32_t indexCount)
	{
		// Neither counter advances here -- both move only after a successful
		// vkQueueSubmit2 at the bottom. Advancing early would burn a timeline value
		// on any path that returns without submitting, and a later frame would then
		// wait forever for a value nothing ever signals.
		const uint32_t frameResIndex = (uint32_t)(this->privFrameIndex % MaxFramesInFlight);
		const uint64_t signalValue   = this->privNextSignalValue;
		const uint64_t waitValue     = signalValue - MaxFramesInFlight;

		// ---- 1. wait until this frame's resources are free (timeline) ----
		VkSemaphoreWaitInfo waitInfo = {};
		waitInfo.sType          = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
		waitInfo.semaphoreCount = 1;
		waitInfo.pSemaphores    = &this->privTimelineSemaphore;
		waitInfo.pValues        = &waitValue;
		vkWaitSemaphores(this->privDevice, &waitInfo, UINT64_MAX);

		FrameResources &res = this->privFrames[frameResIndex];
		vkResetCommandPool(this->privDevice, res.commandPool, 0);

		// ---- 2. acquire the next swapchain image ----
		uint32_t imageIndex = 0;
		VkResult acquire = vkAcquireNextImageKHR(this->privDevice, this->privSwapchain->GetSwapchain(),
			UINT64_MAX, res.imageAcquiredSemaphore, VK_NULL_HANDLE, &imageIndex);

		if (acquire == VK_ERROR_DEVICE_LOST)
		{
			// Not an app bug (TDR / driver update / GPU reset). Engine::Tic turns
			// this into a normal shutdown.
			this->privDeviceLost = true;
			return;
		}
		if (acquire == VK_ERROR_OUT_OF_DATE_KHR)
		{
			// Cannot render into this swapchain -- rebuild before next frame.
			this->privSwapchainStale = true;
			return;
		}
		if (acquire == VK_SUBOPTIMAL_KHR)
		{
			this->privSwapchainStale = true;		// still usable this frame
		}
		else
		{
			VK_Try(acquire);						// SUCCESS passes; real errors assert
		}

		const VkExtent2D extent = this->privSwapchain->GetExtent();

		// ---- 3. record ----
		VkCommandBufferBeginInfo beginInfo = {};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
		vkBeginCommandBuffer(res.commandBuffer, &beginInfo);

		// Transition color (UNDEFINED->COLOR_ATTACHMENT) and depth
		// (UNDEFINED->DEPTH_ATTACHMENT) for this frame.
		VkImageMemoryBarrier2 toAttachment[2] = {};

		toAttachment[0].sType         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
		toAttachment[0].srcStageMask  = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
		toAttachment[0].srcAccessMask = 0;
		toAttachment[0].dstStageMask  = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
		toAttachment[0].dstAccessMask = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT;
		toAttachment[0].oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
		toAttachment[0].newLayout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
		toAttachment[0].image         = this->privSwapchain->GetImage(imageIndex);
		toAttachment[0].subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		toAttachment[0].subresourceRange.levelCount = 1;
		toAttachment[0].subresourceRange.layerCount = 1;

		toAttachment[1].sType         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
		toAttachment[1].srcStageMask  = VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT;
		toAttachment[1].srcAccessMask = 0;
		toAttachment[1].dstStageMask  = VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT | VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT;
		toAttachment[1].dstAccessMask = VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
		toAttachment[1].oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
		toAttachment[1].newLayout     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;
		toAttachment[1].image         = this->privSwapchain->GetDepthImage();
		toAttachment[1].subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
		toAttachment[1].subresourceRange.levelCount = 1;
		toAttachment[1].subresourceRange.layerCount = 1;

		VkDependencyInfo toAttachDep = {};
		toAttachDep.sType                   = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
		toAttachDep.imageMemoryBarrierCount = 2;
		toAttachDep.pImageMemoryBarriers    = toAttachment;
		vkCmdPipelineBarrier2(res.commandBuffer, &toAttachDep);

		// Dynamic rendering: clear color + depth, keep color for present.
		VkRenderingAttachmentInfo colorAttach = {};
		colorAttach.sType                       = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
		colorAttach.imageView                   = this->privSwapchain->GetImageView(imageIndex);
		colorAttach.imageLayout                 = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
		colorAttach.loadOp                      = VK_ATTACHMENT_LOAD_OP_CLEAR;
		colorAttach.storeOp                     = VK_ATTACHMENT_STORE_OP_STORE;
		colorAttach.clearValue.color.float32[0] = this->privClearColor.red;
		colorAttach.clearValue.color.float32[1] = this->privClearColor.green;
		colorAttach.clearValue.color.float32[2] = this->privClearColor.blue;
		colorAttach.clearValue.color.float32[3] = this->privClearColor.alpha;

		VkRenderingAttachmentInfo depthAttach = {};
		depthAttach.sType                             = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
		depthAttach.imageView                         = this->privSwapchain->GetDepthImageView();
		depthAttach.imageLayout                       = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;
		depthAttach.loadOp                            = VK_ATTACHMENT_LOAD_OP_CLEAR;
		depthAttach.storeOp                           = VK_ATTACHMENT_STORE_OP_DONT_CARE;
		depthAttach.clearValue.depthStencil.depth     = 1.0f;
		depthAttach.clearValue.depthStencil.stencil   = 0;

		VkRenderingInfo renderingInfo = {};
		renderingInfo.sType                = VK_STRUCTURE_TYPE_RENDERING_INFO;
		renderingInfo.renderArea.offset    = { 0, 0 };
		renderingInfo.renderArea.extent    = extent;
		renderingInfo.layerCount           = 1;
		renderingInfo.colorAttachmentCount = 1;
		renderingInfo.pColorAttachments    = &colorAttach;
		renderingInfo.pDepthAttachment     = &depthAttach;

		vkCmdBeginRendering(res.commandBuffer, &renderingInfo);

		// Viewport + scissor are dynamic (the pipeline left them out), so the
		// camera can own them. With no camera, fill the whole swapchain -- the
		// behaviour this loop had before the camera existed.
		if (pCamera != nullptr)
		{
			pCamera->SetActive(res.commandBuffer);
		}
		else
		{
			VkViewport viewport = {};
			viewport.x        = 0.0f;
			viewport.y        = 0.0f;
			viewport.width    = (float)extent.width;
			viewport.height   = (float)extent.height;
			viewport.minDepth = 0.0f;
			viewport.maxDepth = 1.0f;
			vkCmdSetViewport(res.commandBuffer, 0, 1, &viewport);

			VkRect2D scissor = {};
			scissor.offset = { 0, 0 };
			scissor.extent = extent;
			vkCmdSetScissor(res.commandBuffer, 0, 1, &scissor);
		}

		// The triangle.
		shader.SetActive(res.commandBuffer);			// vkCmdBindPipeline

		// Push constants, after the bind and re-issued every frame -- the command
		// pool was reset at the top, so last frame's are gone.
		ShaderMatrices matrices;

		// Identity for now -- world becomes per-draw with the scene graph.
		matrices.world.set(Azul::Identity);

		if (pCamera != nullptr)
		{
			// Premultiplied: Azul is row-vector, so v * world * (view * proj)
			// associates correctly, and one matrix leaves room for world inside
			// the 128-byte push-constant limit.
			matrices.viewProj = pCamera->getViewMatrix() * pCamera->getProjMatrix();
		}
		else
		{
			matrices.viewProj.set(Azul::Identity);
		}

		shader.SetMatrices(res.commandBuffer, matrices);

		if (pVertex != nullptr && pIndex != nullptr)
		{
			VkBuffer     vertexBuffers[1] = { pVertex->GetBuffer() };
			VkDeviceSize offsets[1]       = { 0 };

			vkCmdBindVertexBuffers(res.commandBuffer, 0, 1, vertexBuffers, offsets);
			vkCmdBindIndexBuffer(res.commandBuffer, pIndex->GetBuffer(), 0, VK_INDEX_TYPE_UINT32);

			vkCmdDrawIndexed(res.commandBuffer, indexCount, 1, 0, 0, 0);
		}
		else
		{
			// No geometry supplied -- the old SV_VertexID path.
			vkCmdDraw(res.commandBuffer, 3, 1, 0, 0);
		}

		vkCmdEndRendering(res.commandBuffer);

		// Transition color COLOR_ATTACHMENT -> PRESENT_SRC.
		VkImageMemoryBarrier2 toPresent = {};
		toPresent.sType         = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
		toPresent.srcStageMask  = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;
		toPresent.srcAccessMask = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT;
		toPresent.dstStageMask  = VK_PIPELINE_STAGE_2_NONE;
		toPresent.dstAccessMask = 0;
		toPresent.oldLayout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
		toPresent.newLayout     = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
		toPresent.image         = this->privSwapchain->GetImage(imageIndex);
		toPresent.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		toPresent.subresourceRange.levelCount = 1;
		toPresent.subresourceRange.layerCount = 1;

		VkDependencyInfo toPresentDep = {};
		toPresentDep.sType                   = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
		toPresentDep.imageMemoryBarrierCount = 1;
		toPresentDep.pImageMemoryBarriers    = &toPresent;
		vkCmdPipelineBarrier2(res.commandBuffer, &toPresentDep);

		vkEndCommandBuffer(res.commandBuffer);

		// ---- 4. submit ----
		// Wait on the acquire semaphore before the color-output stage; signal
		// the swapchain's per-image render-complete semaphore (for present) and
		// bump the timeline (for pacing).
		VkSemaphoreSubmitInfo waitSem = {};
		waitSem.sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
		waitSem.semaphore = res.imageAcquiredSemaphore;
		waitSem.stageMask = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT;

		VkSemaphoreSubmitInfo signalSems[2] = {};
		signalSems[0].sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
		signalSems[0].semaphore = this->privSwapchain->GetRenderCompleteSemaphore(imageIndex);
		signalSems[0].stageMask = VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT;
		signalSems[1].sType     = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
		signalSems[1].semaphore = this->privTimelineSemaphore;
		signalSems[1].value     = signalValue;
		signalSems[1].stageMask = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT;

		VkCommandBufferSubmitInfo cmdSubmit = {};
		cmdSubmit.sType         = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO;
		cmdSubmit.commandBuffer = res.commandBuffer;

		VkSubmitInfo2 submit = {};
		submit.sType                    = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
		submit.waitSemaphoreInfoCount   = 1;
		submit.pWaitSemaphoreInfos      = &waitSem;
		submit.commandBufferInfoCount   = 1;
		submit.pCommandBufferInfos      = &cmdSubmit;
		submit.signalSemaphoreInfoCount = 2;
		submit.pSignalSemaphoreInfos    = signalSems;
		const VkResult submitResult = vkQueueSubmit2(this->privQueue, 1, &submit, VK_NULL_HANDLE);
		if (submitResult == VK_ERROR_DEVICE_LOST)
		{
			// Nothing was signalled, so the counters below must not advance.
			this->privDeviceLost = true;
			return;
		}
		VK_Try(submitResult);

		// Only here: the timeline is now guaranteed to reach signalValue. Present may
		// still fail below, but the submit has happened and will signal.
		this->privNextSignalValue++;
		this->privFrameIndex++;

		// ---- 5. present ----
		VkSemaphore    renderComplete = this->privSwapchain->GetRenderCompleteSemaphore(imageIndex);
		VkSwapchainKHR sc             = this->privSwapchain->GetSwapchain();

		VkPresentInfoKHR present = {};
		present.sType              = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		present.waitSemaphoreCount = 1;
		present.pWaitSemaphores    = &renderComplete;
		present.swapchainCount     = 1;
		present.pSwapchains        = &sc;
		present.pImageIndices      = &imageIndex;

		VkResult presentResult = vkQueuePresentKHR(this->privQueue, &present);
		if (presentResult == VK_ERROR_DEVICE_LOST)
		{
			this->privDeviceLost = true;
		}
		else if (presentResult == VK_ERROR_OUT_OF_DATE_KHR || presentResult == VK_SUBOPTIMAL_KHR)
		{
			this->privSwapchainStale = true;
		}
		else
		{
			VK_Try(presentResult);
		}
	}

	void GraphicsPipeline::Destroy()
	{
		if (this->privDevice == VK_NULL_HANDLE)
		{
			return;
		}

		// Finish any in-flight frames before freeing what they use.
		vkDeviceWaitIdle(this->privDevice);

		for (uint32_t i = 0; i < MaxFramesInFlight; i++)
		{
			if (this->privFrames[i].imageAcquiredSemaphore != VK_NULL_HANDLE)
			{
				vkDestroySemaphore(this->privDevice, this->privFrames[i].imageAcquiredSemaphore, nullptr);
			}
			if (this->privFrames[i].commandPool != VK_NULL_HANDLE)
			{
				// Destroying the pool frees its command buffers too.
				vkDestroyCommandPool(this->privDevice, this->privFrames[i].commandPool, nullptr);
			}
			this->privFrames[i] = {};
		}

		if (this->privTimelineSemaphore != VK_NULL_HANDLE)
		{
			vkDestroySemaphore(this->privDevice, this->privTimelineSemaphore, nullptr);
			this->privTimelineSemaphore = VK_NULL_HANDLE;
		}

		this->privDevice = VK_NULL_HANDLE;
	}

	bool GraphicsPipeline::IsSwapchainStale() const
	{
		return this->privSwapchainStale;
	}

	void GraphicsPipeline::ClearSwapchainStale()
	{
		this->privSwapchainStale = false;
	}

	bool GraphicsPipeline::IsDeviceLost() const
	{
		return this->privDeviceLost;
	}

	void GraphicsPipeline::SetClearColor(const Color &color)
	{
		this->privClearColor = color;
	}
}

// ---  End of File ---
