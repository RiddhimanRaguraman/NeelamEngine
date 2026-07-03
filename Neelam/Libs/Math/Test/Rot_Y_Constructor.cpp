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

TEST(Rot_Y_Constructor, TestConfig::ALL)
{
#if Rot_Y_Constructor

	Rot Ry(Rot1::Y, 1.0471975512f);

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
