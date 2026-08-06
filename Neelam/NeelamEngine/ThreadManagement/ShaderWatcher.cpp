//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderWatcher.h"
#include "File_CompileShader_Cmd.h"
#include "QueueMan.h"

namespace Neelam
{
	ShaderWatcher::ShaderWatcher()
		: privThread(),
		  privDir{},
		  privLastSeen(0),
		  privQuitEvent(nullptr),
		  poShader(nullptr)
	{
	}

	ShaderWatcher::~ShaderWatcher()
	{
		this->Stop();
	}

	void ShaderWatcher::Start(vk::ShaderObject *pShader)
	{
		assert(pShader);

		this->poShader = pShader;

		// Derive the folder from the technique's own vertex-shader path: copy
		// it, then cut at the last separator. One source of truth -- move the
		// .hlsl folder and this follows automatically.
		strcpy_s(this->privDir, sizeof(this->privDir), pShader->GetVertexPath());

		char *pLastSlash = strrchr(this->privDir, '\\');
		if (pLastSlash == nullptr)
		{
			pLastSlash = strrchr(this->privDir, '/');
		}

		// A bare filename with no directory would leave privDir as the file
		// itself, and FindFirstChangeNotification would fail on it.
		assert(pLastSlash != nullptr);
		*pLastSlash = '\0';

		// Baseline: whatever is newest right now is "already seen", so we only
		// fire on edits made AFTER Start().
		this->privLastSeen = ShaderWatcher::privNewestWriteTime(this->privDir);

		// MANUAL reset (2nd arg TRUE): once Stop() signals, it stays signalled,
		// so the wait below can never miss it and block forever.
		this->privQuitEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
		assert(this->privQuitEvent != nullptr);

		this->privThread = std::thread(&ShaderWatcher::privThreadMain, this);
	}

	void ShaderWatcher::Stop()
	{
		if (this->privQuitEvent != nullptr)
		{
			SetEvent(this->privQuitEvent);
		}

		if (this->privThread.joinable())
		{
			this->privThread.join();
		}

		if (this->privQuitEvent != nullptr)
		{
			CloseHandle(this->privQuitEvent);
			this->privQuitEvent = nullptr;
		}
	}

	//-----------------------------------------------------------------
	// Background thread. Blocks until the OS reports a write in the folder --
	// no timer, no polling -- then posts a compile to the file thread.
	// Nothing Vulkan happens here.
	//-----------------------------------------------------------------
	void ShaderWatcher::privThreadMain()
	{
		// Register this thread's name + print a begin()/end() banner so its
		// Debug::out lines are tagged as the watcher, not the engine.
		Debug::SetCurrentName("ShaderWatcher");
		SimpleBanner banner;

		// FILE_NOTIFY_CHANGE_LAST_WRITE on this folder only (bWatchSubtree
		// FALSE). It reports THAT something changed, not what -- which is all
		// we need, since privNewestWriteTime re-scans anyway.
		HANDLE hChange = FindFirstChangeNotificationA(
			this->privDir, FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);

		if (hChange == INVALID_HANDLE_VALUE)
		{
			Debug::out("FindFirstChangeNotification failed (%lu) -- hot reload OFF\n",
				GetLastError());
			return;
		}

		Debug::out("watching '%s'\n", this->privDir);

		HANDLE waitOn[2] = { hChange, this->privQuitEvent };

		bool running = true;
		while (running)
		{
			// Blocks indefinitely: zero CPU while idle, instant on a save.
			const DWORD result = WaitForMultipleObjects(2, waitOn, FALSE, INFINITE);

			if (result != WAIT_OBJECT_0)
			{
				// Quit event (WAIT_OBJECT_0 + 1) or a wait failure -- either
				// way, leave.
				running = false;
				break;
			}

			// Re-arm BEFORE doing the work, so a save that lands while we are
			// compiling is not missed.
			if (!FindNextChangeNotification(hChange))
			{
				Debug::out("FindNextChangeNotification failed (%lu)\n", GetLastError());
				running = false;
				break;
			}

			// Editors write in bursts (temp file, rename, touch). Let the burst
			// settle so one save produces one compile, and so DXC does not read
			// a half-written file. Interruptible: a quit during the settle
			// leaves immediately.
			if (WaitForSingleObject(this->privQuitEvent, 60) == WAIT_OBJECT_0)
			{
				running = false;
				break;
			}

			const unsigned long long newest = ShaderWatcher::privNewestWriteTime(this->privDir);
			if (newest <= this->privLastSeen)
			{
				// Notification without a newer write -- a rename, an attribute
				// touch, or the tail of a burst we already handled.
				continue;
			}
			this->privLastSeen = newest;

			Debug::out("change detected -> posting compile to FileThread\n");

			// Goes to the FILE thread, not the engine: the compile is the
			// expensive half (disk + DXC). It posts the resulting SPIR-V back
			// to the engine, which does the Vulkan half.
			//
			// Carries the shader's NAME and its two source paths BY VALUE --
			// never a ShaderObject*, because the engine thread may destroy the
			// technique while this is in flight.
			Command *pCmd = new File_CompileShader_Cmd(
				this->poShader->GetName(),
				this->poShader->GetVertexPath(),
				this->poShader->GetPixelPath());

			if (!QueueMan::SendFile(pCmd))
			{
				// Inbox full: never handed over, so it is still ours to free.
				// Dropping is fine -- the next save posts again.
				Debug::out("file inbox FULL -- reload dropped\n");
				delete pCmd;
			}
		}

		FindCloseChangeNotification(hChange);
	}

	//-----------------------------------------------------------------
	// Newest last-write time across *.hlsl in pDir, as a comparable 64-bit
	// value (FILETIME). 0 if the folder cannot be read.
	//
	// Still here after the move to notifications, but its job changed: it is
	// now a DEDUPE filter for bursty saves, not the detection mechanism.
	//-----------------------------------------------------------------
	unsigned long long ShaderWatcher::privNewestWriteTime(const char *pDir)
	{
		char pattern[600] = {};
		sprintf_s(pattern, sizeof(pattern), "%s\\*.hlsl", pDir);

		WIN32_FIND_DATAA findData = {};
		HANDLE hFind = FindFirstFileA(pattern, &findData);
		if (hFind == INVALID_HANDLE_VALUE)
		{
			return 0;
		}

		unsigned long long newest = 0;
		do
		{
			ULARGE_INTEGER t;
			t.LowPart  = findData.ftLastWriteTime.dwLowDateTime;
			t.HighPart = findData.ftLastWriteTime.dwHighDateTime;
			if (t.QuadPart > newest)
			{
				newest = t.QuadPart;
			}
		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
		return newest;
	}
}

// ---  End of File ---
