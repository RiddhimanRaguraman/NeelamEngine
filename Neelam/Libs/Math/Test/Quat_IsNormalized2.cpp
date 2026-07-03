//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsNormalized2, TestConfig::ALL)
{
#if Quat_IsNormalized2

	Quat  q1,q2;
	bool bvalue1;

	// isNormalized()
	q1.set( 0.2174f,0.465148f,0.647723f,0.730297f);

	bvalue1 = q1.isNormalized(0.1f);
	CHECK( bvalue1 == false );

	q2 = -q1;

	bvalue1 = q2.isNormalized(0.1f);
	CHECK(bvalue1 == false);

#endif
} TEST_END


// ---  End of File ---------------
