//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef PHYSICAL_DEVICE_H
#define PHYSICAL_DEVICE_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).

//---------------------------------------------------------------------------
// class PhysicalDevice
//
// Picks the GPU the engine will run on.
//
// Unlike Instance and Surface, this class does NOT create or own a resource.
// vkEnumeratePhysicalDevices hands back handles that belong to the VkInstance,
// so there is nothing to vkDestroy -- you cannot "destroy" a GPU. Create()
// just SELECTS one (preferring a discrete GPU) and caches its handle and
// properties; Destroy() only forgets the handle. Create/Destroy exist purely
// so the Engine can treat it the same shape as Instance/Surface.
//
// It also does an early check that the surface supports the format the
// swapchain will later ask for -- a preview of a swapchain concern, verified
// here while the surface is in hand and a bad GPU can still be rejected.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class PhysicalDevice
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		PhysicalDevice();
		PhysicalDevice(const PhysicalDevice &) = delete;
		PhysicalDevice &operator = (const PhysicalDevice &) = delete;
		~PhysicalDevice();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------

		// Selects a GPU (prefers a discrete one) and verifies the surface
		// supports desiredFormat. No VkResult to branch on -- a missing GPU or
		// unsupported format asserts + exits, same philosophy as VK_Try.
		void Create(VkInstance instance, VkSurfaceKHR surface,
			VkFormat desiredFormat = VK_FORMAT_B8G8R8A8_UNORM);

		// Nothing to release; just forgets the handle (see class note).
		void Destroy();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		VkPhysicalDevice                  GetPhysicalDevice() const;
		const VkPhysicalDeviceProperties &GetProperties() const;

	private:
		// Does the surface offer `format` on the currently-selected GPU?
		bool privSurfaceSupportsFormat(VkSurfaceKHR surface, VkFormat format) const;

		// Data -- a borrowed handle (owned by the instance), not created here.
		VkPhysicalDevice           privPhysicalDevice;
		VkPhysicalDeviceProperties privProperties;
	};
}

#endif   // PHYSICAL_DEVICE_H

// ---  End of File ---
