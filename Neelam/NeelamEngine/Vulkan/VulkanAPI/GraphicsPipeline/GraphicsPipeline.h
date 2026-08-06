//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef GRAPHICS_PIPELINE_H
#define GRAPHICS_PIPELINE_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).
#include "Swapchain.h"
#include "ShaderObject.h"
#include "Color.h"
#include "Camera.h"
#include "GpuBuffer.h"

//---------------------------------------------------------------------------
// class GraphicsPipeline
//
// The frame loop. Every Render() call does one full frame:
//   wait (timeline) -> acquire image -> record (barriers + dynamic rendering +
//   draw the shader's pipeline) -> submit -> present.
//
// It owns the per-frame command buffers and the synchronization; it BORROWS
// the swapchain (queried fresh each frame, so a swapchain rebuild is
// transparent) and is handed the ShaderObject to draw with.
//
// Frame pacing uses a single TIMELINE semaphore instead of per-frame fences:
// frame N waits for the timeline to reach the value frame N-MaxFramesInFlight
// signalled, which is exactly when N's command resources are free to reuse.
//
// This is deliberately NOT in Game::Render -- the Engine owns one of these and
// Game::Render just calls Render(shader). Later this is the seam where the
// game thread's draw list gets consumed on the engine thread.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class GraphicsPipeline
	{
	public:
		GraphicsPipeline();
		GraphicsPipeline(const GraphicsPipeline &) = delete;
		GraphicsPipeline &operator = (const GraphicsPipeline &) = delete;
		~GraphicsPipeline();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------
		void Create(VkDevice device, VkQueue queue, uint32_t queueFamilyIndex, Swapchain *pSwapchain);
		void Destroy();

		//-----------------------------------------------------------------
		// One frame. Draws `shader`'s pipeline (3 verts). If the swapchain went
		// out of date, sets the stale flag (the Engine recreates it next frame)
		// -- see IsSwapchainStale / ClearSwapchainStale.
		//
		// pCamera supplies the viewport + scissor (Camera::SetActive) AND the
		// view/proj matrices pushed to the vertex stage. Pass nullptr to fall
		// back to a full-swapchain viewport with identity matrices -- what the
		// loop did before there was a camera.
		//
		// Non-const because Camera::getViewMatrix()/getProjMatrix() are non-const
		// accessors in the ported DX11 camera.
		//-----------------------------------------------------------------
		// pVertex/pIndex supply the geometry. Pass nullptr for both to fall back
		// to a bare vkCmdDraw(3) -- what the loop did when the triangle was
		// baked into the vertex shader.
		void Render(const ShaderObject &shader,
					Camera *pCamera = nullptr,
					const GpuBuffer *pVertex = nullptr,
					const GpuBuffer *pIndex = nullptr,
					uint32_t indexCount = 0);

		bool IsSwapchainStale() const;
		void ClearSwapchainStale();

		// VK_ERROR_DEVICE_LOST was reported by acquire, submit or present.
		//
		// Not an application bug -- a TDR, driver update or GPU reset produces it.
		// Every device-dependent object is invalid afterwards, so the frame loop
		// must stop. Engine::Tic checks this and starts a normal shutdown.
		bool IsDeviceLost() const;

		// The frame's clear color. Defaults to a BUILD-DIFFERENTIATING color
		// (LightGray in Debug, Wheat in Release) so you can tell which build is
		// running at a glance. Call this to override it.
		void SetClearColor(const Color &color);

	private:
		static const uint32_t MaxFramesInFlight = 2;

		// Per-frame-in-flight resources (own command pool = simpler resets).
		struct FrameResources
		{
			VkCommandPool   commandPool;
			VkCommandBuffer commandBuffer;
			VkSemaphore     imageAcquiredSemaphore;		// binary, per frame
		};

		void privCreateSync();
		void privCreateCommands();

		// Borrowed handles.
		VkDevice   privDevice;
		VkQueue    privQueue;
		uint32_t   privQueueFamilyIndex;
		Swapchain *privSwapchain;

		FrameResources privFrames[MaxFramesInFlight];

		// Timeline semaphore frame pacing.
		VkSemaphore privTimelineSemaphore;
		uint64_t    privFrameIndex;
		uint64_t    privNextSignalValue;

		bool        privSwapchainStale;
		bool        privDeviceLost;

		Color       privClearColor;		// build-differentiating default (see .cpp)
	};
}

#endif   // GRAPHICS_PIPELINE_H

// ---  End of File ---
