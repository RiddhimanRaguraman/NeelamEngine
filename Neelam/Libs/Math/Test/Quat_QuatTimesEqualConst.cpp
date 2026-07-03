//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatTimesEqualConst, TestConfig::ALL)
{
#if Quat_QuatTimesEqualConst

	Quat q1, q2;
	Quat out1, out2;
	// Quat *= Constant

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => q1 *= -10.0f
	q1 *= -10.0f;

	CHECK((q1[x] == -10.0f));
	CHECK((q1[y] == -20.0f));
	CHECK((q1[z] == -30.0f));
	CHECK((q1[w] == -40.0f));

#endif
} TEST_END

// --- End of File ---

