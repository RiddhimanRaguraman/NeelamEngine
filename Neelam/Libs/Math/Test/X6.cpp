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

TEST(X6_qW_Accessor_Write, TestConfig::ALL)
{
#if X6_qW_Accessor_Write

	Quat A(Rot1::X, MATH_PI2);

	CHECK(eq_float(A.qx(), 0.7071f));
	CHECK(eq_float(A.qy(), 0.0f));
	CHECK(eq_float(A.qz(), 0.0f));
	CHECK(eq_float(A.qw(), 0.7071f));
	CHECK(eq_float(A.real(), 0.7071f));
	CHECK(eq_float(A.qw(), A.real()));

	A.qw(0.2345f);
	CHECK(eq_float(A.real(), 0.2345f));
	CHECK(eq_float(A.qw(), A.real()));

	CHECK(eq_float(A.qx(), 0.7071f));
	CHECK(eq_float(A.qy(), 0.0f));
	CHECK(eq_float(A.qz(), 0.0f));

	A.real(-0.1234f);
	CHECK(eq_float(A.real(), -0.1234f));
	CHECK(eq_float(A.qw(), A.real()));

	CHECK(eq_float(A.qx(), 0.7071f));
	CHECK(eq_float(A.qy(), 0.0f));
	CHECK(eq_float(A.qz(), 0.0f));


#endif
} TEST_END

// ---  End of File ---------------
