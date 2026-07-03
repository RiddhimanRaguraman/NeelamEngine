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

TEST(S_Set_Inv_Trans, TestConfig::ALL)
{
#if S_Set_Inv_Trans

	Trans A(2,3,4);
	Trans B(A);
	Mat4 M;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

	B.inv();

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

#endif
} TEST_END

// ---  End of File ---------------
