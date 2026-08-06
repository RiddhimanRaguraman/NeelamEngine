//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SURFACE_H
#define SURFACE_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).

//---------------------------------------------------------------------------
// class Surface
//
// Bridges the Win32 window to Vulkan: turns an HWND into a VkSurfaceKHR,
// which is what a swapchain later gets presented to.
//
// This is the piece that needs the VK_USE_PLATFORM_WIN32_KHR macro. That
// macro is defined project-wide in premake5.lua, and without it neither
// VkWin32SurfaceCreateInfoKHR nor vkCreateWin32SurfaceKHR is declared --
// the Win32 half of the Vulkan headers compiles out entirely.
//
// The surface does NOT own the VkInstance it is created from; the instance
// must outlive the surface (destroy the surface first).
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class Surface
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		Surface();
		Surface(const Surface &) = delete;
		Surface &operator = (const Surface &) = delete;
		~Surface();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------
		void Create(VkInstance instance, HINSTANCE module, HWND hwnd);

		// Safe to call more than once; the destructor calls it too.
		void Destroy();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		VkSurfaceKHR GetSurface() const;

	private:
		// Data
		VkInstance   privInstance;		// borrowed, not owned
		VkSurfaceKHR privSurface;
	};
}

#endif   // SURFACE_H

// ---  End of File ---
