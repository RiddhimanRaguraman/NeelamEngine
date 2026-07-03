//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_QuatTimesRot, TestConfig::ALL)
{
#if Quat_QuatTimesRot

	Quat q1, q2;
	Quat out1, out2;
	// Quat * Matrix 
	Rot mxyz, mx, my, mz, mtmp;
	Quat qxyz, qx, qy, qz, qtmp, qxy;

	mx.set(Rot1::X, MATH_PI3);
	my.set(Rot1::Y, MATH_7PI8);
	mz.set(Rot1::Z, MATH_PI2);

	mxyz = mx * my * mz;

	qx.set(Rot1::X, MATH_PI3);
	qy.set(Rot1::Y, MATH_7PI8);
	qz.set(Rot1::Z, MATH_PI2);

	qxyz = qx * qy * qz;

	qtmp.set(mxyz);

	QTEST(qxyz, qtmp);

	mtmp.set(qxyz);
	CHECK(eq_float(mtmp[m0], mxyz[m0]));
	CHECK(eq_float(mtmp[m1], mxyz[m1]));
	CHECK(eq_float(mtmp[m2], mxyz[m2]));
	CHECK(eq_float(mtmp[m3], mxyz[m3]));
	CHECK(eq_float(mtmp[m4], mxyz[m4]));
	CHECK(eq_float(mtmp[m5], mxyz[m5]));
	CHECK(eq_float(mtmp[m6], mxyz[m6]));
	CHECK(eq_float(mtmp[m7], mxyz[m7]));
	CHECK(eq_float(mtmp[m8], mxyz[m8]));
	CHECK(eq_float(mtmp[m9], mxyz[m9]));
	CHECK(eq_float(mtmp[m10], mxyz[m10]));
	CHECK(eq_float(mtmp[m11], mxyz[m11]));
	CHECK(eq_float(mtmp[m12], mxyz[m12]));
	CHECK(eq_float(mtmp[m13], mxyz[m13]));
	CHECK(eq_float(mtmp[m14], mxyz[m14]));
	CHECK(eq_float(mtmp[m15], mxyz[m15]));

	// => q1 = qx * my * mz
	q1 = qx * my * mz;

	QTEST(q1, qxyz);

	// => qxy = qx * qy
	// => q1 = qxy * mz
	qxy = qx * qy;
	q1 = qxy * mz;

	QTEST(q1, qxyz);

	// => q1 = (qx * qy) * mz
	q1 = (qx * qy) * mz;

	QTEST(q1, qxyz);

	// => q1 = qx * (qy * mz)
	q1 = qx * (qy * mz);

	QTEST(q1, qxyz);

#endif
} TEST_END

// --- End of File ---