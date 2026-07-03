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
static File::Handle fh_file22;
static File::Handle fh_file22b;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_ERROR_ReadBuffer, TestConfig::ALL)
{
#if Write_ERROR_ReadBuffer

	File::Handle fh(nullptr);
	File::Error  ferror;

	//----------- WRITE ------------------------------------------

	ferror = File::Open(fh, "file22.bin", File::Mode::WRITE);
	fh_file22 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(fh, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------

	File::Handle fh2(nullptr);

	ferror = File::Open(fh2, "file22.bin", File::Mode::READ);
	fh_file22b = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	unsigned char dataFromFile[8] = { 0 };
	ferror = File::Read(fh2, nullptr, 8);
	CHECK(ferror == File::Error::READ_FAIL);

	ferror = File::Read(fh2, &dataFromFile[0], 0xFFFFFFFF);
	CHECK(ferror == File::Error::READ_FAIL);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Write_ERROR_ReadBuffer)
{
#if Write_ERROR_ReadBuffer

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file22, &flags);
	if (status)
	{
		File::Close(fh_file22);
	}

	status = GetHandleInformation(fh_file22b, &flags);
	if (status)
	{
		File::Close(fh_file22b);
	}

#endif
}

// --- End of File ----
