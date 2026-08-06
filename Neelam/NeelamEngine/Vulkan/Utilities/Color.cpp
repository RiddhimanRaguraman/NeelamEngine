//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Color.h"


namespace Neelam
{
	Color::Color(const Azul::Vec3& v)
	{
		assert(v.x() >= 0.0f);
		assert(v.y() >= 0.0f);
		assert(v.z() >= 0.0f);

		this->red = v.x();
		this->green = v.y();
		this->blue = v.z();
		this->alpha = 1.0f;
	}

	Color::Color(const Azul::Vec4& v)
	{
		assert(v.x() >= 0.0f);
		assert(v.y() >= 0.0f);
		assert(v.z() >= 0.0f);
		assert(v.w() >= 0.0f);

		this->red = v.x();
		this->green = v.y();
		this->blue = v.z();
		this->alpha = v.w();
	}

	Color::Color(float red, float green, float blue, float alpha)
	{
		assert(red >= 0.0f);
		assert(green >= 0.0f);
		assert(blue >= 0.0f);
		assert(alpha >= 0.0f);

		this->red = red;
		this->green = green;
		this->blue = blue;
		this->alpha = alpha;
	}

	Color::Color()
	{
		this->red = 0.0f;
		this->green = 0.0f;
		this->blue = 0.0f;
		this->alpha = 1.0f;
	}

	void Color::Set(float _red, float _green, float _blue, float _alpha)
	{
		this->red = _red;
		this->green = _green;
		this->blue = _blue;
		this->alpha = _alpha;
	}

	void Color::Set(const Color& r)
	{
		this->red = r.red;
		this->green = r.green;
		this->blue = r.blue;
		this->alpha = r.alpha;
	}

	Color& Color::DefaultColor()
	{
		static Color col(Colors::White);
		return col;
	}


}

//--- End of File ---
