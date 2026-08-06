//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CircularIndex.h"

namespace Neelam
{
	CircularIndex::CircularIndex(unsigned int buffSize)
		: index(0),
		  size(buffSize),
		  mask(buffSize - 1)
	{
		// The whole point of the class: wrapping is an AND, which only works
		// when the size is a power of 2.
		assert((this->size & (this->size - 1)) == 0);
	}

	unsigned int CircularIndex::operator++(int)
	{
		this->index++;
		this->index = this->index & this->mask;

		return this->index;
	}

	bool CircularIndex::operator == (const CircularIndex &tmp)
	{
		assert(this->size == tmp.size);
		return (this->index == tmp.index);
	}

	bool CircularIndex::operator != (const CircularIndex &tmp)
	{
		assert(this->size == tmp.size);
		return (this->index != tmp.index);
	}

	unsigned int CircularIndex::Index() const
	{
		return this->index;
	}
}

// ---  End of File ---
