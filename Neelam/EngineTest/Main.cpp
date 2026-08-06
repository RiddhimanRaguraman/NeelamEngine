//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Entity.h"
#include "Transform.h"
#include "Game.h"

//---------------------------------------------------------------------------
// EngineTest -- the standalone sandbox for NeelamEngine.dll.
//
// This is the "no editor" path: it links the engine DLL and drives it the same
// way the C# / WPF editor eventually will, minus the host window. Make it the
// startup project to run the renderer on its own.
//
// Two halves, in order:
//   1. The component unit tests (entities / transforms), which are pure CPU
//      and must finish -- and release their file-scope arrays -- before the
//      renderer starts allocating.
//   2. The Vulkan engine: construct the Game, Initialize() with a nullptr
//      parent (standalone top-level window), and hand the frame loop to
//      Engine::Run() until the window closes. Run() calls Shutdown() itself.
//
// The editor path will NOT come through here -- it P/Invokes the DLL and calls
// Initialize(hwnd) / Tic() / Shutdown() from C#.
//---------------------------------------------------------------------------

int main()
{
	START_BANNER_MAIN("EngineThread");

	// ---- 1. component tests ---------------------------------------------
	Test::RunTests();

	// Release the engine's file-scope arrays here, at a point we control.
	// This has to happen before the memory tracker's exit report, and in a
	// deterministic order (entities first, then the transforms they index into)
	// -- static destruction order across translation units is unspecified.
	Neelam::GameEntity::shutdown(); // would be moved to worldman singleton with component pool
	Neelam::Transform::shutdown();

	// ---- 2. the Vulkan engine -------------------------------------------
	// Quick sanity ping through the Azul math library (a lib, still Azul::).
	Azul::Vec3 v(1.4f, 1.5f, 1.6f);
	Debug::out("%f ,%f, %f\n", v.x(), v.y(), v.z());

	Neelam::Game game;

	game.Initialize();		// nullptr parent -> standalone top-level window
	game.Run();				// pumps + Update/Render until WM_QUIT, then Shutdown

	return 0;
}

// ---  End of File ---
