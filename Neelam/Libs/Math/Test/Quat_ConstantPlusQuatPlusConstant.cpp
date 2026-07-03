//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;


//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_ConstantPlusQuatPlusConstant, TestConfig::ALL)
{
#if Quat_ConstantPlusQuatPlusConstant

	Quat q1;
	Quat out1;

	// Constant + Quat + Constant
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => out1 = 10.0f + q1 + 5.0f 
	out1 = 10.0f + q1 + 5.0f;

	CHECK((out1[x] == 16.0f));
	CHECK((out1[y] == 17.0f));
	CHECK((out1[z] == 18.0f));
	CHECK((out1[w] == 19.0f));

	CHECK(q1[x] == 1.0f);
	CHECK(q1[y] == 2.0f);
	CHECK(q1[z] == 3.0f);
	CHECK(q1[w] == 4.0f);

#endif
} TEST_END

// --- End of File ---
