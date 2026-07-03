//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_IsConjugateEqual2, TestConfig::ALL)
{
#if Quat_IsConjugateEqual2

	Quat  q1,q2;
	bool bvalue1;

	// isConjugateEqual()
	q1.set(1.0f,2.0f,3.0f,4.0f);
	q2.set(-1.0f,-2.0f,-3.05f,-4.0f);

	// q1.isConjugateEqual(q2, 0.1f) 
	bvalue1 = q1.isConjugateEqual(q2, 0.1f);

	CHECK( bvalue1 == false );

#endif
} TEST_END

// ---  End of File ---------------
