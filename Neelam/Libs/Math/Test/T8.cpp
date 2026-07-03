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

TEST(Quat_Times_Scale, TestConfig::ALL)
{
#if Quat_Times_Scale

	Quat Q1(Rot3::ZXY, MATH_PI3, -MATH_2PI8, MATH_2PI3);

	CHECK(eq_float(Q1[x], -0.0560f));
	CHECK(eq_float(Q1[y], -0.5657f));
	CHECK(eq_float(Q1[z], 0.7885f));
	CHECK(eq_float(Q1[w], 0.2343f));

	Scale S(3, 4, 5);

	CHECK(S[m0] == 3.0f);
	CHECK(S[m1] == 0.0f);
	CHECK(S[m2] == 0.0f);
	CHECK(S[m3] == 0.0f);
	CHECK(S[m4] == 0.0f);
	CHECK(S[m5] == 4.0f);
	CHECK(S[m6] == 0.0f);
	CHECK(S[m7] == 0.0f);
	CHECK(S[m8] == 0.0f);
	CHECK(S[m9] == 0.0f);
	CHECK(S[m10] == 5.0f);
	CHECK(S[m11] == 0.0f);
	CHECK(S[m12] == 0.0f);
	CHECK(S[m13] == 0.0f);
	CHECK(S[m14] == 0.0f);
	CHECK(eq_float(S[m15], 1.0f));

	Mat4 C;
	C = Q1 * S;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	CHECK(eq_float(Q1[x], -0.0560f));
	CHECK(eq_float(Q1[y], -0.5657f));
	CHECK(eq_float(Q1[z], 0.7885f));
	CHECK(eq_float(Q1[w], 0.2343f));

	CHECK(S[m0] == 3.0f);
	CHECK(S[m1] == 0.0f);
	CHECK(S[m2] == 0.0f);
	CHECK(S[m3] == 0.0f);
	CHECK(S[m4] == 0.0f);
	CHECK(S[m5] == 4.0f);
	CHECK(S[m6] == 0.0f);
	CHECK(S[m7] == 0.0f);
	CHECK(S[m8] == 0.0f);
	CHECK(S[m9] == 0.0f);
	CHECK(S[m10] == 5.0f);
	CHECK(S[m11] == 0.0f);
	CHECK(S[m12] == 0.0f);
	CHECK(S[m13] == 0.0f);
	CHECK(S[m14] == 0.0f);
	CHECK(eq_float(S[m15], 1.0f));

	CHECK(eq_float(C[m0], -2.6516f));
	CHECK(eq_float(C[m1], 1.7320f));
	CHECK(eq_float(C[m2], 0.8838f));
	CHECK((C[m3] == 0.0f));
	CHECK(eq_float(C[m4], -0.9185f));
	CHECK(eq_float(C[m5], -1.0000f));
	CHECK(eq_float(C[m6], -4.5927f));
	CHECK((C[m7] == 0.0f));
	CHECK(eq_float(C[m8], -1.0606f));
	CHECK(eq_float(C[m9], -3.4641f));
	CHECK(eq_float(C[m10], 1.7677f));
	CHECK((C[m11] == 0.0f));
	CHECK(C[m12] == 0.0f);
	CHECK(C[m13] == 0.0f);
	CHECK(C[m14] == 0.0f);
	CHECK(eq_float(C[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
