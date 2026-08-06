//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_COMPILER_H
#define SHADER_COMPILER_H

#include <dxc/dxcapi.h>			// DXC: IDxcBlob, IDxcCompiler3, ...

//---------------------------------------------------------------------------
// class ShaderCompiler
//
// Compiles an HLSL file to SPIR-V at RUNTIME using DXC (the DirectX Shader
// Compiler). Runtime compilation -- not precompiled bytecode -- is what makes
// the shaders hot-reloadable: edit the .hlsl, recompile, rebuild the pipeline.
//
// CompileFile returns an IDxcBlob holding the SPIR-V; the CALLER Release()s it
// (ShaderModule copies the code into a VkShaderModule, then releases the blob).
// On any failure it logs the DXC diagnostic and returns nullptr, so the caller
// can keep the last-good shader instead of crashing.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	enum class ShaderStage
	{
		Vertex,
		Pixel
	};

	class ShaderCompiler
	{
	public:
		// Stateless -- each call spins up its own DXC instances, so it is safe
		// to call from any thread.
		static IDxcBlob *CompileFile(const char *pFilePath, ShaderStage stage);
	};
}

#endif   // SHADER_COMPILER_H

// ---  End of File ---
