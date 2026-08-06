//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CIRCULAR_DATA_H
#define CIRCULAR_DATA_H

#include "CircularIndex.h"

namespace Neelam
{
	// Only pointers are stored, so a forward declaration is enough -- keeps
	// every Command subclass out of this header.
	class Command;

	//-----------------------------------------------------------------------
	// class CircularData
	//
	// The mailbox: a fixed ring of Command* guarded by one mutex. One thread
	// pushes, another pops.
	//
	// Properties that matter here:
	//   * FIXED storage -- a plain array + two wrapping indices. No std::queue,
	//     no std::vector, and no allocation while running.
	//   * Never blocks. PushBack/PopFront take the lock, do O(1) work, return.
	//     A full inbox returns false rather than waiting, so a producer can
	//     never stall the engine thread.
	//   * Never throws.
	//
	// No public IsEmpty()/IsFull(): they would lock, read and unlock, so the answer
	// is stale by the time the caller acts on it. Call PushBack/PopFront and check
	// the bool -- that decision is made while the lock is held.
	//-----------------------------------------------------------------------
	class CircularData
	{
	public:
		// Power of 2 -- CircularIndex wraps with an AND, not a modulo.
		static const unsigned int CIRCULAR_DATA_SIZE = 1 << 5;	// 32

		static_assert((CIRCULAR_DATA_SIZE & (CIRCULAR_DATA_SIZE - 1)) == 0,
			"CIRCULAR_DATA_SIZE must be a power of 2");

	public:
		CircularData();
		CircularData(const CircularData &) = delete;
		const CircularData &operator = (const CircularData &) = delete;
		~CircularData() = default;

		// false == inbox full, nothing was stored. The caller still owns pCmd
		// and must delete it (see the ownership rules in Command.h).
		bool PushBack(Command *pCmd);

		// false == inbox empty, rVal untouched.
		bool PopFront(Command *&rVal);

	private:
		Command *data[CIRCULAR_DATA_SIZE];

		CircularIndex front;
		CircularIndex back;

		// front == back is ambiguous -- it means both empty and full -- so the
		// two states are tracked explicitly instead of wasting a slot.
		bool empty;
		bool full;

		std::mutex mtx;
	};
}

#endif   // CIRCULAR_DATA_H

// ---  End of File ---
