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
static File::Handle fh_file10;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_NO_Base_ERROR_Filename, TestConfig::ALL)
{
#if Open_NO_Base_ERROR_Filename 

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, nullptr, File::Mode::WRITE);
	fh_file10 = fh;

	CHECK(ferror == File::Error::OPEN_FILENAME_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(Open_NO_Base_ERROR_Filename)
{
#if Open_NO_Base_ERROR_Filename 

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file10, &flags);
	if (status)
	{
		File::Close(fh_file10);
	}

#endif
}

// --- End of File ---
