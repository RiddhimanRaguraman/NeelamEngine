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

TEST(S_Set_Inv_General, TestConfig::ALL)
{
#if S_Set_Inv_General

	Mat4 A(Vec4(1,2,3,4), Vec4(2,1,5,4), Vec4(9,-2,2,3), Vec4(3,3,3,1));
	Mat4 B(A);
	Mat4 M;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	B.inv();

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
