//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_Set_Accessors_get, TestConfig::ALL)
{
#if Quat_Set_Accessors_get

	Quat A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A.qx() == 2.0f);
	CHECK(A.qy() == 3.0f);
	CHECK(A.qz() == 4.0f);
	CHECK(A.real() == 5.0f);

	float tx, ty, tz, tw;

	tx = A.qx();
	ty = A.qy();
	tz = A.qz();
	tw = A.real();

	CHECK(tx == 2.0f);
	CHECK(ty == 3.0f);
	CHECK(tz == 4.0f);
	CHECK(tw == 5.0f);

#endif
} TEST_END


// ---  End of File ---
