#pragma once

// NEELAM_API resolves to:
//   __declspec(dllexport)  when building NeelamEngine.dll  (NEELAM_LIBRARY_EXPORTS)
//   __declspec(dllimport)  when a consumer links it        (NEELAM_USE_DLL only)
//   nothing                when built as a static lib      (no NEELAM_USE_DLL)
// Mark the engine's public API functions with it so they end up in NeelamEngine.lib.
#ifdef NEELAM_USE_DLL
	#ifdef NEELAM_LIBRARY_EXPORTS
		#define NEELAM_API __declspec(dllexport)
	#else
		#define NEELAM_API __declspec(dllimport)
	#endif
#else
	#define NEELAM_API
#endif
