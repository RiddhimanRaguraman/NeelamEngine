//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "HandleMan.h"
#include "Handle.h"

namespace Neelam
{
	Handle::Handle()
		: id(0),
		  index(0)
	{
		Status status = Handle::ActivateHandle(this->id, this->index);
		assert(status == Status::SUCCESS);
		AZUL_UNUSED_VAR(status);
	}

	Handle::~Handle()
	{
		Handle::InvalidateHandle(*this);
	}

	Handle::ID Handle::GetID() const
	{
		return this->id;
	}

	Handle::Index Handle::GetIndex() const
	{
		return this->index;
	}

	// Tunnel methods -- so callers never include HandleMan.
	Handle::Status Handle::IsValid(const Handle &handle)
	{
		return HandleMan::IsValid(handle);
	}

	Handle::Status Handle::InvalidateHandle(const Handle &handle)
	{
		return HandleMan::InvalidateHandle(handle);
	}

	Handle::Status Handle::ActivateHandle(Handle::ID &id, Handle::Index &index)
	{
		return HandleMan::ActivateHandle(id, index);
	}

	Handle::Status Handle::AcquireResource(const Handle &handle)
	{
		return HandleMan::AcquireResource(handle);
	}

	Handle::Status Handle::ReleaseResource(const Handle &handle)
	{
		return HandleMan::ReleaseResource(handle);
	}

	// --------------------------------------------------
	// Handle::Lock
	// --------------------------------------------------
	Handle::Lock::Lock(const Handle &h)
		: handle(h),
		  status(Lock::Status::UNLOCKED),
		  result(Handle::Status::HANDLE_ERROR)
	{
		this->lock();
	}

	Handle::Lock::~Lock()
	{
		this->unlock();
	}

	Handle::Lock::operator bool() const
	{
		return (this->status == Lock::Status::LOCKED);
	}

	void Handle::Lock::lock()
	{
		if (this->status == Lock::Status::UNLOCKED)
		{
			this->result = Handle::AcquireResource(this->handle);

			this->status = (this->result == Handle::Status::SUCCESS)
				? Lock::Status::LOCKED
				: Lock::Status::UNLOCKED;
		}
	}

	void Handle::Lock::unlock()
	{
		if (this->status == Lock::Status::LOCKED)
		{
			Handle::ReleaseResource(this->handle);
			this->status = Lock::Status::UNLOCKED;
		}
	}

	Handle::Lock::operator Handle::Status() const
	{
		if (this->status == Lock::Status::LOCKED)
		{
			return Handle::Status::SUCCESS;
		}

		return this->result;
	}
}

// ---  End of File ---
