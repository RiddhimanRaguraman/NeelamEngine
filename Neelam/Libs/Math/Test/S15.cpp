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

TEST(S15_Hint_M15, TestConfig::ALL)
{
#if S15_Hint_M15
	Rot A(Rot1::X, -0.45f);

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	A.m15(11.0f);

	h = ((Mat4Hint &)A).GetHint();

	CHECK(h == Mat4Hint::Hint::Generalize);
	
#endif
} TEST_END

// ---  End of File ---------------
