//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Instance.h"

namespace Neelam::vk
{
	Instance::Instance()
		: privInstance(VK_NULL_HANDLE),
		  privDebugMessenger(VK_NULL_HANDLE)
	{
	}

	Instance::~Instance()
	{
		this->Destroy();
	}

	void Instance::Create(const char *pAppName)
	{
		// volk: load vkGetInstanceProcAddr + the global entry points (this
		// opens vulkan-1.dll). MUST run before any vk* call -- including the
		// validation-layer query just below. Nothing works until this succeeds.
		VK_Try(volkInitialize());

		// Validation layer (Debug only, and only if it is installed). All the
		// messenger boilerplate lives in Framework.h -> Validation::.
		const char *layers[1] = { Validation::LayerName };
		uint32_t    layerCount = 0;

		if (Validation::Enabled)
		{
			if (Validation::IsSupported())
			{
				layerCount = 1;
			}
			else
			{
				// Not fatal: a machine with only the runtime driver (no SDK)
				// simply runs without validation.
				Debug::out("Instance: %s not found (install the Vulkan SDK?) "
					"-- continuing without validation\n", Validation::LayerName);
			}
		}

		// Extensions: the two surface ones always; debug-utils only when
		// validation is actually on (it provides the messenger).
		const char *extensions[3];
		uint32_t    extCount = 0;
		extensions[extCount++] = VK_KHR_SURFACE_EXTENSION_NAME;
		extensions[extCount++] = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
		if (layerCount > 0)
		{
			extensions[extCount++] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
		}

		VkApplicationInfo appInfo = {};
		appInfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName   = pAppName;
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName        = "Neelam";
		appInfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion         = VK_API_VERSION_1_4;

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo        = &appInfo;
		createInfo.enabledExtensionCount   = extCount;
		createInfo.ppEnabledExtensionNames = extensions;
		createInfo.enabledLayerCount       = layerCount;
		createInfo.ppEnabledLayerNames     = (layerCount > 0) ? layers : nullptr;

		// Chain a messenger create-info into pNext so the layer also validates
		// the vkCreateInstance / vkDestroyInstance calls themselves.
		VkDebugUtilsMessengerCreateInfoEXT dbgInfo = {};
		if (layerCount > 0)
		{
			Validation::FillMessengerInfo(dbgInfo);
			createInfo.pNext = &dbgInfo;
		}

		VK_Try(vkCreateInstance(&createInfo, nullptr, &this->privInstance));

		// volk: now that the instance exists, load the instance-level and
		// physical-device entry points (vkGetPhysicalDevice*, vkCreateDevice,
		// vkCreateWin32SurfaceKHR, the debug-utils messenger fns, ...). Every
		// object built after this -- surface, physical device, device -- relies
		// on these pointers being live.
		volkLoadInstance(this->privInstance);

		// Standalone messenger: catches everything after instance creation.
		if (layerCount > 0)
		{
			this->privDebugMessenger = Validation::CreateMessenger(this->privInstance);
		}
	}

	void Instance::Destroy()
	{
		if (this->privInstance != VK_NULL_HANDLE)
		{
			// Messenger is created FROM the instance, so it goes first.
			Validation::DestroyMessenger(this->privInstance, this->privDebugMessenger);
			this->privDebugMessenger = VK_NULL_HANDLE;

			vkDestroyInstance(this->privInstance, nullptr);
			this->privInstance = VK_NULL_HANDLE;
		}
	}

	VkInstance Instance::GetInstance() const
	{
		return this->privInstance;
	}
}

// ---  End of File ---
