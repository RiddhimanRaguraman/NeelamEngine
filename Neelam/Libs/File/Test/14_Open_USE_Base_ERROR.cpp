//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "File.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

using namespace Azul;

// used for teardown
static File::Handle fh_file14;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_USE_Base_ERROR, TestConfig::ALL)
{
#if Open_USE_Base_ERROR 

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

	// should give error... Base Dir not set
	ferror = File::Open(fh, "RandomName.txt", File::Mode::WRITE, true);
	fh_file14 = fh;

	CHECK(ferror == File::Error::OPEN_BASE_DIR_FAIL);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Open_USE_Base_ERROR)
{
#if Open_USE_Base_ERROR 

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file14, &flags);
	if (status)
	{
		File::Close(fh_file14);
	}


#endif
}

// --- End of File ---
