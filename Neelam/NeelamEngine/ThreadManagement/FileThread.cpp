//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "FileThread.h"
#include "QueueMan.h"
#include "Command.h"

namespace Neelam
{
	FileThread::FileThread()
		: privThread(),
		  privRunning(false)
	{
	}

	FileThread::~FileThread()
	{
		this->Stop();
	}

	void FileThread::Start()
	{
		this->privRunning = true;
		this->privThread  = std::thread(&FileThread::privThreadMain, this);
	}

	void FileThread::Stop()
	{
		if (!this->privThread.joinable())
		{
			return;
		}

		// Clear the flag FIRST, then wake -- otherwise the thread could go back
		// to sleep on a stale predicate and never see the quit.
		this->privRunning = false;
		QueueMan::WakeFile();

		this->privThread.join();

		// Anything still queued never ran, so its Execute() (which would have
		// deleted it) never happened. Drain or it is a tracked leak.
		CircularData *pInbox = QueueMan::GetFileInQueue();
		Command      *pCmd   = nullptr;
		int           count  = 0;

		while (pInbox->PopFront(pCmd))
		{
			delete pCmd;
			count++;
		}

		if (count > 0)
		{
			Debug::out("FileThread: dropped %d unexecuted command(s)\n", count);
		}
	}

	void FileThread::privThreadMain()
	{
		Debug::SetCurrentName("FileThread");
		SimpleBanner banner;

		CircularData *pInbox = QueueMan::GetFileInQueue();

		while (this->privRunning)
		{
			// Block until something is posted or Stop() wakes us. No spin.
			QueueMan::WaitForFile(this->privRunning);

			// Drain everything available -- a burst is cheap here, and there is
			// no frame budget to protect on this thread.
			Command *pCmd = nullptr;
			while (pInbox->PopFront(pCmd))
			{
				assert(pCmd);
				pCmd->Execute();		// compiles, posts onward, deletes itself
			}
		}
	}
}

// ---  End of File ---
