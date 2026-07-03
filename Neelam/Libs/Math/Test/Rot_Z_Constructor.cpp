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

TEST(Rot_Z_Constructor, TestConfig::ALL)
{
#if Rot_Z_Constructor

	Rot Rz(Rot1::Z, 1.0471975512f);

	CHECK(eq_float(Rz[m0], 0.5f));
	CHECK(eq_float(Rz[m1], 0.866f));
	CHECK(Rz[m2] == 0.0f);
	CHECK(Rz[m3] == 0.0f);
	CHECK(eq_float(Rz[m4], -0.866f));
	CHECK(eq_float(Rz[m5], 0.5f));
	CHECK(Rz[m6] == 0.0f);
	CHECK(Rz[m7] == 0.0f);
	CHECK(Rz[m8] == 0.0f);
	CHECK(Rz[m9] == 0.0f);
	CHECK(Rz[m10] == 1.0f);
	CHECK(Rz[m11] == 0.0f);
	CHECK(Rz[m12] == 0.0f);
	CHECK(Rz[m13] == 0.0f);
	CHECK(Rz[m14] == 0.0f);
	CHECK(eq_float(Rz[m15],1.0f));

#endif
} TEST_END

// --- End of File ---
