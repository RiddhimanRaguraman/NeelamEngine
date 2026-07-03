//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatDivConst, TestConfig::ALL)
{
#if Quat_QuatDivConst

	Quat q1, q2;
	Quat out1, out2;
	// Quat / Constant

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	/// => out1 = q1 / 5.0f
	out1 = q1 / 5.0f;

	CHECK(eq_float(out1[x], 0.2f));
	CHECK(eq_float(out1[y], 0.4f));
	CHECK(eq_float(out1[z], 0.6f));
	CHECK(eq_float(out1[w], 0.80f));

#endif
} TEST_END

// --- End of File ---
