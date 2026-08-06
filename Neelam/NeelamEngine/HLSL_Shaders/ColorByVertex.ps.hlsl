//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------
// ColorByVertex -- pixel stage.
//
// Just passes the interpolated per-vertex color through. Edit this file while
// the app runs and the ShaderWatcher will hot-reload it.

struct PSInput
{
	float4 position : SV_Position;
	float3 color    : COLOR0;
};

float4 main(PSInput input) : SV_Target
{
	return float4(input.color, 1.0);
}
