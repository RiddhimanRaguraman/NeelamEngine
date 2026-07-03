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

TEST(BX9_Hint_R_M, TestConfig::ALL)
{
#if BX9_Hint_R_M
	Mat4 M;
	Rot A(Rot1::Z,0.12f);
	Mat4 B(Vec4(21, 22, 23, 24), Vec4(25, 26, 27, 28), Vec4(29, 20, 21, 22), Vec4(23, 24, 25, 26));

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);


	CHECK(eq_float(A[m0], 0.993f));
	CHECK(eq_float(A[m1], 0.120f));
	CHECK(eq_float(A[m2], 0.000f));
	CHECK(eq_float(A[m3], 0.000f));
	CHECK(eq_float(A[m4], -0.120f));
	CHECK(eq_float(A[m5], 0.993f));
	CHECK(eq_float(A[m6], 0.000f));
	CHECK(eq_float(A[m7], 0.000f));
	CHECK(eq_float(A[m8], 0.000f));
	CHECK(eq_float(A[m9], 0.000f));
	CHECK(eq_float(A[m10], 1.000f));
	CHECK(eq_float(A[m11], 0.000f));
	CHECK(eq_float(A[m12], 0.000f));
	CHECK(eq_float(A[m13], 0.000f));
	CHECK(eq_float(A[m14], 0.000f));
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

	CHECK(eq_float(M[m0], 23.842f));
	CHECK(eq_float(M[m1], 24.954f));
	CHECK(eq_float(M[m2], 26.067f));
	CHECK(eq_float(M[m3], 27.179f));
	CHECK(eq_float(M[m4], 22.306f));
	CHECK(eq_float(M[m5], 23.179f));
	CHECK(eq_float(M[m6], 24.052f));
	CHECK(eq_float(M[m7], 24.926f));
	CHECK(eq_float(M[m8], 29.000f));
	CHECK(eq_float(M[m9], 20.000f));
	CHECK(eq_float(M[m10], 21.000f));
	CHECK(eq_float(M[m11], 22.000f));
	CHECK(eq_float(M[m12], 23.000f));
	CHECK(eq_float(M[m13], 24.000f));
	CHECK(eq_float(M[m14], 25.000f));
	CHECK(eq_float(M[m15], 26.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
