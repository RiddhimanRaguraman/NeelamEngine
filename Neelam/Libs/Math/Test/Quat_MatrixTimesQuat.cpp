//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_RotTimesQuat, TestConfig::ALL)
{
#if Quat_RotTimesQuat

	Quat q1, q2;
	Quat out1, out2;
	// Quat * Matrix 
	Rot rxyz, rx, ry, rz, rtmp;
	Quat qxyz, qx, qy, qz, qtmp, qxy;

	rx.set(Rot1::X, MATH_PI3);
	ry.set(Rot1::Y, MATH_7PI8);
	rz.set(Rot1::Z, MATH_PI2);

	rxyz = rx * ry * rz;

	qx.set(Rot1::X, MATH_PI3);
	qy.set(Rot1::Y, MATH_7PI8);
	qz.set(Rot1::Z, MATH_PI2);

	qxyz = qx * qy * qz;
	qtmp.set(rxyz);

	QTEST(qxyz, qtmp);

	rtmp.set(qxyz);
	CHECK(eq_float(rtmp[m0], rxyz[m0]));
	CHECK(eq_float(rtmp[m1], rxyz[m1]));
	CHECK(eq_float(rtmp[m2], rxyz[m2]));
	CHECK(eq_float(rtmp[m3], rxyz[m3]));
	CHECK(eq_float(rtmp[m4], rxyz[m4]));
	CHECK(eq_float(rtmp[m5], rxyz[m5]));
	CHECK(eq_float(rtmp[m6], rxyz[m6]));
	CHECK(eq_float(rtmp[m7], rxyz[m7]));
	CHECK(eq_float(rtmp[m8], rxyz[m8]));
	CHECK(eq_float(rtmp[m9], rxyz[m9]));
	CHECK(eq_float(rtmp[m10], rxyz[m10]));
	CHECK(eq_float(rtmp[m11], rxyz[m11]));
	CHECK(eq_float(rtmp[m12], rxyz[m12]));
	CHECK(eq_float(rtmp[m13], rxyz[m13]));
	CHECK(eq_float(rtmp[m14], rxyz[m14]));
	CHECK(eq_float(rtmp[m15], rxyz[m15]));

	q1 = rx * ry * qz;

	QTEST(q1, qxyz);

	Quat qyz;
	qyz = qy * qz;
	q1 = rx * qyz;

	QTEST(q1, qxyz);

	q1 = rx * (qy * qz);

	QTEST(q1, qxyz);

	q1 = rx * (ry * qz);

	QTEST(q1, qxyz);

#endif
} TEST_END

// --- End of File ---