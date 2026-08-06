//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef INSTANCE_H
#define INSTANCE_H

// Vulkan types come from the force-included Framework.h (VULKAN FRAMEWORK section).

//---------------------------------------------------------------------------
// class Instance
//
// Owns the VkInstance -- the root Vulkan object every other call hangs off.
// It is created with the two surface extensions turned on:
//
//     VK_KHR_surface         -- generic surface support
//     VK_KHR_win32_surface   -- the Win32 flavour, needed by Surface
//
// In DEBUG builds it also turns on the validation layer
// (VK_LAYER_KHRONOS_validation) plus the debug-utils messenger, which routes
// the layer's messages into Debug::out. Without validation, a wrong struct
// field is a silent black screen or crash; with it, you get a plain-English
// error naming the exact problem. It is Debug-only because the layer adds real
// per-call overhead you do not want in Release.
//
// We include the C++ bindings <vulkan/vulkan.hpp>, which pulls in the C header
// <vulkan/vulkan.h> for us -- so the plain C API used below stays available
// while leaving the door open to layer vk:: RAII types on top later.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class Instance
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		Instance();
		Instance(const Instance &) = delete;
		Instance &operator = (const Instance &) = delete;
		~Instance();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------
		void Create(const char *pAppName);

		// Safe to call more than once; the destructor calls it too.
		void Destroy();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		VkInstance GetInstance() const;

	private:
		// Data
		VkInstance               privInstance;

		// Owns the validation messenger's lifetime (Debug only; the boilerplate
		// to build it lives in Framework.h -> Validation::).
		VkDebugUtilsMessengerEXT privDebugMessenger;
	};
}

#endif   // INSTANCE_H

// ---  End of File ---
