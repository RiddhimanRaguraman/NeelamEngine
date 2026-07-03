//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Trans_Constructor, TestConfig::ALL)
{
#if Trans_Constructor

	Trans A(2.0f, 3.0f, 4.0f);

	CHECK(A[m0] == 1.0f);
	CHECK(A[m1] == 0.0f);
	CHECK(A[m2] == 0.0f);
	CHECK(A[m3] == 0.0f);
	CHECK(A[m4] == 0.0f);
	CHECK(A[m5] == 1.0f);
	CHECK(A[m6] == 0.0f);
	CHECK(A[m7] == 0.0f);
	CHECK(A[m8] == 0.0f);
	CHECK(A[m9] == 0.0f);
	CHECK(A[m10] == 1.0f);
	CHECK(A[m11] == 0.0f);
	CHECK(A[m12] == 2.0f);
	CHECK(A[m13] == 3.0f);
	CHECK(A[m14] == 4.0f);
	CHECK(eq_float(A[m15],1.0f));

#endif
} TEST_END

// --- End of File ---
