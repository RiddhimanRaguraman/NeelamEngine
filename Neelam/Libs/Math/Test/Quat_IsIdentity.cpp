//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsIdentity, TestConfig::ALL)
{
#if Quat_IsIdentity

	Quat  q1,q2;
	bool bvalue1;

	// isIdentity()
	q1.set(0.0f,0.0f,0.0f,1.0f);

	// q1.isIdentity(0.1f) 
	bvalue1 = q1.isIdentity(0.1f);
	
	CHECK( bvalue1 == true );

#endif
} TEST_END

// ---  End of File ---------------
