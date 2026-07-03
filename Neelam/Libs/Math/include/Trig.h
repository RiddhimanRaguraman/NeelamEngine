//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_TRIG_H
#define ENGINE_MATH_TRIG_H

#include "Math_DLLInterface.h"

namespace Azul
{
	class Trig
	{
	public:

		// Do your magic here

		MATH_LIBRARY_API static float cos(const float  angle_radians);
		MATH_LIBRARY_API static float sin(const float  angle_radians);
		MATH_LIBRARY_API static float tan(const float  val);
		MATH_LIBRARY_API static float atan(const float val);
		MATH_LIBRARY_API static float atan2(const float x, const float y);
		MATH_LIBRARY_API static float acos(const float val);
		MATH_LIBRARY_API static float asin(const float val);
		MATH_LIBRARY_API static void  cossin(float &cos, float &sin, const float angle_radians);
		MATH_LIBRARY_API static float sqrt(const float val);
		MATH_LIBRARY_API static float rsqrt(const float val);
	};
}

#endif

//--- End of File ---
