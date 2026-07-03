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

TEST(Mat4_TimesEqual_Trans, TestConfig::ALL)
{
#if Mat4_TimesEqual_Trans

	Vec4 v0(1.0f, 2.0f, 3.0f, 4.0f);
	Vec4 v1(5.0f, 6.0f, 7.0f, 8.0f);
	Vec4 v2(9.0f, 10.0f, 11.0f, 12.0f);
	Vec4 v3(13.0f, 14.0f, 15.0f, 16.0f);
	Vec4 v4(10.0f, 20.0f, 30.0f, 40.0f);
	Vec4 v5(50.0f, 60.0f, 70.0f, 80.0f);
	Vec4 v6(90.0f, 100.0f, 110.0f, 120.0f);
	Vec4 v7(130.0f, 140.0f, 150.0f, 160.0f);

	Mat4 A(v0, v1, v2, v3);

	CHECK((A[m0] == 1.0f));
	CHECK((A[m1] == 2.0f));
	CHECK((A[m2] == 3.0f));
	CHECK((A[m3] == 4.0f));
	CHECK((A[m4] == 5.0f));
	CHECK((A[m5] == 6.0f));
	CHECK((A[m6] == 7.0f));
	CHECK((A[m7] == 8.0f));
	CHECK((A[m8] == 9.0f));
	CHECK((A[m9] == 10.0f));
	CHECK((A[m10] == 11.0f));
	CHECK((A[m11] == 12.0f));
	CHECK((A[m12] == 13.0f));
	CHECK((A[m13] == 14.0f));
	CHECK((A[m14] == 15.0f));
	CHECK(eq_float(A[m15], 16.0f));

	Trans T(3, 4, 5);

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(T[m12] == 3.0f);
	CHECK(T[m13] == 4.0f);
	CHECK(T[m14] == 5.0f);
	CHECK(eq_float(T[m15], 1.0f));

	A *= T;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(T[m12] == 3.0f);
	CHECK(T[m13] == 4.0f);
	CHECK(T[m14] == 5.0f);
	CHECK(eq_float(T[m15], 1.0f));

	CHECK(eq_float(A[m0], 13.0f));
	CHECK(eq_float(A[m1], 18.0f));
	CHECK(eq_float(A[m2], 23.0f));
	CHECK(eq_float(A[m3], 4.0f));
	CHECK(eq_float(A[m4], 29.0f));
	CHECK(eq_float(A[m5], 38.0f));
	CHECK(eq_float(A[m6], 47.0f));
	CHECK(eq_float(A[m7], 8.0f));
	CHECK(eq_float(A[m8], 45.0f));
	CHECK(eq_float(A[m9], 58.0f));
	CHECK(eq_float(A[m10], 71.0f));
	CHECK(eq_float(A[m11], 12.0f));
	CHECK(eq_float(A[m12], 61.0f));
	CHECK(eq_float(A[m13], 78.0f));
	CHECK(eq_float(A[m14], 95.0f));
	CHECK(eq_float(A[m15], 16.0f));

#endif
} TEST_END

// ---  End of File ---------------
