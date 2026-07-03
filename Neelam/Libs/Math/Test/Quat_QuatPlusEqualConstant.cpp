//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatPlusEqualConstant, TestConfig::ALL)
{
#if Quat_QuatPlusEqualConstant

	Quat q1;
	Quat out1;

	// Quat += Const
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => q1 += 10.0f 
	q1 += 10.0f;

	CHECK(q1[x] == 11.0f);
	CHECK(q1[y] == 12.0f);
	CHECK(q1[z] == 13.0f);
	CHECK(q1[w] == 14.0f);

#endif
} TEST_END

// --- End of File ---
