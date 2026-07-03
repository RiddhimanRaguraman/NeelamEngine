//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_ConstantMinusQuat, TestConfig::ALL)
{
#if Quat_ConstantMinusQuat

	Quat q1, q2;
	Quat out1, out2;

	// Constant - Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => out1 = 10.0f - q1 
	out1 = 10.0f - q1;

	CHECK((out1[x] == 9.0f));
	CHECK((out1[y] == 8.0f));
	CHECK((out1[z] == 7.0f));
	CHECK((out1[w] == 6.0f));

#endif
} TEST_END

// --- End of File ---
