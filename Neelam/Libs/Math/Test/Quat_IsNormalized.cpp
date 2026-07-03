//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsNormalized, TestConfig::ALL)
{
#if Quat_IsNormalized

	Quat  q1,q2;
	bool bvalue1;

	// isNormalized()
	q1.set( 0.182574f,0.365148f,0.547723f,0.730297f);
	
	bvalue1 = q1.isNormalized(0.1f);
	CHECK( bvalue1 == true );

	q2 = -q1;

	bvalue1 = q2.isNormalized(0.1f);
	CHECK(bvalue1 == true);

#endif
} TEST_END

// ---  End of File ---------------
