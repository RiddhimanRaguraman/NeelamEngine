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
static File::Handle fh_file27;
static File::Handle fh_file27b;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_SUCCESS_Read, TestConfig::ALL)
{
#if Write_SUCCESS_Read

	File::Handle fh(nullptr);
	File::Error  ferror;

	//----------- WRITE ------------------------------------------

	ferror = File::Open(fh, "file27.bin", File::Mode::WRITE);
	fh_file27 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(fh, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------

	File::Handle fh2(nullptr);

	ferror = File::Open(fh2, "file27.bin", File::Mode::READ);
	fh_file27b = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	unsigned char dataFromFile[8];
	ferror = File::Read(fh2, &dataFromFile[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	CHECK(memcmp(&data[0], &dataFromFile[0], 8) == 0);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END


TEST_TEARDOWN(Write_SUCCESS_Read)
{
#if Write_SUCCESS_Read

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file27, &flags);
	if (status)
	{
		File::Close(fh_file27);
	}

	status = GetHandleInformation(fh_file27b, &flags);
	if (status)
	{
		File::Close(fh_file27b);
	}

#endif
}

// --- End of File ---
