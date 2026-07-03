//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

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

TEST_WITH_TEARDOWN(SetBaseDir_ERROR_size, TestConfig::ALL)
{
#if SetBaseDir_ERROR_size

	File::Error  ferror;

	const char *pLongPath =
	"C:\\RandomLongString that is too big for the buffer really long. "  
		"Did I say long.. I mean longer than the 128 length path. "
		"I just realized that a 128 byte path is long";
	
	CHECK(strlen(pLongPath) > File::BASE_DIR_SIZE);

	ferror = File::SetBaseDir( pLongPath );

	CHECK(ferror == File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(SetBaseDir_ERROR_size)
{
#if SetBaseDir_ERROR_size


#endif
}

// --- End of File ---
