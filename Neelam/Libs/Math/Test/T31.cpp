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

TEST(Scale_Times_Scale, TestConfig::ALL)
{
#if	Scale_Times_Scale

	Scale S1(3, 4, 5);

	CHECK(S1[m0] == 3.0f);
	CHECK(S1[m1] == 0.0f);
	CHECK(S1[m2] == 0.0f);
	CHECK(S1[m3] == 0.0f);
	CHECK(S1[m4] == 0.0f);
	CHECK(S1[m5] == 4.0f);
	CHECK(S1[m6] == 0.0f);
	CHECK(S1[m7] == 0.0f);
	CHECK(S1[m8] == 0.0f);
	CHECK(S1[m9] == 0.0f);
	CHECK(S1[m10] == 5.0f);
	CHECK(S1[m11] == 0.0f);
	CHECK(S1[m12] == 0.0f);
	CHECK(S1[m13] == 0.0f);
	CHECK(S1[m14] == 0.0f);
	CHECK(eq_float(S1[m15], 1.0f));

	Scale S2(3, 4, 5);

	CHECK(S2[m0] == 3.0f);
	CHECK(S2[m1] == 0.0f);
	CHECK(S2[m2] == 0.0f);
	CHECK(S2[m3] == 0.0f);
	CHECK(S2[m4] == 0.0f);
	CHECK(S2[m5] == 4.0f);
	CHECK(S2[m6] == 0.0f);
	CHECK(S2[m7] == 0.0f);
	CHECK(S2[m8] == 0.0f);
	CHECK(S2[m9] == 0.0f);
	CHECK(S2[m10] == 5.0f);
	CHECK(S2[m11] == 0.0f);
	CHECK(S2[m12] == 0.0f);
	CHECK(S2[m13] == 0.0f);
	CHECK(S2[m14] == 0.0f);
	CHECK(eq_float(S2[m15], 1.0f));

	Scale C;

	C = S1 * S2;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	CHECK(S1[m0] == 3.0f);
	CHECK(S1[m1] == 0.0f);
	CHECK(S1[m2] == 0.0f);
	CHECK(S1[m3] == 0.0f);
	CHECK(S1[m4] == 0.0f);
	CHECK(S1[m5] == 4.0f);
	CHECK(S1[m6] == 0.0f);
	CHECK(S1[m7] == 0.0f);
	CHECK(S1[m8] == 0.0f);
	CHECK(S1[m9] == 0.0f);
	CHECK(S1[m10] == 5.0f);
	CHECK(S1[m11] == 0.0f);
	CHECK(S1[m12] == 0.0f);
	CHECK(S1[m13] == 0.0f);
	CHECK(S1[m14] == 0.0f);
	CHECK(eq_float(S1[m15], 1.0f));

	CHECK(S2[m0] == 3.0f);
	CHECK(S2[m1] == 0.0f);
	CHECK(S2[m2] == 0.0f);
	CHECK(S2[m3] == 0.0f);
	CHECK(S2[m4] == 0.0f);
	CHECK(S2[m5] == 4.0f);
	CHECK(S2[m6] == 0.0f);
	CHECK(S2[m7] == 0.0f);
	CHECK(S2[m8] == 0.0f);
	CHECK(S2[m9] == 0.0f);
	CHECK(S2[m10] == 5.0f);
	CHECK(S2[m11] == 0.0f);
	CHECK(S2[m12] == 0.0f);
	CHECK(S2[m13] == 0.0f);
	CHECK(S2[m14] == 0.0f);
	CHECK(eq_float(S2[m15], 1.0f));

	CHECK(C[m0] == 9.0f);
	CHECK(C[m1] == 0.0f);
	CHECK(C[m2] == 0.0f);
	CHECK(C[m3] == 0.0f);
	CHECK(C[m4] == 0.0f);
	CHECK(C[m5] == 16.0f);
	CHECK(C[m6] == 0.0f);
	CHECK(C[m7] == 0.0f);
	CHECK(C[m8] == 0.0f);
	CHECK(C[m9] == 0.0f);
	CHECK(C[m10] == 25.0f);
	CHECK(C[m11] == 0.0f);
	CHECK(C[m12] == 0.0f);
	CHECK(C[m13] == 0.0f);
	CHECK(C[m14] == 0.0f);
	CHECK(eq_float(C[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
