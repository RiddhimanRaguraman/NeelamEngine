#pragma once

#define USE_STL 1

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
	// TODO: Implement our own vector
	template <class T>
	class vector {};

	// TODO: Implement our own deque
	template <class T>
	class deque {};
}
#endif