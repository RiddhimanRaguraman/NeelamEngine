//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Swapchain.h"

namespace Neelam::vk
{
	Swapchain::Swapchain()
		: privDevice(VK_NULL_HANDLE),
		  privAllocator(VK_NULL_HANDLE),
		  privSwapchain(VK_NULL_HANDLE),
		  privImageCount(0),
		  privImages{},
		  privImageViews{},
		  privRenderCompleteSemaphores{},
		  privDepthImage(VK_NULL_HANDLE),
		  privDepthAllocation(VK_NULL_HANDLE),
		  privDepthImageView(VK_NULL_HANDLE),
		  privExtent{},
		  privColorFormat(VK_FORMAT_UNDEFINED),
		  privDepthFormat(VK_FORMAT_UNDEFINED)
	{
	}

	Swapchain::~Swapchain()
	{
		this->Destroy();
	}

	void Swapchain::Create(VkPhysicalDevice physicalDevice, VkDevice device, VkSurfaceKHR surface,
		VmaAllocator allocator, uint32_t width, uint32_t height,
		VkFormat colorFormat, VkFormat depthFormat, VkSwapchainKHR oldSwapchain)
	{
		this->privDevice      = device;
		this->privAllocator   = allocator;
		this->privColorFormat = colorFormat;

		// UNDEFINED means "you choose" (first-time creation). A concrete format
		// means a caller asked for it -- Recreate passing back what was already
		// picked -- so verify rather than silently re-pick something else.
		if (depthFormat == VK_FORMAT_UNDEFINED)
		{
			this->privDepthFormat = Swapchain::privPickDepthFormat(physicalDevice);
		}
		else
		{
			VkFormatProperties props = {};
			vkGetPhysicalDeviceFormatProperties(physicalDevice, depthFormat, &props);

			if ((props.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) == 0)
			{
				Debug::out("Swapchain: requested depth format %d unsupported as a depth attachment\n",
					(int)depthFormat);
				assert(false);
				ExitProcess(1);
			}

			this->privDepthFormat = depthFormat;
		}

		// ---- surface capabilities: how many images, what size ----
		VkSurfaceCapabilitiesKHR caps = {};
		VK_Try(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &caps));

		// Extent: on Windows the surface fixes the size (currentExtent). Only
		// when it is the "let the app choose" sentinel do we use the hint,
		// clamped into the surface's allowed range.
		if (caps.currentExtent.width != 0xFFFFFFFF)
		{
			this->privExtent = caps.currentExtent;
		}
		else
		{
			this->privExtent.width  = width;
			this->privExtent.height = height;

			if (this->privExtent.width  < caps.minImageExtent.width)  this->privExtent.width  = caps.minImageExtent.width;
			if (this->privExtent.width  > caps.maxImageExtent.width)  this->privExtent.width  = caps.maxImageExtent.width;
			if (this->privExtent.height < caps.minImageExtent.height) this->privExtent.height = caps.minImageExtent.height;
			if (this->privExtent.height > caps.maxImageExtent.height) this->privExtent.height = caps.maxImageExtent.height;
		}

		// ---- create the swapchain ----
		VkSwapchainCreateInfoKHR swapInfo = {};
		swapInfo.sType            = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapInfo.surface          = surface;
		// minImageCount + 1, NOT minImageCount. Asking for the bare minimum (2
		// on Windows) means vkAcquireNextImageKHR has to block until the
		// presentation engine hands an image back -- which throttles the whole
		// MaxFramesInFlight=2 timeline-pacing design down to one frame of
		// overlap. One spare image is what lets the CPU actually run ahead.
		//
		// maxImageCount == 0 means "no limit", so it is only a clamp when set.
		uint32_t desiredImageCount = caps.minImageCount + 1;
		if (caps.maxImageCount > 0 && desiredImageCount > caps.maxImageCount)
		{
			desiredImageCount = caps.maxImageCount;
		}

		swapInfo.minImageCount    = desiredImageCount;
		swapInfo.imageFormat      = this->privColorFormat;
		swapInfo.imageColorSpace  = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		swapInfo.imageExtent      = this->privExtent;
		swapInfo.imageArrayLayers = 1;
		swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;	// graphics == present family
		swapInfo.preTransform     = caps.currentTransform;
		swapInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		swapInfo.presentMode      = VK_PRESENT_MODE_FIFO_KHR;	// vsync, always supported
		swapInfo.clipped          = VK_TRUE;
		swapInfo.oldSwapchain     = oldSwapchain;		// see Recreate()

		VK_Try(vkCreateSwapchainKHR(device, &swapInfo, nullptr, &this->privSwapchain));

		// ---- grab the swapchain's color images ----
		VK_Try(vkGetSwapchainImagesKHR(device, this->privSwapchain, &this->privImageCount, nullptr));
		assert(this->privImageCount <= privMaxImages);
		VK_Try(vkGetSwapchainImagesKHR(device, this->privSwapchain, &this->privImageCount, this->privImages));

		// ---- one image view + one render-complete semaphore per image ----
		for (uint32_t i = 0; i < this->privImageCount; i++)
		{
			VkImageViewCreateInfo viewInfo = {};
			viewInfo.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			viewInfo.image                           = this->privImages[i];
			viewInfo.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
			viewInfo.format                          = this->privColorFormat;
			viewInfo.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
			viewInfo.subresourceRange.levelCount     = 1;
			viewInfo.subresourceRange.layerCount     = 1;

			VK_Try(vkCreateImageView(device, &viewInfo, nullptr, &this->privImageViews[i]));

			VkSemaphoreCreateInfo semInfo = {};
			semInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

			VK_Try(vkCreateSemaphore(device, &semInfo, nullptr, &this->privRenderCompleteSemaphores[i]));
		}

		// ---- depth image (allocated through VMA) ----
		VkImageCreateInfo depthInfo = {};
		depthInfo.sType         = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		depthInfo.imageType     = VK_IMAGE_TYPE_2D;
		// privDepthFormat, NOT the depthFormat parameter -- the parameter may
		// still be VK_FORMAT_UNDEFINED ("you pick"), and the resolved format
		// lives in the member. Reading the parameter here handed
		// VK_FORMAT_UNDEFINED to vkCreateImage, which the driver turned into a
		// divide-by-zero inside nvoglv64.dll.
		depthInfo.format        = this->privDepthFormat;
		depthInfo.extent.width  = this->privExtent.width;
		depthInfo.extent.height = this->privExtent.height;
		depthInfo.extent.depth  = 1;
		depthInfo.mipLevels     = 1;
		depthInfo.arrayLayers   = 1;
		depthInfo.samples       = VK_SAMPLE_COUNT_1_BIT;
		depthInfo.tiling        = VK_IMAGE_TILING_OPTIMAL;
		depthInfo.usage         = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
		depthInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

		VmaAllocationCreateInfo depthAlloc = {};
		depthAlloc.flags = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT;
		depthAlloc.usage = VMA_MEMORY_USAGE_AUTO;

		VK_Try(vmaCreateImage(allocator, &depthInfo, &depthAlloc,
			&this->privDepthImage, &this->privDepthAllocation, nullptr));

		// ---- depth image view ----
		VkImageViewCreateInfo depthViewInfo = {};
		depthViewInfo.sType                       = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		depthViewInfo.image                       = this->privDepthImage;
		depthViewInfo.viewType                    = VK_IMAGE_VIEW_TYPE_2D;
		depthViewInfo.format                      = this->privDepthFormat;
		depthViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
		depthViewInfo.subresourceRange.levelCount = 1;
		depthViewInfo.subresourceRange.layerCount = 1;

		VK_Try(vkCreateImageView(device, &depthViewInfo, nullptr, &this->privDepthImageView));

		Debug::out("Swapchain: created (%u images, %ux%u)\n",
			this->privImageCount, this->privExtent.width, this->privExtent.height);
	}

	//-----------------------------------------------------------------
	// Depth-only first, then the combined depth+stencil formats. Order is
	// preference: D32_SFLOAT is the highest-precision depth-only format and
	// costs no stencil bytes, so it wins when available.
	//-----------------------------------------------------------------
	VkFormat Swapchain::privPickDepthFormat(VkPhysicalDevice physicalDevice)
	{
		const VkFormat candidates[3] =
		{
			VK_FORMAT_D32_SFLOAT,
			VK_FORMAT_D32_SFLOAT_S8_UINT,
			VK_FORMAT_D24_UNORM_S8_UINT
		};

		for (uint32_t i = 0; i < 3; i++)
		{
			VkFormatProperties props = {};
			vkGetPhysicalDeviceFormatProperties(physicalDevice, candidates[i], &props);

			// OPTIMAL tiling, because that is what the depth image is created
			// with (VK_IMAGE_TILING_OPTIMAL below).
			if (props.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
			{
				return candidates[i];
			}
		}

		// No depth format at all is not a real GPU.
		Debug::out("Swapchain: no supported depth-attachment format found\n");
		assert(false);
		ExitProcess(1);

		return VK_FORMAT_UNDEFINED;
	}

	//-----------------------------------------------------------------
	// Resize in place, new-before-old.
	//
	// The swapchain HANDLE is deliberately stashed and cleared before Destroy()
	// runs, so Destroy tears down the views / semaphores / depth image but
	// leaves the handle alone. That handle is then handed to the new
	// vkCreateSwapchainKHR as oldSwapchain -- letting the driver recycle its
	// images -- and only destroyed once the new one exists.
	//
	// Destroying the old semaphores here is safe because the caller has already
	// made the device idle: vkQueuePresentKHR's semaphore wait is a QUEUE
	// operation, so vkDeviceWaitIdle has completed it.
	//-----------------------------------------------------------------
	void Swapchain::Recreate(VkPhysicalDevice physicalDevice, VkDevice device, VkSurfaceKHR surface,
		VmaAllocator allocator, uint32_t width, uint32_t height)
	{
		// Formats survive Destroy(), but read them first so the intent is clear.
		const VkFormat colorFormat = this->privColorFormat;
		const VkFormat depthFormat = this->privDepthFormat;

		VkSwapchainKHR oldHandle = this->privSwapchain;
		this->privSwapchain = VK_NULL_HANDLE;		// hide it from Destroy()

		this->Destroy();

		this->Create(physicalDevice, device, surface, allocator,
			width, height, colorFormat, depthFormat, oldHandle);

		// Retired and replaced -- now it can go.
		if (oldHandle != VK_NULL_HANDLE)
		{
			vkDestroySwapchainKHR(device, oldHandle, nullptr);
		}
	}

	void Swapchain::Destroy()
	{
		if (this->privDevice == VK_NULL_HANDLE)
		{
			return;
		}

		// Reverse of Create. Depth first.
		if (this->privDepthImageView != VK_NULL_HANDLE)
		{
			vkDestroyImageView(this->privDevice, this->privDepthImageView, nullptr);
			this->privDepthImageView = VK_NULL_HANDLE;
		}
		if (this->privDepthImage != VK_NULL_HANDLE)
		{
			// Frees the VkImage and its VMA allocation together. Must happen
			// before the allocator is destroyed -- VMA asserts on any block still
			// live at vmaDestroyAllocator.
			vmaDestroyImage(this->privAllocator, this->privDepthImage, this->privDepthAllocation);
			this->privDepthImage      = VK_NULL_HANDLE;
			this->privDepthAllocation = VK_NULL_HANDLE;
		}

		// Per-image objects.
		for (uint32_t i = 0; i < this->privImageCount; i++)
		{
			if (this->privRenderCompleteSemaphores[i] != VK_NULL_HANDLE)
			{
				vkDestroySemaphore(this->privDevice, this->privRenderCompleteSemaphores[i], nullptr);
				this->privRenderCompleteSemaphores[i] = VK_NULL_HANDLE;
			}
			if (this->privImageViews[i] != VK_NULL_HANDLE)
			{
				vkDestroyImageView(this->privDevice, this->privImageViews[i], nullptr);
				this->privImageViews[i] = VK_NULL_HANDLE;
			}
			// privImages[i] is owned by the swapchain -- not destroyed here.
		}
		this->privImageCount = 0;

		if (this->privSwapchain != VK_NULL_HANDLE)
		{
			vkDestroySwapchainKHR(this->privDevice, this->privSwapchain, nullptr);
			this->privSwapchain = VK_NULL_HANDLE;
		}

		this->privDevice    = VK_NULL_HANDLE;
		this->privAllocator = VK_NULL_HANDLE;
	}

	VkSwapchainKHR Swapchain::GetSwapchain() const
	{
		return this->privSwapchain;
	}

	uint32_t Swapchain::GetImageCount() const
	{
		return this->privImageCount;
	}

	VkImage Swapchain::GetImage(uint32_t i) const
	{
		assert(i < this->privImageCount);
		return this->privImages[i];
	}

	VkImageView Swapchain::GetImageView(uint32_t i) const
	{
		assert(i < this->privImageCount);
		return this->privImageViews[i];
	}

	VkSemaphore Swapchain::GetRenderCompleteSemaphore(uint32_t i) const
	{
		assert(i < this->privImageCount);
		return this->privRenderCompleteSemaphores[i];
	}

	VkImage Swapchain::GetDepthImage() const
	{
		return this->privDepthImage;
	}

	VkImageView Swapchain::GetDepthImageView() const
	{
		return this->privDepthImageView;
	}

	VkExtent2D Swapchain::GetExtent() const
	{
		return this->privExtent;
	}

	VkFormat Swapchain::GetColorFormat() const
	{
		return this->privColorFormat;
	}

	VkFormat Swapchain::GetDepthFormat() const
	{
		return this->privDepthFormat;
	}
}

// ---  End of File ---
