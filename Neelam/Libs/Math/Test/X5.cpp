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

TEST(X5_qW_Accessor_Read, TestConfig::ALL)
{
#if X5_qW_Accessor_Read

	Quat A(Rot1::X, MATH_PI2);

	CHECK(eq_float(A.qx(),0.7071f));
	CHECK(eq_float(A.qy(),0.0f));
	CHECK(eq_float(A.qz(),0.0f));
	CHECK(eq_float(A.qw(),0.7071f));
	CHECK(eq_float(A.real(),0.7071f));
	CHECK(eq_float(A.qw(),A.real()));

	Quat B(Rot1::X, -MATH_PI);

	CHECK(eq_float(B.qx(), -1.0f));
	CHECK(eq_float(B.qy(), 0.0f));
	CHECK(eq_float(B.qz(), 0.0f));
	CHECK(eq_float(B.qw(), 0.0f));
	CHECK(eq_float(B.real(), 0.0f));
	CHECK(eq_float(B.qw(), B.real()));

	Quat C(Rot1::X, MATH_2PI3);

	CHECK(eq_float(C.qx(), 0.866f));
	CHECK(eq_float(C.qy(), 0.0f));
	CHECK(eq_float(C.qz(), 0.0f));
	CHECK(eq_float(C.qw(), 0.4999f));
	CHECK(eq_float(C.real(), 0.4999f));
	CHECK(eq_float(C.qw(), C.real()));

	Quat D(Rot1::X, MATH_5PI8);

	CHECK(eq_float(D.qx(), 0.8314f));
	CHECK(eq_float(D.qy(), 0.0f));
	CHECK(eq_float(D.qz(), 0.0f));
	CHECK(eq_float(D.qw(), 0.5555f));
	CHECK(eq_float(D.real(), 0.5555f));
	CHECK(eq_float(D.qw(), D.real()));


#endif
} TEST_END

// ---  End of File ---------------
