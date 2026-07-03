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
static File::Handle fh_file6b;
static File::Handle fh_file6c;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(IsHandleValid_ERROR, TestConfig::ALL)
{
#if IsHandleValid_ERROR

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file6.bin", File::Mode::WRITE);
	// used to clean up at end of test
	fh_file6b = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	bool status = File::IsHandleValid(fh);
	CHECK(status == true);

	ferror = File::Close(fh);
	// used to clean up at end of test
	fh_file6c = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr );

	status = File::IsHandleValid(fh);
	CHECK(status == false);

#endif
} TEST_END

TEST_TEARDOWN(IsHandleValid_ERROR)
{
#if IsHandleValid_ERROR

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file6b, &flags);
	if (status)
	{
		File::Close(fh_file6b);
	}

	status = GetHandleInformation(fh_file6c, &flags);
	if (status)
	{
		File::Close(fh_file6c);
	}

#endif
}

// --- End of File ---
