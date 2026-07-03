//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

#if Quat_Get_Accessors_const
float constTestAccessor(const Quat &t)
{
	return (t.qx() + t.qy() + t.qz() + t.real());
}
#endif

TEST(Quat_Get_Accessors_const, TestConfig::ALL)
{
#if Quat_Get_Accessors_const

	Quat A(2.0f, 3.0f, 4.0f, 5.0f);

	float sum = constTestAccessor(A);

	CHECK(sum == 14.0f);

	CHECK(A.qx() == 2.0f);
	CHECK(A.qy() == 3.0f);
	CHECK(A.qz() == 4.0f);
	CHECK(A.real() == 5.0f);

#endif
} TEST_END

// ---  End of File ---
