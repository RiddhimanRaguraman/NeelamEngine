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

TEST(Rot_Times_Quat, TestConfig::ALL)
{
#if Rot_Times_Quat

	Rot R1(Rot3::ZXY, MATH_PI3, -MATH_2PI8, MATH_2PI3);
	
	CHECK( eq_float(R1[m0],-0.8838f) );
	CHECK( eq_float(R1[m1], 0.4330f) );
	CHECK( eq_float(R1[m2], 0.1767f) );
	CHECK( (R1[m3] == 0.0f) );
	CHECK( eq_float(R1[m4], -0.3061f) );
	CHECK( eq_float(R1[m5], -0.2500f) );
	CHECK( eq_float(R1[m6], -0.9185f) );
	CHECK( (R1[m7] == 0.0f) );
	CHECK( eq_float(R1[m8], -0.3535f) );
	CHECK( eq_float(R1[m9], -0.8660f) );
	CHECK( eq_float(R1[m10], 0.3535f) );
	CHECK( (R1[m11] == 0.0f) );
	CHECK( (R1[m12] == 0.0f) );
	CHECK( (R1[m13] == 0.0f) );
	CHECK( (R1[m14] == 0.0f) );
	CHECK( eq_float(R1[m15],1.0f) );

	Quat Q2(Rot3::YXZ, -MATH_PI3, MATH_PI8, MATH_3PI4);

	CHECK(eq_float(Q2[x], -0.34375f));
	CHECK(eq_float(Q2[y], -0.38840f));
	CHECK(eq_float(Q2[z],  0.74740f));
	CHECK(eq_float(Q2[w],  0.41516f));

	Rot C;
	C = R1 * Q2;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	CHECK(eq_float(R1[m0], -0.8838f));
	CHECK(eq_float(R1[m1], 0.4330f));
	CHECK(eq_float(R1[m2], 0.1767f));
	CHECK((R1[m3] == 0.0f));
	CHECK(eq_float(R1[m4], -0.3061f));
	CHECK(eq_float(R1[m5], -0.2500f));
	CHECK(eq_float(R1[m6], -0.9185f));
	CHECK((R1[m7] == 0.0f));
	CHECK(eq_float(R1[m8], -0.3535f));
	CHECK(eq_float(R1[m9], -0.8660f));
	CHECK(eq_float(R1[m10], 0.3535f));
	CHECK((R1[m11] == 0.0f));
	CHECK((R1[m12] == 0.0f));
	CHECK((R1[m13] == 0.0f));
	CHECK((R1[m14] == 0.0f));
	CHECK(eq_float(R1[m15], 1.0f));

	CHECK(eq_float(Q2[x], -0.34375f));
	CHECK(eq_float(Q2[y], -0.38840f));
	CHECK(eq_float(Q2[z], 0.74740f));
	CHECK(eq_float(Q2[w], 0.41516f));

	CHECK(eq_float(C[m0],  0.06934f));
	CHECK(eq_float(C[m1], -0.98982f));
	CHECK(eq_float(C[m2], -0.12421f));
	CHECK((C[m3] == 0.0f));
	CHECK(eq_float(C[m4],  0.9849f));
	CHECK(eq_float(C[m5],  0.0877f));
	CHECK(eq_float(C[m6], -0.1492f));
	CHECK((C[m7] == 0.0f));
	CHECK(eq_float(C[m8],  0.1586f));
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
