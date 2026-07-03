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

TEST(S_Set_Inv_Scale, TestConfig::ALL)
{
#if S_Set_Inv_Scale

	Scale A(2,3,4);
	Scale B(A);
	Mat4 M;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	B.inv();

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	M = A * B;

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
