//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "QueueMan.h"
#include "Command.h"

namespace Neelam
{
	QueueMan *QueueMan::posInstance = nullptr;

	QueueMan::QueueMan()
		: poEngineIn(new CircularData()),
		  poFileIn(new CircularData()),
		  fileMtx(),
		  fileCv(),
		  fileSignalled(false)
	{
	}

	QueueMan::~QueueMan()
	{
		// Anything still in an inbox was posted but never executed -- so its
		// Execute() (which would have `delete this`) never ran. Drain and free,
		// or every leftover is a tracked leak.
		//
		// The file inbox is normally already empty: FileThread::Stop drains it
		// before this runs. Belt and braces.
		Command *pCmd  = nullptr;
		int      count = 0;

		while (this->poEngineIn->PopFront(pCmd))
		{
			delete pCmd;
			count++;
		}
		while (this->poFileIn->PopFront(pCmd))
		{
			delete pCmd;
			count++;
		}

		if (count > 0)
		{
			// Not fatal, but worth knowing: work was posted late enough that
			// its consumer never got a chance to run it.
			Debug::out("QueueMan: dropped %d unexecuted command(s) at shutdown\n", count);
		}

		delete this->poEngineIn;
		this->poEngineIn = nullptr;

		delete this->poFileIn;
		this->poFileIn = nullptr;
	}

	void QueueMan::Create()
	{
		assert(QueueMan::posInstance == nullptr);
		QueueMan::posInstance = new QueueMan();
	}

	void QueueMan::Destroy()
	{
		assert(QueueMan::posInstance != nullptr);

		delete QueueMan::posInstance;
		QueueMan::posInstance = nullptr;
	}

	QueueMan *QueueMan::privGetInstance()
	{
		assert(QueueMan::posInstance != nullptr);
		return QueueMan::posInstance;
	}

	bool QueueMan::SendEngine(Command *pCmd)
	{
		assert(pCmd);

		QueueMan *pMan = QueueMan::privGetInstance();
		return pMan->poEngineIn->PushBack(pCmd);
	}

	CircularData *QueueMan::GetEngineInQueue()
	{
		QueueMan *pMan = QueueMan::privGetInstance();
		return pMan->poEngineIn;
	}

	bool QueueMan::SendFile(Command *pCmd)
	{
		assert(pCmd);

		QueueMan *pMan = QueueMan::privGetInstance();

		const bool status = pMan->poFileIn->PushBack(pCmd);

		// Wake even on failure is harmless; waking only on success would be a
		// lost-wakeup risk if the queue drained between push and notify.
		QueueMan::WakeFile();

		return status;
	}

	CircularData *QueueMan::GetFileInQueue()
	{
		QueueMan *pMan = QueueMan::privGetInstance();
		return pMan->poFileIn;
	}

	//-----------------------------------------------------------------
	// The `fileSignalled` flag is what makes this immune to lost wakeups: a
	// notify that arrives BEFORE the wait still sets the flag, so the wait
	// returns immediately instead of sleeping forever. A bare CV without a
	// predicate would deadlock on exactly that race at shutdown.
	//-----------------------------------------------------------------
	void QueueMan::WaitForFile(const std::atomic<bool> &rRunning)
	{
		QueueMan *pMan = QueueMan::privGetInstance();

		std::unique_lock<std::mutex> lock(pMan->fileMtx);

		pMan->fileCv.wait(lock, [pMan, &rRunning]
		{
			return pMan->fileSignalled || !rRunning.load();
		});

		pMan->fileSignalled = false;
	}

	void QueueMan::WakeFile()
	{
		QueueMan *pMan = QueueMan::privGetInstance();

		{
			std::lock_guard<std::mutex> lock(pMan->fileMtx);
			pMan->fileSignalled = true;
		}

		pMan->fileCv.notify_one();
	}
}

// ---  End of File ---
