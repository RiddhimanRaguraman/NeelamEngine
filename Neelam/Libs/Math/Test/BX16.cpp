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

TEST(BX16_Hint_T_T, TestConfig::ALL)
{
#if BX16_Hint_T_T
	Mat4 M;
	Trans A(2, 3, 4);
	Trans B(5,6,7);

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

	CHECK(eq_float(A[m0], 1.000f));
	CHECK(eq_float(A[m1], 0.000f));
	CHECK(eq_float(A[m2], 0.000f));
	CHECK(eq_float(A[m3], 0.000f));
	CHECK(eq_float(A[m4], 0.000f));
	CHECK(eq_float(A[m5], 1.000f));
	CHECK(eq_float(A[m6], 0.000f));
	CHECK(eq_float(A[m7], 0.000f));
	CHECK(eq_float(A[m8], 0.000f));
	CHECK(eq_float(A[m9], 0.000f));
	CHECK(eq_float(A[m10], 1.000f));
	CHECK(eq_float(A[m11], 0.000f));
	CHECK(eq_float(A[m12], 2.000f));
	CHECK(eq_float(A[m13], 3.000f));
	CHECK(eq_float(A[m14], 4.000f));
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
	CHECK(eq_float(B[m12], 5.000f));
	CHECK(eq_float(B[m13], 6.000f));
	CHECK(eq_float(B[m14], 7.000f));
	CHECK(eq_float(B[m15], 1.000f));

	CHECK(eq_float(M[m0], 1.000f));
	CHECK(eq_float(M[m1], 0.000f));
	CHECK(eq_float(M[m2], 0.000f));
	CHECK(eq_float(M[m3], 0.000f));
	CHECK(eq_float(M[m4], 0.000f));
	CHECK(eq_float(M[m5], 1.000f));
	CHECK(eq_float(M[m6], 0.000f));
	CHECK(eq_float(M[m7], 0.000f));
	CHECK(eq_float(M[m8], 0.000f));
	CHECK(eq_float(M[m9], 0.000f));
	CHECK(eq_float(M[m10], 1.000f));
	CHECK(eq_float(M[m11], 0.000f));
	CHECK(eq_float(M[m12], 7.000f));
	CHECK(eq_float(M[m13], 9.000f));
	CHECK(eq_float(M[m14], 11.000f));
	CHECK(eq_float(M[m15], 1.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

#endif
} TEST_END

// ---  End of File ---------------
