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

static float Input_Minus_1[]
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

TEST(Trig_ACos, TestConfig::ALL)
{
#if Trig_ACos

	float OutAngle[sizeof(Input_Minus_1) / sizeof(Input_Minus_1[0])]{0};

	float *pOut = &OutAngle[0];
	for(float x : Input_Minus_1)
	{
		*pOut++ = Trig::acos(x);
	}

	CHECK(eq_float(OutAngle[0], 3.1416f));
	CHECK(eq_float(OutAngle[1], 2.4189f));
	CHECK(eq_float(OutAngle[2], 2.0944f));
	CHECK(eq_float(OutAngle[3], 1.8235f));
	CHECK(eq_float(OutAngle[4], 1.5708f));
	CHECK(eq_float(OutAngle[5], 1.3181f));
	CHECK(eq_float(OutAngle[6], 1.0472f));
	CHECK(eq_float(OutAngle[7], 0.7227f));
	CHECK(eq_float(OutAngle[8], 0.0000f));

#endif
} TEST_END

// ---  End of File ---
