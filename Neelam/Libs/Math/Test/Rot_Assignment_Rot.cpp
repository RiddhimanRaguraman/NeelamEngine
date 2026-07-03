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

#if Rot_Assignment_Rot
bool Rot_Assignment_Rot_REF_TEST(Rot &r)
{
	AZUL_UNUSED_VAR(r);
	return true;
}
#endif

TEST(Rot_Assignment_Rot, TestConfig::ALL)
{
#if Rot_Assignment_Rot

	// Axis and Angle Type Constructor:
	Vec3  v1(2.0f, 53.0f, 24.0f);
	Rot Ra(Axis::AxisAngle, v1, MATH_PI3);

	CHECK(eq_float(Ra[m0], 0.500f));
	CHECK(eq_float(Ra[m1], 0.372f));
	CHECK(eq_float(Ra[m2], -0.781f));
	CHECK(eq_float(Ra[m3], 0.000f));
	CHECK(eq_float(Ra[m4], -0.341f));
	CHECK(eq_float(Ra[m5], 0.914f));
	CHECK(eq_float(Ra[m6], 0.217f));
	CHECK(eq_float(Ra[m7], 0.000f));
	CHECK(eq_float(Ra[m8], 0.795f));
	CHECK(eq_float(Ra[m9], 0.157f));
	CHECK(eq_float(Ra[m10], 0.584f));
	CHECK(eq_float(Ra[m11], 0.000f));
	CHECK(eq_float(Ra[m12], 0.000f));
	CHECK(eq_float(Ra[m13], 0.000f));
	CHECK(eq_float(Ra[m14], 0.000f));
	CHECK(eq_float(Ra[m15], 1.000f));

	// Matrix to Quaternion
	Rot M2;

	CHECK(eq_float(M2[m0], 1.0f));
	CHECK(eq_float(M2[m1], 0.0f));
	CHECK(eq_float(M2[m2], 0.0f));
	CHECK(eq_float(M2[m3], 0.0f));
	CHECK(eq_float(M2[m4], 0.0f));
	CHECK(eq_float(M2[m5], 1.0f));
	CHECK(eq_float(M2[m6], 0.0f));
	CHECK(eq_float(M2[m7], 0.0f));
	CHECK(eq_float(M2[m8], 0.0f));
	CHECK(eq_float(M2[m9], 0.0f));
	CHECK(eq_float(M2[m10], 1.0f));
	CHECK(eq_float(M2[m11], 0.0f));
	CHECK(eq_float(M2[m12], 0.0f));
	CHECK(eq_float(M2[m13], 0.0f));
	CHECK(eq_float(M2[m14], 0.0f));
	CHECK(eq_float(M2[m15], 1.0f));

	//M2 = Qa;
	bool status = Rot_Assignment_Rot_REF_TEST(M2 = Ra);
	CHECK(status == true);


	CHECK(eq_float(M2[m0], Ra[m0]));
	CHECK(eq_float(M2[m1], Ra[m1]));
	CHECK(eq_float(M2[m2], Ra[m2]));
	CHECK(eq_float(M2[m3], Ra[m3]));
	CHECK(eq_float(M2[m4], Ra[m4]));
	CHECK(eq_float(M2[m5], Ra[m5]));
	CHECK(eq_float(M2[m6], Ra[m6]));
	CHECK(eq_float(M2[m7], Ra[m7]));
	CHECK(eq_float(M2[m8], Ra[m8]));
	CHECK(eq_float(M2[m9], Ra[m9]));
	CHECK(eq_float(M2[m10], Ra[m10]));
	CHECK(eq_float(M2[m11], Ra[m11]));
	CHECK(eq_float(M2[m12], Ra[m12]));
	CHECK(eq_float(M2[m13], Ra[m13]));
	CHECK(eq_float(M2[m14], Ra[m14]));
	CHECK(eq_float(M2[m15], Ra[m15]));

	CHECK(eq_float(M2[m0], 0.500f));
	CHECK(eq_float(M2[m1], 0.372f));
	CHECK(eq_float(M2[m2], -0.781f));
	CHECK(eq_float(M2[m3], 0.000f));
	CHECK(eq_float(M2[m4], -0.341f));
	CHECK(eq_float(M2[m5], 0.914f));
	CHECK(eq_float(M2[m6], 0.217f));
	CHECK(eq_float(M2[m7], 0.000f));
	CHECK(eq_float(M2[m8], 0.795f));
	CHECK(eq_float(M2[m9], 0.157f));
	CHECK(eq_float(M2[m10], 0.584f));
	CHECK(eq_float(M2[m11], 0.000f));
	CHECK(eq_float(M2[m12], 0.000f));
	CHECK(eq_float(M2[m13], 0.000f));
	CHECK(eq_float(M2[m14], 0.000f));
	CHECK(eq_float(M2[m15], 1.000f));


#endif
} TEST_END

// --- End of File ---
