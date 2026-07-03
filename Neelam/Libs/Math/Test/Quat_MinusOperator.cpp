//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_MinusOperator, TestConfig::ALL)
{
#if Quat_MinusOperator

	Quat q1, q2;
	Quat out1, out2;

	// -Quat
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	//=> out1 = -q1 
	out1 = -q1;
	CHECK((out1[x] == -1.0f));
	CHECK((out1[y] == -2.0f));
	CHECK((out1[z] == -3.0f));
	CHECK((out1[w] == -4.0f));

#endif
} TEST_END

// --- End of File ---

