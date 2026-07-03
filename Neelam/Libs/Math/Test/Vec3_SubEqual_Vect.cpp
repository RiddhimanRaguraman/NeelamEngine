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
#if Vec3_SubEqual_Vect

bool Vec3_SubEqual_Vect_REF_TEST(Vec3 &r)
{
	AZUL_UNUSED_VAR(r);
	return true;
}

#endif

TEST(Vec3_SubEqual_Vect, TestConfig::ALL)
{
#if Vec3_SubEqual_Vect

	Vec3 A(2.0f, 3.0f, 4.0f);
	Vec3 B(21.0f, 31.0f, 41.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);

	CHECK(B[x] == 21.0f);
	CHECK(B[y] == 31.0f);
	CHECK(B[z] == 41.0f);

	//B -= A;
	bool status = Vec3_SubEqual_Vect_REF_TEST(B -= A);
	CHECK(status == true);

	CHECK(B[x] == 19.0f);
	CHECK(B[y] == 28.0f);
	CHECK(B[z] == 37.0f);

	CHECK(A[x] == 2.0f);
	CHECK(A[y] == 3.0f);
	CHECK(A[z] == 4.0f);

#endif

} TEST_END

// ---  End of File ---------------
