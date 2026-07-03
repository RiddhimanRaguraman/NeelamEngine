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

TEST(S_Set_T0, TestConfig::ALL)
{
#if S_Set_T0
	Rot A(Rot1::X, -0.45f);
	Scale S(2, 3, 4);
	Mat4 M = A * S;

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	h = ((Mat4Hint &)S).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	M.T();

	h = ((Mat4Hint &)M).GetHint();
	CHECK(h == Mat4Hint::Hint::RotScale);

	h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);
	
	h = ((Mat4Hint &)S).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
