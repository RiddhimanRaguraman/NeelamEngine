//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CIRCULAR_INDEX_H
#define CIRCULAR_INDEX_H

//---------------------------------------------------------------------------
// class CircularIndex
//
// An index that wraps. The buffer size is forced to a power of 2, so the wrap
// is a single AND against (size-1) instead of a modulo -- no division in the
// hot path, and no branch.
//
// Deliberately dumb: it knows nothing about what it indexes. CircularData
// keeps one of these for the front and one for the back, and compares them to
// decide empty/full.
//---------------------------------------------------------------------------

namespace Neelam
{
	class CircularIndex
	{
	public:
		CircularIndex(unsigned int buffSize);

		CircularIndex() = delete;
		CircularIndex(const CircularIndex &) = delete;
		const CircularIndex &operator = (const CircularIndex &) = delete;
		~CircularIndex() = default;

		// postfix -- advances, wraps, and returns the NEW index
		unsigned int operator++(int);

		bool operator == (const CircularIndex &tmp);
		bool operator != (const CircularIndex &tmp);

		unsigned int Index() const;

	private:
		unsigned int index;
		unsigned int size;
		unsigned int mask;
	};
}

#endif   // CIRCULAR_INDEX_H

// ---  End of File ---
