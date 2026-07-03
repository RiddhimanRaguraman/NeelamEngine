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

static float Input_Sqrt2[]
{
	0.0f,
	0.5f,
	0.8f,
	2.0f,
	4.0f,
	1000.0f,
	5000.0f,
	10000.0f
};

TEST(Trig_InvSqrt, TestConfig::ALL)
{
#if Trig_InvSqrt

	float Out[sizeof(Input_Sqrt2) / sizeof(Input_Sqrt2[0])]{0};

	float *pOut = &Out[0];
	for(float x : Input_Sqrt2)
	{
		*pOut++ = Trig::rsqrt(x + 0.01f);
	}

	CHECK(eq_float(Out[0], 10.0000f));
	CHECK(eq_float(Out[1],  1.4003f));
	CHECK(eq_float(Out[2],  1.1111f));
	CHECK(eq_float(Out[3],  0.7053f));
	CHECK(eq_float(Out[4],  0.4994f));
	CHECK(eq_float(Out[5],  0.0316f));
	CHECK(eq_float(Out[6],  0.0141f));
	CHECK(eq_float(Out[7],  0.0100f));

#endif
} TEST_END

// ---  End of File ---
