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
static File::Handle fh_file2;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Close_ERROR_Close,TestConfig::ALL)
{
#if Close_ERROR_Close 

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file2.bin", File::Mode::WRITE);
	fh_file2 = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::CLOSE_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(Close_ERROR_Close)
{
#if Close_ERROR_Close 

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file2, &flags);
	if (status)
	{
		File::Close(fh_file2);
	}


#endif
}

// --- End of File ---
