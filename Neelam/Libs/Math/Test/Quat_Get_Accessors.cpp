//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Quat_Get_Accessors, TestConfig::ALL)
{
#if Quat_Get_Accessors

	Quat A(2.0f, 3.0f, 4.0f, 5.0f);

	CHECK(A.qx() == 2.0f);
	CHECK(A.qy() == 3.0f);
	CHECK(A.qz() == 4.0f);
	CHECK(A.real() == 5.0f);

#endif
} TEST_END

// ---  End of File ---
