//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_Set_Accessors, TestConfig::ALL)
{
#if Quat_Set_Accessors

	Quat A(0.0f, 0.0f, 0.0f, 0.0f);

	CHECK(A.qx() == 0.0f);
	CHECK(A.qy() == 0.0f);
	CHECK(A.qz() == 0.0f);
	CHECK(A.real() == 0.0f);

	A.qx(2.0f);
	A.qy(3.0f);
	A.qz(4.0f);
	A.real(5.0f);

	CHECK(A.qx() == 2.0f);
	CHECK(A.qy() == 3.0f);
	CHECK(A.qz() == 4.0f);
	CHECK(A.real() == 5.0f);

#endif
} TEST_END

// ---  End of File ---
