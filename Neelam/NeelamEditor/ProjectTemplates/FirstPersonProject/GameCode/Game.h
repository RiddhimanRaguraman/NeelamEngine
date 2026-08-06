//-----------------------------------------------------------------
// Your game.
//
// The concrete half of the engine's Engine/Game pair, copied here when this
// project was created. LoadContent / UnloadContent / Update / Render are the
// four hooks Engine calls; everything a game owns -- techniques, cameras,
// geometry -- lives behind them. Out of the box this draws one triangle.
//
// NOT COMPILED YET. premake builds Neelam.sln -- the editor, the engine and the
// libs -- and knows nothing about projects the editor creates at runtime. What
// the viewport actually runs is the copy of this class inside NeelamEngine.dll,
// built from NeelamEngine\Game. Compiling per-project game code needs its own
// build step, which does not exist yet.
//
// So this is a starting point and a reference: the real shape of a game, ready
// for the day the project itself gets built.
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "ShaderObject_ColorByVertex.h"
#include "ShaderWatcher.h"
#include "CameraNodeMan.h"
#include "ShaderObjectNodeMan.h"

//---------------------------------------------------------------------------
// class Game
//
// The concrete application. Derives from Engine and fills in the four content
// hooks. This is where objects, cameras and (later) a scene graph live -- the
// Engine's frame loop calls Update()/Render() here every Tic().
//
// Right now the hooks are stubs: there is no graphics pipeline yet, so the
// window simply comes up and the loop spins. Loading buffers, shaders and a
// swapchain, then drawing, all slot in behind these same four methods without
// the Engine loop or the window/instance/surface changing.
//
// NEELAM_API for the same reason Engine carries it: EngineTest declares a
// `Neelam::Game game;` on its stack, so the constructor, destructor and vtable
// all have to be reachable from outside NeelamEngine.dll.
//---------------------------------------------------------------------------

namespace Neelam
{
	class NEELAM_API Game : public Engine
	{
	public:
		Game();
		Game(const Game &) = delete;
		Game &operator = (const Game &) = delete;
		virtual ~Game();

		//-----------------------------------------------------------------
		// Engine content hooks
		//-----------------------------------------------------------------
		virtual void LoadContent()           override;
		virtual void UnloadContent()         override;
		virtual void Update(float deltaTime) override;
		virtual void Render()                override;

	private:
		// Rebuild the cameras' viewport/aspect when the window size changes.
		// CameraNodeMan owns the cameras themselves (singleton), so nothing here
		// holds one -- GetCurrent() hands the active one back.
		void privSyncCamerasToWindow();

		// The triangle technique + the background watcher that hot-reloads it.
		// ShaderWatcher is Neelam:: (threading plumbing), not Neelam::vk -- it
		// touches no Vulkan, it only posts commands.
		vk::ShaderObject_ColorByVertex triangleShader;
		ShaderWatcher                  shaderWatcher;

		// Real geometry, replacing the SV_VertexID triangle. Both are VMA
		// allocations, so they show up in the leak report if leaked.
		vk::GpuBuffer                  triangleVerts;
		vk::GpuBuffer                  triangleIndices;
		uint32_t                       triangleIndexCount;

		// Last extent the cameras were sized against, so the sync above only
		// runs on an actual resize instead of every frame.
		uint32_t privCamWidth;
		uint32_t privCamHeight;
	};
}

#endif   // GAME_H

// ---  End of File ---
