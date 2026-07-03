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
static File::Handle fh_file29;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_SUCCESS_ReadFlush, TestConfig::ALL)
{
#if Write_SUCCESS_ReadFlush

	File::Handle fh(nullptr);
	File::Error  ferror;

	//----------- WRITE ------------------------------------------

	ferror = File::Open(fh, "file29.bin", File::Mode::READ_WRITE);
	fh_file29 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(fh, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------
	ferror = File::Flush(fh);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Seek(fh, File::Position::BEGIN, 0);
	CHECK(ferror == File::Error::SUCCESS);

	DWORD offset;

	ferror = File::Tell(fh, offset);
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(offset == 0);

	unsigned char dataFromFile[8];

	ferror = File::Read(fh, &dataFromFile[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	CHECK(memcmp(&data[0], &dataFromFile[0], 8) == 0);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END


TEST_TEARDOWN(Write_SUCCESS_ReadFlush)
{
#if Write_SUCCESS_ReadFlush

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file29, &flags);
	if (status)
	{
		File::Close(fh_file29);
	}

#endif
}

// --- End of File ---
