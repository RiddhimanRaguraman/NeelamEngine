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

TEST(S_Set_Inv_Rot, TestConfig::ALL)
{
#if S_Set_Inv_Rot

	Rot A(Rot1::X,0.45f);
	Mat4 B(A);
	Mat4 M;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	B.inv();

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

#endif
} TEST_END

// ---  End of File ---------------
