//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef HANDLE_MAN_H
#define HANDLE_MAN_H

#include "Handle.h"

namespace Neelam
{
	//-----------------------------------------------------------------------
	// class HandleMan  (singleton)
	//
	// The table behind Handle. One fixed array of {mutex, id} slots -- no
	// allocation, no std::map.
	//
	// How the validity check works: a Handle stores {id, index}. The slot at
	// `index` stores the id that currently owns it. Destroying the owner sets
	// the slot back to INVALID_STATE, so a stale Handle's id no longer matches
	// and every lookup fails cleanly instead of dereferencing freed memory.
	// Ids are monotonically increasing, so a recycled SLOT never accidentally
	// validates an old handle.
	//
	// Acquire/Release lock the SLOT's mutex, which is what pins an owner for
	// the duration of a Handle::Lock.
	//-----------------------------------------------------------------------
	class HandleMan
	{
	private:
		static const unsigned int TABLE_SIZE    = 256;
		static const unsigned int INVALID_STATE = 0x0;
		static const unsigned int STARTING_ID   = 0xAAAA0000;

		class HandleTableEntry
		{
		public:
			HandleTableEntry() = default;
			HandleTableEntry(const HandleTableEntry &) = delete;
			HandleTableEntry &operator = (const HandleTableEntry &) = delete;
			~HandleTableEntry() = default;

		public:
			std::mutex   mtx;
			unsigned int id;
		};

	public:
		static void Create();
		static void Destroy();

		HandleMan(const HandleMan &) = delete;
		const HandleMan &operator = (const HandleMan &) = delete;

		static Handle::Status IsValid(const Handle &handle);

		static Handle::Status InvalidateHandle(const Handle &handle);
		static Handle::Status ActivateHandle(Handle::ID &id, Handle::Index &index);

		static Handle::Status AcquireResource(const Handle &handle);
		static Handle::Status ReleaseResource(const Handle &handle);

		// Debug aid -- dumps which slots are live.
		static void PrintTable();

	private:
		HandleMan();
		~HandleMan();

		static HandleMan *privInstance();
		static HandleMan *psInstance;

		Handle::ID     privGetNewID();
		Handle::Status privIsHandleAndRangeValid(const Handle &handle);

		HandleTableEntry table[TABLE_SIZE];
		std::mutex       srcID_mtx;
		Handle::ID       srcID;
	};
}

#endif   // HANDLE_MAN_H

// ---  End of File ---
