//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef HANDLE_H
#define HANDLE_H

//---------------------------------------------------------------------------
// class Handle
//
// NOT WIRED TO ANYTHING YET -- a deliberate keep. The cross-thread lifetime
// problem in the actor model is solved by ShaderObjectNodeMan::Find(name),
// because a Handle is not a weak pointer (see below). Kept because it is the
// right tool for an object whose own methods can be called from more than one
// thread; nothing has that shape today.
//
// A cross-thread answer to "is the thing this message points at still alive?"
//
// A raw pointer cannot answer that. Thread A posts a command holding
// ShaderObject*, thread B destroys the ShaderObject, thread C executes the
// command -- and the pointer is now garbage that still looks valid. A Handle
// is an {id, index} pair into HandleMan's table: destroying the owner clears
// the slot, so the stale id no longer matches and the command knows to bail.
//
// USAGE -- always through the RAII Lock, never by hand:
//
//     Handle::Lock lock(this->handle);
//     if (lock)
//     {
//         // owner is alive AND pinned for this scope -- safe to touch
//     }
//     // destructor releases
//
// While a Lock is held the table slot's mutex is held, so the owner cannot be
// destroyed mid-use. That is the whole guarantee.
//
// Non-copyable on purpose: two copies would both invalidate the same slot on
// destruction.
//---------------------------------------------------------------------------

namespace Neelam
{
	class Handle
	{
	public:
		// Retries when the slot mutex is contended, before giving up.
		static const unsigned int NUM_RETRY = 80;

		enum class Status
		{
			SUCCESS = 0x7EEE0000,

			INSUFFIENT_SPACE,
			INVALID_HANDLE,
			VALID_HANDLE,

			NOT_INITIALIZE,

			HANDLE_ERROR = 0x7EEEFFFF
		};

		//---------------------------------------------------------------
		// RAII pin. `if (lock)` is true only when the owner is still alive.
		//---------------------------------------------------------------
		class Lock
		{
		public:
			enum class Status
			{
				LOCKED,
				UNLOCKED
			};

		public:
			explicit Lock(const Handle &h);

			Lock() = delete;
			Lock(const Lock &) = delete;
			Lock &operator = (const Lock &) = delete;
			~Lock();

			operator bool() const;

			void lock();
			void unlock();

			operator Handle::Status() const;

		private:
			const Handle  &handle;		// reference, never a copy
			Lock::Status   status;
			Handle::Status result;
		};

		typedef unsigned int ID;
		typedef unsigned int Index;

	public:
		Handle();
		~Handle();

		// Copying a handle would double-invalidate one table slot.
		Handle(const Handle &) = delete;
		const Handle &operator = (const Handle &) = delete;

		// Peek, but never set.
		ID    GetID() const;
		Index GetIndex() const;

		// Tunnel methods -- keep callers off HandleMan directly.
		static Handle::Status IsValid(const Handle &handle);

		static Handle::Status InvalidateHandle(const Handle &handle);
		static Handle::Status ActivateHandle(Handle::ID &id, Handle::Index &index);

		static Handle::Status AcquireResource(const Handle &handle);
		static Handle::Status ReleaseResource(const Handle &handle);

	private:
		ID    id;
		Index index;
	};
}

#endif   // HANDLE_H

// ---  End of File ---
