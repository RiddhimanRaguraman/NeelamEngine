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

TEST(Rot_ZXY_Constructor, TestConfig::ALL)
{
#if Rot_ZXY_Constructor

	Rot Rx;
	Rot Ry;
	Rot Rz;

	// Rot_X Type Constructor:
	Rx.set(Rot1::X, MATH_PI3);

	CHECK(Rx[m0] == 1.0f);
	CHECK(Rx[m1] == 0.0f);
	CHECK(Rx[m2] == 0.0f);
	CHECK(Rx[m3] == 0.0f);
	CHECK(Rx[m4] == 0.0f);
	CHECK(eq_float(Rx[m5], 0.5f));
	CHECK(eq_float(Rx[m6], 0.866f));
	CHECK(Rx[m7] == 0.0f);
	CHECK(Rx[m8] == 0.0f);
	CHECK(eq_float(Rx[m9], -0.866f));
	CHECK(eq_float(Rx[m10], 0.5f));
	CHECK(Rx[m11] == 0.0f);
	CHECK(Rx[m12] == 0.0f);
	CHECK(Rx[m13] == 0.0f);
	CHECK(Rx[m14] == 0.0f);
	CHECK(eq_float(Rx[m15],1.0f));

	Ry.set(Rot1::Y, MATH_7PI8);

	CHECK(eq_float(Ry[m0], -0.9238f));
	CHECK(Ry[m1] == 0.0f);
	CHECK(eq_float(Ry[m2], -0.3826f));
	CHECK(Ry[m3] == 0.0f);
	CHECK(Ry[m4] == 0.0f);
	CHECK(Ry[m5] == 1.0f);
	CHECK(Ry[m6] == 0.0f);
	CHECK(Ry[m7] == 0.0f);
	CHECK(eq_float(Ry[m8], 0.3826f));
	CHECK(Ry[m9] == 0.0f);
	CHECK(eq_float(Ry[m10], -0.9238f));
	CHECK(Ry[m11] == 0.0f);
	CHECK(Ry[m12] == 0.0f);
	CHECK(Ry[m13] == 0.0f);
	CHECK(Ry[m14] == 0.0f);
	CHECK(eq_float(Ry[m15],1.0f));

	Rz.set(Rot1::Z, MATH_PI2);

	CHECK(eq_float(Rz[m0], 0.0f));
	CHECK(eq_float(Rz[m1], 1.0f));
	CHECK(Rz[m2] == 0.0f);
	CHECK(Rz[m3] == 0.0f);
	CHECK(eq_float(Rz[m4], -1.0f));
	CHECK(eq_float(Rz[m5], 0.0f));
	CHECK(Rz[m6] == 0.0f);
	CHECK(Rz[m7] == 0.0f);
	CHECK(Rz[m8] == 0.0f);
	CHECK(Rz[m9] == 0.0f);
	CHECK(Rz[m10] == 1.0f);
	CHECK(Rz[m11] == 0.0f);
	CHECK(Rz[m12] == 0.0f);
	CHECK(Rz[m13] == 0.0f);
	CHECK(Rz[m14] == 0.0f);
	CHECK(eq_float(Rz[m15],1.0f));

	Mat4 R;

	R = Rz * Rx * Ry;

	Rot mTmp(Rot3::ZXY, MATH_PI3, MATH_7PI8, MATH_PI2);

	CHECK(eq_float(R[m0], mTmp[m0]));
	CHECK(eq_float(R[m1], mTmp[m1]));
	CHECK(eq_float(R[m2], mTmp[m2]));
	CHECK(eq_float(R[m3], mTmp[m3]));
	CHECK(eq_float(R[m4], mTmp[m4]));
	CHECK(eq_float(R[m5], mTmp[m5]));
	CHECK(eq_float(R[m6], mTmp[m6]));
	CHECK(eq_float(R[m7], mTmp[m7]));
	CHECK(eq_float(R[m8], mTmp[m8]));
	CHECK(eq_float(R[m9], mTmp[m9]));
	CHECK(eq_float(R[m10], mTmp[m10]));
	CHECK(eq_float(R[m11], mTmp[m11]));
	CHECK(eq_float(R[m12], mTmp[m12]));
	CHECK(eq_float(R[m13], mTmp[m13]));
	CHECK(eq_float(R[m14], mTmp[m14]));
	CHECK(eq_float(R[m15], mTmp[m15]));

#endif
} TEST_END

// --- End of File ---
