//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatPlusConstPlusQuat, TestConfig::ALL)
{
#if Quat_QuatPlusConstPlusQuat

	Quat q1, q2;
	Quat out1;

	// Quat + Constant + Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(3.0f, 10.0f, 5.0f, 20.0f);

	// => out1 = q1 + 5.0f + q2 
	out1 = q1 + 5.0f + q2;

	CHECK((out1[x] == 9.0f));
	CHECK((out1[y] == 17.0f));
	CHECK((out1[z] == 13.0f));
	CHECK((out1[w] == 29.0f));

	CHECK(q1[x] == 1.0f);
	CHECK(q1[y] == 2.0f);
	CHECK(q1[z] == 3.0f);
	CHECK(q1[w] == 4.0f);

	CHECK(q2[x] == 3.0f);
	CHECK(q2[y] == 10.0f);
	CHECK(q2[z] == 5.0f);
	CHECK(q2[w] == 20.0f);

#endif
} TEST_END

// --- End of File ---
