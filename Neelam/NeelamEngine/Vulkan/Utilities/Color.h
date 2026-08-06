//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef COLOR_H
#define COLOR_H
#include "MathEngine.h"
#include "Colors.h"
namespace Neelam
{
	// matches Vec4 for casting reasons. Align16 is global (from Framework.h);
	// Vec3/Vec4 are Azul math types, so they stay Azul-qualified.
	class Color final : public Align16
	{
	public:
		Color();
		Color(const Color& r) = default;
		Color& operator=(const Color&) = default;
		Color(const Azul::Vec3& v);
		Color(const Azul::Vec4& v);
		Color(float red, float green, float blue, float alpha = 1.0f);
		~Color() = default;

		void Set(float red, float green, float blue, float alpha = 1.0f);
		void Set(const Color& r);
		static Color& DefaultColor();

		union
		{
			/*                             */
			/*   color  = | x  y  z  w |   */
			/*                             */

			__m128	_mv;

			// anonymous struct
			struct
			{
				float red;
				float green;
				float blue;
				float alpha;
			};
		};

	private:

	};
}

#endif

//--- End of File ---
