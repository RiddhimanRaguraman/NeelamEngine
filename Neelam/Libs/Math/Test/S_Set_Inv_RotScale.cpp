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

TEST(S_Set_Inv_RotScale, TestConfig::ALL)
{
#if S_Set_Inv_RotScale

	Scale A(2,3,4);
	Rot B(Rot1::Z,0.33f);
	Mat4 M;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	M = A * B;

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	Mat4 N(M);

	h = ((Mat4Hint &)N).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	M.inv();

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	Mat4 L = N * M;

	const bool flag = L.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = ((Mat4Hint &)L).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

#endif
} TEST_END

// ---  End of File ---------------
