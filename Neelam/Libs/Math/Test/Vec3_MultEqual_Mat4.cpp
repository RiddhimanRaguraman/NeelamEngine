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
#if Vec3_MultEqual_Mat4

bool Vec3_MultEqual_Mat4_REF_TEST(Vec4 &r,Vec4 &vOut)
{
	vOut = r;
	return true;
}

#endif

TEST(Vec3_MultEqual_Mat4, TestConfig::ALL)
{
#if Vec3_MultEqual_Mat4
	Vec3 vA(2.0f, 3.0f, 4.0f);

	CHECK(vA[x] == 2.0f);
	CHECK(vA[y] == 3.0f);
	CHECK(vA[z] == 4.0f);

	Vec4 V0(1.0f, 2.0f, 3.0f,0.0f);
	Vec4 V1(7.0f, 6.0f, 5.0f,0.0f);
	Vec4 V2(-4.0f, -2.0f, -1.0f,0.0f);
	Vec4 V3(0, 0, 0, 1);

	Mat4 M(V0, V1, V2,V3);

	CHECK(M[m0] == 1.0f);
	CHECK(M[m1] == 2.0f);
	CHECK(M[m2] == 3.0f);
	CHECK(M[m3] == 0.0f);
	CHECK(M[m4] == 7.0f);
	CHECK(M[m5] == 6.0f);
	CHECK(M[m6] == 5.0f);
	CHECK(M[m7] == 0.0f);
	CHECK(M[m8] == -4.0f);
	CHECK(M[m9] == -2.0f);
	CHECK(M[m10] == -1.0f);
	CHECK(M[m11] == 0.0f);
	CHECK(M[m12] == 0.0f);
	CHECK(M[m13] == 0.0f);
	CHECK(M[m14] == 0.0f);
	CHECK(eq_float(M[m15], 1.0f));

	//vA *= M;
	Vec4 vOut;
	bool status = Vec3_MultEqual_Mat4_REF_TEST(Vec4(vA,1) *= M, vOut);
	CHECK(status == true);

	CHECK(M[m0] == 1.0f);
	CHECK(M[m1] == 2.0f);
	CHECK(M[m2] == 3.0f);
	CHECK(M[m3] == 0.0f);
	CHECK(M[m4] == 7.0f);
	CHECK(M[m5] == 6.0f);
	CHECK(M[m6] == 5.0f);
	CHECK(M[m7] == 0.0f);
	CHECK(M[m8] == -4.0f);
	CHECK(M[m9] == -2.0f);
	CHECK(M[m10] == -1.0f);
	CHECK(M[m11] == 0.0f);
	CHECK(M[m12] == 0.0f);
	CHECK(M[m13] == 0.0f);
	CHECK(M[m14] == 0.0f);
	CHECK(eq_float(M[m15], 1.0f));

	// cannot check vA externally since its expiring rvalue
	CHECK(eq_float(vOut[x], 7.0f));
	CHECK(eq_float(vOut[y], 14.0f));
	CHECK(eq_float(vOut[z], 17.0f));
	CHECK(eq_float(vOut[w], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
