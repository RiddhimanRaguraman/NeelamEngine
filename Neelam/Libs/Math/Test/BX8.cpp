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

TEST(BX8_Hint_S_T, TestConfig::ALL)
{
#if BX8_Hint_S_T
	Mat4 M;
	Scale A(14, 15, 16);
	Trans B(2, 3, 4);

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::TransScale);


	CHECK(eq_float(A[m0], 14.000f));
	CHECK(eq_float(A[m1], 0.000f));
	CHECK(eq_float(A[m2], 0.000f));
	CHECK(eq_float(A[m3], 0.000f));
	CHECK(eq_float(A[m4], 0.000f));
	CHECK(eq_float(A[m5], 15.000f));
	CHECK(eq_float(A[m6], 0.000f));
	CHECK(eq_float(A[m7], 0.000f));
	CHECK(eq_float(A[m8], 0.000f));
	CHECK(eq_float(A[m9], 0.000f));
	CHECK(eq_float(A[m10], 16.000f));
	CHECK(eq_float(A[m11], 0.000f));
	CHECK(eq_float(A[m12], 0.000f));
	CHECK(eq_float(A[m13], 0.000f));
	CHECK(eq_float(A[m14], 0.000f));
	CHECK(eq_float(A[m15], 1.000f));

	CHECK(eq_float(B[m0], 1.000f));
	CHECK(eq_float(B[m1], 0.000f));
	CHECK(eq_float(B[m2], 0.000f));
	CHECK(eq_float(B[m3], 0.000f));
	CHECK(eq_float(B[m4], 0.000f));
	CHECK(eq_float(B[m5], 1.000f));
	CHECK(eq_float(B[m6], 0.000f));
	CHECK(eq_float(B[m7], 0.000f));
	CHECK(eq_float(B[m8], 0.000f));
	CHECK(eq_float(B[m9], 0.000f));
	CHECK(eq_float(B[m10], 1.000f));
	CHECK(eq_float(B[m11], 0.000f));
	CHECK(eq_float(B[m12], 2.000f));
	CHECK(eq_float(B[m13], 3.000f));
	CHECK(eq_float(B[m14], 4.000f));
	CHECK(eq_float(B[m15], 1.000f));

	CHECK(eq_float(M[m0], 14.000f));
	CHECK(eq_float(M[m1], 0.000f));
	CHECK(eq_float(M[m2], 0.000f));
	CHECK(eq_float(M[m3], 0.000f));
	CHECK(eq_float(M[m4], 0.000f));
	CHECK(eq_float(M[m5], 15.000f));
	CHECK(eq_float(M[m6], 0.000f));
	CHECK(eq_float(M[m7], 0.000f));
	CHECK(eq_float(M[m8], 0.000f));
	CHECK(eq_float(M[m9], 0.000f));
	CHECK(eq_float(M[m10], 16.000f));
	CHECK(eq_float(M[m11], 0.000f));
	CHECK(eq_float(M[m12], 2.000f));
	CHECK(eq_float(M[m13], 3.000f));
	CHECK(eq_float(M[m14], 4.000f));
	CHECK(eq_float(M[m15], 1.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::TransScale);

#endif
} TEST_END

// ---  End of File ---------------
