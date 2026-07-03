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

TEST(Scale_TimesEqual_Scale, TestConfig::ALL)
{
#if	Scale_TimesEqual_Scale

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


	Scale S2(7, 8, 9);

	CHECK(S2[m0] == 7.0f);
	CHECK(S2[m1] == 0.0f);
	CHECK(S2[m2] == 0.0f);
	CHECK(S2[m3] == 0.0f);
	CHECK(S2[m4] == 0.0f);
	CHECK(S2[m5] == 8.0f);
	CHECK(S2[m6] == 0.0f);
	CHECK(S2[m7] == 0.0f);
	CHECK(S2[m8] == 0.0f);
	CHECK(S2[m9] == 0.0f);
	CHECK(S2[m10] == 9.0f);
	CHECK(S2[m11] == 0.0f);
	CHECK(S2[m12] == 0.0f);
	CHECK(S2[m13] == 0.0f);
	CHECK(S2[m14] == 0.0f);
	CHECK(eq_float(S2[m15], 1.0f));

	S1 *= S2;

	Mat4Hint::Hint h = ((Mat4Hint &)S1).GetHint();
	CHECK(h == Mat4Hint::Hint::Scale);

	CHECK(S2[m0] == 7.0f);
	CHECK(S2[m1] == 0.0f);
	CHECK(S2[m2] == 0.0f);
	CHECK(S2[m3] == 0.0f);
	CHECK(S2[m4] == 0.0f);
	CHECK(S2[m5] == 8.0f);
	CHECK(S2[m6] == 0.0f);
	CHECK(S2[m7] == 0.0f);
	CHECK(S2[m8] == 0.0f);
	CHECK(S2[m9] == 0.0f);
	CHECK(S2[m10] == 9.0f);
	CHECK(S2[m11] == 0.0f);
	CHECK(S2[m12] == 0.0f);
	CHECK(S2[m13] == 0.0f);
	CHECK(S2[m14] == 0.0f);
	CHECK(eq_float(S2[m15], 1.0f));

	CHECK(eq_float(S1[m0] ,21.0f));
	CHECK(eq_float(S1[m1] ,0.0f));
	CHECK(eq_float(S1[m2] ,0.0f));
	CHECK(eq_float(S1[m3] ,0.0f));
	CHECK(eq_float(S1[m4] ,0.0f));
	CHECK(eq_float(S1[m5] ,32.0f));
	CHECK(eq_float(S1[m6] ,0.0f));
	CHECK(eq_float(S1[m7] ,0.0f));
	CHECK(eq_float(S1[m8] ,0.0f));
	CHECK(eq_float(S1[m9] ,0.0f));
	CHECK(eq_float(S1[m10], 45.0f));
	CHECK(eq_float(S1[m11], 0.0f));
	CHECK(eq_float(S1[m12], 0.0f));
	CHECK(eq_float(S1[m13], 0.0f));
	CHECK(eq_float(S1[m14], 0.0f));
	CHECK(eq_float(S1[m15], 1.0f));



#endif
} TEST_END

// ---  End of File ---------------
