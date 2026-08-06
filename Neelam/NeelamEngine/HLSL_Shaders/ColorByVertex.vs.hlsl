//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------
// ColorByVertex -- vertex stage.
//
// Reads a real VERTEX BUFFER now (VertexPosColor: float3 pos + float3 color,
// stride 24) instead of building positions from SV_VertexID. The layout is
// declared C++-side in ShaderObject_ColorByVertex; the semantics below must
// line up with the attribute LOCATIONS there -- POSITION is location 0, COLOR0
// is location 1.
//
// Edit this file while the app runs and the ShaderWatcher will hot-reload it.

//-----------------------------------------------------------------
// Push constants -- must match Neelam::vk::ShaderMatrices exactly (128 bytes)
// and the VkPushConstantRange in ShaderObject::privBuildLayout.
//
// row_major is NOT optional. HLSL packs matrices COLUMN-major by default, but
// Azul::Mat4 is stored as 4 row Vec4s and Azul is a row-vector library (v * M).
// Without it every matrix arrives transposed and the geometry vanishes.
//
// viewProj is premultiplied on the CPU, so this is world THEN viewProj -- the
// same left-to-right order the C++ side uses.
//-----------------------------------------------------------------
struct PushConstants
{
	row_major float4x4 world;
	row_major float4x4 viewProj;
};

[[vk::push_constant]] PushConstants pc;

struct VSInput
{
	float3 position : POSITION;
	float3 color    : COLOR0;
};

struct VSOutput
{
	float4 position : SV_Position;
	float3 color    : COLOR0;
};

VSOutput main(VSInput input)
{
	VSOutput output;

	// Row-vector chain, left to right: model -> world -> clip.
	float4 worldPos = mul(float4(input.position, 1.0), pc.world);
	output.position = mul(worldPos, pc.viewProj);

	output.color = input.color;
	return output;
}
