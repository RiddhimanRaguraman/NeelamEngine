//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatTimesQuat, TestConfig::ALL)
{
#if Quat_QuatTimesQuat

	Quat q1, q2;
	Quat out1, out2;

	// Quat * Quat 
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(9.0f, -3.0f, 5.0f, 20.0f);

	// out1 = q1 * q2 
	out1 = q1 * q2;

	CHECK((out1[x] == 37.0f));
	CHECK((out1[y] == 6.0f));
	CHECK((out1[z] == 101.0f));
	CHECK((out1[w] == 62.0f));

#endif
} TEST_END

// --- End of File ---

