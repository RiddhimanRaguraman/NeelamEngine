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

TEST_WITH_TEARDOWN(GetBaseDir_ERROR_PTR, TestConfig::ALL)
{
#if GetBaseDir_ERROR_PTR

	File::Error  ferror;

	ferror = File::SetBaseDir("C:\\Code\\Monkey\\");
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::GetBaseDir(nullptr, File::BASE_DIR_SIZE);

	CHECK(ferror == File::Error::BASE_DIR_NULLPTR_FAIL);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(GetBaseDir_ERROR_PTR)
{
#if GetBaseDir_ERROR_PTR



#endif
}

// --- End of File ---
