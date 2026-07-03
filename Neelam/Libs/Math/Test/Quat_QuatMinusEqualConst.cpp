//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatMinusEqualConst, TestConfig::ALL)
{
#if Quat_QuatMinusEqualConst

	Quat q1;
	// Quat -= Const
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => q1 -= 10.0f 
	q1 -= 10.0f;

	CHECK((q1[x] == -9.0f));
	CHECK((q1[y] == -8.0f));
	CHECK((q1[z] == -7.0f));
	CHECK((q1[w] == -6.0f));

#endif
} TEST_END

// --- End of File ---