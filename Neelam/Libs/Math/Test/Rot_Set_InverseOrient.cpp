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

TEST(Rot_Set_InverseOrient, TestConfig::ALL)
{
#if Rot_Set_InverseOrient

	// Orientation Type Constructor:
	Vec3  v17( 2.0f, 53.0f, 24.0f);
	Vec3  v18( 0.0f, -24.0f, 53.0f);
	Rot r57;
	r57.set(Orient::WorldToLocal, v17, v18 );

	CHECK( eq_float(r57[m0],-0.9994f) );
	CHECK( eq_float(r57[m1], 0.0000f) );
	CHECK( eq_float(r57[m2], 0.0344f) );
	CHECK( (r57[m3] == 0.0f) );
	CHECK( eq_float(r57[m4], 0.0313f) );
	CHECK( eq_float(r57[m5],-0.4125f) );
	CHECK( eq_float(r57[m6], 0.9104f) );
	CHECK( (r57[m7] == 0.0f) );
	CHECK( eq_float(r57[m8],  0.0142f) );
	CHECK( eq_float(r57[m9],  0.9110f) );
	CHECK( eq_float(r57[m10], 0.4123f) );
	CHECK( (r57[m11] == 0.0f) );
	CHECK( (r57[m12] == 0.0f) );
	CHECK( (r57[m13] == 0.0f) );
	CHECK( (r57[m14] == 0.0f) );
	CHECK( eq_float(r57[m15],1.0f) );
	

#endif
} TEST_END

// ---  End of File ---------------
