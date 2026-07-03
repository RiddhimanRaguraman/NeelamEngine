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

TEST(Vec4_Get_Normalize, TestConfig::ALL)
{
#if Vec4_Get_Normalize

	Vec4 v1(1.0f, 2.0f, 3.0f, 5.0f);
	Vec4 v2;

	v2 = v1.getNorm();

	CHECK(eq_float(v2[x], 0.1601f));
	CHECK(eq_float(v2[y], 0.3202f));
	CHECK(eq_float(v2[z], 0.4803f));
	CHECK(eq_float(v2[w], 0.8006f));

	CHECK((v1[x] == 1.0f));
	CHECK((v1[y] == 2.0f));
	CHECK((v1[z] == 3.0f));
	CHECK((v1[w] == 5.0f));
#endif
} TEST_END

// ---  End of File ---------------
