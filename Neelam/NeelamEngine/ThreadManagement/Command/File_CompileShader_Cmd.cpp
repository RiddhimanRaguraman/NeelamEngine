//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "File_CompileShader_Cmd.h"
#include "ShaderModulesReady_Cmd.h"
#include "ShaderCompiler.h"
#include "QueueMan.h"

namespace Neelam
{
	File_CompileShader_Cmd::File_CompileShader_Cmd(vk::ShaderObject::Name name,
												   const char *pVertexPath,
												   const char *pPixelPath)
		: Command(),
		  privName(name),
		  privVertexPath{},
		  privPixelPath{}
	{
		assert(pVertexPath);
		assert(pPixelPath);

		strcpy_s(this->privVertexPath, sizeof(this->privVertexPath), pVertexPath);
		strcpy_s(this->privPixelPath,  sizeof(this->privPixelPath),  pPixelPath);
	}

	void File_CompileShader_Cmd::Execute()
	{
		// ---- FILE THREAD. No Vulkan below this line. ----
		IDxcBlob *pVs = vk::ShaderCompiler::CompileFile(this->privVertexPath, vk::ShaderStage::Vertex);
		IDxcBlob *pPs = vk::ShaderCompiler::CompileFile(this->privPixelPath,  vk::ShaderStage::Pixel);

		if (pVs == nullptr && pPs == nullptr)
		{
			// Both stages failed to compile -- DXC already logged why. Nothing
			// to hand over, so do not post: keep the last-good pipeline.
			Debug::out("File_CompileShader: both stages failed, reload dropped\n");
			delete this;
			return;
		}

		// Hand the blobs to the engine thread. ShaderModulesReady_Cmd owns them
		// from here and releases them in its destructor.
		Command *pReady = new ShaderModulesReady_Cmd(this->privName, pVs, pPs);

		if (!QueueMan::SendEngine(pReady))
		{
			// Inbox full: never handed over, so it is still ours. Deleting it
			// releases the blobs too (see its destructor).
			Debug::out("File_CompileShader: engine inbox FULL, reload dropped\n");
			delete pReady;
		}

		delete this;
	}
}

// ---  End of File ---
