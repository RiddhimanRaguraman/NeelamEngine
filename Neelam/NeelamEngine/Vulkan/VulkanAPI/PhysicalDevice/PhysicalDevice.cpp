//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "PhysicalDevice.h"

namespace Neelam::vk
{
	PhysicalDevice::PhysicalDevice()
		: privPhysicalDevice(VK_NULL_HANDLE),
		  privProperties{}
	{
	}

	PhysicalDevice::~PhysicalDevice()
	{
		this->Destroy();
	}

	void PhysicalDevice::Create(VkInstance instance, VkSurfaceKHR surface, VkFormat desiredFormat)
	{
		// ---- enumerate every GPU the instance can see ----
		uint32_t count = 0;
		VK_Try(vkEnumeratePhysicalDevices(instance, &count, nullptr));

		if (count == 0)
		{
			Debug::out("PhysicalDevice: no Vulkan-capable GPU found\n");
			assert(false);
			ExitProcess(1);
		}

		VkPhysicalDevice *pDevices = new VkPhysicalDevice[count];
		VK_Try(vkEnumeratePhysicalDevices(instance, &count, pDevices));

		// ---- pick one: default to the first, then prefer a discrete GPU ----
		// The first entry is a safe fallback (integrated GPUs work fine); the
		// loop upgrades to a discrete card if the machine has one.
		this->privPhysicalDevice = pDevices[0];
		vkGetPhysicalDeviceProperties(this->privPhysicalDevice, &this->privProperties);

		for (uint32_t i = 0; i < count; i++)
		{
			VkPhysicalDeviceProperties props = {};
			vkGetPhysicalDeviceProperties(pDevices[i], &props);

			if (props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
			{
				this->privPhysicalDevice = pDevices[i];
				this->privProperties     = props;
				break;
			}
		}

		delete[] pDevices;

		Debug::out("PhysicalDevice: using \"%s\"\n", this->privProperties.deviceName);

		// ---- verify the surface offers the format the swapchain will want ----
		if (!this->privSurfaceSupportsFormat(surface, desiredFormat))
		{
			Debug::out("PhysicalDevice: surface does not support requested format (%d)\n",
				(int)desiredFormat);
			assert(false);
			ExitProcess(1);
		}
	}

	void PhysicalDevice::Destroy()
	{
		// A physical device is owned by the instance -- there is no
		// vkDestroyPhysicalDevice to call. Just forget the handle.
		this->privPhysicalDevice = VK_NULL_HANDLE;
	}

	VkPhysicalDevice PhysicalDevice::GetPhysicalDevice() const
	{
		return this->privPhysicalDevice;
	}

	const VkPhysicalDeviceProperties &PhysicalDevice::GetProperties() const
	{
		return this->privProperties;
	}

	bool PhysicalDevice::privSurfaceSupportsFormat(VkSurfaceKHR surface, VkFormat format) const
	{
		uint32_t formatCount = 0;
		VK_Try(vkGetPhysicalDeviceSurfaceFormatsKHR(this->privPhysicalDevice, surface, &formatCount, nullptr));

		if (formatCount == 0)
		{
			return false;
		}

		VkSurfaceFormatKHR *pFormats = new VkSurfaceFormatKHR[formatCount];
		VK_Try(vkGetPhysicalDeviceSurfaceFormatsKHR(this->privPhysicalDevice, surface, &formatCount, pFormats));

		bool supported = false;
		for (uint32_t i = 0; i < formatCount; i++)
		{
			if (pFormats[i].format == format)
			{
				supported = true;
				break;
			}
		}

		delete[] pFormats;
		return supported;
	}
}

// ---  End of File ---
