//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Game.h"

namespace Neelam
{
	Game::Game()
		: Engine(),
		  triangleShader(),
		  shaderWatcher(),
		  triangleVerts(),
		  triangleIndices(),
		  triangleIndexCount(0),
		  privCamWidth(0),
		  privCamHeight(0)
	{
	}

	Game::~Game()
	{
	}

	//-----------------------------------------------------------------
	// LoadContent -- called once, after the window + Vulkan are up.
	//   Later: create GameObjects, cameras, and insert them into a scene
	//   graph (the PCSTree). Load buffers / shaders / pipeline.
	//-----------------------------------------------------------------
	void Game::LoadContent()
	{
		Debug::out("Game: LoadContent\n");

		// Technique registry. Content, so it lives here with CameraNodeMan --
		// the Engine owns the FileThread but knows nothing about shaders.
		// It is also how a cross-thread command resolves a ShaderObject::Name
		// back to a live technique.
		vk::ShaderObjectNodeMan::Create(4, 2);

		// Build the triangle technique (compiles HLSL -> SPIR-V -> pipeline).
		// The pipeline bakes in the swapchain's color + depth formats.
		this->triangleShader.Create(this->logicalDevice.GetDevice(),
									this->swapchain.GetColorFormat(),
									this->swapchain.GetDepthFormat());

		// Register the technique so a cross-thread command can resolve it by
		// NAME. The node BORROWS it -- triangleShader is a member of this Game,
		// so the manager must not (and does not) delete it.
		this->triangleShader.SetName(vk::ShaderObject::Name::ColorByVertex);
		vk::ShaderObjectNodeMan::Add(&this->triangleShader);

		// ---- geometry -------------------------------------------------------
		// World space, +Y up -- the camera's projection does the Vulkan Y flip.
		const vk::VertexPosColor verts[3] =
		{
			//   x      y     z        r     g     b
			{  0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f },		// top    - red
			{  0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f },		// b-right- green
			{ -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f }		// b-left - blue
		};

		const uint32_t indices[3] = { 0, 1, 2 };

		this->triangleVerts.Create(verts, sizeof(verts), VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
		this->triangleIndices.Create(indices, sizeof(indices), VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
		this->triangleIndexCount = 3;

		// Start the background watcher on the shader folder. From here on,
		// saving a .hlsl posts a compile to the FILE thread, which compiles the
		// SPIR-V off-frame and posts the result back to the engine thread to be
		// swapped in. Game does not participate -- that is the actor split.
		this->shaderWatcher.Start(&this->triangleShader);

		// ---- cameras -------------------------------------------------------
		// CameraNodeMan is a singleton manager over the Manager DLL's DLink list:
		// it owns every Camera, finds them by Camera::Name, and drives their
		// per-frame update + input. Reserve 2 so Add() never allocates at
		// runtime (the reserve pool grows by 1 if it ever needs to).
		CameraNodeMan::Create(2, 1);

		const VkExtent2D extent = this->swapchain.GetExtent();
		const float aspect = (float)extent.width / (float)extent.height;

		// 3D perspective camera. Right-handed: setOrientAndPosition flips vDir,
		// so the camera looks from +Z back toward the origin.
		Camera *pCam3D = new Camera(Camera::Type::PERSPECTIVE_3D);
		pCam3D->setViewport(0, 0, (int)extent.width, (int)extent.height);
		pCam3D->setPerspective(35.0f, aspect, 1.0f, 1000.0f);
		pCam3D->setOrientAndPosition(Azul::Vec3(0.0f, 1.0f, 0.0f),		// up
									 Azul::Vec3(0.0f, 0.0f, 0.0f),		// look at
									 Azul::Vec3(0.0f, 0.0f, 5.0f));		// position
		pCam3D->updateCamera();

		CameraNodeMan::Add(Camera::Name::CAMERA_0, pCam3D);
		CameraNodeMan::SetCurrent(Camera::Name::CAMERA_0, Camera::Type::PERSPECTIVE_3D);

		// 2D orthographic camera, in pixel units, for later sprite/UI work.
		Camera *pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
		pCam2D->setViewport(0, 0, (int)extent.width, (int)extent.height);
		pCam2D->setOrthographic(0.0f, (float)extent.width,
								0.0f, (float)extent.height,
								1.0f, 1000.0f);
		pCam2D->setOrientAndPosition(Azul::Vec3(0.0f, 1.0f, 0.0f),
									 Azul::Vec3(0.0f, 0.0f, 0.0f),
									 Azul::Vec3(0.0f, 0.0f, 5.0f));
		pCam2D->updateCamera();

		CameraNodeMan::Add(Camera::Name::CAMERA_1, pCam2D);
		CameraNodeMan::SetCurrent(Camera::Name::CAMERA_1, Camera::Type::ORTHOGRAPHIC_2D);

		this->privCamWidth  = extent.width;
		this->privCamHeight = extent.height;

		Debug::out("Game: cameras created (3D + 2D, %ux%u)\n", extent.width, extent.height);
	}

	//-----------------------------------------------------------------
	// Match the cameras to the window. Only fires when the swapchain extent
	// actually changed (resize), because setPerspective() would otherwise
	// rewrite fovy every frame and stomp the Z/C zoom in ProcessInput -- hence
	// setAspectRatio(), which touches the aspect alone.
	//-----------------------------------------------------------------
	void Game::privSyncCamerasToWindow()
	{
		const VkExtent2D extent = this->swapchain.GetExtent();

		// Minimized: a 0-size extent would divide by zero in the aspect below.
		if (extent.width == 0 || extent.height == 0)
		{
			return;
		}
		if (extent.width == this->privCamWidth && extent.height == this->privCamHeight)
		{
			return;
		}

		Camera *pCam3D = CameraNodeMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
		pCam3D->setViewport(0, 0, (int)extent.width, (int)extent.height);
		pCam3D->setAspectRatio((float)extent.width / (float)extent.height);

		Camera *pCam2D = CameraNodeMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
		pCam2D->setViewport(0, 0, (int)extent.width, (int)extent.height);
		pCam2D->setOrthographic(0.0f, (float)extent.width,
								0.0f, (float)extent.height,
								1.0f, 1000.0f);

		this->privCamWidth  = extent.width;
		this->privCamHeight = extent.height;
	}

	//-----------------------------------------------------------------
	// UnloadContent -- called once, before Vulkan is torn down.
	//   Later: destroy whatever LoadContent created (reverse order).
	//-----------------------------------------------------------------
	void Game::UnloadContent()
	{
		Debug::out("Game: UnloadContent\n");

		// Stop the watcher thread before tearing the shader down.
		this->shaderWatcher.Stop();
		this->triangleShader.Destroy();

		// Before VulkanAllocator is destroyed (Engine::Shutdown) -- VMA asserts
		// on any allocation still live at vmaDestroyAllocator.
		this->triangleVerts.Destroy();
		this->triangleIndices.Destroy();

		// Nodes only -- ShaderObjectNode BORROWS its technique (triangleShader
		// is a member of this Game), so nothing here deletes a ShaderObject.
		//
		// Safe to drop now even with a compile possibly still in flight: from
		// this point Engine::Shutdown only ever DELETES queued commands, never
		// executes them, so no Find() can run against a dead registry.
		vk::ShaderObjectNodeMan::Destroy();

		// Deletes every Camera it owns (the CameraNodes delete their Camera in
		// privClear), plus the reserve pool and the compare strategy.
		CameraNodeMan::Destroy();
	}

	//-----------------------------------------------------------------
	// Update -- once per frame, before Render. deltaTime is in seconds.
	//   Later: walk the scene graph updating each node (input, animation,
	//   transforms, camera).
	//-----------------------------------------------------------------
	void Game::Update(float deltaTime)
	{
		AZUL_UNUSED_VAR(deltaTime);

		this->privSyncCamerasToWindow();

		CameraNodeMan::Update();
	}

	//-----------------------------------------------------------------
	// Render -- once per frame, after Update.
	//   The whole frame loop lives in GraphicsPipeline (owned by Engine); Game
	//   just hands it what to draw. Later this becomes a draw list / scene-graph
	//   walk instead of a single hard-coded technique.
	//-----------------------------------------------------------------
	void Game::Render()
	{
		// Camera supplies viewport/scissor + the viewProj push constant; the
		// buffers supply the geometry. Later this becomes a draw list / scene
		// graph walk instead of one hard-coded technique + mesh.
		this->graphicsPipeline.Render(this->triangleShader,
									  CameraNodeMan::GetCurrent(Camera::Type::PERSPECTIVE_3D),
									  &this->triangleVerts,
									  &this->triangleIndices,
									  this->triangleIndexCount);
	}
}

// ---  End of File ---
