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
static File::Handle fh_file19;
static File::Handle fh_file19b;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_ERROR_Fail, TestConfig::ALL)
{
#if Write_ERROR_Fail

	File::Handle fh(nullptr);
	File::Handle fh2(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file19.bin", File::Mode::WRITE);
	fh_file19 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	ferror = File::Open(fh2, "file19b.bin", File::Mode::WRITE);
	fh_file19b = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(fh2, &data[0], 8);
	CHECK(ferror == File::Error::WRITE_FAIL);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Write_ERROR_Fail)
{
#if Write_ERROR_Fail

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file19, &flags);
	if (status)
	{
		File::Close(fh_file19);
	}

	status = GetHandleInformation(fh_file19b, &flags);
	if (status)
	{
		File::Close(fh_file19b);
	}

#endif
}

// --- End of File ---
