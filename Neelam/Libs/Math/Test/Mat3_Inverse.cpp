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

TEST( Mat3_Inverse, TestConfig::ALL)
{
#if Mat3_Inverse

	Rot Rx(Rot1::X, 0.23f);
	Rot Ry(Rot1::Y, -1.23f);
	Trans T(3.4f, 2.9f, -9.0f);

	Mat4 M0	= Rx * Ry * T;
	Mat3 M(M0);

	Mat3 N(M);

	M.inv();

	Mat3 C;
	C = N * M;

	// verify C is identity

	const bool flag = C.isIdentity(MATH_TOLERANCE);

	CHECK(flag == true);

#endif
} TEST_END

// ---  End of File ---
