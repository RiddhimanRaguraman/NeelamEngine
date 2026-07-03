//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

void verifyRot2Angle(float a1, float a2, bool &result);
void verifyRot3Angle(float a1, float a2, float a3, bool &result);

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_Functions, TestConfig::ALL)
{
#if Quat_Functions

	// Quat Functions tests:
	CHECK(1);

#endif
} TEST_END



TEST(Quat_GetConjugate, TestConfig::ALL)
{
#if Quat_GetConjugate

	Rot	mm2, mm3;
	Quat	q1, q2, q3, qtmp;
	Vec3	v1, v2, v3, v4;

	// Conjugate

	//q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);
	Quat qx(Rot1::X, MATH_2PI3);
	Quat qy(Rot1::Y, MATH_3PI8);
	Quat qz(Rot1::Z, MATH_3PI4);

	// => q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4
	q1 = qx * qy * qz;

	CHECK(eq_float(q1[x], 0.01887f));
	CHECK(eq_float(q1[y], 0.7715f));
	CHECK(eq_float(q1[z], 0.1999f));
	CHECK(eq_float(q1[w], 0.6036f));

	q2 = q1.getConj();
	// => q2 = q1.getConj();\n"););

	CHECK(eq_float(q2[x], -0.01887f));
	CHECK(eq_float(q2[y], -0.7715f));
	CHECK(eq_float(q2[z], -0.1999f));
	CHECK(eq_float(q2[w], 0.6036f));


	// Matrix to Quat
	//m2.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);
	Rot mx(Rot1::X, MATH_2PI3);
	Rot my(Rot1::Y, MATH_3PI8);
	Rot mz(Rot1::Z, MATH_3PI4);

	mm2 = mx * my * mz;

	qtmp.set(mm2);

	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	mm3.set(q1);

	CHECK(eq_float(mm2[m0], mm3[m0]));
	CHECK(eq_float(mm2[m1], mm3[m1]));
	CHECK(eq_float(mm2[m2], mm3[m2]));
	CHECK(eq_float(mm2[m3], mm3[m3]));
	CHECK(eq_float(mm2[m4], mm3[m4]));
	CHECK(eq_float(mm2[m5], mm3[m5]));
	CHECK(eq_float(mm2[m6], mm3[m6]));
	CHECK(eq_float(mm2[m7], mm3[m7]));
	CHECK(eq_float(mm2[m8], mm3[m8]));
	CHECK(eq_float(mm2[m9], mm3[m9]));
	CHECK(eq_float(mm2[m10], mm3[m10]));
	CHECK(eq_float(mm2[m11], mm3[m11]));
	CHECK(eq_float(mm2[m12], mm3[m12]));
	CHECK(eq_float(mm2[m13], mm3[m13]));
	CHECK(eq_float(mm2[m14], mm3[m14]));
	CHECK(eq_float(mm2[m15], mm3[m15]));

#endif
} TEST_END



TEST(Quat_ConjugateInPlace, TestConfig::ALL)
{
#if Quat_ConjugateInPlace

	Quat q1;

	// Conjugate in place 

	//q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);
	// => q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);
	Quat qx(Rot1::X, MATH_2PI3);
	Quat qy(Rot1::Y, MATH_3PI8);
	Quat qz(Rot1::Z, MATH_3PI4);

	// => q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4
	q1 = qx * qy * qz;

	CHECK(eq_float(q1[x], 0.01887f));
	CHECK(eq_float(q1[y], 0.7715f));
	CHECK(eq_float(q1[z], 0.1999f));
	CHECK(eq_float(q1[w], 0.6036f));

	q1.conj();
	// => q1.conj()

	CHECK(eq_float(q1[x], -0.01887f));
	CHECK(eq_float(q1[y], -0.7715f));
	CHECK(eq_float(q1[z], -0.1999f));
	CHECK(eq_float(q1[w], 0.6036f));

#endif
} TEST_END



TEST(Quat_ConjugateByValue, TestConfig::ALL)
{
#if Quat_ConjugateByValue

	Quat q1, q2, qtmp;
	Rot mm2, mm3;

	// Conjugate by value
	// q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);
	Quat qx(Rot1::X, MATH_2PI3);
	Quat qy(Rot1::Y, MATH_3PI8);
	Quat qz(Rot1::Z, MATH_3PI4);

	// => q1.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4
	q1 = qx * qy * qz;

	CHECK(eq_float(q1[x], 0.01887f));
	CHECK(eq_float(q1[y], 0.7715f));
	CHECK(eq_float(q1[z], 0.1999f));
	CHECK(eq_float(q1[w], 0.6036f));

	q2 = q1.getConj();
	// => q2 = q1.getConj();

	CHECK(eq_float(q2[x], -0.01887f));
	CHECK(eq_float(q2[y], -0.7715f));
	CHECK(eq_float(q2[z], -0.1999f));
	CHECK(eq_float(q2[w], 0.6036f));

	// Matrix to Quat
	//m2.set(Rot_XYZ,MATH_2PI3,MATH_3PI8,MATH_3PI4);

	Rot mx(Rot1::X, MATH_2PI3);
	Rot my(Rot1::Y, MATH_3PI8);
	Rot mz(Rot1::Z, MATH_3PI4);

	mm2 = mx * my * mz;

	qtmp.set(mm2);

	CHECK(eq_float(q1[x], qtmp[x]));
	CHECK(eq_float(q1[y], qtmp[y]));
	CHECK(eq_float(q1[z], qtmp[z]));
	CHECK(eq_float(q1[w], qtmp[w]));

	// Quaternion to Matrix
	mm3.set(q1);
	CHECK(eq_float(mm2[m0], mm3[m0]));
	CHECK(eq_float(mm2[m1], mm3[m1]));
	CHECK(eq_float(mm2[m2], mm3[m2]));
	CHECK(eq_float(mm2[m3], mm3[m3]));
	CHECK(eq_float(mm2[m4], mm3[m4]));
	CHECK(eq_float(mm2[m5], mm3[m5]));
	CHECK(eq_float(mm2[m6], mm3[m6]));
	CHECK(eq_float(mm2[m7], mm3[m7]));
	CHECK(eq_float(mm2[m8], mm3[m8]));
	CHECK(eq_float(mm2[m9], mm3[m9]));
	CHECK(eq_float(mm2[m10], mm3[m10]));
	CHECK(eq_float(mm2[m11], mm3[m11]));
	CHECK(eq_float(mm2[m12], mm3[m12]));
	CHECK(eq_float(mm2[m13], mm3[m13]));
	CHECK(eq_float(mm2[m14], mm3[m14]));
	CHECK(eq_float(mm2[m15], mm3[m15]));

#endif
} TEST_END

TEST(Quat_Mag, TestConfig::ALL)
{
#if Quat_Mag

	// magnitude()
	Quat q1;
	float value;
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => mag = q1.mag() 
	value = q1.mag();

	CHECK(eq_float(value, 5.477225f));

#endif
} TEST_END



TEST(Quat_MagSquared, TestConfig::ALL)
{
#if Quat_MagSquared

	// magnitude Squared()

	Quat q1;
	float value;
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// => value = q1.magSquared() 
	value = q1.magSquared();

	CHECK(eq_float(value, 30.0f));

#endif
} TEST_END



TEST(Quat_InvMag, TestConfig::ALL)
{
#if Quat_InvMag

	// inverse magnitude()
	Quat q1;
	float value;

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => invMag = q1.invMag() 
	value = q1.invMag();

	CHECK(eq_float(value, 0.1825742f));

#endif
} TEST_END



TEST(Quat_Norm, TestConfig::ALL)
{
#if Quat_Norm

	Quat q1, q2;
	// norm()

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => q2 = q1.norm() 
	q2 = q1.norm();

	CHECK(eq_float(q2.mag(), 1.0f));
	CHECK(eq_float(q1[x], 0.18257418f));
	CHECK(eq_float(q1[y], 0.36514837f));
	CHECK(eq_float(q1[z], 0.54772258f));
	CHECK(eq_float(q1[w], 0.73029673f));

	CHECK(q1.isNormalized(MATH_TOLERANCE));

	CHECK(eq_float(q1.magSquared(), 1.0f));

	CHECK(eq_float(q2[x], 0.18257418f));
	CHECK(eq_float(q2[y], 0.36514837f));
	CHECK(eq_float(q2[z], 0.54772258f));
	CHECK(eq_float(q2[w], 0.73029673f));

	CHECK(q2.isNormalized(MATH_TOLERANCE));
	CHECK(eq_float(q2.magSquared(), 1.0f));

#endif
} TEST_END



TEST(Quat_GetNorm, TestConfig::ALL)
{
#if Quat_GetNorm

	Quat q1, q2;
	// getNorm()
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => q2 = q1.getNorm(); 
	q2 = q1.getNorm();

	CHECK(eq_float(q2.mag(), 1.0f));
	CHECK(eq_float(q2[x], 0.18257418f));
	CHECK(eq_float(q2[y], 0.36514837f));
	CHECK(eq_float(q2[z], 0.54772258f));
	CHECK(eq_float(q2[w], 0.73029673f));

	CHECK((q1[x] == 1.0f));
	CHECK((q1[y] == 2.0f));
	CHECK((q1[z] == 3.0f));
	CHECK((q1[w] == 4.0f));

#endif
} TEST_END



TEST(Quat_GetInverse, TestConfig::ALL)
{
#if Quat_GetInverse

	Quat q1, q2, q3;
	// getInv()\n");
	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q1.norm();

	CHECK(eq_float(q1[x], 0.18257f));
	CHECK(eq_float(q1[y], 0.36514f));
	CHECK(eq_float(q1[z], 0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	// => q2 = q1.getInv() 
	q2 = q1.getInv();

	CHECK(eq_float(q1[x], 0.18257f));
	CHECK(eq_float(q1[y], 0.36514f));
	CHECK(eq_float(q1[z], 0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	CHECK(eq_float(q2[x], -0.18257f));
	CHECK(eq_float(q2[y], -0.36514f));
	CHECK(eq_float(q2[z], -0.54772f));
	CHECK(eq_float(q2[w], 0.73029f));


	q3 = q1 * q2;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

	q3 = q2 * q1;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

#endif
} TEST_END




TEST(Quat_Inverse, TestConfig::ALL)
{
#if Quat_Inverse

	Quat q1, q2, q3;
	// inverse()

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q1.norm();

	CHECK(eq_float(q1[x], 0.18257f));
	CHECK(eq_float(q1[y], 0.36514f));
	CHECK(eq_float(q1[z], 0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	// => q1.inv() 
	q2 = q1;
	q1.inv();

	CHECK(eq_float(q1[x], -0.18257f));
	CHECK(eq_float(q1[y], -0.36514f));
	CHECK(eq_float(q1[z], -0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	CHECK(eq_float(q2[x], 0.18257f));
	CHECK(eq_float(q2[y], 0.36514f));
	CHECK(eq_float(q2[z], 0.54772f));
	CHECK(eq_float(q2[w], 0.73029f));

	q3 = q1 * q2;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

	q3 = q2 * q1;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

#endif
} TEST_END



TEST(Quat_Inverse_3, TestConfig::ALL)
{
#if Quat_Inverse_3

	Quat q1, q2, q3;
	// inverse()

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	q1.norm();
	CHECK(eq_float(q1[x], 0.18257f));
	CHECK(eq_float(q1[y], 0.36514f));
	CHECK(eq_float(q1[z], 0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	// => q1.inv(q1) 
	q2 = q1;
	q1.inv();

	CHECK(eq_float(q2[x], 0.18257f));
	CHECK(eq_float(q2[y], 0.36514f));
	CHECK(eq_float(q2[z], 0.54772f));
	CHECK(eq_float(q2[w], 0.73029f));

	CHECK(eq_float(q1[x], -0.18257f));
	CHECK(eq_float(q1[y], -0.36514f));
	CHECK(eq_float(q1[z], -0.54772f));
	CHECK(eq_float(q1[w], 0.73029f));

	q3 = q1 * q2;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

	q3 = q2 * q1;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

#endif
} TEST_END



TEST(Quat_Inverse_Transpose, TestConfig::ALL)
{
#if Quat_Inverse_Transpose

	Quat q1, q2, q3;
	// inverse()

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);
	// => q1.inv(q1) 
	q2 = q1.norm();
	q2.inv();

	CHECK(eq_float(q1.mag(), 1.0f));
	CHECK(eq_float(q1[x], 0.18257418f));
	CHECK(eq_float(q1[y], 0.36514837f));
	CHECK(eq_float(q1[z], 0.54772258f));
	CHECK(eq_float(q1[w], 0.73029673f));

	CHECK(eq_float(q2[x], -0.18257418f));
	CHECK(eq_float(q2[y], -0.36514837f));
	CHECK(eq_float(q2[z], -0.54772258f));
	CHECK(eq_float(q2[w], 0.73029673f));

	q3 = q1 * q2;

	CHECK(eq_float(q3[x], 0.0f));
	CHECK(eq_float(q3[y], 0.0f));
	CHECK(eq_float(q3[z], 0.0f));
	CHECK(eq_float(q3[w], 1.0f));

#endif
} TEST_END



TEST(Quat_Lqcvq_Lqvqc_1, TestConfig::ALL)
{
#if Quat_Lqcvq_Lqvqc_1

	// Lqcvq() and Lqvqc() operator

	//Matrix Mxyz(Rot_XYZ,MATH_PI3,MATH_3PI4,MATH_PI2);
	Rot mx(Rot1::X, MATH_PI3);
	Rot my(Rot1::Y, MATH_3PI4);
	Rot mz(Rot1::Z, MATH_PI2);
	Mat4 Mxyz = mx * my * mz;

	Mat4 MTxyz(Mxyz.getT());
	//Quat   Qxyz(Rot_XYZ,MATH_PI3,MATH_3PI4,MATH_PI2);
	Quat qx(Rot1::X, MATH_PI3);
	Quat qy(Rot1::Y, MATH_3PI4);
	Quat qz(Rot1::Z, MATH_PI2);
	Quat Qxyz = qx * qy * qz;

	Quat   QTxyz(Qxyz.getInv());

	Vec3 vx(1.0f, 0.0f, 0.0f);
	Vec3 vy(0.0f, 1.0f, 0.0f);
	Vec3 vz(0.0f, 0.0f, 1.0f);
	Vec3 vo(1.0f, 2.0f, 3.0f);
	Vec3 Vout1_x, Vout1_y, Vout1_z, Vout1_o;
	Vec3 Vout2_x, Vout2_y, Vout2_z, Vout2_o;

	Vout1_x = Vec3(Vec4(vx, 1) * Mxyz);
	Vout1_y = Vec3(Vec4(vy, 1) * Mxyz);
	Vout1_z = Vec3(Vec4(vz, 1) * Mxyz);
	Vout1_o = Vec3(Vec4(vo, 1) * Mxyz);

	// Vout = vIn * Quat
	Qxyz.Lqcvq(vx, Vout2_x);
	Qxyz.Lqcvq(vy, Vout2_y);
	Qxyz.Lqcvq(vz, Vout2_z);
	Qxyz.Lqcvq(vo, Vout2_o);

	// => Vout1_x = vx * Mxyz;
	// => Vout1_y = vy * Mxyz;
	// => Vout1_z = vz * Mxyz;
	// => Vout1_o = vo * Mxyz;
	// => Qxyz.Lqcvq(vx, Vout2_x);
	// => Qxyz.Lqcvq(vy, Vout2_y);
	// => Qxyz.Lqcvq(vz, Vout2_z);  
	// => Qxyz.Lqcvq(vo, Vout2_o);  

	CHECK(eq_float(Vout1_x[x], Vout2_x[x]));
	CHECK(eq_float(Vout1_x[y], Vout2_x[y]));
	CHECK(eq_float(Vout1_x[z], Vout2_x[z]));

	CHECK(eq_float(Vout1_y[x], Vout2_y[x]));
	CHECK(eq_float(Vout1_y[y], Vout2_y[y]));
	CHECK(eq_float(Vout1_y[z], Vout2_y[z]));

	CHECK(eq_float(Vout1_z[x], Vout2_z[x]));
	CHECK(eq_float(Vout1_z[y], Vout2_z[y]));
	CHECK(eq_float(Vout1_z[z], Vout2_z[z]));

	CHECK(eq_float(Vout1_o[x], Vout2_o[x]));
	CHECK(eq_float(Vout1_o[y], Vout2_o[y]));
	CHECK(eq_float(Vout1_o[z], Vout2_o[z]));

	Vout1_x = Vec3(Vec4(vx, 1) * Mxyz.getT());
	Vout1_y = Vec3(Vec4(vy, 1) * Mxyz.getT());
	Vout1_z = Vec3(Vec4(vz, 1) * Mxyz.getT());
	Vout1_o = Vec3(Vec4(vo, 1) * Mxyz.getT());

	// Vout = vIn * Quat.T()
	Qxyz.Lqvqc(vx, Vout2_x);
	Qxyz.Lqvqc(vy, Vout2_y);
	Qxyz.Lqvqc(vz, Vout2_z);
	Qxyz.Lqvqc(vo, Vout2_o);

	// => Vout1_x = vx * Mxyz.T();
	// => Vout1_y = vy * Mxyz.T();
	// => Vout1_z = vz * Mxyz.T();
	// => Vout1_o = vo * Mxyz.T();
	// => Qxyz.Lqvqc(vx, Vout2_x);
	// => Qxyz.Lqvqc(vy, Vout2_y);
	// => Qxyz.Lqvqc(vz, Vout2_z); 
	// => Qxyz.Lqvqc(vo, Vout2_o);  

	CHECK(eq_float(Vout1_x[x], Vout2_x[x]));
	CHECK(eq_float(Vout1_x[y], Vout2_x[y]));
	CHECK(eq_float(Vout1_x[z], Vout2_x[z]));

	CHECK(eq_float(Vout1_y[x], Vout2_y[x]));
	CHECK(eq_float(Vout1_y[y], Vout2_y[y]));
	CHECK(eq_float(Vout1_y[z], Vout2_y[z]));

	CHECK(eq_float(Vout1_z[x], Vout2_z[x]));
	CHECK(eq_float(Vout1_z[y], Vout2_z[y]));
	CHECK(eq_float(Vout1_z[z], Vout2_z[z]));

	CHECK(eq_float(Vout1_o[x], Vout2_o[x]));
	CHECK(eq_float(Vout1_o[y], Vout2_o[y]));
	CHECK(eq_float(Vout1_o[z], Vout2_o[z]));

#endif
} TEST_END



TEST(Quat_Dot, TestConfig::ALL)
{
#if Quat_Dot

	Quat q1;

	q1.set(1.0f, 2.0f, 3.0f, 4.0f);

	// 4D dot product
	float value = q1.dot(q1);

	CHECK(eq_float(value, 30.0f));
	CHECK(eq_float(q1[x], 1.0f));
	CHECK(eq_float(q1[y], 2.0f));
	CHECK(eq_float(q1[z], 3.0f));
	CHECK(eq_float(q1[w], 4.0f));

#endif
} TEST_END



TEST(Quat_Assignment_Rot, TestConfig::ALL)
{
#if Quat_Assignment_Rot

	Quat q1;
	Rot A(Rot3::XYZ, 0.34f, -2.3f, 1.2f);

	Quat q2(A);

	q1 = A;

	Mat4 B(q1);

	CHECK(eq_float(A[m0], B[m0]));
	CHECK(eq_float(A[m1], B[m1]));
	CHECK(eq_float(A[m2], B[m2]));
	CHECK(eq_float(A[m3], B[m3]));
	CHECK(eq_float(A[m4], B[m4]));
	CHECK(eq_float(A[m5], B[m5]));
	CHECK(eq_float(A[m6], B[m6]));
	CHECK(eq_float(A[m7], B[m7]));
	CHECK(eq_float(A[m8], B[m8]));
	CHECK(eq_float(A[m9], B[m9]));
	CHECK(eq_float(A[m10], B[m10]));
	CHECK(eq_float(A[m11], B[m11]));
	CHECK(eq_float(A[m12], B[m12]));
	CHECK(eq_float(A[m13], B[m13]));
	CHECK(eq_float(A[m14], B[m14]));
	CHECK(eq_float(A[m15], B[m15]));

	q1 = -q1;
	Mat4 C(q1);

	CHECK(eq_float(A[m0], C[m0]));
	CHECK(eq_float(A[m1], C[m1]));
	CHECK(eq_float(A[m2], C[m2]));
	CHECK(eq_float(A[m3], C[m3]));
	CHECK(eq_float(A[m4], C[m4]));
	CHECK(eq_float(A[m5], C[m5]));
	CHECK(eq_float(A[m6], C[m6]));
	CHECK(eq_float(A[m7], C[m7]));
	CHECK(eq_float(A[m8], C[m8]));
	CHECK(eq_float(A[m9], C[m9]));
	CHECK(eq_float(A[m10], C[m10]));
	CHECK(eq_float(A[m11], C[m11]));
	CHECK(eq_float(A[m12], C[m12]));
	CHECK(eq_float(A[m13], C[m13]));
	CHECK(eq_float(A[m14], C[m14]));
	CHECK(eq_float(A[m15], C[m15]));

#endif
} TEST_END


// ---  End of File ---------------
