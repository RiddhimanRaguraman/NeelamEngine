//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------
//
// The single TRANSLATION UNIT that compiles the BODIES of volk (the Vulkan
// meta-loader) and VMA (Vulkan Memory Allocator).
//
// WHY A WHOLE FILE FOR TWO INCLUDES
// ---------------------------------
// Framework.h is force-included into every TU, but it carries only the
// DECLARATIONS (its VULKAN FRAMEWORK section) -- "these functions exist, here
// is how to call them". The DEFINITIONS are ordinary non-inline functions and
// global variables: vmaCreateAllocator's ~300 lines, volk's ~400 function
// pointers. The One Definition Rule allows each of those exactly once in the
// whole program, so compiling them in all 23 app TUs would be LNK2005 hundreds
// of times over. An include guard cannot help -- a guard is per-TU, and every
// TU starts with a clean set of macros. This file is the "exactly once".
//
// Including volk.h / vk_mem_alloc.h a SECOND time here (Framework.h already
// pulled them in above) is safe and intended: in both headers the
// implementation block sits OUTSIDE the header's own include guard, so on this
// pass the guard swallows the declarations and only the bodies compile. That is
// the standard single-header-library contract, and it is why VOLK_IMPLEMENTATION
// / VMA_IMPLEMENTATION exist at all.
//
// WHERE IT LIVES
// --------------
// In Framework/ next to Framework.h, but only the Vulkan_Baseline project
// compiles it (see premake5.lua). It is deliberately NOT part of the shared
// "Framework" project: shared items are compiled by every consumer, and the lib
// DLLs (Math / File / AnimTime) are not in the Vulkan tier -- no
// USE_VULKAN_FRAMEWORK, no Vulkan SDK include path. The guard below makes that
// a no-op rather than a C1083 if this file is ever added somewhere it does not
// belong.

#ifdef USE_VULKAN_FRAMEWORK

// --- volk ---------------------------------------------------------------
// No barricade needed: volk is C-style function-pointer loading and never uses
// new / malloc.
#define VOLK_IMPLEMENTATION
#include <Volk/volk.h>

// --- VMA ----------------------------------------------------------------
// VMA_ASSERT_LEAK is VMA's own hook for "an allocation was never freed". Its
// default is assert(), and pressing Abort on that dialog calls abort() -- which
// tears the process down BEFORE MemTrace::ProcessEnd runs, so the VkLeak report
// never prints. Here MemTrace OWNS leak reporting, which makes VMA's abort both
// redundant and actively harmful: it destroys the very output we want. So route
// it to Debug::out and let the run finish.
//
// VMA_ASSERT proper is left FATAL -- a genuine VMA programming error still
// breaks into the debugger. Only the leak assert is downgraded.
//
// Both must be defined BEFORE the VMA_IMPLEMENTATION include below: VMA guards
// its own defaults with #ifndef, and it declares them inside its implementation
// section -- so ours land first and no redefinition warning fires.
//
// %.120s caps the expression: Debug::out formats through a 256-char vsprintf_s,
// and overflowing that trips its own "Buffer too small" assert.
#define VMA_ASSERT_LEAK(expr)                                                     \
	do                                                                            \
	{                                                                             \
		if (!(expr))                                                              \
		{                                                                         \
			Debug::out("[VMA] unfreed allocation -- vk_mem_alloc.h(%d)\n", __LINE__); \
			Debug::out("[VMA] %.120s\n", #expr);                                  \
		}                                                                         \
	} while (false)

// Per-allocation detail, for block (non-dedicated) leaks.
#define VMA_LEAK_LOG_FORMAT(format, ...)                                          \
	do                                                                            \
	{                                                                             \
		Debug::out("[VMA] " format "\n", __VA_ARGS__);                             \
	} while (false)

// Barricaded: the framework's memory-tracking macro rewrites `new` into
// new(_NORMAL_BLOCK, __FILE__, __LINE__), and VMA uses PLACEMENT new (new(ptr) T)
// internally, which that macro turns into a syntax error. Neutralize the memory
// macros across this include only, then put them back -- balanced, so every
// `new` after this point is tracked normally again.
//
// (The framework's AZUL_PLACEMENT_NEW_BEGIN/END are the sanctioned form, but
// they emit runtime statements -- an assert + a counter bump -- so they only
// work INSIDE a function body. Around a file-scope #include, use the underlying
// push_macro / #undef / pop_macro directly.)
#pragma push_macro("new")
#pragma push_macro("malloc")
#pragma push_macro("free")
#pragma push_macro("calloc")
#pragma push_macro("realloc")
#undef new
#undef malloc
#undef free
#undef calloc
#undef realloc

#define VMA_IMPLEMENTATION
#include <vma/vk_mem_alloc.h>

#pragma pop_macro("realloc")
#pragma pop_macro("calloc")
#pragma pop_macro("free")
#pragma pop_macro("malloc")
#pragma pop_macro("new")

#endif   // USE_VULKAN_FRAMEWORK

// ---  End of File ---
