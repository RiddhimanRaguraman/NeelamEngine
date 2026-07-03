//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_Constructor, TestConfig::ALL)
{
#if Quat_Constructor

	CHECK( 1 );

#endif
} TEST_END



TEST( Quat_Default_Constructor, TestConfig::ALL)
{
#if Quat_Default_Constructor

	// Default Constructor:
	Quat q1;

	CHECK( ( 0.0f == q1[x] ) );
	CHECK( ( 0.0f == q1[y] ) );
	CHECK( ( 0.0f == q1[z] ) );
	CHECK( ( 1.0f == q1[w] ) );
	CHECK( sizeof(q1) == sizeof(Quat) );

#endif
} TEST_END



TEST( Quat_Constructor_Set_Every_Component, TestConfig::ALL)
{
#if Quat_Constructor_Set_Every_Component

	// Set every element constructor
	Quat q10(2.0f,3.0f,4.0f,5.0f);

	CHECK( ( 2.0f == q10[x] ) );
	CHECK( ( 3.0f == q10[y] ) );
	CHECK( ( 4.0f == q10[z] ) );
	CHECK( ( 5.0f == q10[w] ) );

#endif
} TEST_END



TEST( Quat_Copy_Constructor, TestConfig::ALL)
{
#if Quat_Copy_Constructor

	// Copy Constructor
	Quat q11(2.0f,3.0f,4.0f,5.0f);
	Quat q12(q11);

	CHECK( ( 2.0f == q11[x] ) );
	CHECK( ( 3.0f == q11[y] ) );
	CHECK( ( 4.0f == q11[z] ) );
	CHECK( ( 5.0f == q11[w] ) );
	CHECK( ( q12[x] == q11[x] ) );
	CHECK( ( q12[y] == q11[y] ) );
	CHECK( ( q12[z] == q11[z] ) );
	CHECK( ( q12[w] == q11[w] ) );

#endif
} TEST_END


TEST( Quat_Vect_Comp_Real_Comp_Constructor, TestConfig::ALL)
{
#if Quat_Vect_Comp_Real_Comp_Constructor

	// Vector component, Real component Constructor
	Vec3 v10(12.0f,13.0f,14.0f);
	Quat q13(v10,20.0f);

	CHECK( ( 12.0f == q13[x] ) );
	CHECK( ( 13.0f == q13[y] ) );
	CHECK( ( 14.0f == q13[z] ) );
	CHECK( ( 20.0f == q13[w] ) );

#endif
} TEST_END



TEST( Quat_From_Rot_Constructor, TestConfig::ALL)
{
#if Quat_From_Rot_Constructor

	// Quaternion from a Matrix Constructor
	Rot m40;
	Rot Rx(Rot1::X,MATH_PI2);
	Rot Ry(Rot1::Y,-MATH_PI3);
	Rot Rz(Rot1::Z,-MATH_7PI8);

	m40 = Rx * Ry * Rz;

	Quat q14(m40);
	
	CHECK( eq_float(0.2273f,q14[x]) );
	CHECK( eq_float(0.6695f,q14[y]) );
	CHECK( eq_float(0.5316f,q14[z]) );
	CHECK( eq_float(-0.4662f,q14[w]) );

	Mat4 M3;
	M3.set(q14);

	CHECK( eq_float(m40[m0],M3[m0]) );
	CHECK( eq_float(m40[m1],M3[m1]) );
	CHECK( eq_float(m40[m2],M3[m2]) );
	CHECK( eq_float(m40[m3],M3[m3]) );
	CHECK( eq_float(m40[m4],M3[m4]) );
	CHECK( eq_float(m40[m5],M3[m5]) );
	CHECK( eq_float(m40[m6],M3[m6]) );
	CHECK( eq_float(m40[m7],M3[m7]) );
	CHECK( eq_float(m40[m8],M3[m8]) );
	CHECK( eq_float(m40[m9],M3[m9]) );
	CHECK( eq_float(m40[m10],M3[m10]) );
	CHECK( eq_float(m40[m11],M3[m11]) );
	CHECK( eq_float(m40[m12],M3[m12]) );
	CHECK( eq_float(m40[m13],M3[m13]) );
	CHECK( eq_float(m40[m14],M3[m14]) );
	CHECK( eq_float(m40[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_IDENTITY_Constructor, TestConfig::ALL)
{
#if Quat_IDENTITY_Constructor

	// Special Type Constructor:
	Quat q2(Identity);

	CHECK( (q2[x] == 0.0f) );
	CHECK( (q2[y] == 0.0f) );
	CHECK( (q2[z] == 0.0f) );
	CHECK( (q2[w] == 1.0f) );

	Rot 	M2;
	M2.set(Identity);
	Quat qtmp;
	qtmp.set( M2 );
	CHECK( eq_float(q2[x],qtmp[x]) );
	CHECK( eq_float(q2[y],qtmp[y]) );
	CHECK( eq_float(q2[z],qtmp[z]) );
	CHECK( eq_float(q2[w],qtmp[w]) );
	
	Mat4 M3;
	M3.set(q2);
	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ROTXYZ_Constructor, TestConfig::ALL)
{
#if Quat_ROTXYZ_Constructor

	// Special Type Constructor:
	Quat qxyz(Rot3::XYZ, 0.345f, -1.234f, 0.832f);

   Quat qx( Rot1::X, 0.345f);
   Quat qy( Rot1::Y, -1.234f);
   Quat qz( Rot1::Z,  0.832f);

   Quat qtmp;

   qtmp = qx * qy * qz;

	CHECK( eq_float(qxyz[x],qtmp[x]) );
	CHECK( eq_float(qxyz[y],qtmp[y]) );
	CHECK( eq_float(qxyz[z],qtmp[z]) );
	CHECK( eq_float(qxyz[w],qtmp[w]) );

#endif
} TEST_END



TEST( Quat_SET_ROTXYZ_Constructor, TestConfig::ALL)
{
#if Quat_SET_ROTXYZ_Constructor

	// Special Type Constructor:
	Quat qxyz;
   
   qxyz.set(Rot3::XYZ, 0.345f, -1.234f, 0.832f);

   Quat qx(Rot1::X, 0.345f);
   Quat qy(Rot1::Y, -1.234f);
   Quat qz(Rot1::Z,  0.832f);

   Quat qtmp;

   qtmp = qx * qy * qz;

	CHECK( eq_float(qxyz[x],qtmp[x]) );
	CHECK( eq_float(qxyz[y],qtmp[y]) );
	CHECK( eq_float(qxyz[z],qtmp[z]) );
	CHECK( eq_float(qxyz[w],qtmp[w]) );

#endif
} TEST_END



TEST(Quat_X_PI2_Constructor, TestConfig::ALL)
{
#if Quat_X_PI2_Constructor

	// Special Type Constructor:
	Quat q4(Rot1::X, MATH_PI2);

	// Matrix to Quaternion
	Rot M2;
	M2.set(Rot1::X, MATH_PI2);

	Quat qtmp;
	qtmp.set( M2);
	CHECK( eq_float(q4[x],qtmp[x]) );
	CHECK( eq_float(q4[y],qtmp[y]) );
	CHECK( eq_float(q4[z],qtmp[z]) );
	CHECK( eq_float(q4[w],qtmp[w]) );

	// Quaternion to Matrix
	Mat4 M3;
	M3.set(q4);
	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_X_PI_Constructor, TestConfig::ALL)
{
#if Quat_X_PI_Constructor

	// Special Type Constructor:
	Quat q5(Rot1::X, MATH_PI);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::X, MATH_PI);
	qtmp.set( M2 );

	CHECK( eq_float(q5[x],qtmp[x]) );
	CHECK( eq_float(q5[y],qtmp[y]) );
	CHECK( eq_float(q5[z],qtmp[z]) );
	CHECK( eq_float(q5[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q5);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Y_PI2_Constructor, TestConfig::ALL)
{
#if Quat_Y_PI2_Constructor

	// Special Type Constructor:
	Quat q6(Rot1::Y, MATH_PI2);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Y, MATH_PI2);
	qtmp.set( M2 );
	CHECK( eq_float(q6[x],qtmp[x]) );
	CHECK( eq_float(q6[y],qtmp[y]) );
	CHECK( eq_float(q6[z],qtmp[z]) );
	CHECK( eq_float(q6[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q6);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Y_PI_Constructor, TestConfig::ALL)
{
#if Quat_Y_PI_Constructor

	// Special Type Constructor:
	Quat q7(Rot1::Y, MATH_PI);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Y, MATH_PI);
	qtmp.set( M2 );
	CHECK( eq_float(q7[x],qtmp[x]) );
	CHECK( eq_float(q7[y],qtmp[y]) );
	CHECK( eq_float(q7[z],qtmp[z]) );
	CHECK( eq_float(q7[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q7);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Z_PI2_Constructor, TestConfig::ALL)
{
#if Quat_Z_PI2_Constructor

	// Special Type Constructor:
	Quat q8(Rot1::Z, MATH_PI2);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Z, MATH_PI2);
	qtmp.set( M2 );
	CHECK( eq_float(q8[x],qtmp[x]) );
	CHECK( eq_float(q8[y],qtmp[y]) );
	CHECK( eq_float(q8[z],qtmp[z]) );
	CHECK( eq_float(q8[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q8);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Z_PI_Constructor, TestConfig::ALL)
{
#if Quat_Z_PI_Constructor

	// Special Type Constructor:
	Quat q9(Rot1::Z,MATH_PI);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Z,MATH_PI);
	qtmp.set( M2 );
	CHECK( eq_float(q9[x],qtmp[x]) );
	CHECK( eq_float(q9[y],qtmp[y]) );
	CHECK( eq_float(q9[z],qtmp[z]) );
	CHECK( eq_float(q9[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q9);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_X_Constructor, TestConfig::ALL)
{
#if Quat_X_Constructor

	// Rot_X Type Constructor:
	Quat Qx(Rot1::X, MATH_PI3);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::X, MATH_PI3);	
	qtmp.set( M2 );
	CHECK( eq_float(Qx[x],qtmp[x]) );
	CHECK( eq_float(Qx[y],qtmp[y]) );
	CHECK( eq_float(Qx[z],qtmp[z]) );
	CHECK( eq_float(Qx[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qx);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Y_Constructor, TestConfig::ALL)
{
#if Quat_Y_Constructor

	// Rot_Y Type Constructor:
	Quat Qy(Rot1::Y, MATH_PI3);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Y, MATH_PI3);	
	qtmp.set( M2 );
	CHECK( eq_float(Qy[x],qtmp[x]) );
	CHECK( eq_float(Qy[y],qtmp[y]) );
	CHECK( eq_float(Qy[z],qtmp[z]) );
	CHECK( eq_float(Qy[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qy);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Z_Constructor, TestConfig::ALL)
{
#if Quat_Z_Constructor

	// Rot_Z Type Constructor:
	Quat Qz(Rot1::Z, MATH_PI3);

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;
	M2.set(Rot1::Z, MATH_PI3);	
	qtmp.set( M2 );
	CHECK( eq_float(Qz[x],qtmp[x]) );
	CHECK( eq_float(Qz[y],qtmp[y]) );
	CHECK( eq_float(Qz[z],qtmp[z]) );
	CHECK( eq_float(Qz[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qz);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_XY_Constructor, TestConfig::ALL)
{
#if Quat_XY_Constructor

	// Rot_XY Type Constructor:
	Quat Qx(Rot1::X, MATH_PI3);
	Quat Qy(Rot1::Y, MATH_PI4);

	Quat Qxy;
	Qxy = Qx * Qy;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot My(Rot1::Y, MATH_PI4);
	M2 = Mx * My;

	qtmp.set( M2 );
	CHECK( eq_float(Qxy[x],qtmp[x]) );
	CHECK( eq_float(Qxy[y],qtmp[y]) );
	CHECK( eq_float(Qxy[z],qtmp[z]) );
	CHECK( eq_float(Qxy[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qxy);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_XZ_Constructor, TestConfig::ALL)
{
#if Quat_XZ_Constructor

	// Rot_XZ Type Constructor:
	Quat Qx(Rot1::X, MATH_PI3);
	Quat Qz(Rot1::Z, MATH_PI4);
	Quat Qxz;
	
	Qxz = Qx * Qz;

	// Rot to Quaternion
	Rot M2, M3;
	Quat qtmp;
	Rot Mx(Rot1::X, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_PI4);	
	M2 = Mx * Mz;

	qtmp.set( M2 );
	CHECK( eq_float(Qxz[x],qtmp[x]) );
	CHECK( eq_float(Qxz[y],qtmp[y]) );
	CHECK( eq_float(Qxz[z],qtmp[z]) );
	CHECK( eq_float(Qxz[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qxz);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_YX_Constructor, TestConfig::ALL)
{
#if Quat_YX_Constructor

	// Rot_YX Type Constructor:
	Quat Qy(Rot1::Y, MATH_PI3);
	Quat Qx(Rot1::X, MATH_PI4);
	Quat Qyx = Qy * Qx;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mx(Rot1::X, MATH_PI4);	
	M2 = My * Mx;

	qtmp.set( M2 );
	CHECK( eq_float(Qyx[x],qtmp[x]) );
	CHECK( eq_float(Qyx[y],qtmp[y]) );
	CHECK( eq_float(Qyx[z],qtmp[z]) );
	CHECK( eq_float(Qyx[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qyx);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_YZ_Constructor, TestConfig::ALL)
{
#if Quat_YZ_Constructor

	// Rot_YZ Type Constructor:
	Quat Qy(Rot1::Y, MATH_PI3);
	Quat Qz(Rot1::Z, MATH_PI4);
	Quat Qyz = Qy * Qz;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mz(Rot1::Z, MATH_PI4);	
	M2 = My * Mz;

	qtmp.set( M2 );
	CHECK( eq_float(Qyz[x],qtmp[x]) );
	CHECK( eq_float(Qyz[y],qtmp[y]) );
	CHECK( eq_float(Qyz[z],qtmp[z]) );
	CHECK( eq_float(Qyz[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qyz);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ZX_Constructor, TestConfig::ALL)
{
#if Quat_ZX_Constructor

	// Rot_ZX Type Constructor:
	Quat Qz(Rot1::Z, MATH_PI3);
	Quat Qx(Rot1::X, MATH_PI4);
	Quat Qzx =Qz * Qx;

	 // Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot Mx(Rot1::X, MATH_PI4);	
	M2 = Mz * Mx;

	qtmp.set( M2 );
	CHECK( eq_float(Qzx[x],qtmp[x]) );
	CHECK( eq_float(Qzx[y],qtmp[y]) );
	CHECK( eq_float(Qzx[z],qtmp[z]) );
	CHECK( eq_float(Qzx[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qzx);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ZY_Constructor, TestConfig::ALL)
{
#if Quat_ZY_Constructor

	// Rot_ZY Type Constructor:
	Quat Qz(Rot1::Z, MATH_PI3);
	Quat Qy(Rot1::Y, MATH_PI4);
	Quat Qzy =Qz * Qy;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot My(Rot1::Y, MATH_PI4);	
	M2 = Mz * My;

	qtmp.set( M2 );
	CHECK( eq_float(Qzy[x],qtmp[x]) );
	CHECK( eq_float(Qzy[y],qtmp[y]) );
	CHECK( eq_float(Qzy[z],qtmp[z]) );
	CHECK( eq_float(Qzy[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qzy);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_XYZ_Constructor, TestConfig::ALL)
{
#if Quat_XYZ_Constructor

	// Rot_XYZ Type Constructor:
	Quat Qx(Rot1::X, MATH_PI3 );
	Quat Qy(Rot1::Y, MATH_5PI8);
	Quat Qz(Rot1::Z, MATH_PI4 );
	Quat Qxyz = Qx * Qy * Qz;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot My(Rot1::Y,  MATH_5PI8);
	Rot Mz(Rot1::Z,  MATH_PI4 );
	M2 = Mx * My * Mz;

	qtmp.set( M2 );
	CHECK( eq_float(Qxyz[x],qtmp[x]) );
	CHECK( eq_float(Qxyz[y],qtmp[y]) );
	CHECK( eq_float(Qxyz[z],qtmp[z]) );
	CHECK( eq_float(Qxyz[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qxyz);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_XZY_Constructor, TestConfig::ALL)
{
#if Quat_XZY_Constructor

	// Rot_XZY Type Constructor:
	Quat Qx(Rot1::X, MATH_PI3 );
	Quat Qz(Rot1::Z, MATH_5PI8);
	Quat Qy(Rot1::Y, MATH_PI4 );
	Quat Qxzy = Qx * Qz * Qy;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mx(Rot1::X, MATH_PI3);
	Rot Mz(Rot1::Z,  MATH_5PI8);
	Rot My(Rot1::Y,  MATH_PI4 );
	M2 = Mx * Mz * My;

	qtmp.set( M2 );
	CHECK( eq_float(Qxzy[x],qtmp[x]) );
	CHECK( eq_float(Qxzy[y],qtmp[y]) );
	CHECK( eq_float(Qxzy[z],qtmp[z]) );
	CHECK( eq_float(Qxzy[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qxzy);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_YXZ_Constructor, TestConfig::ALL)
{
#if Quat_YXZ_Constructor

	// Rot_YXZ Type Constructor:
	Quat Qy(Rot1::Y, MATH_PI3 );
	Quat Qx(Rot1::X, MATH_5PI8);
	Quat Qz(Rot1::Z, MATH_PI4 );
	Quat Qyxz = Qy * Qx * Qz;

	CHECK(eq_float(Qyxz[x], 0.5589f));
	CHECK(eq_float(Qyxz[y], 0.5322f));
	CHECK(eq_float(Qyxz[z], 0.5682f));
	CHECK(eq_float(Qyxz[w], 0.2854f));

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mx(Rot1::X,  MATH_5PI8);
	Rot Mz(Rot1::Z,  MATH_PI4 );
	M2 = My * Mx * Mz;

	qtmp.set( M2 );
	CHECK( eq_float(Qyxz[x],qtmp[x]) );
	CHECK( eq_float(Qyxz[y],qtmp[y]) );
	CHECK( eq_float(Qyxz[z],qtmp[z]) );
	CHECK( eq_float(Qyxz[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qyxz);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_YZX_Constructor, TestConfig::ALL)
{
#if Quat_YZX_Constructor

	// Rot_YZX Type Constructor:
	Quat Qy(Rot1::Y, MATH_PI3 );
	Quat Qz(Rot1::Z, MATH_5PI8);
	Quat Qx(Rot1::X, MATH_PI4 );
	Quat Qyzx = Qy * Qz * Qx;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot My(Rot1::Y, MATH_PI3);
	Rot Mz(Rot1::Z,  MATH_5PI8);
	Rot Mx(Rot1::X,  MATH_PI4 );
	M2 = My * Mz * Mx;

	qtmp.set( M2 );
	CHECK( eq_float(Qyzx[x],qtmp[x]) );
	CHECK( eq_float(Qyzx[y],qtmp[y]) );
	CHECK( eq_float(Qyzx[z],qtmp[z]) );
	CHECK( eq_float(Qyzx[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qyzx);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ZXY_Constructor, TestConfig::ALL)
{
#if Quat_ZXY_Constructor

	// Rot_ZXY Type Constructor:
	Quat Qz(Rot1::Z, MATH_PI3 );
	Quat Qx(Rot1::X, MATH_5PI8);
	Quat Qy(Rot1::Y, MATH_PI4 );
	Quat Qzxy = Qz * Qx * Qy;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot Mx(Rot1::X,  MATH_5PI8);
	Rot My(Rot1::Y,  MATH_PI4 );
	M2 = Mz * Mx * My;

	qtmp.set( M2 );
	CHECK( eq_float(Qzxy[x],qtmp[x]) );
	CHECK( eq_float(Qzxy[y],qtmp[y]) );
	CHECK( eq_float(Qzxy[z],qtmp[z]) );
	CHECK( eq_float(Qzxy[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qzxy);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ZYX_Constructor, TestConfig::ALL)
{
#if Quat_ZYX_Constructor

	// Rot_ZYX Type Constructor:
	Quat Qz(Rot1::Z, MATH_PI3 );
	Quat Qy(Rot1::Y, MATH_5PI8);
	Quat Qx(Rot1::X, MATH_PI4 );
	Quat Qzyx = Qz * Qy * Qx;

	// Rot to Quaternion
	Rot M2,M3;
	Quat qtmp;

	Rot Mz(Rot1::Z, MATH_PI3);
	Rot My(Rot1::Y,  MATH_5PI8);
	Rot Mx(Rot1::X,  MATH_PI4 );
	M2 = Mz * My * Mx;

	qtmp.set( M2 );
	CHECK( eq_float(Qzyx[x],qtmp[x]) );
	CHECK( eq_float(Qzyx[y],qtmp[y]) );
	CHECK( eq_float(Qzyx[z],qtmp[z]) );
	CHECK( eq_float(Qzyx[w],qtmp[w]) );

	// Quaternion to Rot
	M3.set(Qzyx);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST(Quat_AXIS_ANGLE_Constructor, TestConfig::ALL)
{
#if Quat_AXIS_ANGLE_Constructor

	// Axis and Angle Type Constructor:
	Vec3  v11( 2.0f, 53.0f, 24.0f);
	Quat Qa1(Axis::AxisAngle, v11, MATH_PI3 );

	// Matrix to Quaternion
	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Axis::AxisAngle, v11, MATH_PI3 );

	qtmp.set( M2 );
	CHECK( eq_float(Qa1[x],qtmp[x]) );
	CHECK( eq_float(Qa1[y],qtmp[y]) );
	CHECK( eq_float(Qa1[z],qtmp[z]) );
	CHECK( eq_float(Qa1[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(Qa1);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ROT_ORIENT_Constructor, TestConfig::ALL)
{
#if Quat_ROT_ORIENT_Constructor

	// Orientation Type Constructor:

	Vec3  v15( 2.0f, 53.0f, 24.0f);
	Vec3  v16( 0.0f, -24.0f, 53.0f);
	Quat q56(Orient::LocalToWorld, v15, v16 );

	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Orient::LocalToWorld, v15, v16 );
	qtmp.set( M2 );
	CHECK( eq_float(q56[x],qtmp[x]) );
	CHECK( eq_float(q56[y],qtmp[y]) );
	CHECK( eq_float(q56[z],qtmp[z]) );
	CHECK( eq_float(q56[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q56);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_ROT_INVERSE_ORIENT_Constructor, TestConfig::ALL)
{
#if Quat_ROT_INVERSE_ORIENT_Constructor

	// Orientation Type Constructor:
	Vec3  v17( 2.0f, 53.0f, 24.0f);
	Vec3  v18( 0.0f, -24.0f, 53.0f);
	Quat q57(Orient::WorldToLocal, v17, v18 );

	Rot M2;
	Mat4 M3;
	Quat qtmp;

	M2.set(Orient::WorldToLocal, v17, v18 );
	qtmp.set( M2 );
	CHECK( eq_float(q57[x],qtmp[x]) );
	CHECK( eq_float(q57[y],qtmp[y]) );
	CHECK( eq_float(q57[z],qtmp[z]) );
	CHECK( eq_float(q57[w],qtmp[w]) );

	// Quaternion to Matrix
	M3.set(q57);

	CHECK( eq_float(M2[m0],M3[m0]) );
	CHECK( eq_float(M2[m1],M3[m1]) );
	CHECK( eq_float(M2[m2],M3[m2]) );
	CHECK( eq_float(M2[m3],M3[m3]) );
	CHECK( eq_float(M2[m4],M3[m4]) );
	CHECK( eq_float(M2[m5],M3[m5]) );
	CHECK( eq_float(M2[m6],M3[m6]) );
	CHECK( eq_float(M2[m7],M3[m7]) );
	CHECK( eq_float(M2[m8],M3[m8]) );
	CHECK( eq_float(M2[m9],M3[m9]) );
	CHECK( eq_float(M2[m10],M3[m10]) );
	CHECK( eq_float(M2[m11],M3[m11]) );
	CHECK( eq_float(M2[m12],M3[m12]) );
	CHECK( eq_float(M2[m13],M3[m13]) );
	CHECK( eq_float(M2[m14],M3[m14]) );
	CHECK( eq_float(M2[m15],M3[m15]) );

#endif
} TEST_END



TEST( Quat_Destructor, TestConfig::ALL)
{
#if Quat_Destructor

	// Destructor

	Quat qDstr( Identity );

	Quat *pMdstr = &qDstr;

	pMdstr->~Quat();

	CHECK(1);

#endif
}  TEST_END



// ---  End of File ---------------
