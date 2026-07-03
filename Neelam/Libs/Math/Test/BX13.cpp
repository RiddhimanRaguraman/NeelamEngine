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

TEST(BX13_Hint_T_M, TestConfig::ALL)
{
#if BX13_Hint_T_M
	Mat4 M;
	Trans A(2,3,4);
	Mat4 B(Vec4(21, 22, 23, 24), Vec4(25, 26, 27, 28), Vec4(29, 20, 21, 22), Vec4(23, 24, 25, 26));

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

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

	CHECK(eq_float(B[m0], 21.000f));
	CHECK(eq_float(B[m1], 22.000f));
	CHECK(eq_float(B[m2], 23.000f));
	CHECK(eq_float(B[m3], 24.000f));
	CHECK(eq_float(B[m4], 25.000f));
	CHECK(eq_float(B[m5], 26.000f));
	CHECK(eq_float(B[m6], 27.000f));
	CHECK(eq_float(B[m7], 28.000f));
	CHECK(eq_float(B[m8], 29.000f));
	CHECK(eq_float(B[m9], 20.000f));
	CHECK(eq_float(B[m10], 21.000f));
	CHECK(eq_float(B[m11], 22.000f));
	CHECK(eq_float(B[m12], 23.000f));
	CHECK(eq_float(B[m13], 24.000f));
	CHECK(eq_float(B[m14], 25.000f));
	CHECK(eq_float(B[m15], 26.000f));

	CHECK(eq_float(M[m0], 21.000f));
	CHECK(eq_float(M[m1], 22.000f));
	CHECK(eq_float(M[m2], 23.000f));
	CHECK(eq_float(M[m3], 24.000f));
	CHECK(eq_float(M[m4], 25.000f));
	CHECK(eq_float(M[m5], 26.000f));
	CHECK(eq_float(M[m6], 27.000f));
	CHECK(eq_float(M[m7], 28.000f));
	CHECK(eq_float(M[m8], 29.000f));
	CHECK(eq_float(M[m9], 20.000f));
	CHECK(eq_float(M[m10], 21.000f));
	CHECK(eq_float(M[m11], 22.000f));
	CHECK(eq_float(M[m12], 256.000f));
	CHECK(eq_float(M[m13], 226.000f));
	CHECK(eq_float(M[m14], 236.000f));
	CHECK(eq_float(M[m15], 246.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	
#endif
} TEST_END

// ---  End of File ---------------
