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
static File::Handle fh_file12;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_USE_Base, TestConfig::ALL)
{
#if Open_USE_Base

	File::Handle fh(nullptr);
	File::Error  ferror;

	CHECK(File::MAJOR_VERSION == 4);
	CHECK(File::MINOR_VERSION == 0);

	CHECK(sizeof(File::Mode) == 4);
	CHECK(sizeof(File::Position) == 4);
	CHECK(sizeof(File::Error) == 4);

	system("mkdir Temp12");

	ferror = File::SetBaseDir(".\\Temp12\\");
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Open(fh, "file12.bin", File::Mode::WRITE, true);
	// used to clean up at end of test
	fh_file12 = fh;

	// make sure it opened, also check the directory
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Open_USE_Base)
{
#if Open_USE_Base

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file12, &flags);
	if(status)
	{
		File::Close(fh_file12);
	}

#endif
}

// --- End of File ---
