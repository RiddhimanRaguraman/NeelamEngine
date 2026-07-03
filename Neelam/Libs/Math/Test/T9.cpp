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

TEST(Quat_Times_Rot, TestConfig::ALL)
{
#if Quat_Times_Rot

	Quat Q1(Rot3::ZXY, MATH_PI3, -MATH_2PI8, MATH_2PI3);

	CHECK(eq_float(Q1[x], -0.0560f));
	CHECK(eq_float(Q1[y], -0.5657f));
	CHECK(eq_float(Q1[z], 0.7885f));
	CHECK(eq_float(Q1[w], 0.2343f));

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

	Rot C;
	C = Q1 * R2;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	CHECK(eq_float(Q1[x], -0.0560f));
	CHECK(eq_float(Q1[y], -0.5657f));
	CHECK(eq_float(Q1[z], 0.7885f));
	CHECK(eq_float(Q1[w], 0.2343f));

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

	CHECK(eq_float(C[m0], 0.06934f));
	CHECK(eq_float(C[m1], -0.98982f));
	CHECK(eq_float(C[m2], -0.12421f));
	CHECK((C[m3] == 0.0f));
	CHECK(eq_float(C[m4], 0.9849f));
	CHECK(eq_float(C[m5], 0.0877f));
	CHECK(eq_float(C[m6], -0.1492f));
	CHECK((C[m7] == 0.0f));
	CHECK(eq_float(C[m8], 0.1586f));
	CHECK(eq_float(C[m9], -0.1119f));
	CHECK(eq_float(C[m10], 0.9809f));
	CHECK((C[m11] == 0.0f));
	CHECK((C[m12] == 0.0f));
	CHECK((C[m13] == 0.0f));
	CHECK((C[m14] == 0.0f));
	CHECK(eq_float(C[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
