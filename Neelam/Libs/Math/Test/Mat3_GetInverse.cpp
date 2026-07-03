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

TEST(Mat3_GetInverse, TestConfig::ALL)
{
#if Mat3_GetInverse

	Rot Rx(Rot1::X, 0.23f);
	Rot Ry(Rot1::Y, -1.23f);
	Scale S(4.0f, 5.0f, 2.0f);
	Trans T(-2.3f, 7.9f, 9.03f);

	Mat4 M0 = S * T * Rx * Ry * S;

	Mat3 M(M0);
	Mat3 N;

	N = M.getInv();

	Mat3 C;
	C = N * M;

	// verify C is identity
	const bool flag = C.isIdentity(MATH_TOLERANCE);

	CHECK(flag == true);

#endif
} TEST_END

// ---  End of File ---
