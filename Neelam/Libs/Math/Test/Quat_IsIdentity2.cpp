//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsIdentity2, TestConfig::ALL)
{
#if Quat_IsIdentity2

	Quat  q1,q2;
	bool bvalue1;

	// isIdentity()
	q1.set(0.0f,0.0f,0.0f,4.0f);

	// q1.isIdentity(0.1f) 
	bvalue1 = q1.isIdentity(0.1f);
	CHECK( bvalue1 == false );

#endif
} TEST_END

// ---  End of File ---------------
