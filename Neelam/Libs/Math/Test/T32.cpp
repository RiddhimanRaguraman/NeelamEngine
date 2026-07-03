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

TEST(Scale_Times_Trans, TestConfig::ALL)
{
#if	Scale_Times_Trans

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

	Trans T(7, 8, 9);

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(T[m12] == 7.0f);
	CHECK(T[m13] == 8.0f);
	CHECK(T[m14] == 9.0f);
	CHECK(eq_float(T[m15], 1.0f));

	Mat4 C;
	C = S1 * T;

	Mat4Hint::Hint h = ((Mat4Hint &)C).GetHint();
	CHECK(h == Mat4Hint::Hint::TransScale);

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

	CHECK(T[m0] == 1.0f);
	CHECK(T[m1] == 0.0f);
	CHECK(T[m2] == 0.0f);
	CHECK(T[m3] == 0.0f);
	CHECK(T[m4] == 0.0f);
	CHECK(T[m5] == 1.0f);
	CHECK(T[m6] == 0.0f);
	CHECK(T[m7] == 0.0f);
	CHECK(T[m8] == 0.0f);
	CHECK(T[m9] == 0.0f);
	CHECK(T[m10] == 1.0f);
	CHECK(T[m11] == 0.0f);
	CHECK(eq_float(T[m12],7.0f));
	CHECK(eq_float(T[m13],8.0f));
	CHECK(eq_float(T[m14],9.0f));
	CHECK(eq_float(T[m15], 1.0f));

	CHECK(C[m0] == 3.0f);
	CHECK(C[m1] == 0.0f);
	CHECK(C[m2] == 0.0f);
	CHECK(C[m3] == 0.0f);
	CHECK(C[m4] == 0.0f);
	CHECK(C[m5] == 4.0f);
	CHECK(C[m6] == 0.0f);
	CHECK(C[m7] == 0.0f);
	CHECK(C[m8] == 0.0f);
	CHECK(C[m9] == 0.0f);
	CHECK(C[m10] == 5.0f);
	CHECK(C[m11] == 0.0f);
	CHECK(eq_float(C[m12],7.0f));
	CHECK(eq_float(C[m13],8.0f));
	CHECK(eq_float(C[m14],9.0f));
	CHECK(eq_float(C[m15], 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
