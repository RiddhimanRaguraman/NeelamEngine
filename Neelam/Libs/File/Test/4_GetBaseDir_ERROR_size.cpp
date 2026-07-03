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

TEST_WITH_TEARDOWN(GetBaseDir_ERROR_size, TestConfig::ALL)
{
#if GetBaseDir_ERROR_size

	File::Error  ferror;

	ferror = File::SetBaseDir("C:\\Code\\Monkey\\");
	CHECK(ferror == File::Error::SUCCESS);

	char buff[File::BASE_DIR_SIZE];
	ferror = File::GetBaseDir(buff, 5);

	CHECK(ferror == File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(GetBaseDir_ERROR_size)
{
#if GetBaseDir_ERROR_size


#endif
}

// --- End of File ---
