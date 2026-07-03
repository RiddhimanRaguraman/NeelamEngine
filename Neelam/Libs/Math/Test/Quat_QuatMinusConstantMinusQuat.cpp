//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatMinusConstantMinusQuat, TestConfig::ALL)
{
#if Quat_QuatMinusConstantMinusQuat

	Quat q1, q2;
	Quat out1, out2;

	// Quat - Constant - Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(3.0f, 10.0f, 5.0f, 20.0f);

	// out1 = q1 - 5.0f - q2 
	out1 = q1 - 5.0f - q2;

	CHECK((out1[x] == -7.0f));
	CHECK((out1[y] == -13.0f));
	CHECK((out1[z] == -7.0f));
	CHECK((out1[w] == -21.0f));

#endif
} TEST_END

// --- End of File ---