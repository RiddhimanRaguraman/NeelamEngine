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
#if Vec4_MultEqual_Mat4

bool Vec4_MultEqual_Mat4_REF_TEST(Vec4 &r)
{
	AZUL_UNUSED_VAR(r);
	return true;
}

#endif

TEST(Vec4_MultEqual_Mat4, TestConfig::ALL)
{
#if Vec4_MultEqual_Mat4

	Vec4 vA(2.0f, 3.0f, 4.0f, -2.0f);

	CHECK(vA[x] == 2.0f);
	CHECK(vA[y] == 3.0f);
	CHECK(vA[z] == 4.0f);
	CHECK(vA[w] == -2.0f);

	Vec4 V0(1.0f, 2.0f, 3.0f, 4.0f);
	Vec4 V1(7.0f, 6.0f, 5.0f, 3.0f);
	Vec4 V2(-4.0f, -2.0f, -1.0f, -4.0f);
	Vec4 V3(9.0f, -7.0f, -2.0f, 5.0f);

	Mat4 M(V0, V1, V2, V3);

	CHECK(M[m0] == 1.0f);
	CHECK(M[m1] == 2.0f);
	CHECK(M[m2] == 3.0f);
	CHECK(M[m3] == 4.0f);
	CHECK(M[m4] == 7.0f);
	CHECK(M[m5] == 6.0f);
	CHECK(M[m6] == 5.0f);
	CHECK(M[m7] == 3.0f);
	CHECK(M[m8] == -4.0f);
	CHECK(M[m9] == -2.0f);
	CHECK(M[m10] == -1.0f);
	CHECK(M[m11] == -4.0f);
	CHECK(M[m12] == 9.0f);
	CHECK(M[m13] == -7.0f);
	CHECK(M[m14] == -2.0f);
	CHECK(eq_float(M[m15],5.0f));

	//vA *= M;
	bool status = Vec4_MultEqual_Mat4_REF_TEST(vA *= M);
	CHECK(status == true)

	CHECK(M[m0] == 1.0f);
	CHECK(M[m1] == 2.0f);
	CHECK(M[m2] == 3.0f);
	CHECK(M[m3] == 4.0f);
	CHECK(M[m4] == 7.0f);
	CHECK(M[m5] == 6.0f);
	CHECK(M[m6] == 5.0f);
	CHECK(M[m7] == 3.0f);
	CHECK(M[m8] == -4.0f);
	CHECK(M[m9] == -2.0f);
	CHECK(M[m10] == -1.0f);
	CHECK(M[m11] == -4.0f);
	CHECK(M[m12] == 9.0f);
	CHECK(M[m13] == -7.0f);
	CHECK(M[m14] == -2.0f);
	CHECK(eq_float(M[m15], 5.0f));

	CHECK(eq_float(vA[x], -11.0f));
	CHECK(eq_float(vA[y],  28.0f));
	CHECK(eq_float(vA[z],  21.0f));
	CHECK(eq_float(vA[w],  -9.0f));

#endif
} TEST_END

// ---  End of File ---------------
