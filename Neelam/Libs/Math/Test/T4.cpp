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

TEST(Rot_Times_Trans, TestConfig::ALL)
{
#if Rot_Times_Trans

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

	Trans T(3,4,5);

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(T[m12] == 3.0f);
	CHECK(T[m13] == 4.0f);
	CHECK(T[m14] == 5.0f);
	CHECK(eq_float(T[m15], 1.0f));

	Mat4 C;
	C = R1 * T;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::RotTrans);

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

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(T[m12] == 3.0f);
	CHECK(T[m13] == 4.0f);
	CHECK(T[m14] == 5.0f);
	CHECK(eq_float(T[m15], 1.0f));

	CHECK(eq_float(C[m0], -0.8838f));
	CHECK(eq_float(C[m1], 0.4330f));
	CHECK(eq_float(C[m2], 0.1767f));
	CHECK((C[m3] == 0.0f));
	CHECK(eq_float(C[m4], -0.3061f));
	CHECK(eq_float(C[m5], -0.2500f));
	CHECK(eq_float(C[m6], -0.9185f));
	CHECK((C[m7] == 0.0f));
	CHECK(eq_float(C[m8], -0.3535f));
	CHECK(eq_float(C[m9], -0.8660f));
	CHECK(eq_float(C[m10], 0.3535f));
	CHECK(eq_float(C[m11],0.0f));
	CHECK(eq_float(C[m12],3.0f));
	CHECK(eq_float(C[m13],4.0f));
	CHECK(eq_float(C[m14],5.0f));
	CHECK(eq_float(C[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
