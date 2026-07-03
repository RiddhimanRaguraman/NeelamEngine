//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatDivEqualConst, TestConfig::ALL)
{
#if Quat_QuatDivEqualConst

	Quat q1, q2;
	Quat out1, out2;
	// Quat /= Constant
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => q1 /= -10.0f 
	q1 /= -10.0f;

	CHECK(eq_float(q1[x], -0.1f));
	CHECK(eq_float(q1[y], -0.2f));
	CHECK(eq_float(q1[z], -0.3f));
	CHECK(eq_float(q1[w], -0.40f));

#endif
} TEST_END

// --- End of File ---
