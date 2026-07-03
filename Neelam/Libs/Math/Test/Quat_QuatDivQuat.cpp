//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatDivQuat, TestConfig::ALL)
{
#if Quat_QuatDivQuat

	Quat q1, q2;
	Quat out1, out2;

	// Quat / Quat 
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(9.0f, -3.0f, 5.0f, 20.0f);

	// => out1 = q1 / q2 
	out1 = q1 / q2;

	CHECK(eq_float(out1[x], 0.1111f));
	CHECK(eq_float(out1[y], -0.6667f));
	CHECK(eq_float(out1[z], 0.6f));
	CHECK(eq_float(out1[w], 0.2f));

#endif
} TEST_END

// --- End of File ---
