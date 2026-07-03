//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MAT4_PROXY_H
#define ENGINE_MATH_MAT4_PROXY_H

#include "Math_DLLInterface.h"

namespace Azul
{
	// Matrix related proxies here:
	struct Mat4Proxy
	{
		MATH_LIBRARY_API inline Mat4Proxy(Mat4 &rMat, float &_x)
			: ref(rMat), x(_x)
		{
		}

		MATH_LIBRARY_API inline Mat4Proxy operator = (float v)
		{
			x = v;

			// no knowledge on how changing this variable affects the matrix
			// so make it general hint
			ref._u_m15 &= (unsigned int) (0xFFFFFFF8);

			return *this;
		}

		MATH_LIBRARY_API inline operator float()
		{
			return this->x;
		}

		Mat4 &ref;
		float &x;
	};

}

#endif

//--- End of File ---
