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
static  File::Handle fh_file9;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
// To Run all tests: Debug-> Start without debugging
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_NO_Base_Close, TestConfig::ALL)
{
#if Open_NO_Base_Close

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file9.bin", File::Mode::WRITE);
	fh_file9 = fh;
	
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Open_NO_Base_Close)
{
#if Open_NO_Base_Close

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file9, &flags);
	if (status)
	{
		File::Close(fh_file9);
	}

#endif
}

// --- End of File ---
