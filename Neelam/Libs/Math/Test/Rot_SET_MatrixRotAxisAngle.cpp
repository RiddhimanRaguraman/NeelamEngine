//-----------------------------------------------------------------------------
// Copyright 2025,, Ed Keenan, all rights reserved.
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

TEST(Rot_SET_RotAxisAngle, TestConfig::ALL)
{
#if Rot_SET_RotAxisAngle

	// Axis and Angle Type Constructor:
	Vec3  v11( 2.0f, 53.0f, 24.0f);
	Rot m54;
	
	m54.set( Axis::AxisAngle, v11, MATH_PI3 );
			
	// => Vec4  v11( 2.0f, 53.0f, 24.0f); \n"););
	// => Mat4 m54(ROT_AXIS_ANGLE, v11, MATH_PI3 );\n"););
	CHECK( eq_float(m54[m0], 0.5005f) );
	CHECK( eq_float(m54[m1], 0.3726f) );
	CHECK( eq_float(m54[m2],-0.7813f) );
	CHECK( m54[m3] == 0.0f );
	CHECK( eq_float(m54[m4],-0.3413f) );
	CHECK( eq_float(m54[m5], 0.9144f) );
	CHECK( eq_float(m54[m6], 0.2174f) );
	CHECK( (m54[m7] == 0.0f) );
	CHECK( eq_float(m54[m8], 0.7955f) );
	CHECK( eq_float(m54[m9], 0.1579f) );
	CHECK( eq_float(m54[m10], 0.5849f) );
	CHECK( (m54[m11] == 0.0f) );
	CHECK( (m54[m12] == 0.0f) );
	CHECK( (m54[m13] == 0.0f) );
	CHECK( (m54[m14] == 0.0f) );
	CHECK( eq_float(m54[m15],1.0f) );

#endif
} TEST_END

// ---  End of File ---------------
