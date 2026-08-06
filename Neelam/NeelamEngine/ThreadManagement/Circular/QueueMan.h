//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef QUEUE_MAN_H
#define QUEUE_MAN_H

#include "CircularData.h"

namespace Neelam
{
	//-----------------------------------------------------------------------
	// class QueueMan  (singleton)
	//
	// Owns one INBOX per consumer thread and routes commands into it. The inbox
	// belongs to the CONSUMER, so any number of threads can post to the engine
	// without knowing anything about it.
	//
	// Lifetime is Engine::Initialize -> Engine::Shutdown, which brackets every
	// worker thread.
	//-----------------------------------------------------------------------
	class QueueMan
	{
	public:
		static void Create();

		// Drains and DELETES anything still queued -- commands are heap
		// allocated and their Execute() never ran, so this is the difference
		// between a clean run and Memory Tracking: FAIL.
		static void Destroy();

		// Post to the engine thread. Returns false if the inbox is full, in
		// which case the command was NOT stored and the caller must delete it.
		static bool SendEngine(Command *pCmd);

		// Post to the file thread. Same contract as SendEngine, and it WAKES
		// the file thread -- which blocks rather than spinning.
		static bool SendFile(Command *pCmd);

		// For the consumers' own drain loops.
		static CircularData *GetEngineInQueue();
		static CircularData *GetFileInQueue();

		//-----------------------------------------------------------------
		// File-thread sleep/wake. Only the file thread blocks: it is idle most of
		// the time. The engine thread renders every frame, so it drains by polling
		// and a condition variable would buy it nothing.
		//-----------------------------------------------------------------
		static void WaitForFile(const std::atomic<bool> &rRunning);
		static void WakeFile();

	private:
		QueueMan();
		QueueMan(const QueueMan &) = delete;
		QueueMan &operator = (const QueueMan &) = delete;
		~QueueMan();

		static QueueMan *privGetInstance();
		static QueueMan *posInstance;

		CircularData *poEngineIn;		// ---> to the engine thread
		CircularData *poFileIn;			// ---> to the file thread

		// Guards nothing but the wait itself -- CircularData has its own mutex.
		std::mutex              fileMtx;
		std::condition_variable fileCv;
		bool                    fileSignalled;
	};
}

#endif   // QUEUE_MAN_H

// ---  End of File ---
