//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "MathApp.h"

//----------------------------------------------------------------------------- 
// Mutates result to be a slerp between the source and target by the
// specified factor.
// For a factor of 0.0, result == source.
// For a factor of 1.0, result == target.
//----------------------------------------------------------------------------- 

namespace Azul
{
	void QuatApp::Slerp(Quat &result, const Quat &src, const Quat &tar, const float slerpFactor)
	{
		Quat target;
		const float QUAT_EPSILON = 0.001f;

		float cosom = src.dot(tar);

		if (cosom >= 1.0f)
		{
			// source and target are identical
			result = src;
		}
		else
		{
			// adjust signs if necessary
			if (cosom < 0.0f)
			{
				// negate: angle is too large (> 90deg)
				cosom = -cosom;
				target = -tar;
			}
			else
			{
				// small angle (< 90deg), keep target as-is
				target = tar;
			}

			// default to linear blend factors
			float tarFactor = slerpFactor;
			float srcFactor = 1.0f - slerpFactor;

			// if quats are not close, use spherical interpolation
			if (cosom < (1.0f - QUAT_EPSILON))
			{
				const float omega = acosf(cosom);
				const float sinom = 1.0f / sinf(omega);

				srcFactor = sinf(srcFactor * omega) * sinom;
				tarFactor = sinf(tarFactor * omega) * sinom;
			}

			result.set(
				src[x] * srcFactor + target[x] * tarFactor,
				src[y] * srcFactor + target[y] * tarFactor,
				src[z] * srcFactor + target[z] * tarFactor,
				src[w] * srcFactor + target[w] * tarFactor);
		}
	}

	void QuatApp::SlerpArray(Quat *result, const Quat *source, const Quat *target, const float slerpFactor, const int numQuats)
	{
		for (int i = 0; i < numQuats; ++i)
		{
			Slerp(result[i], source[i], target[i], slerpFactor);
		}
	}
}

// ---  End of File ---------------
