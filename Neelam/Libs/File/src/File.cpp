//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include "File.h"

namespace Azul
{
	// holds the directory internally to File.cpp
	static char BaseDir[File::BASE_DIR_SIZE] = { 0 };

	File::Error File::ClearBaseDir() noexcept
	{
		std::memset(BaseDir, 0, sizeof(BaseDir));
		return File::Error::SUCCESS;
	}

	File::Error File::GetBaseDir(char* const pDirOut, size_t DirOutSize) noexcept
	{
		if (pDirOut == nullptr)
		{
			return File::Error::BASE_DIR_NULLPTR_FAIL;
		}

		const size_t len = std::strlen(BaseDir);
		if (len == 0)
		{
			return File::Error::BASE_DIR_FAIL; // no base dir set
		}

		if (DirOutSize < len + 1)
		{
			return File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL;
		}

		std::memcpy(pDirOut, BaseDir, len + 1);
		return File::Error::SUCCESS;
	}

	File::Error File::SetBaseDir(const char* const pDir) noexcept
	{
		if (pDir == nullptr)
		{
			return File::Error::BASE_DIR_NULLPTR_FAIL;
		}

		const size_t len = std::strlen(pDir);
		if (len >= File::BASE_DIR_SIZE)
		{
			return File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL;
		}

		std::memcpy(BaseDir, pDir, len + 1);
		return File::Error::SUCCESS;
	}

	bool File::IsHandleValid(File::Handle fh) noexcept
	{
		DWORD flags;
		return GetHandleInformation(fh, &flags) != 0;
	}

	File::Error File::GetFileAsBuffer(const char* const pFileName, unsigned char*& pBuff, unsigned int& numBytes) noexcept
	{
		File::Handle fh;
		File::Error  ferror;

		ferror = File::Open(fh, pFileName, File::Mode::READ);
		assert(ferror == File::Error::SUCCESS);

		// Get the size
		ferror = File::Seek(fh, File::Position::END, 0);
		assert(ferror == File::Error::SUCCESS);

		DWORD length;
		ferror = File::Tell(fh, length);
		assert(ferror == File::Error::SUCCESS);

		ferror = File::Seek(fh, File::Position::BEGIN, 0);
		assert(ferror == File::Error::SUCCESS);

		unsigned char* buff = new unsigned char[length];
		assert(buff);

		ferror = File::Read(fh, buff, length);
		assert(ferror == File::Error::SUCCESS);

		ferror = File::Close(fh);

		numBytes = (unsigned int)length;
		pBuff = buff;
		return ferror;
	}

    DWORD File::privGetFileDesiredAccess(File::Mode mode) noexcept
    {
        switch (mode)
        {
        case Mode::WRITE:      return GENERIC_WRITE;
        case Mode::READ:       return GENERIC_READ;
        case Mode::READ_WRITE: return GENERIC_WRITE | GENERIC_READ;
        default:               return 0;
        }
    }

    DWORD File::privGetSeek(File::Position location) noexcept
    {
        switch (location)
        {
        case File::Position::BEGIN:   return FILE_BEGIN;
        case File::Position::CURRENT: return FILE_CURRENT;
        case File::Position::END:     return FILE_END;
        default:                      return FILE_BEGIN;
        }
    }

	File::Error File::Open(File::Handle& fh, const char* const fileName, File::Mode mode, bool UseBaseAddr) noexcept
	{
		if (fileName == nullptr)
			return Error::OPEN_FILENAME_FAIL;

		char path[128] = { 0 };

		if (UseBaseAddr)
		{
			if (strlen(BaseDir) < 2)
				return Error::OPEN_BASE_DIR_FAIL;

			strcat_s(path, 128, BaseDir);
		}

		if (strcat_s(path, 128, fileName) != 0)
			return Error::OPEN_BASE_DIR_FAIL;

		DWORD access;
		DWORD creation;
		DWORD flags;

		if (mode == Mode::READ)
		{
			access = GENERIC_READ;
			creation = OPEN_EXISTING;
			flags = 1;
		}
		else
		{
			access = (mode == Mode::WRITE) ?
				GENERIC_WRITE :
				GENERIC_READ | GENERIC_WRITE;

			creation = CREATE_ALWAYS;
			flags = FILE_ATTRIBUTE_NORMAL;
		}

		fh = CreateFileA(
			path,
			access,
			0,
			nullptr,
			creation,
			flags,
			nullptr);

		if (fh == INVALID_HANDLE_VALUE)
			return Error::OPEN_FAIL;

		return Error::SUCCESS;
	}

	File::Error File::Close(File::Handle& fh) noexcept
	{
		DWORD flags;

		if (GetHandleInformation(fh, &flags) && fh != INVALID_HANDLE_VALUE)
		{
			if (CloseHandle(fh))
			{
				fh = INVALID_HANDLE_VALUE;
				return File::Error::SUCCESS;
			}
		}

		return File::Error::CLOSE_FAIL;
	}

	File::Error File::Write(File::Handle fh, const void* const buffer, const DWORD inSize) noexcept
	{
		DWORD bytesWritten = 0;
		if (!WriteFile(fh, buffer, inSize, &bytesWritten, nullptr) || bytesWritten != inSize)
		{
			return File::Error::WRITE_FAIL;
		}
		return File::Error::SUCCESS;
	}

	File::Error File::Read(File::Handle fh, void* const buffer, const DWORD inSize) noexcept
	{
		DWORD bytesRead = 0;
		if (!ReadFile(fh, buffer, inSize, &bytesRead, nullptr) || bytesRead != inSize)
		{
			return File::Error::READ_FAIL;
		}
		return File::Error::SUCCESS;
	}

	File::Error File::Seek(File::Handle fh, File::Position location, int offset) noexcept
	{
        DWORD origin = privGetSeek(location);

		DWORD result = SetFilePointer(fh, offset, nullptr, origin);
		if (result == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		{
			return File::Error::SEEK_FAIL;
		}
		return File::Error::SUCCESS;
	}

	File::Error File::Tell(File::Handle fh, DWORD& offset) noexcept
	{
		DWORD cur = SetFilePointer(fh, 0, nullptr, FILE_CURRENT);

		if (cur == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		{
			return File::Error::TELL_FAIL;
		}

		offset = cur;
		return File::Error::SUCCESS;
	}

	File::Error File::Flush(File::Handle fh) noexcept
	{
		if (!FlushFileBuffers(fh))
		{
			return File::Error::FLUSH_FAIL;
		}
		return File::Error::SUCCESS;
	}

}

// --- End of File ---
