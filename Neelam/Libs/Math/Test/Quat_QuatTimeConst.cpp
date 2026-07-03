//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatTimeConst, TestConfig::ALL)
{
#if Quat_QuatTimeConst

	Quat q1, q2;
	Quat out1, out2;
	// Quat * Constant

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => out1 = q1 * 5.0f
	out1 = q1 * 5.0f;

	CHECK((out1[x] == 5.0f));
	CHECK((out1[y] == 10.0f));
	CHECK((out1[z] == 15.0f));
	CHECK((out1[w] == 20.0f));

#endif
} TEST_END

// --- End of File ---

