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

TEST(Rot_Y_Set, TestConfig::ALL)
{
#if Rot_Y_Set

	Rot Ry(Rot1::X, 0.5f);

	CHECK(Ry[m0] == 1.0f);
	CHECK(Ry[m1] == 0.0f);
	CHECK(Ry[m2] == 0.0f);
	CHECK(Ry[m3] == 0.0f);
	CHECK(Ry[m4] == 0.0f);
	CHECK(eq_float(Ry[m5], 0.87758f));
	CHECK(eq_float(Ry[m6], 0.47942f));
	CHECK(Ry[m7] == 0.0f);
	CHECK(Ry[m8] == 0.0f);
	CHECK(eq_float(Ry[m9], -0.47942f));
	CHECK(eq_float(Ry[m10], 0.87758f));
	CHECK(Ry[m11] == 0.0f);
	CHECK(Ry[m12] == 0.0f);
	CHECK(Ry[m13] == 0.0f);
	CHECK(Ry[m14] == 0.0f);
	CHECK(eq_float(Ry[m15], 1.0f));

	Ry.set(Rot1::Y, 1.0471975512f);

	CHECK(eq_float(Ry[m0], 0.5f));
	CHECK(Ry[m1] == 0.0f);
	CHECK(eq_float(Ry[m2], -0.866f));
	CHECK(Ry[m3] == 0.0f);
	CHECK(Ry[m4] == 0.0f);
	CHECK(Ry[m5] == 1.0f);
	CHECK(Ry[m6] == 0.0f);
	CHECK(Ry[m7] == 0.0f);
	CHECK(eq_float(Ry[m8], 0.866f));
	CHECK(Ry[m9] == 0.0f);
	CHECK(eq_float(Ry[m10], 0.5f));
	CHECK(Ry[m11] == 0.0f);
	CHECK(Ry[m12] == 0.0f);
	CHECK(Ry[m13] == 0.0f);
	CHECK(Ry[m14] == 0.0f);
	CHECK(eq_float(Ry[m15],1.0f));

#endif
} TEST_END

// --- End of File ---
