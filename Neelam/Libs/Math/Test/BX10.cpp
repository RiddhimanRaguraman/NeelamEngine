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

TEST(BX10_Hint_R_S, TestConfig::ALL)
{
#if BX10_Hint_R_S
	Mat4 M;
	Rot A(Rot1::Z, 0.12f);
	Scale B(2,3,4);

	M = A * B;

	Mat4Hint::Hint h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);


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

	CHECK(eq_float(B[m0], 2.000f));
	CHECK(eq_float(B[m1], 0.000f));
	CHECK(eq_float(B[m2], 0.000f));
	CHECK(eq_float(B[m3], 0.000f));
	CHECK(eq_float(B[m4], 0.000f));
	CHECK(eq_float(B[m5], 3.000f));
	CHECK(eq_float(B[m6], 0.000f));
	CHECK(eq_float(B[m7], 0.000f));
	CHECK(eq_float(B[m8], 0.000f));
	CHECK(eq_float(B[m9], 0.000f));
	CHECK(eq_float(B[m10], 4.000f));
	CHECK(eq_float(B[m11], 0.000f));
	CHECK(eq_float(B[m12], 0.000f));
	CHECK(eq_float(B[m13], 0.000f));
	CHECK(eq_float(B[m14], 0.000f));
	CHECK(eq_float(B[m15], 1.000f));

	CHECK(eq_float(M[m0], 1.986f));
	CHECK(eq_float(M[m1], 0.359f));
	CHECK(eq_float(M[m2], 0.000f));
	CHECK(eq_float(M[m3], 0.000f));
	CHECK(eq_float(M[m4], -0.239f));
	CHECK(eq_float(M[m5], 2.978f));
	CHECK(eq_float(M[m6], 0.000f));
	CHECK(eq_float(M[m7], 0.000f));
	CHECK(eq_float(M[m8], 0.000f));
	CHECK(eq_float(M[m9], 0.000f));
	CHECK(eq_float(M[m10], 4.000f));
	CHECK(eq_float(M[m11], 0.000f));
	CHECK(eq_float(M[m12], 0.000f));
	CHECK(eq_float(M[m13], 0.000f));
	CHECK(eq_float(M[m14], 0.000f));
	CHECK(eq_float(M[m15], 1.000f));

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

#endif
} TEST_END

// ---  End of File ---------------
