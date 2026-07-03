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

TEST(S_Set_Vec4, TestConfig::ALL)
{
#if S_Set_Vec4
	Rot A(Rot1::X, -0.45f);

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	Vec4 v0(1, 2, 3, 4);
	Vec4 v1(2, 3, 4, 5);
	Vec4 v2(3, 4, 5, 6);
	Vec4 v3(4, 5, 6, 7);

	Mat4 &B = A;

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	B.set(v0, v1, v2, v3);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
