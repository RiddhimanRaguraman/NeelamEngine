//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "LogicalDevice.h"

namespace Neelam::vk
{
	LogicalDevice::LogicalDevice()
		: privDevice(VK_NULL_HANDLE),
		  privQueues{},
		  privQueueCount(0)
	{
	}

	LogicalDevice::~LogicalDevice()
	{
		this->Destroy();
	}

	void LogicalDevice::Add(uint32_t queueFamilyIndex, float priority)
	{
		// Must register queues before the device is built.
		assert(this->privDevice == VK_NULL_HANDLE);
		assert(this->privQueueCount < privMaxQueues);

		QueueRequest &req = this->privQueues[this->privQueueCount];
		req.familyIndex = queueFamilyIndex;
		req.priority    = priority;
		req.queue       = VK_NULL_HANDLE;

		this->privQueueCount++;
	}

	void LogicalDevice::Create(VkPhysicalDevice physicalDevice)
	{
		assert(this->privQueueCount > 0);	// Add() at least one queue first

		// ---- one VkDeviceQueueCreateInfo per added family ----
		// pQueuePriorities points into privQueues[] (a member), so it stays
		// valid for the duration of the vkCreateDevice call below.
		VkDeviceQueueCreateInfo queueInfos[privMaxQueues] = {};
		for (uint32_t i = 0; i < this->privQueueCount; i++)
		{
			queueInfos[i].sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueInfos[i].queueFamilyIndex = this->privQueues[i].familyIndex;
			queueInfos[i].queueCount       = 1;
			queueInfos[i].pQueuePriorities = &this->privQueues[i].priority;
		}

		// ---- confirm the GPU supports the features we require ----
		// The driver fills these in. The pNext chain lets one query cover the
		// 1.2 / 1.3 / 1.4 feature sets at once.
		VkPhysicalDeviceVulkan14Features supported14 = {};
		supported14.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES;

		VkPhysicalDeviceVulkan13Features supported13 = {};
		supported13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
		supported13.pNext = &supported14;

		VkPhysicalDeviceVulkan12Features supported12 = {};
		supported12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
		supported12.pNext = &supported13;

		VkPhysicalDeviceFeatures2 supported = {};
		supported.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
		supported.pNext = &supported12;

		vkGetPhysicalDeviceFeatures2(physicalDevice, &supported);

		if (!supported13.dynamicRendering ||
			!supported13.synchronization2 ||
			!supported12.timelineSemaphore ||
			!supported12.bufferDeviceAddress)		// VMA is created with the
		{											// BUFFER_DEVICE_ADDRESS flag
			Debug::out("LogicalDevice: GPU missing required features "
				"(dynamicRendering / synchronization2 / timelineSemaphore / bufferDeviceAddress)\n");
			assert(false);
			ExitProcess(1);
		}

		// ---- a SEPARATE chain that turns those features ON for the device ----
		VkPhysicalDeviceVulkan14Features features14 = {};
		features14.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES;

		VkPhysicalDeviceVulkan13Features features13 = {};
		features13.sType            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
		features13.pNext            = &features14;
		features13.synchronization2 = VK_TRUE;
		features13.dynamicRendering = VK_TRUE;

		VkPhysicalDeviceVulkan12Features features12 = {};
		features12.sType               = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
		features12.pNext               = &features13;
		features12.timelineSemaphore   = VK_TRUE;
		features12.bufferDeviceAddress = VK_TRUE;	// required by VMA's BUFFER_DEVICE_ADDRESS flag

		VkPhysicalDeviceFeatures2 features2 = {};
		features2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
		features2.pNext = &features12;

		// ---- device-level extensions ----
		const char *deviceExtensions[1] = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

		// ---- create the device ----
		VkDeviceCreateInfo createInfo = {};
		createInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.pNext                   = &features2;	// features via chain
		createInfo.queueCreateInfoCount    = this->privQueueCount;
		createInfo.pQueueCreateInfos       = queueInfos;
		createInfo.enabledExtensionCount   = 1;
		createInfo.ppEnabledExtensionNames = deviceExtensions;
		createInfo.pEnabledFeatures        = nullptr;		// must be null when pNext has features2

		VK_Try(vkCreateDevice(physicalDevice, &createInfo, nullptr, &this->privDevice));

		// volk: upgrade the device-level entry points to DIRECT dispatch (they
		// skip the loader trampoline now that we have the device). Must run
		// before any device call below -- e.g. vkGetDeviceQueue.
		volkLoadDevice(this->privDevice);

		// ---- fetch the actual VkQueue for each requested family ----
		// (queue index 0 -- we asked for one queue per family). This is where
		// the "graphics queue" finally becomes a real handle.
		for (uint32_t i = 0; i < this->privQueueCount; i++)
		{
			vkGetDeviceQueue(this->privDevice,
				this->privQueues[i].familyIndex, 0, &this->privQueues[i].queue);
		}

		Debug::out("LogicalDevice: created (%u queue(s))\n", this->privQueueCount);
	}

	void LogicalDevice::Destroy()
	{
		if (this->privDevice != VK_NULL_HANDLE)
		{
			// Never destroy a device with work still in flight. Harmless now
			// (nothing submitted yet) and correct once frames are rendering.
			vkDeviceWaitIdle(this->privDevice);

			vkDestroyDevice(this->privDevice, nullptr);
			this->privDevice = VK_NULL_HANDLE;
		}

		// Queues are owned by the device -- just forget them.
		for (uint32_t i = 0; i < this->privQueueCount; i++)
		{
			this->privQueues[i].queue = VK_NULL_HANDLE;
		}
		this->privQueueCount = 0;
	}

	VkDevice LogicalDevice::GetDevice() const
	{
		return this->privDevice;
	}

	VkQueue LogicalDevice::GetQueue(uint32_t queueFamilyIndex) const
	{
		for (uint32_t i = 0; i < this->privQueueCount; i++)
		{
			if (this->privQueues[i].familyIndex == queueFamilyIndex)
			{
				return this->privQueues[i].queue;
			}
		}
		return VK_NULL_HANDLE;
	}
}

// ---  End of File ---
