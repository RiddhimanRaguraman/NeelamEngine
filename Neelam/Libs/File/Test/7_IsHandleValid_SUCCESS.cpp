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
static File::Handle fh_file7b;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(IsHandleValid_SUCCESS, TestConfig::ALL)
{
#if IsHandleValid_SUCCESS

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file7.bin", File::Mode::WRITE);
	// used to clean up at end of test
	fh_file7b = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	bool status = File::IsHandleValid(fh);
	CHECK(status == true);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(IsHandleValid_SUCCESS)
{
#if IsHandleValid_SUCCESS

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file7b, &flags);
	if (status)
	{
		File::Close(fh_file7b);
	}

#endif
}

// --- End of File ---
