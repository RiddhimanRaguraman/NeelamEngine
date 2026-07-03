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

TEST(BX2_Hint_M_S, TestConfig::ALL)
{
#if BX2_Hint_M_S
	Mat4 M;
	Mat4 A(Vec4(1, 2, 3, 4), Vec4(5, 6, 7, 8), Vec4(9, 10, 11, 12), Vec4(13, 14, 15, 16));
	Scale B(1,2,3);

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	CHECK(eq_float(A[m0], 1.000f));
	CHECK(eq_float(A[m1], 2.000f));
	CHECK(eq_float(A[m2], 3.000f));
	CHECK(eq_float(A[m3], 4.000f));
	CHECK(eq_float(A[m4], 5.000f));
	CHECK(eq_float(A[m5], 6.000f));
	CHECK(eq_float(A[m6], 7.000f));
	CHECK(eq_float(A[m7], 8.000f));
	CHECK(eq_float(A[m8], 9.000f));
	CHECK(eq_float(A[m9], 10.000f));
	CHECK(eq_float(A[m10], 11.000f));
	CHECK(eq_float(A[m11], 12.000f));
	CHECK(eq_float(A[m12], 13.000f));
	CHECK(eq_float(A[m13], 14.000f));
	CHECK(eq_float(A[m14], 15.000f));
	CHECK(eq_float(A[m15], 16.000f));

	CHECK(eq_float(B[m0], 1.000f));
	CHECK(eq_float(B[m1], 0.000f));
	CHECK(eq_float(B[m2], 0.000f));
	CHECK(eq_float(B[m3], 0.000f));
	CHECK(eq_float(B[m4], 0.000f));
	CHECK(eq_float(B[m5], 2.000f));
	CHECK(eq_float(B[m6], 0.000f));
	CHECK(eq_float(B[m7], 0.000f));
	CHECK(eq_float(B[m8], 0.000f));
	CHECK(eq_float(B[m9], 0.000f));
	CHECK(eq_float(B[m10], 3.000f));
	CHECK(eq_float(B[m11], 0.000f));
	CHECK(eq_float(B[m12], 0.000f));
	CHECK(eq_float(B[m13], 0.000f));
	CHECK(eq_float(B[m14], 0.000f));
	CHECK(eq_float(B[m15], 1.000f));

	CHECK(eq_float(M[m0], 1.000f));
	CHECK(eq_float(M[m1], 4.000f));
	CHECK(eq_float(M[m2], 9.000f));
	CHECK(eq_float(M[m3], 4.000f));
	CHECK(eq_float(M[m4], 5.000f));
	CHECK(eq_float(M[m5], 12.000f));
	CHECK(eq_float(M[m6], 21.000f));
	CHECK(eq_float(M[m7], 8.000f));
	CHECK(eq_float(M[m8], 9.000f));
	CHECK(eq_float(M[m9], 20.000f));
	CHECK(eq_float(M[m10], 33.000f));
	CHECK(eq_float(M[m11], 12.000f));
	CHECK(eq_float(M[m12], 13.000f));
	CHECK(eq_float(M[m13], 28.000f));
	CHECK(eq_float(M[m14], 45.000f));
	CHECK(eq_float(M[m15], 16.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
