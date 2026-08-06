//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef ENGINE_H
#define ENGINE_H

#include "EngineAPI.h"		// NEELAM_API export/import macro

#include "Window.h"
#include "Instance.h"
#include "Surface.h"
#include "PhysicalDevice.h"
#include "QueueFamily.h"
#include "LogicalDevice.h"
#include "Swapchain.h"
#include "GraphicsPipeline.h"

#include "QueueMan.h"
#include "FileThread.h"

#include "AnimTimer.h"

//---------------------------------------------------------------------------
// class Engine  (Template Method base)
//
// Owns the window + the Vulkan objects (by composition) and the frame loop.
// Game derives from it and fills in the four content hooks -- the base calls
// DOWN into them through the vtable, so Engine never knows what the game is
// and Game never knows what a message pump is.
//
// Two ways to run:
//
//   Standalone .exe:
//       Game game;
//       game.Initialize();     // nullptr parent -> own top-level window
//       game.Run();            // Engine owns the loop until WM_QUIT
//
//   Hosted in the C# / WPF editor:
//       game.Initialize(hwndFromWpf);   // child window inside the editor
//       ... C# drives frames by calling Tick() from its render callback ...
//       game.Shutdown();
//       (hand GetWindowHandle() to WPF's HwndHost.BuildWindowCore)
//
// The public Initialize / Tick / Shutdown / GetWindowHandle map 1:1 to the
// extern "C" functions a future DLL build will export for P/Invoke -- keeping
// them free of C++ types in their signatures is deliberate.
//
// NEELAM_API: the engine builds as NeelamEngine.dll, so the whole class is
// exported (dllexport here, dllimport in EngineTest / any other consumer).
// Whole-class rather than per-member because Game is constructed BY VALUE in
// the consumer -- that needs the vtable and the base's members to come across,
// not just a hand-picked set of entry points.
//---------------------------------------------------------------------------

namespace Neelam
{
	class NEELAM_API Engine
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		Engine();
		Engine(const Engine &) = delete;
		Engine &operator = (const Engine &) = delete;
		virtual ~Engine() = default;

		//-----------------------------------------------------------------
		// Lifecycle  (the DLL-export surface)
		//-----------------------------------------------------------------

		// Bring up window + Vulkan, then LoadContent().
		//   hParentWnd == nullptr -> standalone top-level window.
		//   hParentWnd != nullptr -> child window hosted in the editor's HWND.
		void Initialize(HWND hParentWnd = nullptr);

		// Advance exactly one frame: compute dt, Update(dt), Render().
		// Does NOT pump the message queue -- in the editor WPF owns the pump,
		// and standalone Run() pumps separately before calling this.
		void Tic();

		// UnloadContent() + tear down Vulkan and the window (reverse order).
		void Shutdown();

		// Standalone convenience: pump this window's own queue and Tic() until
		// WM_QUIT, then Shutdown(). Do not call this when hosted in WPF.
		void Run();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------

		// The native handle the editor hosts. Valid after Initialize().
		HWND GetWindowHandle() const;

	protected:
		//-----------------------------------------------------------------
		// Content hooks -- Game overrides these.
		//-----------------------------------------------------------------
		virtual void LoadContent()           = 0;
		virtual void UnloadContent()         = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render()                = 0;

		//-----------------------------------------------------------------
		// Vulkan Objects
		//-----------------------------------------------------------------
		vk::Window			 window;
		vk::Instance		 instance;
		vk::Surface			 surface;
		vk::PhysicalDevice   physicalDevice;
		vk::QueueFamily		 queueFamily;
		vk::LogicalDevice	 logicalDevice;
		vk::Swapchain        swapchain;
		vk::GraphicsPipeline graphicsPipeline;	

	private:
		void privRecreateSwapchain();
		void privDrainCommands();

		FileThread      privFileThread;
		Azul::AnimTimer privFrameTimer;
		bool            privInitialized;

		// Both DEFINED in Engine.cpp, deliberately -- an in-class initializer
		// would make this an inline variable, and a dllexport class exports its
		// static data members. Consumers would then be defining a dllimport
		// static member (C2491). Out-of-line, the header only declares them.
		static const float    privMaxTimeStep;
		static const uint32_t privMaxCommandsPerFrame;
	};
}

#endif   // ENGINE_H

// ---  End of File ---
