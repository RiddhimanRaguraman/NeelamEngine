//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_EqualOperator, TestConfig::ALL)
{
#if Quat_EqualOperator

	Quat q1, q2;
	Quat out1, out2;
	// Overload the = operator
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(9.0f, -3.0f, 5.0f, 7.0f);
	// => q1 = q2 \n"););
	q1 = q2;

	CHECK((q1[x] == q2[x]));
	CHECK((q1[y] == q2[y]));
	CHECK((q1[z] == q2[z]));
	CHECK((q1[w] == q2[w]));

	CHECK((9.0f == q2[x]));
	CHECK((-3.0f == q2[y]));
	CHECK((5.0f == q2[z]));
	CHECK((7.0f == q2[w]));

#endif
} TEST_END

// --- End of File ---
