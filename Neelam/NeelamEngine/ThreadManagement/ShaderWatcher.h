//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_WATCHER_H
#define SHADER_WATCHER_H

#include "ShaderObject.h"		// Name + the two source paths, read on this thread

//---------------------------------------------------------------------------
// class ShaderWatcher   (an actor)
//
// Watches a folder of .hlsl files and, when one is edited, POSTS a
// File_CompileShader_Cmd to the FILE thread's inbox.
//
// Three actors, one direction:
//   Watcher  detects the change, posts the shader NAME + source paths
//   File     reads + DXC-compiles to SPIR-V (the slow part), posts the blobs
//   Engine   vkCreateShaderModule + pipeline rebuild -- the only Vulkan step
//
// The split is the point: the compile costs tens of milliseconds and used to
// stall a frame, while ALL Vulkan work belongs to the engine thread. This
// thread does neither -- it only detects and posts.
//
// Detection is OS-driven, not polled: it blocks in WaitForMultipleObjects on
// {change-notification, quit-event}, so an idle watcher costs no CPU and a save
// is seen immediately. Timestamps are still compared, but only to DEDUPE --
// editors commonly write a file two or three times per save.
//
// Namespace is Neelam, not Neelam::vk: threading plumbing, not a Vulkan object.
//---------------------------------------------------------------------------

namespace Neelam
{
	class ShaderWatcher
	{
	public:
		ShaderWatcher();
		ShaderWatcher(const ShaderWatcher &) = delete;
		ShaderWatcher &operator = (const ShaderWatcher &) = delete;
		~ShaderWatcher();

		// Launch the watcher on the folder pShader's sources live in -- the
		// directory is DERIVED from GetVertexPath() rather than passed in.
		//
		// It used to take the folder as a second argument, which meant the same
		// path existed as a literal in two places; moving the .hlsl folder
		// updated one and not the other, and the watcher silently died with
		// "hot reload OFF" because the folder no longer existed. One source of
		// truth now: the technique's own path.
		void Start(vk::ShaderObject *pShader);

		// Signals the quit event, wakes the blocked wait, joins. Safe to call
		// more than once.
		void Stop();

	private:
		void privThreadMain();
		static unsigned long long privNewestWriteTime(const char *pDir);

		std::thread        privThread;
		char               privDir[512];
		unsigned long long privLastSeen;

		// Manual-reset event, signalled by Stop(). Waited on ALONGSIDE the
		// change notification, which is what lets the thread block forever and
		// still shut down promptly -- no timeout, no polling.
		HANDLE             privQuitEvent;

		vk::ShaderObject  *poShader;		// borrowed; see Start()
	};
}

#endif   // SHADER_WATCHER_H

// ---  End of File ---
