//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_ConstDivQuat, TestConfig::ALL)
{
#if Quat_ConstDivQuat

	Quat q1, q2;
	Quat out1, out2;
	// Constant / Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => out1 = 5.0f / q1 \n"););
	out1 = 5.0f / q1;

	CHECK(eq_float(out1[x], 5.0f));
	CHECK(eq_float(out1[y], 2.5f));
	CHECK(eq_float(out1[z], 1.6666f));
	CHECK(eq_float(out1[w], 1.25f));

#endif
} TEST_END

// --- End of File ---
