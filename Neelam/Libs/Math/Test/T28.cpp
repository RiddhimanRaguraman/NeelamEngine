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

TEST(Quat_TimesEqual_Quat, TestConfig::ALL)
{
#if	Quat_TimesEqual_Quat

	Quat Q1(Rot3::ZXY, MATH_PI3, -MATH_2PI8, MATH_2PI3);

	CHECK(eq_float(Q1[x], -0.0560f));
	CHECK(eq_float(Q1[y], -0.5657f));
	CHECK(eq_float(Q1[z], 0.7885f));
	CHECK(eq_float(Q1[w], 0.2343f));

	Quat Q2(Rot3::YXZ, -MATH_PI3, MATH_PI8, MATH_3PI4);

	CHECK(eq_float(Q2[x], -0.34375f));
	CHECK(eq_float(Q2[y], -0.38840f));
	CHECK(eq_float(Q2[z], 0.74740f));
	CHECK(eq_float(Q2[w], 0.41516f));

	Quat C;
	Q1 *= Q2;

	CHECK(eq_float(Q2[x], -0.34375f));
	CHECK(eq_float(Q2[y], -0.38840f));
	CHECK(eq_float(Q2[z], 0.74740f));
	CHECK(eq_float(Q2[w], 0.41516f));

	CHECK(eq_float(Q1[x], 0.01273f));
	CHECK(eq_float(Q1[y], -0.09671f));
	CHECK(eq_float(Q1[z], 0.67525f));
	CHECK(eq_float(Q1[w], -0.73110f));

#endif
} TEST_END

// ---  End of File ---------------
