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

TEST(Yahtzee, TestConfig::ALL)
{
#if	Yahtzee

	Trans T1(3, 4, 5);

	CHECK(T1[m0] == 1.0f);
	CHECK(T1[m1] == 0.0f);
	CHECK(T1[m2] == 0.0f);
	CHECK(T1[m3] == 0.0f);
	CHECK(T1[m4] == 0.0f);
	CHECK(T1[m5] == 1.0f);
	CHECK(T1[m6] == 0.0f);
	CHECK(T1[m7] == 0.0f);
	CHECK(T1[m8] == 0.0f);
	CHECK(T1[m9] == 0.0f);
	CHECK(T1[m10] == 1.0f);
	CHECK(T1[m11] == 0.0f);
	CHECK(T1[m12] == 3.0f);
	CHECK(T1[m13] == 4.0f);
	CHECK(T1[m14] == 5.0f);
	CHECK(eq_float(T1[m15], 1.0f));

	Scale S1(3, 4, 5);

	CHECK(S1[m0] == 3.0f);
	CHECK(S1[m1] == 0.0f);
	CHECK(S1[m2] == 0.0f);
	CHECK(S1[m3] == 0.0f);
	CHECK(S1[m4] == 0.0f);
	CHECK(S1[m5] == 4.0f);
	CHECK(S1[m6] == 0.0f);
	CHECK(S1[m7] == 0.0f);
	CHECK(S1[m8] == 0.0f);
	CHECK(S1[m9] == 0.0f);
	CHECK(S1[m10] == 5.0f);
	CHECK(S1[m11] == 0.0f);
	CHECK(S1[m12] == 0.0f);
	CHECK(S1[m13] == 0.0f);
	CHECK(S1[m14] == 0.0f);
	CHECK(eq_float(S1[m15], 1.0f));

	// Rot_X Type Constructor:
	Rot Rx(Rot1::X, MATH_PI3);

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
	CHECK(eq_float(Rx[m15], 1.0f));

	Rot Ry(Rot1::Y, MATH_7PI8);

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
	CHECK(eq_float(Ry[m15], 1.0f));

	Rot Rz(Rot1::Z, MATH_PI2);

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
	CHECK(eq_float(Rz[m15], 1.0f));


	Quat Qy(Rot1::Y, MATH_PI3);
	Quat Qx(Rot1::X, MATH_5PI8);
	Quat Qz(Rot1::Z, MATH_PI4);

	Quat Qyxz = Qy * Qx * Qz;
	Quat QA(Rot3::YXZ, MATH_5PI8, MATH_PI3, MATH_PI4);

	QTEST(Qyxz, QA);

	CHECK(eq_float(Qyxz[x], 0.5589f));
	CHECK(eq_float(Qyxz[y], 0.5322f));
	CHECK(eq_float(Qyxz[z], 0.5682f));
	CHECK(eq_float(Qyxz[w], 0.2854f));

	//Mat4 M1 = S1 * Qy *Rx *Ry *T1 *QA *S1 *S1;
	Mat4 M1;
	//M1.Print("M1");
	M1 = S1 * Qy;
	//M1.Print("M1 = S1 * Qy");
	M1 = S1 * Qy * Rx;
	//M1.Print("M1 = S1 * Qy * Rx");
	M1 = S1 * Qy * Rx * Ry;
	//M1.Print("M1 = S1 * Qy * Rx * Ry");
	M1 = S1 * Qy * Rx * Ry * T1;
	//M1.Print("M1 = S1 * Qy * Rx * Ry * T1");
	M1 = S1 * Qy * Rx * Ry * T1 * QA;
	//M1.Print("M1 = S1 * Qy * Rx * Ry * T1 * QA");
	M1 = S1 * Qy * Rx * Ry * T1 * QA * S1;
	//M1.Print("M1 = S1 * Qy * Rx * Ry * T1 * QA * S1");
	M1 = S1 * Qy * Rx * Ry * T1 * QA * S1 * S1;
	//M1.Print("M1 = S1 * Qy * Rx * Ry * T1 * QA * S1 * S1");
	M1 *= Scale(0.1f,0.1f,0.1f);
	//M1.Print("m1");

	Mat4Hint::Hint h = ((Mat4Hint &)M1).GetHint();
	CHECK(h == Mat4Hint::Hint::Affine);

	CHECK(eq_float(M1[m0] , 1.4367f));
	CHECK(eq_float(M1[m1] , -3.4575f));
	CHECK(eq_float(M1[m2] , 3.3372f));
	CHECK(eq_float(M1[m3] , 0.0f));
	CHECK(eq_float(M1[m4] , -2.4708f));
	CHECK(eq_float(M1[m5] , -0.37915f));
	CHECK(eq_float(M1[m6] , 7.2487f));
	CHECK(eq_float(M1[m7] , 0.0f));
	CHECK(eq_float(M1[m8] , -2.231f));
	CHECK(eq_float(M1[m9] , -5.5289f));
	CHECK(eq_float(M1[m10], -6.5738f));
	CHECK(eq_float(M1[m11], 0.0f));
	CHECK(eq_float(M1[m12], 4.6268f));
	CHECK(eq_float(M1[m13], 4.9667f));
	CHECK(eq_float(M1[m14], 9.3326f));
	CHECK(eq_float(M1[m15], 1.0f));

	//M2 = S1 * Rz * M1 * T1 * Qz * S1 * T1;
	Mat4 M2;
	//M2.Print("M2");
	M2 = S1 * Rz;
	//M2.Print("M2 = S1 * Rz");
	M2 = S1 * Rz * M1;
	//M2.Print("M2 = S1 * Rz * M1");
	M2 = S1 * Rz * M1 * T1;
	//M2.Print("M2 = S1 * Rz * M1 * T1");
	M2 = S1 * Rz * M1 * T1 * Qz;
	//M2.Print("M2 = S1 * Rz * M1 * T1 * Qz");
	M2 = S1 * Rz * M1 * T1 * Qz * S1;
	//M2.Print("M2 = S1 * Rz * M1 * T1 * Qz * S1");
	M2 = S1 * Rz * M1 * T1 * Qz * S1 * T1;
	//M2.Print("M2 = S1 * Rz * M1 * T1 * Qz * S1 * T1");

	CHECK(eq_float(M2[m0], -13.3113f));
	CHECK(eq_float(M2[m1], -24.1827f));
	CHECK(eq_float(M2[m2], 108.73f));
	CHECK(eq_float(M2[m3], 0.0f));
	CHECK(eq_float(M2[m4], -41.529f));
	CHECK(eq_float(M2[m5], 22.8627f));
	CHECK(eq_float(M2[m6], -66.7446f));
	CHECK(eq_float(M2[m7], 0.0f));
	CHECK(eq_float(M2[m8], 34.9796f));
	CHECK(eq_float(M2[m9], -109.741f));
	CHECK(eq_float(M2[m10], -164.345f));
	CHECK(eq_float(M2[m11], 0.0f));
	CHECK(eq_float(M2[m12], 0.157513f));
	CHECK(eq_float(M2[m13], 50.9336f));
	CHECK(eq_float(M2[m14], 76.6634f));
	CHECK(eq_float(M2[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
