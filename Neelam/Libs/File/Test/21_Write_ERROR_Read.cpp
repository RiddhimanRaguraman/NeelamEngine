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
static File::Handle fh_file21;
static File::Handle fh_file21b;
static File::Handle fh_file21c;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_ERROR_Read, TestConfig::ALL)
{
#if Write_ERROR_Read

	File::Handle A(nullptr);
	File::Handle fh2(nullptr);
	File::Error  ferror;

	//----------- WRITE ------------------------------------------

	ferror = File::Open(A, "file21.bin", File::Mode::WRITE);
	fh_file21 = A;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(A != nullptr);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(A, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	// Microsoft sucks, these next two lines need to be there, but it cant due to aliasing
	//ferror = File::Close(A);
	//CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Open(fh2, "file21b.bin", File::Mode::WRITE);
	fh_file21b = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	ferror = File::Close(A);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Write(fh2, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------

	ferror = File::Open(fh2, "file21b.bin", File::Mode::READ);
	fh_file21c = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	unsigned char dataFromFile[8];
	ferror = File::Read(A, &dataFromFile[0], 8);
	CHECK(ferror == File::Error::READ_FAIL);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Write_ERROR_Read)
{
#if Write_ERROR_Read

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file21, &flags);
	if (status)
	{
		File::Close(fh_file21);
	}

	status = GetHandleInformation(fh_file21b, &flags);
	if (status)
	{
		File::Close(fh_file21b);
	}

	status = GetHandleInformation(fh_file21c, &flags);
	if (status)
	{
		File::Close(fh_file21c);
	}


#endif
}

// --- End of File ---
