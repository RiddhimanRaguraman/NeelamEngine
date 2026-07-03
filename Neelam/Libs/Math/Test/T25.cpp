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

TEST(Mat4_TimesEqual_Rot, TestConfig::ALL)
{
#if Mat4_TimesEqual_Rot

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

	Rot R2(Rot3::YXZ, -MATH_PI3, MATH_PI8, MATH_3PI4);

	CHECK(eq_float(R2[m0], -0.4189f));
	CHECK(eq_float(R2[m1], 0.8876f));
	CHECK(eq_float(R2[m2], -0.1913f));
	CHECK((R2[m3] == 0.0f));
	CHECK(eq_float(R2[m4], -0.35355f));
	CHECK(eq_float(R2[m5], -0.35355f));
	CHECK(eq_float(R2[m6], -0.86602f));
	CHECK((R2[m7] == 0.0f));
	CHECK(eq_float(R2[m8], -0.8363f));
	CHECK(eq_float(R2[m9], -0.2951f));
	CHECK(eq_float(R2[m10], 0.4619f));
	CHECK((R2[m11] == 0.0f));
	CHECK((R2[m12] == 0.0f));
	CHECK((R2[m13] == 0.0f));
	CHECK((R2[m14] == 0.0f));
	CHECK(eq_float(R2[m15], 1.0f));

	A *= R2;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	CHECK(eq_float(R2[m0], -0.4189f));
	CHECK(eq_float(R2[m1], 0.8876f));
	CHECK(eq_float(R2[m2], -0.1913f));
	CHECK((R2[m3] == 0.0f));
	CHECK(eq_float(R2[m4], -0.35355f));
	CHECK(eq_float(R2[m5], -0.35355f));
	CHECK(eq_float(R2[m6], -0.86602f));
	CHECK((R2[m7] == 0.0f));
	CHECK(eq_float(R2[m8], -0.8363f));
	CHECK(eq_float(R2[m9], -0.2951f));
	CHECK(eq_float(R2[m10], 0.4619f));
	CHECK((R2[m11] == 0.0f));
	CHECK((R2[m12] == 0.0f));
	CHECK((R2[m13] == 0.0f));
	CHECK((R2[m14] == 0.0f));
	CHECK(eq_float(R2[m15], 1.0f));

	CHECK(eq_float(A[m0], -3.6351f));
	CHECK(eq_float(A[m1], -0.7049f));
	CHECK(eq_float(A[m2], -0.5375f));
	CHECK(eq_float(A[m3], 4.0000f));
	CHECK(eq_float(A[m4], -10.0704f));
	CHECK(eq_float(A[m5], 0.2506f));
	CHECK(eq_float(A[m6], -2.9192f));
	CHECK(eq_float(A[m7], 8.0000f));
	CHECK(eq_float(A[m8], -16.5058f));
	CHECK(eq_float(A[m9], 1.2063f));
	CHECK(eq_float(A[m10], -5.3009f));
	CHECK(eq_float(A[m11], 12.0000f));
	CHECK(eq_float(A[m12], -22.9412f));
	CHECK(eq_float(A[m13], 2.1619f));
	CHECK(eq_float(A[m14], -7.6827f));
	CHECK(eq_float(A[m15], 16.0000f));

#endif
} TEST_END

// ---  End of File ---------------
