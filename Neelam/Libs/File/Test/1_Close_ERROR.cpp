//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "File.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Close_ERROR,TestConfig::ALL)
{
#if Close_ERROR

	File::Error  ferror(File::Error::UNDEFINED);
	int a = 0x55;
	File::Handle fh = &a;

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::CLOSE_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(Close_ERROR)
{
#if Close_ERROR


#endif
}

// --- End of File ---
