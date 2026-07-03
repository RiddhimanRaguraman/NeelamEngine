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

TEST(Mat4_UnaryMinus, TestConfig::ALL)
{
#if Mat4_UnaryMinus

	Vec4 V0(30.0f, 29.0f, 28.0f, 27.0f);
	Vec4 V1(26.0f, 25.0f, 24.0f, 23.0f);
	Vec4 V2(22.0f, 21.0f, 20.0f, 19.0f);
	Vec4 V3(18.0f, 17.0f, 16.0f, 15.0f);

	Mat4 A(V0, V1, V2, V3);

	CHECK(A[m0] == 30.0f);
	CHECK(A[m1] == 29.0f);
	CHECK(A[m2] == 28.0f);
	CHECK(A[m3] == 27.0f);
	CHECK(A[m4] == 26.0f);
	CHECK(A[m5] == 25.0f);
	CHECK(A[m6] == 24.0f);
	CHECK(A[m7] == 23.0f);
	CHECK(A[m8] == 22.0f);
	CHECK(A[m9] == 21.0f);
	CHECK(A[m10] == 20.0f);
	CHECK(A[m11] == 19.0f);
	CHECK(A[m12] == 18.0f);
	CHECK(A[m13] == 17.0f);
	CHECK(A[m14] == 16.0f);
	CHECK(eq_float(A[m15],15.0f));

	-A;

	CHECK(A[m0] == 30.0f);
	CHECK(A[m1] == 29.0f);
	CHECK(A[m2] == 28.0f);
	CHECK(A[m3] == 27.0f);
	CHECK(A[m4] == 26.0f);
	CHECK(A[m5] == 25.0f);
	CHECK(A[m6] == 24.0f);
	CHECK(A[m7] == 23.0f);
	CHECK(A[m8] == 22.0f);
	CHECK(A[m9] == 21.0f);
	CHECK(A[m10] == 20.0f);
	CHECK(A[m11] == 19.0f);
	CHECK(A[m12] == 18.0f);
	CHECK(A[m13] == 17.0f);
	CHECK(A[m14] == 16.0f);
	CHECK(eq_float(A[m15], 15.0f));

	Mat4 M;
	M = -A;

	CHECK(M[m0] == -30.0f);
	CHECK(M[m1] == -29.0f);
	CHECK(M[m2] == -28.0f);
	CHECK(M[m3] == -27.0f);
	CHECK(M[m4] == -26.0f);
	CHECK(M[m5] == -25.0f);
	CHECK(M[m6] == -24.0f);
	CHECK(M[m7] == -23.0f);
	CHECK(M[m8] == -22.0f);
	CHECK(M[m9] == -21.0f);
	CHECK(M[m10] == -20.0f);
	CHECK(M[m11] == -19.0f);
	CHECK(M[m12] == -18.0f);
	CHECK(M[m13] == -17.0f);
	CHECK(M[m14] == -16.0f);
	CHECK(eq_float(M[m15], -15.0f));

#endif
} TEST_END

// ---  End of File ---
