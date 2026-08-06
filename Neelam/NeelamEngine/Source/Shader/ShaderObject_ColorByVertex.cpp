//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderObject_ColorByVertex.h"
#include "GpuBuffer.h"			// VertexPosColor -- the layout described below

namespace Neelam::vk
{
	//-----------------------------------------------------------------
	// Vertex layout for VertexPosColor. STATIC, because the pipeline create
	// info only stores POINTERS to these -- a local array would dangle by the
	// time vkCreateGraphicsPipelines reads it.
	//
	// offsetof() rather than hardcoded 0/12 so the struct stays the single
	// source of truth: reorder VertexPosColor and this follows.
	//-----------------------------------------------------------------
	static const VkVertexInputBindingDescription privBindings[1] =
	{
		{ 0, (uint32_t)sizeof(VertexPosColor), VK_VERTEX_INPUT_RATE_VERTEX }
	};

	static const VkVertexInputAttributeDescription privAttributes[2] =
	{
		// location, binding, format, offset
		{ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, (uint32_t)offsetof(VertexPosColor, x) },	// POSITION
		{ 1, 0, VK_FORMAT_R32G32B32_SFLOAT, (uint32_t)offsetof(VertexPosColor, r) }		// COLOR0
	};

	uint32_t ShaderObject_ColorByVertex::GetVertexBindings(const VkVertexInputBindingDescription **ppOut) const
	{
		*ppOut = privBindings;
		return 1;
	}

	uint32_t ShaderObject_ColorByVertex::GetVertexAttributes(const VkVertexInputAttributeDescription **ppOut) const
	{
		*ppOut = privAttributes;
		return 2;
	}

	// Absolute paths via SOLUTION_DIR (a compile-time macro from premake), so
	// the shaders are found no matter what the working directory is. The .hlsl
	// files must stay on disk at runtime -- hot-reload reads the SOURCE, not
	// baked bytecode.
	const char *ShaderObject_ColorByVertex::GetVertexPath() const
	{
		return SOLUTION_DIR "NeelamEngine\\HLSL_Shaders\\ColorByVertex.vs.hlsl";
	}

	const char *ShaderObject_ColorByVertex::GetPixelPath() const
	{
		return SOLUTION_DIR "NeelamEngine\\HLSL_Shaders\\ColorByVertex.ps.hlsl";
	}
}

// ---  End of File ---
