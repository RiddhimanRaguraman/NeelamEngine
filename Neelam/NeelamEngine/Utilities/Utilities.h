#pragma once

#include "PrimitiveTypes.h"

// Flip to 1 to fall back on the STL containers.
//
// Why we roll our own (USE_STL 0):
//   MSVC's Debug std::vector/std::deque allocate a 16-byte iterator-debug proxy
//   the moment they are CONSTRUCTED. Our component arrays are file-scope, so that
//   proxy is only released at static destruction -- which happens AFTER the
//   Framework's leak check runs, and so gets reported as a leak.
//
//   These containers deliberately allocate NOTHING while empty (_data == nullptr),
//   so an unused (or purged) file-scope instance costs zero heap. Combined with each
//   subsystem's shutdown() calling purge(), nothing is still allocated when the
//   tracker reports.
#define USE_STL 0

#if USE_STL
#include <vector>
#include <deque>
namespace Neelam::Util
{
	template <class T>
	using vector = std::vector<T>;

	template <class T>
	using deque = std::deque<T>;
}
#else
namespace Neelam::Util
{
	//-----------------------------------------------------------------------
	// Minimal dynamic array over a raw new[]/delete[] block.
	// Elements are stored by value and packed contiguously -- that is the whole
	// point of the component arrays: a system sweeps them as one linear walk.
	//-----------------------------------------------------------------------
	template <class T>
	class vector
	{
	public:
		vector() = default;
		~vector() { purge(); }

		vector(const vector&) = delete;
		vector& operator = (const vector&) = delete;

		T&       operator[](uint32_t i)       { assert(i < _count); return _data[i]; }
		const T& operator[](uint32_t i) const { assert(i < _count); return _data[i]; }

		uint32_t  size()  const { return _count; }
		bool empty() const { return _count == 0; }

		T*       begin()       { return _data; }
		T*       end()         { return _data + _count; }
		const T* begin() const { return _data; }
		const T* end()   const { return _data + _count; }

		void push_back(const T& v)
		{
			grow_if_full();
			_data[_count] = v;
			++_count;
		}

		// append a default-constructed element
		T& emplace_back()
		{
			grow_if_full();
			_data[_count] = T{};
			return _data[_count++];
		}

		T& emplace_back(const T& v)
		{
			grow_if_full();
			_data[_count] = v;
			return _data[_count++];
		}

		// remove one element, shuffling the tail down (keeps the array packed)
		void erase(T* it)
		{
			assert(it >= _data && it < _data + _count);
			for (T* k = it; k + 1 < _data + _count; ++k)
			{
				*k = *(k + 1);
			}
			--_count;
		}

		void swap(vector& o)
		{
			T*  d = _data;     _data     = o._data;     o._data     = d;
			u32 c = _count;    _count    = o._count;    o._count    = c;
			u32 p = _capacity; _capacity = o._capacity; o._capacity = p;
		}

		// Hand the buffer back to the allocator outright. shutdown() calls this so
		// nothing is still allocated when the leak check runs.
		void purge()
		{
			delete[] _data;
			_data     = nullptr;
			_count    = 0;
			_capacity = 0;
		}

	private:
		void grow_if_full()
		{
			if (_count < _capacity) return;

			// allocate bigger, copy across, drop the old block
			const uint32_t newCapacity = _capacity ? (_capacity * 2) : 8;
			T* pNew = new T[newCapacity];
			for (uint32_t i = 0; i < _count; ++i)
			{
				pNew[i] = _data[i];
			}
			delete[] _data;
			_data     = pNew;
			_capacity = newCapacity;
		}

		// Data Members

		T*  _data{ nullptr };
		uint32_t _count{ 0 };
		uint32_t _capacity{ 0 };
	};

	//-----------------------------------------------------------------------
	// Minimal FIFO queue over a raw block, kept as a ring so push_back and
	// pop_front are both O(1) and nothing is shuffled.
	//-----------------------------------------------------------------------
	template <class T>
	class deque
	{
	public:
		deque() = default;
		~deque() { purge(); }

		deque(const deque&) = delete;
		deque& operator = (const deque&) = delete;

		uint32_t  size()  const { return _count; }
		bool empty() const { return _count == 0; }

		T&       front()       { assert(_count > 0); return _data[_head]; }
		const T& front() const { assert(_count > 0); return _data[_head]; }

		void push_back(const T& v)
		{
			if (_count == _capacity) grow();
			_data[(_head + _count) % _capacity] = v;
			++_count;
		}

		void pop_front()
		{
			assert(_count > 0);
			_head = (_head + 1) % _capacity;
			--_count;
		}

		void swap(deque& o)
		{
			T*       d = _data;     _data     = o._data;     o._data     = d;
			uint32_t h = _head;     _head     = o._head;     o._head     = h;
			uint32_t c = _count;    _count    = o._count;    o._count    = c;
			uint32_t p = _capacity; _capacity = o._capacity; o._capacity = p;
		}

		void purge()
		{
			delete[] _data;
			_data     = nullptr;
			_head     = 0;
			_count    = 0;
			_capacity = 0;
		}

	private:
		void grow()
		{
			// unwrap the ring into a bigger block, head back to 0
			const uint32_t newCapacity = _capacity ? (_capacity * 2) : 8;
			T* pNew = new T[newCapacity];
			for (uint32_t i = 0; i < _count; ++i)
			{
				pNew[i] = _data[(_head + i) % _capacity];
			}
			delete[] _data;
			_data     = pNew;
			_head     = 0;
			_capacity = newCapacity;
		}

		T*  _data{ nullptr };
		uint32_t _head{ 0 };
		uint32_t _count{ 0 };
		uint32_t _capacity{ 0 };
	};
}
#endif
