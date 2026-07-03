//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_Set_everyElement,TestConfig::ALL)
{
#if Quat_Set_everyElement

	Quat q1;
	// Set every element
	q1.set(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(2.0f == q1[x]);
	CHECK(3.0f == q1[y]);
	CHECK(4.0f == q1[z]);
	CHECK(5.0f == q1[w]);

#endif
} TEST_END


TEST(Quat_Set_Vect_Real, TestConfig::ALL)
{
#if Quat_Set_Vect_Real

	Quat q1;
	Vec3 v1;

	// Set Vector component, Real component
	v1.set(12.0f, 13.0f, 14.0f);
	q1.set(v1, 20.0f);

	CHECK((12.0f == q1[x]));
	CHECK((13.0f == q1[y]));
	CHECK((14.0f == q1[z]));
	CHECK((20.0f == q1[w]));

#endif
} TEST_END



TEST(Quat_Set_Quat_From_Rot, TestConfig::ALL)
{
#if Quat_Set_Quat_From_Rot

	Quat q1;
	Rot M2, M3;

	// Set Quaternion from a Rot
	Rot Rx(Rot1::X, MATH_PI2);
	Rot Ry(Rot1::Y, -MATH_PI3);
	Rot Rz(Rot1::Z, -MATH_7PI8);
	M2 = Rx * Ry * Rz;

	q1.set(M2);

	CHECK(eq_float(0.2273f, q1[x]));
	CHECK(eq_float(0.6695f, q1[y]));
	CHECK(eq_float(0.5316f, q1[z]));
	CHECK(eq_float(-0.4662f, q1[w]));

	M3.set(q1);

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

#endif
} TEST_END

TEST(Quat_Set_IDENTITY, TestConfig::ALL)
{
#if Quat_Set_IDENTITY

	Quat q2, qtmp;
	Rot M2, M3;
	// Set Special Type:
	q2.set(Identity);

	CHECK((q2[x] == 0.0f));
	CHECK((q2[y] == 0.0f));
	CHECK((q2[z] == 0.0f));
	CHECK((q2[w] == 1.0f));

	M2.set(Identity);
	qtmp.set(M2);
	CHECK(eq_float(q2[x], qtmp[x]));
	CHECK(eq_float(q2[y], qtmp[y]));
	CHECK(eq_float(q2[z], qtmp[z]));
	CHECK(eq_float(q2[w], qtmp[w]));

	M3.set(q2);

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

#endif
} TEST_END

TEST(Quat_Set_ROT_X_PI2, TestConfig::ALL)
{
#if Quat_Set_ROT_X_PI2

	Quat q1, qtmp;
	Rot M2;
	Mat4 M3;
	// set Special Type:
	q1.set(Rot1::X, MATH_PI2);

	// Matrix to Quaternion
	M2.set(Rot1::X, MATH_PI2);
	qtmp.set(M2);
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q1);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_X_PI, TestConfig::ALL)
{
#if Quat_Set_ROT_X_PI

	Quat q2, qtmp;
	Rot M2;
	Mat4 M3;

	// set Special Type:
	q2.set(Rot1::X, MATH_PI);

	// Matrix to Quaternion
	M2.set(Rot1::X, MATH_PI);
	qtmp.set(M2);
	CHECK(eq_float(q2[x], qtmp[x]));
	CHECK(eq_float(q2[y], qtmp[y]));
	CHECK(eq_float(q2[z], qtmp[z]));
	CHECK(eq_float(q2[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q2);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Y_PI2, TestConfig::ALL)
{
#if Quat_Set_ROT_Y_PI2

	Quat q3, qtmp;
	Rot M2;
	Mat4 M3;

	// set Special Type:
	q3.set(Rot1::Y, MATH_PI2);

	// Matrix to Quaternion
	M2.set(Rot1::Y, MATH_PI2);
	qtmp.set(M2);
	CHECK(eq_float(q3[x], qtmp[x]));
	CHECK(eq_float(q3[y], qtmp[y]));
	CHECK(eq_float(q3[z], qtmp[z]));
	CHECK(eq_float(q3[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q3);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Y_PI, TestConfig::ALL)
{
#if Quat_Set_ROT_Y_PI

	Quat q4, qtmp;
	Rot M2;
	Mat4 M3;

	// set Special Type:
	q4.set(Rot1::Y, MATH_PI);

	// Matrix to Quaternion
	M2.set(Rot1::Y, MATH_PI);
	qtmp.set(M2);
	CHECK(eq_float(q4[x], qtmp[x]));
	CHECK(eq_float(q4[y], qtmp[y]));
	CHECK(eq_float(q4[z], qtmp[z]));
	CHECK(eq_float(q4[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q4);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Z_PI2, TestConfig::ALL)
{
#if Quat_Set_ROT_Z_PI2

	Quat q1, qtmp;
	Rot M2;
	Mat4 M3;

	// set Special Type:
	q1.set(Rot1::Z, MATH_PI2);

	// Matrix to Quaternion
	M2.set(Rot1::Z, MATH_PI2);
	qtmp.set(M2);
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q1);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Z_PI, TestConfig::ALL)
{
#if Quat_Set_ROT_Z_PI

	Quat q2, qtmp;
	Rot M2;
	Mat4 M3;

	// set Special Type:
	q2.set(Rot1::Z, MATH_PI);

	// Matrix to Quaternion
	M2.set(Rot1::Z, MATH_PI);
	qtmp.set(M2);
	CHECK(eq_float(q2[x], qtmp[x]));
	CHECK(eq_float(q2[y], qtmp[y]));
	CHECK(eq_float(q2[z], qtmp[z]));
	CHECK(eq_float(q2[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q2);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_X, TestConfig::ALL)
{
#if Quat_Set_ROT_X

	Quat q1, qtmp;
	Rot M2;
	Mat4 M3;

	// set Rot_X Type  :
	q1.set(Rot1::X, MATH_PI3);

	// Matrix to Quaternion
	M2.set(Rot1::X, MATH_PI3);
	qtmp.set(M2);
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q1);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Y, TestConfig::ALL)
{
#if Quat_Set_ROT_Y

	Quat q2, qtmp;
	Rot M2;
	Mat4 M3;

	// set Rot_Y Type  :
	q2.set(Rot1::Y, MATH_PI3);

	// Matrix to Quaternion
	M2.set(Rot1::Y, MATH_PI3);
	qtmp.set(M2);
	CHECK(eq_float(q2[x], qtmp[x]));
	CHECK(eq_float(q2[y], qtmp[y]));
	CHECK(eq_float(q2[z], qtmp[z]));
	CHECK(eq_float(q2[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q2);

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

#endif
} TEST_END



TEST(Quat_Set_ROT_Z, TestConfig::ALL)
{
#if Quat_Set_ROT_Z

	Quat q3, qtmp;
	Rot M2;
	Mat4 M3;

	// set Rot_Z Type  :
	q3.set(Rot1::Z, MATH_PI3);

	// Matrix to Quaternion
	M2.set(Rot1::Z, MATH_PI3);
	qtmp.set(M2);
	CHECK(eq_float(q3[x], qtmp[x]));
	CHECK(eq_float(q3[y], qtmp[y]));
	CHECK(eq_float(q3[z], qtmp[z]));
	CHECK(eq_float(q3[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q3);

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

#endif
} TEST_END



TEST(Quat_XY_set, TestConfig::ALL)
{
#if Quat_XY_set

	// Rot_XY Type Constructor:
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI3);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI4);

	Quat Qxy;
	Qxy = Qx * Qy;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot My(Rot1::Y, MATH_PI4);
	M2 = Mx * My;

	qtmp.set(M2);
	CHECK(eq_float(Qxy[x], qtmp[x]));
	CHECK(eq_float(Qxy[y], qtmp[y]));
	CHECK(eq_float(Qxy[z], qtmp[z]));
	CHECK(eq_float(Qxy[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qxy);

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

#endif
} TEST_END



TEST(Quat_XZ_set, TestConfig::ALL)
{
#if Quat_XZ_set

	// Rot_XZ Type Constructor:
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI3);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI4);
	Quat Qxz;

	Qxz = Qx * Qz;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;
	Rot Mx(Rot1::X, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_PI4);
	M2 = Mx * Mz;

	qtmp.set(M2);
	CHECK(eq_float(Qxz[x], qtmp[x]));
	CHECK(eq_float(Qxz[y], qtmp[y]));
	CHECK(eq_float(Qxz[z], qtmp[z]));
	CHECK(eq_float(Qxz[w], qtmp[w]));

	// Quaternion to Rot
	M3.set(Qxz);

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

#endif
} TEST_END



TEST(Quat_YX_set, TestConfig::ALL)
{
#if Quat_YX_set

	// Rot_YX Type Constructor:
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI3);
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI4);
	Quat Qyx = Qy * Qx;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mx(Rot1::X, MATH_PI4);
	M2 = My * Mx;

	qtmp.set(M2);
	CHECK(eq_float(Qyx[x], qtmp[x]));
	CHECK(eq_float(Qyx[y], qtmp[y]));
	CHECK(eq_float(Qyx[z], qtmp[z]));
	CHECK(eq_float(Qyx[w], qtmp[w]));

	// Quaternion to Rot
	M3.set(Qyx);

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

#endif
} TEST_END



TEST(Quat_YZ_set, TestConfig::ALL)
{
#if Quat_YZ_set

	// Rot_YZ Type Constructor:
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI3);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI4);
	Quat Qyz = Qy * Qz;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_PI4);
	M2 = My * Mz;

	qtmp.set(M2);
	CHECK(eq_float(Qyz[x], qtmp[x]));
	CHECK(eq_float(Qyz[y], qtmp[y]));
	CHECK(eq_float(Qyz[z], qtmp[z]));
	CHECK(eq_float(Qyz[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qyz);

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

#endif
} TEST_END



TEST(Quat_ZX_set, TestConfig::ALL)
{
#if Quat_ZX_set

	// Rot_ZX Type Constructor:
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI3);
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI4);
	Quat Qzx = Qz * Qx;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot Mx(Rot1::X, MATH_PI4);
	M2 = Mz * Mx;

	qtmp.set(M2);
	CHECK(eq_float(Qzx[x], qtmp[x]));
	CHECK(eq_float(Qzx[y], qtmp[y]));
	CHECK(eq_float(Qzx[z], qtmp[z]));
	CHECK(eq_float(Qzx[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qzx);

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

#endif
} TEST_END



TEST(Quat_ZY_set, TestConfig::ALL)
{
#if Quat_ZY_set

	// Rot_ZY Type Constructor:

	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI3);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI4);
	Quat Qzy = Qz * Qy;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot My(Rot1::Y, MATH_PI4);
	M2 = Mz * My;

	qtmp.set(M2);
	CHECK(eq_float(Qzy[x], qtmp[x]));
	CHECK(eq_float(Qzy[y], qtmp[y]));
	CHECK(eq_float(Qzy[z], qtmp[z]));
	CHECK(eq_float(Qzy[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qzy);

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

#endif
} TEST_END


TEST(Quat_XYZ_set, TestConfig::ALL)
{
#if Quat_XYZ_set

	// Rot_XYZ Type Constructor:
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI3);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_5PI8);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI4);
	Quat Qxyz = Qx * Qy * Qz;

	// rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot My(Rot1::Y, MATH_5PI8);
	Rot Mz(Rot1::Z, MATH_PI4);
	M2 = Mx * My * Mz;

	qtmp.set(M2);
	CHECK(eq_float(Qxyz[x], qtmp[x]));
	CHECK(eq_float(Qxyz[y], qtmp[y]));
	CHECK(eq_float(Qxyz[z], qtmp[z]));
	CHECK(eq_float(Qxyz[w], qtmp[w]));

	// Quaternion to Rot
	M3.set(Qxyz);

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

#endif
} TEST_END



TEST(Quat_XZY_set, TestConfig::ALL)
{
#if Quat_XZY_set

	// Rot_XZY Type Constructor:
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI3);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_5PI8);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI4);
	Quat Qxzy = Qx * Qz * Qy;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_5PI8);
	Rot My(Rot1::Y, MATH_PI4);
	M2 = Mx * Mz * My;

	qtmp.set(M2);
	CHECK(eq_float(Qxzy[x], qtmp[x]));
	CHECK(eq_float(Qxzy[y], qtmp[y]));
	CHECK(eq_float(Qxzy[z], qtmp[z]));
	CHECK(eq_float(Qxzy[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qxzy);

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

#endif
} TEST_END



TEST(Quat_YXZ_set, TestConfig::ALL)
{
#if Quat_YXZ_set

	// Rot_YXZ Type Constructor:
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI3);
	Quat Qx;
	Qx.set(Rot1::X, MATH_5PI8);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI4);
	Quat Qyxz = Qy * Qx * Qz;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mx(Rot1::X, MATH_5PI8);
	Rot Mz(Rot1::Z, MATH_PI4);
	M2 = My * Mx * Mz;

	qtmp.set(M2);
	CHECK(eq_float(Qyxz[x], qtmp[x]));
	CHECK(eq_float(Qyxz[y], qtmp[y]));
	CHECK(eq_float(Qyxz[z], qtmp[z]));
	CHECK(eq_float(Qyxz[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qyxz);

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

#endif
} TEST_END



TEST(Quat_YZX_set, TestConfig::ALL)
{
#if Quat_YZX_set

	// Rot_YZX Type Constructor:
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI3);
	Quat Qz;
	Qz.set(Rot1::Z, MATH_5PI8);
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI4);
	Quat Qyzx = Qy * Qz * Qx;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_5PI8);
	Rot Mx(Rot1::X, MATH_PI4);
	M2 = My * Mz * Mx;

	qtmp.set(M2);
	CHECK(eq_float(Qyzx[x], qtmp[x]));
	CHECK(eq_float(Qyzx[y], qtmp[y]));
	CHECK(eq_float(Qyzx[z], qtmp[z]));
	CHECK(eq_float(Qyzx[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qyzx);

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

#endif
} TEST_END



TEST(Quat_ZXY_set, TestConfig::ALL)
{
#if Quat_ZXY_set

	// Rot_ZXY Type Constructor:
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI3);
	Quat Qx;
	Qx.set(Rot1::X, MATH_5PI8);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_PI4);
	Quat Qzxy = Qz * Qx * Qy;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot Mx(Rot1::X, MATH_5PI8);
	Rot My(Rot1::Y, MATH_PI4);
	M2 = Mz * Mx * My;

	qtmp.set(M2);
	CHECK(eq_float(Qzxy[x], qtmp[x]));
	CHECK(eq_float(Qzxy[y], qtmp[y]));
	CHECK(eq_float(Qzxy[z], qtmp[z]));
	CHECK(eq_float(Qzxy[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qzxy);

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

#endif
} TEST_END



TEST(Quat_ZYX_set, TestConfig::ALL)
{
#if Quat_ZYX_set

	// Rot_ZYX Type Constructor:
	Quat Qz;
	Qz.set(Rot1::Z, MATH_PI3);
	Quat Qy;
	Qy.set(Rot1::Y, MATH_5PI8);
	Quat Qx;
	Qx.set(Rot1::X, MATH_PI4);
	Quat Qzyx = Qz * Qy * Qx;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot My(Rot1::Y, MATH_5PI8);
	Rot Mx(Rot1::X, MATH_PI4);
	M2 = Mz * My * Mx;

	qtmp.set(M2);
	CHECK(eq_float(Qzyx[x], qtmp[x]));
	CHECK(eq_float(Qzyx[y], qtmp[y]));
	CHECK(eq_float(Qzyx[z], qtmp[z]));
	CHECK(eq_float(Qzyx[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qzyx);

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

#endif
} TEST_END



TEST(Quat_AXIS_ANGLE_set, TestConfig::ALL)
{
#if Quat_AXIS_ANGLE_set
	// Axis and Angle Type Constructor:
	Vec3 v11(2.0f, 53.0f, 24.0f);
	Quat Qa1;
	Qa1.set(Axis::AxisAngle, v11, MATH_PI3);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Axis::AxisAngle, v11, MATH_PI3);

	qtmp.set(M2);
	CHECK(eq_float(Qa1[x], qtmp[x]));
	CHECK(eq_float(Qa1[y], qtmp[y]));
	CHECK(eq_float(Qa1[z], qtmp[z]));
	CHECK(eq_float(Qa1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(Qa1);

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

#endif
} TEST_END



TEST(Quat_ROT_ORIENT_set, TestConfig::ALL)
{
#if Quat_ROT_ORIENT_set

	// Orientation Type Constructor:
	Vec3  v15(2.0f, 53.0f, 24.0f);
	Vec3  v16(0.0f, -24.0f, 53.0f);
	Quat q56;
	q56.set(Orient::LocalToWorld, v15, v16);

	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Orient::LocalToWorld, v15, v16);
	qtmp.set(M2);
	CHECK(eq_float(q56[x], qtmp[x]));
	CHECK(eq_float(q56[y], qtmp[y]));
	CHECK(eq_float(q56[z], qtmp[z]));
	CHECK(eq_float(q56[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q56);

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

#endif
} TEST_END



TEST(Quat_ROT_INVERSE_ORIENT_set, TestConfig::ALL)
{
#if Quat_ROT_INVERSE_ORIENT_set

	// Orientation Type Constructor:
	Vec3  v17(2.0f, 53.0f, 24.0f);
	Vec3  v18(0.0f, -24.0f, 53.0f);
	Quat q57;
	q57.set(Orient::WorldToLocal, v17, v18);

	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Orient::WorldToLocal, v17, v18);
	qtmp.set(M2);
	CHECK(eq_float(q57[x], qtmp[x]));
	CHECK(eq_float(q57[y], qtmp[y]));
	CHECK(eq_float(q57[z], qtmp[z]));
	CHECK(eq_float(q57[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q57);

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

#endif
} TEST_END



TEST(Quat_Set_Each_ELEMENT, TestConfig::ALL)
{
#if Quat_Set_Each_ELEMENT

	Quat q2;

	// set Quat each Element:
	q2[x] = 11.0f;
	q2[y] = 12.0f;
	q2[z] = 13.0f;
	q2[real] = 14.0f;

	CHECK((q2[x] == 11.0f));
	CHECK((q2[y] == 12.0f));
	CHECK((q2[z] == 13.0f));
	CHECK((q2[w] == 14.0f));

#endif
} TEST_END



TEST(Quat_Set_From_VECT, TestConfig::ALL)
{
#if Quat_Set_From_VECT

	Vec3 v1;
	Quat q2;
	// set Quat Vector Element:

	v1.set(3.0f, 4.0f, 5.0f);

	q2.setVec3(v1);

	CHECK((q2[x] == 3.0f));
	CHECK((q2[y] == 4.0f));
	CHECK((q2[z] == 5.0f));


#endif
} TEST_END



TEST(Quat_Get_Vect_elements, TestConfig::ALL)
{
#if Quat_Get_Vect_elements

	Quat q1;
	float tmp_x, tmp_y, tmp_z, tmp_real;

	// get Quat Vector Elements:
	q1.set(3.0f, 4.0f, 5.0f, 6.0f);

	tmp_x = q1[x];
	tmp_y = q1[y];
	tmp_z = q1[z];
	tmp_real = q1[real];

	CHECK((q1[x] == 3.0f));
	CHECK((q1[y] == 4.0f));
	CHECK((q1[z] == 5.0f));
	CHECK((q1[w] == 6.0f));
	CHECK((tmp_x == 3.0f));
	CHECK((tmp_y == 4.0f));
	CHECK((tmp_z == 5.0f));
	CHECK((tmp_real == 6.0f));

#endif
} TEST_END



TEST(Quat_Get_Vect, TestConfig::ALL)
{
#if Quat_Get_Vect

	Quat q1;
	Vec3 v1;

	//  get Vector:
	q1.set(7.0f, 8.0f, 9.0f, 10.0f);

	q1.getVec3(v1);

	CHECK((v1[x] == 7.0f));
	CHECK((v1[y] == 8.0f));
	CHECK((v1[z] == 9.0f));

	CHECK((q1[x] == 7.0f));
	CHECK((q1[y] == 8.0f));
	CHECK((q1[z] == 9.0f));
	CHECK((q1[w] == 10.0f));

#endif
} TEST_END



TEST(Quat_Get_Angle_of_rotation, TestConfig::ALL)
{
#if Quat_Get_Angle_of_rotation

	Quat q1, qtmp;
	Vec3 v1;
	Rot M2;
	Mat4 M3;

	//  get Angle of rotattion about the axis of rotation
	v1.set(2.0f, 53.0f, 24.0f);
	q1.set(Axis::AxisAngle, v1, MATH_PI3);

	// Matrix to Quaternion
	M2.set(Axis::AxisAngle, v1, MATH_PI3);
	qtmp.set(M2);
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q1);

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

	float value;
	value = q1.getAngle();
	CHECK(eq_float(value, MATH_PI3));

#endif
} TEST_END



TEST(Quat_Get_Axis_of_rotation, TestConfig::ALL)
{
#if Quat_Get_Axis_of_rotation

	Quat q1, qtmp;
	Vec3 v1;
	Rot M2;
	Mat4 M3;

	//  get Axis of rotattion about the axis of rotation
	v1.set(2.0f, 53.0f, 24.0f);

	q1.set(Axis::AxisAngle, v1, MATH_PI3);

	// Matrix to Quaternion
	M2.set(Axis::AxisAngle, v1, MATH_PI3);
	qtmp.set(M2);
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	M3.set(q1);

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

	//  get axis of rotation:
	Vec3 v2 = v1;
	v2.norm();
	Vec3 v3;
 
	//Debug::Print("v1 - Orig", v1);
	//Debug::Print("v2 - norm", v2);
 
	q1.getAxis(v3);
	//Debug::Print("From quat v3", v3);
 
	CHECK(eq_float(v3[x], 0.03436f));
	CHECK(eq_float(v3[y], 0.9104f));
	CHECK(eq_float(v3[z], 0.4123f));
	
 
	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));
 
	//Trace::out("\n");
	//Trace::out("\n");
	Quat qa(0, 0, 0, 1);
	Mat4 Ma(qa);
 
	//Debug::Print("qa: ", qa);
	//Debug::Print("Ma: ", Ma);
 
	//Trace::out("\n");
	//Trace::out("\n");
 
	Rot M1(Identity);
	q1.set(M1);
 
	//Debug::Print("q1: ", q1);
	//Debug::Print("M1: ", M1);

 #endif
} TEST_END



TEST(Quat_Get_bracket1, TestConfig::ALL)
{
#if Quat_Get_bracket1

	Quat q1;
	float tmp_x, tmp_y, tmp_z, tmp_real;

	//  [] operator:
	q1.set(7.0f, 8.0f, 9.0f, 10.0f);

	tmp_x = q1[x];
	tmp_y = q1[y];
	tmp_z = q1[z];
	tmp_real = q1[w];

	CHECK((q1[x] == 7.0f));
	CHECK((q1[y] == 8.0f));
	CHECK((q1[z] == 9.0f));
	CHECK((q1[w] == 10.0f));
	CHECK((tmp_x == 7.0f));
	CHECK((tmp_y == 8.0f));
	CHECK((tmp_z == 9.0f));
	CHECK((tmp_real == 10.0f));

#endif
} TEST_END



TEST(Quat_Get_bracket2, TestConfig::ALL)
{
#if Quat_Get_bracket2

	Quat q1;
	float tmp_x, tmp_y, tmp_z, tmp_real;

	//  [] operator:
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	tmp_x = q1[X];
	tmp_y = q1[Y];
	tmp_z = q1[Z];
	tmp_real = q1[W];

	CHECK((q1[x] == 1.0f));
	CHECK((q1[y] == 2.0f));
	CHECK((q1[z] == 3.0f));
	CHECK((q1[w] == 4.0f));
	CHECK((tmp_x == 1.0f));
	CHECK((tmp_y == 2.0f));
	CHECK((tmp_z == 3.0f));
	CHECK((tmp_real == 4.0f));

#endif
} TEST_END



TEST(Quat_Get_bracket3, TestConfig::ALL)
{
#if Quat_Get_bracket3

	Quat q1;
	float tmp_x, tmp_y, tmp_z, tmp_real;

	//  [] operator:
	q1.set(7.0f, 8.0f, 9.0f, 10.0f);

	tmp_x = q1[vx];
	tmp_y = q1[vy];
	tmp_z = q1[vz];
	tmp_real = q1[real];

	CHECK((q1[x] == 7.0f));
	CHECK((q1[y] == 8.0f));
	CHECK((q1[z] == 9.0f));
	CHECK((q1[w] == 10.0f));
	CHECK((tmp_x == 7.0f));
	CHECK((tmp_y == 8.0f));
	CHECK((tmp_z == 9.0f));
	CHECK((tmp_real == 10.0f));

#endif
} TEST_END



TEST(Quat_Get_bracket4, TestConfig::ALL)
{
#if Quat_Get_bracket4

	Quat q1;
	float tmp_x, tmp_y, tmp_z, tmp_real;

	//  [] operator:
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	tmp_x = q1[VX];
	tmp_y = q1[VY];
	tmp_z = q1[VZ];
	tmp_real = q1[REAL];

	CHECK((q1[x] == 1.0f));
	CHECK((q1[y] == 2.0f));
	CHECK((q1[z] == 3.0f));
	CHECK((q1[w] == 4.0f));
	CHECK((tmp_x == 1.0f));
	CHECK((tmp_y == 2.0f));
	CHECK((tmp_z == 3.0f));
	CHECK((tmp_real == 4.0f));

#endif
} TEST_END


// ---  End of File ---------------
