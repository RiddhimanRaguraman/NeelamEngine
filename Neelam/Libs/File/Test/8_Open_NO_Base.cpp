//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "File.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

using namespace Azul;

// used for teardown
static File::Handle fh_file8;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_NO_Base, TestConfig::ALL)
{
#if Open_NO_Base

	File::Handle fh(nullptr);
	File::Error  ferror;

	CHECK(File::MAJOR_VERSION == 4);
	CHECK(File::MINOR_VERSION == 0);

	CHECK(sizeof(File::Mode) == 4);
	CHECK(sizeof(File::Position) == 4);
	CHECK(sizeof(File::Error) == 4);

	ferror = File::Open(fh, "file8.bin", File::Mode::WRITE);
	// used to clean up at end of test
	fh_file8 = fh;

	// make sure it opened, also check the directory
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

#endif
} TEST_END

TEST_TEARDOWN(Open_NO_Base)
{
#if Open_NO_Base

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file8, &flags);
	if (status)
	{
		File::Close(fh_file8);
	}

#endif
}

// --- End of File ---
