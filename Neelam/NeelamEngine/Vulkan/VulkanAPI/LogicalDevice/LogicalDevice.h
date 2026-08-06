//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef LOGICAL_DEVICE_H
#define LOGICAL_DEVICE_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).

//---------------------------------------------------------------------------
// class LogicalDevice
//
// Wraps the VkDevice -- the logical device, i.e. *this app's* configured
// connection to the chosen GPU. Unlike PhysicalDevice/QueueFamily (which only
// SELECT), this class CREATES and OWNS a resource: Destroy() calls
// vkDestroyDevice. Almost every later object (buffers, images, pipelines,
// command pools, and the swapchain) is created FROM this device.
//
// Two-phase, because vkCreateDevice wants every queue request in one call:
//
//     Add(familyIndex);   // register queues to request -- call before Create
//     Add(...);           //   ... any number / any family ...
//     Create(physDev);    // build the device + fetch each VkQueue
//     GetQueue(familyIndex);  // the actual queue for a family
//
// Create() also enables the swapchain extension and the modern feature set
// this engine targets: dynamic rendering, synchronization2, timeline
// semaphores (Vulkan 1.2/1.3). A GPU missing them asserts + exits.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class LogicalDevice
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		LogicalDevice();
		LogicalDevice(const LogicalDevice &) = delete;
		LogicalDevice &operator = (const LogicalDevice &) = delete;
		~LogicalDevice();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------

		// Register a queue family to request. Call BEFORE Create(). priority is
		// in [0,1]. Pass any family (graphics / present / compute / transfer);
		// one Add per distinct family index.
		void Add(uint32_t queueFamilyIndex, float priority = 1.0f);

		// Build the VkDevice from physicalDevice with every added queue, the
		// swapchain extension, and the required features. Fetches each queue.
		void Create(VkPhysicalDevice physicalDevice);

		// vkDeviceWaitIdle then vkDestroyDevice. Owned, so this really releases.
		void Destroy();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		VkDevice GetDevice() const;

		// The VkQueue for a previously-added family (VK_NULL_HANDLE if none).
		VkQueue GetQueue(uint32_t queueFamilyIndex) const;

	private:
		static const uint32_t privMaxQueues = 8;

		struct QueueRequest
		{
			uint32_t familyIndex;
			float    priority;
			VkQueue  queue;			// filled after Create via vkGetDeviceQueue
		};

		// Data
		VkDevice     privDevice;
		QueueRequest privQueues[privMaxQueues];
		uint32_t     privQueueCount;
	};
}

#endif   // LOGICAL_DEVICE_H

// ---  End of File ---
