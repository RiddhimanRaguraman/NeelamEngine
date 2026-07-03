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

TEST_WITH_TEARDOWN(SetBaseDir_ERROR_Filename, TestConfig::ALL)
{
#if SetBaseDir_ERROR_Filename

	File::Error  ferror;

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::SetBaseDir(nullptr);

	CHECK(ferror == File::Error::BASE_DIR_NULLPTR_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(SetBaseDir_ERROR_Filename)
{
#if SetBaseDir_ERROR_Filename


#endif
}

// --- End of File ---
