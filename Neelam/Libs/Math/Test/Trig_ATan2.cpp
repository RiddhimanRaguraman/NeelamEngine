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

TEST(Trig_ATan2, TestConfig::ALL)
{
#if Trig_ATan2

	float angle;
	float x;
	float y;

	x = -1.0f;
	y = 0.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, 3.1416f));

	y = 0.01f;
	x = -1.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, 3.1316f));

	y = -0.01f;
	x = -1.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, -3.1316f));

	y = 1.0f;
	x = 0.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, 1.5708f));

	y = -1.0f;
	x = 0.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, -1.5708f));

	y = 0.0f;
	x = 1.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, 0.0000f));

	y = 0.01f;
	x = 1.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, 0.0100f));

	y = -0.01f;
	x = 1.0f;
	angle = Trig::atan2(y, x);
	CHECK(eq_float(angle, -0.0100f));

#endif
} TEST_END

// ---  End of File ---
