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
static File::Handle fh_file11;
static File::Handle fh_file11b;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_NO_Base_ERROR_Open, TestConfig::ALL)
{
#if Open_NO_Base_ERROR_Open

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file11.bin", File::Mode::WRITE);
	fh_file11 = fh;  // used for teardown

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	// should fail
	ferror = File::Open(fh, "file11.bin", File::Mode::WRITE);
	fh_file11b = fh;  // used for teardown
	CHECK(ferror == File::Error::OPEN_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(Open_NO_Base_ERROR_Open)
{
#if Open_NO_Base_ERROR_Open

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file11, &flags);
	if (status)
	{
		File::Close(fh_file11);
	}
	status = GetHandleInformation(fh_file11b, &flags);
	if (status)
	{
		File::Close(fh_file11b);
	}

#endif
}

// --- End of File ---
