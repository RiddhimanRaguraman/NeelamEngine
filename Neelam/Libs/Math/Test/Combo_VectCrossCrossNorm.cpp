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

TEST(Combo_VectCrossCrossNorm, TestConfig::ALL)
{
#if Combo_VectCrossCrossNorm

	Vec3 A(1.0f, 2.0f, 3.0f);
	Vec3 B(10.0f, 11.0f, 12.0f);
	Vec3 C;

	CHECK(A[x] == 1.0f);
	CHECK(A[y] == 2.0f);
	CHECK(A[z] == 3.0f);

	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 11.0f);
	CHECK(B[z] == 12.0f);

	C = (A - B).cross(B);
	Vec3 D = C.cross(B);
	D.norm();

	CHECK(eq_float(D[x], 0.74790420f));
	CHECK(eq_float(D[y], 0.04273730f));
	CHECK(eq_float(D[z], -0.6624290f));

	CHECK(C[x] == -9.0f);
	CHECK(C[y] == 18.0f);
	CHECK(C[z] == -9.0f);
	
	CHECK(A[x] == 1.0f);
	CHECK(A[y] == 2.0f);
	CHECK(A[z] == 3.0f);
	
	CHECK(B[x] == 10.0f);
	CHECK(B[y] == 11.0f);
	CHECK(B[z] == 12.0f);

#endif
} TEST_END

// ---  End of File ---
