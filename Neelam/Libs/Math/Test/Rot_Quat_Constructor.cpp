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

TEST(Rot_Quat_Constructor, TestConfig::ALL)
{
#if Rot_Quat_Constructor

	// Axis and Angle Type Constructor:
	Vec3  v1(2.0f, 53.0f, 24.0f);
	Quat Qa(Axis::AxisAngle, v1, MATH_PI3);

	// Matrix to Quaternion
	Rot M2(Qa);


	Mat4 M3;
	Quat qtmp;

	M2.set(Axis::AxisAngle, v1, MATH_PI3);

	qtmp.set(M2);
	CHECK(eq_float(Qa[x], qtmp[x]));
	CHECK(eq_float(Qa[y], qtmp[y]));
	CHECK(eq_float(Qa[z], qtmp[z]));
	CHECK(eq_float(Qa[w], qtmp[w]));


	CHECK(eq_float(Qa[x], 0.017f));
	CHECK(eq_float(Qa[y], 0.455f));
	CHECK(eq_float(Qa[z], 0.206f));
	CHECK(eq_float(Qa[w], 0.866f));

	// Quaternion to Matrix
	M3.set(Qa);

	CHECK(eq_float(M2[m0], M3[m0]));
	CHECK(eq_float(M2[m1], M3[m1]));
	CHECK(eq_float(M2[m2], M3[m2]));
	CHECK(eq_float(M2[m3], M3[m3]));
	CHECK(eq_float(M2[m4], M3[m4]));
	CHECK(eq_float(M2[m5], M3[m5]));
	CHECK(eq_float(M2[m6], M3[m6]));
	CHECK(eq_float(M2[m7], M3[m7]));
	CHECK(eq_float(M2[m8], M3[m8]));
	CHECK(eq_float(M2[m9], M3[m9]));
	CHECK(eq_float(M2[m10], M3[m10]));
	CHECK(eq_float(M2[m11], M3[m11]));
	CHECK(eq_float(M2[m12], M3[m12]));
	CHECK(eq_float(M2[m13], M3[m13]));
	CHECK(eq_float(M2[m14], M3[m14]));
	CHECK(eq_float(M2[m15], M3[m15]));

	CHECK(eq_float(M2[m0],  0.500f));
	CHECK(eq_float(M2[m1],  0.372f));
	CHECK(eq_float(M2[m2], -0.781f));
	CHECK(eq_float(M2[m3],  0.000f));
	CHECK(eq_float(M2[m4], -0.341f));
	CHECK(eq_float(M2[m5],  0.914f));
	CHECK(eq_float(M2[m6],  0.217f));
	CHECK(eq_float(M2[m7],  0.000f));
	CHECK(eq_float(M2[m8],  0.795f));
	CHECK(eq_float(M2[m9],  0.157f));
	CHECK(eq_float(M2[m10], 0.584f));
	CHECK(eq_float(M2[m11], 0.000f));
	CHECK(eq_float(M2[m12], 0.000f));
	CHECK(eq_float(M2[m13], 0.000f));
	CHECK(eq_float(M2[m14], 0.000f));
	CHECK(eq_float(M2[m15], 1.000f));


#endif
} TEST_END

// --- End of File ---
