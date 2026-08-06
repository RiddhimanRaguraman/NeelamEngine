//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "HandleMan.h"

namespace Neelam
{
	HandleMan *HandleMan::psInstance = nullptr;

	HandleMan::HandleMan()
		: table(),
		  srcID_mtx(),
		  srcID(STARTING_ID)
	{
		for (unsigned int i = 0; i < TABLE_SIZE; i++)
		{
			this->table[i].id = INVALID_STATE;
		}
	}

	HandleMan::~HandleMan()
	{
		// Safety: nuke it again so a stale handle used after Destroy fails.
		this->srcID = STARTING_ID;

		for (unsigned int i = 0; i < TABLE_SIZE; i++)
		{
			this->table[i].id = INVALID_STATE;
		}
	}

	void HandleMan::Create()
	{
		assert(HandleMan::psInstance == nullptr);
		HandleMan::psInstance = new HandleMan();
	}

	void HandleMan::Destroy()
	{
		assert(HandleMan::psInstance != nullptr);

		delete HandleMan::psInstance;
		HandleMan::psInstance = nullptr;
	}

	HandleMan *HandleMan::privInstance()
	{
		return HandleMan::psInstance;
	}

	//-----------------------------------------------------------------
	// Ids only ever increase, so a recycled SLOT never revalidates an old
	// handle. INVALID_STATE is reserved as the "empty" marker and must never
	// be handed out as a real id.
	//-----------------------------------------------------------------
	Handle::ID HandleMan::privGetNewID()
	{
		std::lock_guard<std::mutex> lock(this->srcID_mtx);

		this->srcID++;

		while (this->srcID == INVALID_STATE)
		{
			this->srcID++;
		}

		return this->srcID;
	}

	Handle::Status HandleMan::ActivateHandle(Handle::ID &new_id, Handle::Index &index)
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return Handle::Status::NOT_INITIALIZE;
		}

		// try_lock rather than lock: a contended slot is skipped and retried,
		// so scanning for a free slot can never deadlock against a live Lock.
		for (unsigned int attempt = 0; attempt < Handle::NUM_RETRY; attempt++)
		{
			for (Handle::Index i = 0; i < TABLE_SIZE; i++)
			{
				if (pMan->table[i].mtx.try_lock())
				{
					if (pMan->table[i].id == INVALID_STATE)
					{
						new_id = pMan->privGetNewID();
						index  = i;
						pMan->table[i].id = new_id;

						pMan->table[i].mtx.unlock();
						return Handle::Status::SUCCESS;
					}

					pMan->table[i].mtx.unlock();
				}
			}
		}

		Debug::out("HandleMan::ActivateHandle() - insufficient space\n");
		return Handle::Status::INSUFFIENT_SPACE;
	}

	Handle::Status HandleMan::InvalidateHandle(const Handle &handle)
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return Handle::Status::NOT_INITIALIZE;
		}

		if (handle.GetIndex() >= TABLE_SIZE)
		{
			Debug::out("HandleMan::InvalidateHandle() - out of range h(%x):%x\n",
				handle.GetIndex(), handle.GetID());
			return Handle::Status::HANDLE_ERROR;
		}

		std::lock_guard<std::mutex> lock(pMan->table[handle.GetIndex()].mtx);

		if (pMan->table[handle.GetIndex()].id == handle.GetID())
		{
			pMan->table[handle.GetIndex()].id = INVALID_STATE;
		}
		else
		{
			Debug::out("HandleMan::InvalidateHandle() - id mismatch h(%x):%x table:%x\n",
				handle.GetIndex(), handle.GetID(), pMan->table[handle.GetIndex()].id);
		}

		return Handle::Status::INVALID_HANDLE;
	}

	Handle::Status HandleMan::IsValid(const Handle &handle)
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return Handle::Status::NOT_INITIALIZE;
		}

		return pMan->privIsHandleAndRangeValid(handle);
	}

	//-----------------------------------------------------------------
	// Acquire LEAVES THE SLOT MUTEX HELD on success -- that is the pin. It is
	// released by ReleaseResource. Only Handle::Lock should call this pair, so
	// the two always match up.
	//-----------------------------------------------------------------
	Handle::Status HandleMan::AcquireResource(const Handle &handle)
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return Handle::Status::NOT_INITIALIZE;
		}

		if (handle.GetIndex() >= TABLE_SIZE)
		{
			Debug::out("HandleMan::AcquireResource() - out of range h(%x):%x\n",
				handle.GetIndex(), handle.GetID());
			return Handle::Status::HANDLE_ERROR;
		}

		for (unsigned int attempt = 0; attempt < Handle::NUM_RETRY; attempt++)
		{
			if (pMan->table[handle.GetIndex()].mtx.try_lock())
			{
				if (pMan->table[handle.GetIndex()].id == handle.GetID())
				{
					// Deliberately still locked -- the caller holds the pin.
					return Handle::Status::SUCCESS;
				}

				// Owner is gone: unlock and report, so the caller bails out.
				pMan->table[handle.GetIndex()].mtx.unlock();
				return Handle::Status::INVALID_HANDLE;
			}
		}

		Debug::out("HandleMan::AcquireResource() - lock failed h(%x):%x\n",
			handle.GetIndex(), handle.GetID());
		return Handle::Status::HANDLE_ERROR;
	}

	Handle::Status HandleMan::ReleaseResource(const Handle &handle)
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return Handle::Status::NOT_INITIALIZE;
		}

		if (handle.GetIndex() >= TABLE_SIZE)
		{
			Debug::out("HandleMan::ReleaseResource() - out of range h(%x):%x\n",
				handle.GetIndex(), handle.GetID());
			return Handle::Status::HANDLE_ERROR;
		}

		pMan->table[handle.GetIndex()].mtx.unlock();
		return Handle::Status::SUCCESS;
	}

	Handle::Status HandleMan::privIsHandleAndRangeValid(const Handle &handle)
	{
		if (handle.GetIndex() >= TABLE_SIZE)
		{
			return Handle::Status::HANDLE_ERROR;
		}

		std::lock_guard<std::mutex> lock(this->table[handle.GetIndex()].mtx);

		return (this->table[handle.GetIndex()].id == handle.GetID())
			? Handle::Status::VALID_HANDLE
			: Handle::Status::INVALID_HANDLE;
	}

	void HandleMan::PrintTable()
	{
		HandleMan *pMan = HandleMan::privInstance();
		if (pMan == nullptr)
		{
			return;
		}

		Debug::out("--- HandleMan table ---\n");

		for (unsigned int i = 0; i < TABLE_SIZE; i++)
		{
			std::lock_guard<std::mutex> lock(pMan->table[i].mtx);

			if (pMan->table[i].id != INVALID_STATE)
			{
				Debug::out("   [%d]: %x \n", i, pMan->table[i].id);
			}
		}
	}
}

// ---  End of File ---
