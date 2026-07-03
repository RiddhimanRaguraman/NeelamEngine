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
#if Vec4_ScaleEquals

bool Vec4_ScaleEquals_REF_TEST(Vec4 &r)
{
	AZUL_UNUSED_VAR(r);
	return true;
}

#endif

TEST(Vec4_ScaleEquals, TestConfig::ALL)
{
#if Vec4_ScaleEquals

	Vec4 A(2.0f, 3.0f, 4.0f, 5.0f);
	const float s = 5.0f;

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);
	CHECK(A[w] == 5.0f);

	//A *= s;
	bool status = Vec4_ScaleEquals_REF_TEST(A *= s);
	CHECK(status == true);

	CHECK(A[x] == 10.0f);
	CHECK(A[y] == 15.0f);
	CHECK(A[z] == 20.0f);
	CHECK(A[w] == 25.0f);

#endif
} TEST_END

// ---  End of File ---------------
