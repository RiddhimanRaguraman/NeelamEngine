//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CommonHeaders.h"
#include "Game.h"

//---------------------------------------------------------------------------
// The renderer's P/Invoke surface.
//
// Engine::Initialize / Tic / Shutdown / GetWindowHandle were written from the
// start with signatures free of C++ types, precisely so they could be exposed
// 1:1 as extern "C" once the editor needed them. This file is that exposure and
// nothing more -- no logic lives here.
//
// The C# side (NeelamEditor.EngineWrapper.EngineAPI) drives it from a WPF
// HwndHost:
//
//     BuildWindowCore(hwndParent)  -> EngineInitialize(hwndParent)
//                                     EngineGetWindowHandle()  -> handed to WPF
//     CompositionTarget.Rendering  -> EngineTic()
//     DestroyWindowCore()          -> EngineShutdown()
//
// ENGINE_API (EngineAPI.h) is `extern "C" __declspec(dllexport)` in this build,
// so the names land in NeelamEngine.dll's export table unmangled and P/Invoke
// finds them by plain name.
//
// EVERY function here must be called from ONE thread -- the same thread, every
// time. That is not a C# constraint, it is the engine's: all Vulkan work
// belongs to the engine thread, and Initialize is what claims the caller as
// that thread. WPF's UI thread satisfies this (BuildWindowCore, the Rendering
// event and DestroyWindowCore all run on it).
//---------------------------------------------------------------------------

namespace
{
	// Function-local static, NOT a heap object, and that is deliberate. A
	// `new Game` still alive when the host process leaves main() is reported as
	// a leak: MemTrace::ProcessEnd walks the shared debug heap from the exe's
	// static destructors, before this DLL detaches, so anything the DLL still
	// owns at that instant is snapshotted no matter when it is freed. A static
	// never touches the heap, and the content it DOES allocate (cameras,
	// buffers, the technique registry) is released by Shutdown well before then.
	//
	// Lazy by construction: nothing exists until the first EngineInitialize, so
	// a host that never shows a viewport pays nothing.
	Neelam::Game &privGetGame()
	{
		static Neelam::Game game;
		return game;
	}

	// Engine::Shutdown is already idempotent and Initialize is not, so this
	// tracks the pair. It also makes Tic before Initialize a no-op instead of a
	// crash -- worth having, because the call order is decided in C# where the
	// compiler cannot help.
	bool privRunning = false;
}

//---------------------------------------------------------------------------
// Bring up the renderer inside the host's window.
//
//   hParentWnd != nullptr -> child window parented to it (the editor case)
//   hParentWnd == nullptr -> standalone top-level window
//
// Returns 1 on success, 0 if it was already running. Failures inside the engine
// do not come back through here -- VK_Try reports and exits (see §12 of the
// build notes), which is the same contract the standalone path has always had.
//---------------------------------------------------------------------------
ENGINE_API int EngineInitialize(void *hParentWnd)
{
	if (privRunning)
	{
		return 0;
	}

	privGetGame().Initialize(reinterpret_cast<HWND>(hParentWnd));
	privRunning = true;

	return 1;
}

//---------------------------------------------------------------------------
// One frame: drain commands, Update, Render. Does NOT pump the message queue --
// hosted in WPF the host owns the pump, which is exactly why Tic and Run are
// separate entry points.
//---------------------------------------------------------------------------
ENGINE_API void EngineTic()
{
	if (!privRunning)
	{
		return;
	}

	privGetGame().Tic();
}

//---------------------------------------------------------------------------
// Tear down content + Vulkan + the window. Safe to call more than once, and
// safe to follow with another EngineInitialize -- the Game object survives and
// is re-initialized, which is what makes closing and reopening a project work.
//---------------------------------------------------------------------------
ENGINE_API void EngineShutdown()
{
	if (!privRunning)
	{
		return;
	}

	privGetGame().Shutdown();
	privRunning = false;
}

//---------------------------------------------------------------------------
// The native surface for the host to embed. This is the handle WPF's
// HwndHost.BuildWindowCore returns. Valid only between Initialize and Shutdown.
//---------------------------------------------------------------------------
ENGINE_API void *EngineGetWindowHandle()
{
	if (!privRunning)
	{
		return nullptr;
	}

	return reinterpret_cast<void *>(privGetGame().GetWindowHandle());
}

// ---  End of File ---
