//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CircularData.h"
#include "Command.h"

namespace Neelam
{
	CircularData::CircularData()
		: data{},
		  front(CIRCULAR_DATA_SIZE),
		  back(CIRCULAR_DATA_SIZE),
		  empty(true),
		  full(false),
		  mtx()
	{
		for (unsigned int i = 0; i < CIRCULAR_DATA_SIZE; i++)
		{
			this->data[i] = nullptr;
		}
	}

	bool CircularData::PushBack(Command *pCmd)
	{
		std::lock_guard<std::mutex> lock(this->mtx);

		bool status = true;

		// Room to add? front != back means partially filled; the `empty` flag
		// disambiguates the front == back case.
		if (this->front != this->back || this->empty)
		{
			this->data[this->back.Index()] = pCmd;
			this->back++;

			this->empty = false;

			// Did that add fill it?
			if (this->front == this->back)
			{
				this->full = true;
			}
		}
		else
		{
			// Full. Nothing stored -- the caller still owns pCmd.
			status = false;
		}

		return status;
	}

	bool CircularData::PopFront(Command *&rVal)
	{
		std::lock_guard<std::mutex> lock(this->mtx);

		bool status = true;

		// Anything to process? Mirror of PushBack: `full` disambiguates
		// front == back the other way.
		if (this->front != this->back || this->full)
		{
			rVal = this->data[this->front.Index()];
			this->data[this->front.Index()] = nullptr;		// no stale pointer left behind
			this->front++;

			this->full = false;

			// Did that pop empty it?
			if (this->front == this->back)
			{
				this->empty = true;
			}
		}
		else
		{
			status = false;
		}

		return status;
	}
}

// ---  End of File ---
