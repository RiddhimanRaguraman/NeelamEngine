//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_ConstantMinusQuatMinusConstant, TestConfig::ALL)
{
#if Quat_ConstantMinusQuatMinusConstant

	Quat q1, q2;
	Quat out1, out2;
	// Constant - Quat - Constant
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => out1 = 10.0f - q1 - 5.0f
	out1 = 10.0f - q1 - 5.0f;

	CHECK((out1[x] == 4.0f));
	CHECK((out1[y] == 3.0f));
	CHECK((out1[z] == 2.0f));
	CHECK((out1[w] == 1.0f));

#endif
} TEST_END

// --- End of File ---