//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "QueueFamily.h"

namespace Neelam::vk
{
	QueueFamily::QueueFamily()
		: privGraphicsFamilyIndex(privInvalidIndex)
	{
	}

	QueueFamily::~QueueFamily()
	{
		this->Destroy();
	}

	void QueueFamily::Create(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface)
	{
		// ---- grab every queue family on this GPU ----
		// The "...2" query uses extensible structs (a pNext chain), so each
		// element must have its sType set before the second (data) call.
		uint32_t count = 0;
		vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &count, nullptr);

		VkQueueFamilyProperties2 *pProps = new VkQueueFamilyProperties2[count];
		for (uint32_t i = 0; i < count; i++)
		{
			pProps[i]       = {};
			pProps[i].sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
		}
		vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, &count, pProps);

		// ---- pick the first family that does graphics AND can present ----
		// Most desktop GPUs expose one family that does both; splitting them
		// across separate families is a later, more complex case.
		this->privGraphicsFamilyIndex = privInvalidIndex;

		for (uint32_t i = 0; i < count; i++)
		{
			VkBool32 presentSupport = VK_FALSE;
			VK_Try(vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &presentSupport));

			const bool hasGraphics =
				(pProps[i].queueFamilyProperties.queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0;

			if (hasGraphics && presentSupport)
			{
				this->privGraphicsFamilyIndex = i;
				break;
			}
		}

		delete[] pProps;

		if (this->privGraphicsFamilyIndex == privInvalidIndex)
		{
			Debug::out("QueueFamily: no graphics+present queue family found\n");
			assert(false);
			ExitProcess(1);
		}

		Debug::out("QueueFamily: graphics+present family index = %u\n",
			this->privGraphicsFamilyIndex);
	}

	void QueueFamily::Destroy()
	{
		// Just an index -- nothing to release.
		this->privGraphicsFamilyIndex = privInvalidIndex;
	}

	uint32_t QueueFamily::GetGraphicsFamilyIndex() const
	{
		return this->privGraphicsFamilyIndex;
	}
}

// ---  End of File ---
