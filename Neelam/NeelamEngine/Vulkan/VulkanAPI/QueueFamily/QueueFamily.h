//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef QUEUE_FAMILY_H
#define QUEUE_FAMILY_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).

//---------------------------------------------------------------------------
// class QueueFamily
//
// Finds the queue family the engine will submit work to. Like PhysicalDevice,
// this SELECTS rather than creates -- a "queue family" is just an index into
// the GPU's list of queue types, so there is nothing to release; Create() only
// records the index and Destroy() forgets it.
//
// It looks for a single family that can do BOTH graphics AND presentation to
// our surface (the common desktop case). That index is what logical-device
// creation needs in order to request a queue, and what you later hand to
// vkGetDeviceQueue to obtain the actual VkQueue -- which cannot exist until a
// VkDevice does. So this class holds the index; the queue itself comes later.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class QueueFamily
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		QueueFamily();
		QueueFamily(const QueueFamily &) = delete;
		QueueFamily &operator = (const QueueFamily &) = delete;
		~QueueFamily();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------

		// Finds a graphics+present family on physicalDevice for surface. No
		// queue is created (that needs a VkDevice) -- this records the index
		// only. No family found asserts + exits, same philosophy as VK_Try.
		void Create(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface);

		// Nothing to release; just forgets the index.
		void Destroy();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------

		// The graphics/present family index. Valid after Create().
		uint32_t GetGraphicsFamilyIndex() const;

	private:
		// "not found" sentinel (a real family index is never this).
		static constexpr uint32_t privInvalidIndex = ~0u;

		uint32_t privGraphicsFamilyIndex;
	};
}

#endif   // QUEUE_FAMILY_H

// ---  End of File ---
