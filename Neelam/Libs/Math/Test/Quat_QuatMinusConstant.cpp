//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatMinusConstant, TestConfig::ALL)
{
#if Quat_QuatMinusConstant

	Quat q1;
	Quat out1;

	// Quat - Constant
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	//=> out1 = q1 - 5.0f 
	out1 = q1 - 5.0f;

	CHECK(out1[x] == -4.0f);
	CHECK(out1[y] == -3.0f);
	CHECK(out1[z] == -2.0f);
	CHECK(out1[w] == -1.0f);

	CHECK(q1[x] == 1.0f);
	CHECK(q1[y] == 2.0f);
	CHECK(q1[z] == 3.0f);
	CHECK(q1[w] == 4.0f);

#endif
} TEST_END

// --- End of File ---