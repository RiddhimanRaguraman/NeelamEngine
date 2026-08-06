//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_OBJECT_COLOR_BY_VERTEX_H
#define SHADER_OBJECT_COLOR_BY_VERTEX_H

#include "ShaderObject.h"

//---------------------------------------------------------------------------
// class ShaderObject_ColorByVertex
//
// The concrete triangle technique (same name Azul used for the vertex-colored
// shader). It supplies its two .hlsl source files AND its vertex layout; the
// base does the compile, pipeline build, and hot-reload.
//
// The layout describes VertexPosColor (GpuBuffer.h) -- position at offset 0,
// color at 12, stride 24. These three numbers, that struct, and the HLSL
// input struct must agree; a mismatch is a validation error at pipeline
// creation, not a silent wrong result.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class ShaderObject_ColorByVertex : public ShaderObject
	{
	public:
		ShaderObject_ColorByVertex() = default;
		ShaderObject_ColorByVertex(const ShaderObject_ColorByVertex &) = delete;
		ShaderObject_ColorByVertex &operator = (const ShaderObject_ColorByVertex &) = delete;
		virtual ~ShaderObject_ColorByVertex() = default;

		virtual const char *GetVertexPath() const override;
		virtual const char *GetPixelPath() const override;

		virtual uint32_t GetVertexBindings(const VkVertexInputBindingDescription **ppOut) const override;
		virtual uint32_t GetVertexAttributes(const VkVertexInputAttributeDescription **ppOut) const override;
	};
}

#endif   // SHADER_OBJECT_COLOR_BY_VERTEX_H

// ---  End of File ---
