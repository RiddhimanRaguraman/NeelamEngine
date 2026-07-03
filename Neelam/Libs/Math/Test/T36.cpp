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

TEST(Trans_TimesEqual_Trans, TestConfig::ALL)
{
#if	Trans_TimesEqual_Trans

	Trans T1(3, 4, 5);

	CHECK(T1[m0] == 1.0f);
	CHECK(T1[m1] == 0.0f);
	CHECK(T1[m2] == 0.0f);
	CHECK(T1[m3] == 0.0f);
	CHECK(T1[m4] == 0.0f);
	CHECK(T1[m5] == 1.0f);
	CHECK(T1[m6] == 0.0f);
	CHECK(T1[m7] == 0.0f);
	CHECK(T1[m8] == 0.0f);
	CHECK(T1[m9] == 0.0f);
	CHECK(T1[m10] == 1.0f);
	CHECK(T1[m11] == 0.0f);
	CHECK(T1[m12] == 3.0f);
	CHECK(T1[m13] == 4.0f);
	CHECK(T1[m14] == 5.0f);
	CHECK(eq_float(T1[m15], 1.0f));

	Trans T2(7, 8, 9);

	CHECK(T2[m0] == 1.0f);
	CHECK(T2[m1] == 0.0f);
	CHECK(T2[m2] == 0.0f);
	CHECK(T2[m3] == 0.0f);
	CHECK(T2[m4] == 0.0f);
	CHECK(T2[m5] == 1.0f);
	CHECK(T2[m6] == 0.0f);
	CHECK(T2[m7] == 0.0f);
	CHECK(T2[m8] == 0.0f);
	CHECK(T2[m9] == 0.0f);
	CHECK(T2[m10] == 1.0f);
	CHECK(T2[m11] == 0.0f);
	CHECK(T2[m12] == 7.0f);
	CHECK(T2[m13] == 8.0f);
	CHECK(T2[m14] == 9.0f);
	CHECK(eq_float(T2[m15], 1.0f));

	T1 *= T2;

	Mat4Hint::Hint h = ((Mat4Hint &)T1).GetHint();
	CHECK(h == Mat4Hint::Hint::Trans);

	CHECK(T2[m0] == 1.0f);
	CHECK(T2[m1] == 0.0f);
	CHECK(T2[m2] == 0.0f);
	CHECK(T2[m3] == 0.0f);
	CHECK(T2[m4] == 0.0f);
	CHECK(T2[m5] == 1.0f);
	CHECK(T2[m6] == 0.0f);
	CHECK(T2[m7] == 0.0f);
	CHECK(T2[m8] == 0.0f);
	CHECK(T2[m9] == 0.0f);
	CHECK(T2[m10] == 1.0f);
	CHECK(T2[m11] == 0.0f);
	CHECK(T2[m12] == 7.0f);
	CHECK(T2[m13] == 8.0f);
	CHECK(T2[m14] == 9.0f);
	CHECK(eq_float(T2[m15], 1.0f));

	CHECK(eq_float(T1[m0] , 1.0f ));
	CHECK(eq_float(T1[m1] , 0.0f ));
	CHECK(eq_float(T1[m2] , 0.0f ));
	CHECK(eq_float(T1[m3] , 0.0f ));
	CHECK(eq_float(T1[m4] , 0.0f ));
	CHECK(eq_float(T1[m5] , 1.0f ));
	CHECK(eq_float(T1[m6] , 0.0f ));
	CHECK(eq_float(T1[m7] , 0.0f ));
	CHECK(eq_float(T1[m8] , 0.0f ));
	CHECK(eq_float(T1[m9] , 0.0f ));
	CHECK(eq_float(T1[m10], 1.0f ));
	CHECK(eq_float(T1[m11], 0.0f ));
	CHECK(eq_float(T1[m12], 10.0f));
	CHECK(eq_float(T1[m13], 12.0f));
	CHECK(eq_float(T1[m14], 14.0f));
	CHECK(eq_float(T1[m15], 1.0f));
#endif
} TEST_END

// ---  End of File ---------------
