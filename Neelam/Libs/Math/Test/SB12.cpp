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

TEST(S12_Hint_bracket_M12, TestConfig::ALL)
{
#if S12_Hint_bracket_M12
	Rot A(Rot1::X, -0.45f);

	Mat4Hint::Hint h = ((Mat4Hint &)A).GetHint();
	CHECK(h == Mat4Hint::Hint::Rot);

	A[m12] = 11.0f;

	h = ((Mat4Hint &)A).GetHint();

	CHECK(h == Mat4Hint::Hint::Generalize);
	
#endif
} TEST_END

// ---  End of File ---------------
