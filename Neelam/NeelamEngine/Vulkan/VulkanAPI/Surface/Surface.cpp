//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Surface.h"

namespace Neelam::vk
{
	Surface::Surface()
		: privInstance(VK_NULL_HANDLE),
		  privSurface(VK_NULL_HANDLE)
	{
	}

	Surface::~Surface()
	{
		this->Destroy();
	}

	void Surface::Create(VkInstance instance, HINSTANCE module, HWND hwnd)
	{
		this->privInstance = instance;

		// VkWin32SurfaceCreateInfoKHR only exists when VK_USE_PLATFORM_WIN32_KHR
		// is defined -- see the note in the header.
		VkWin32SurfaceCreateInfoKHR createInfo = {};
		createInfo.sType     = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		createInfo.hinstance = module;
		createInfo.hwnd      = hwnd;

		VK_Try(vkCreateWin32SurfaceKHR(instance, &createInfo, nullptr, &this->privSurface));
	}

	void Surface::Destroy()
	{
		if (this->privSurface != VK_NULL_HANDLE)
		{
			vkDestroySurfaceKHR(this->privInstance, this->privSurface, nullptr);
			this->privSurface = VK_NULL_HANDLE;
		}

		this->privInstance = VK_NULL_HANDLE;
	}

	VkSurfaceKHR Surface::GetSurface() const
	{
		return this->privSurface;
	}
}

// ---  End of File ---
