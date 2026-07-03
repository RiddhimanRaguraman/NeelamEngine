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

static float Input_Minus_11[]
{
	-1.0f + 0 * 0.25f,
	-1.0f + 1 * 0.25f,
	-1.0f + 2 * 0.25f,
	-1.0f + 3 * 0.25f,
	-1.0f + 4 * 0.25f,
	-1.0f + 5 * 0.25f,
	-1.0f + 6 * 0.25f,
	-1.0f + 7 * 0.25f,
	-1.0f + 8 * 0.25f
};

TEST(Trig_ASin, TestConfig::ALL)
{
#if Trig_ASin

	float OutAngle[sizeof(Input_Minus_11) / sizeof(Input_Minus_11[0])]{0};

	float *pOut = &OutAngle[0];
	for(float x : Input_Minus_11)
	{
		*pOut++ = Trig::asin(x);
	}

	CHECK(eq_float(OutAngle[0], -1.5708f));
	CHECK(eq_float(OutAngle[1], -0.8481f));
	CHECK(eq_float(OutAngle[2], -0.5236f));
	CHECK(eq_float(OutAngle[3], -0.2527f));
	CHECK(eq_float(OutAngle[4], 0.0000f));
	CHECK(eq_float(OutAngle[5], 0.2527f));
	CHECK(eq_float(OutAngle[6], 0.5236f));
	CHECK(eq_float(OutAngle[7], 0.8481f));
	CHECK(eq_float(OutAngle[8], 1.5708f));

#endif
} TEST_END

// ---  End of File ---
