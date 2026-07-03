//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatPlusQuat, TestConfig::ALL)
{
#if Quat_QuatPlusQuat

	Quat q1, q2;
	Quat out1;

	// Quat + Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q2.set(3.0f, 10.0f, 5.0f, 20.0f);

	// => out1 = q1 + q2 
	out1 = q1 + q2;

	CHECK((out1[x] == 4.0f));
	CHECK((out1[y] == 12.0f));
	CHECK((out1[z] == 8.0f));
	CHECK((out1[w] == 24.0f));

	CHECK((q1[x] == 1.0f));
	CHECK((q1[y] == 2.0f));
	CHECK((q1[z] == 3.0f));
	CHECK((q1[w] == 4.0f));

	CHECK((q2[x] == 3.0f));
	CHECK((q2[y] == 10.0f));
	CHECK((q2[z] == 5.0f));
	CHECK((q2[w] == 20.0f));

#endif
} TEST_END

// --- End of File ---
