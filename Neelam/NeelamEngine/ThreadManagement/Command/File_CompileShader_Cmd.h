//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef FILE_COMPILE_SHADER_CMD_H
#define FILE_COMPILE_SHADER_CMD_H

#include "Command.h"
#include "ShaderObject.h"

namespace Neelam
{
	//-----------------------------------------------------------------------
	// class File_CompileShader_Cmd
	//
	// "Read these two .hlsl files and compile them to SPIR-V."
	//
	// Posted by the ShaderWatcher, executed on the FILE THREAD. This is the
	// expensive half of a hot-reload -- disk I/O plus a DXC compile, tens of
	// milliseconds -- and moving it off the engine thread is the entire point
	// of the FileThread. ShaderCompiler::CompileFile is stateless (it builds
	// its own DXC instances per call), which is what makes it callable here.
	//
	// NO VULKAN happens on this thread. On success it posts a
	// ShaderModulesReady_Cmd carrying the blobs back to the engine, which does
	// the vkCreateShaderModule + pipeline rebuild.
	//
	// Paths are copied by value: the ShaderObject they came from lives on
	// another thread and could be destroyed while this is queued.
	//-----------------------------------------------------------------------
	class File_CompileShader_Cmd final : public Command
	{
	public:
		File_CompileShader_Cmd() = delete;
		File_CompileShader_Cmd(const File_CompileShader_Cmd &) = delete;
		File_CompileShader_Cmd &operator = (const File_CompileShader_Cmd &) = delete;
		virtual ~File_CompileShader_Cmd() = default;

		File_CompileShader_Cmd(vk::ShaderObject::Name name,
							   const char *pVertexPath,
							   const char *pPixelPath);

		virtual void Execute() override;

	private:
		vk::ShaderObject::Name privName;
		char                   privVertexPath[512];
		char                   privPixelPath[512];
	};
}

#endif   // FILE_COMPILE_SHADER_CMD_H

// ---  End of File ---
