//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsNegEqual, TestConfig::ALL)
{
#if Quat_IsNegEqual

	Quat  q1,q2;
	bool bvalue1;

	// IsNegEqual()
	q1.set(1.0f,2.0f,3.0f,4.0f);
	q2.set(9.0f,-3.0f,5.0f,4.0f);

	// q1.isNegEqual(q2, 0.1f) 
	bvalue1 = q1.isNegEqual(q2, 0.1f);

	CHECK( bvalue1 == false );

#endif
} TEST_END

// ---  End of File ---------------
