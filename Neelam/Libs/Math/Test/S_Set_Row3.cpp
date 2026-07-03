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

TEST(S_Set_Row3, TestConfig::ALL)
{
#if S_Set_Row3
	Rot A(Rot1::X, -0.45f);

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	Vec4 v3(1, 2, 3, 4);

	Mat4 &B = A;

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	B.set(Row4::i3, v3);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

	h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
