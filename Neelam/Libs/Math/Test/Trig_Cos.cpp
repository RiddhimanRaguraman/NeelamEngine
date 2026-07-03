//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

static float AngleTest_0_2PI[] // 0-2PI
{
	0.0f,
	1.0f * MATH_PI8,
	2.0f * MATH_PI8,
	3.0f * MATH_PI8,
	4.0f * MATH_PI8,
	5.0f * MATH_PI8,
	6.0f * MATH_PI8,
	7.0f * MATH_PI8,
	8.0f * MATH_PI8,
	9.0f * MATH_PI8,
	10.0f * MATH_PI8,
	11.0f * MATH_PI8,
	12.0f * MATH_PI8,
	13.0f * MATH_PI8,
	14.0f * MATH_PI8,
	15.0f * MATH_PI8,
	16.0f * MATH_PI8
};

TEST(Trig_Cos, TestConfig::ALL)
{
#if Trig_Cos

	float OutAngle[sizeof(AngleTest_0_2PI) / sizeof(AngleTest_0_2PI[0])]{0};

	float *pOut = &OutAngle[0];
	for(float x : AngleTest_0_2PI)
	{
		*pOut++ = Trig::cos(x);
	}

	CHECK(eq_float(OutAngle[0], 1.0000f));
	CHECK(eq_float(OutAngle[1], 0.9239f));
	CHECK(eq_float(OutAngle[2], 0.7071f));
	CHECK(eq_float(OutAngle[3], 0.3827f));
	CHECK(eq_float(OutAngle[4], -0.0000f));
	CHECK(eq_float(OutAngle[5], -0.3827f));
	CHECK(eq_float(OutAngle[6], -0.7071f));
	CHECK(eq_float(OutAngle[7], -0.9239f));
	CHECK(eq_float(OutAngle[8], -1.0000f));
	CHECK(eq_float(OutAngle[9], -0.9239f));
	CHECK(eq_float(OutAngle[10], -0.7071f));
	CHECK(eq_float(OutAngle[11], -0.3827f));
	CHECK(eq_float(OutAngle[12], 0.0000f));
	CHECK(eq_float(OutAngle[13], 0.3827f));
	CHECK(eq_float(OutAngle[14], 0.7071f));
	CHECK(eq_float(OutAngle[15], 0.9239f));
	CHECK(eq_float(OutAngle[16], 1.0000f));

#endif
} TEST_END

// ---  End of File ---
