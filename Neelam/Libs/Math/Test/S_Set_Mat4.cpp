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

TEST(S_Set_Mat4, TestConfig::ALL)
{
#if S_Set_Mat4

	Rot A(Rot1::X, -0.45f);
	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	Scale B(2,3,4);
	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	Mat4 &AA = A;
	Mat4 &BB = B;

	h = ((Mat4Hint &)AA).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	h = ((Mat4Hint &)BB).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	AA.set(BB);

	h = ((Mat4Hint &)AA).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)BB).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)B).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
