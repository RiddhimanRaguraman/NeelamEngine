//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	// Add Proxy here
	Vec4Proxy::Vec4Proxy(float a, float b, float c, float d)
		: x(a), y(b), z(c), w(d)
	{
	}

	Vec4Proxy::operator float() const
	{
		return Azul::Trig::sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	float Vec4Proxy::operator*(const Vec4Proxy& r) const
	{
		const float lenA = static_cast<float>(*this);   // |a|
		const float lenB = static_cast<float>(r);       // |b|
		return lenA * lenB;
	}

	bool Vec4Proxy::operator>(const Vec4Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w) > (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w));
	}

	bool Vec4Proxy::operator<(const Vec4Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w) < (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w));
	}

	bool Vec4Proxy::operator==(const Vec4Proxy& r) const
	{
		float input = (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w);
		float owner = (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		return ((owner == input));
	}

	bool Vec4Proxy::operator>=(const Vec4Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w) >= (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w));
	}

	bool Vec4Proxy::operator<=(const Vec4Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w) <= (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w));
	}

	bool Vec4Proxy::operator!=(const Vec4Proxy& r) const
	{
		float input = (r.x * r.x + r.y * r.y + r.z * r.z + r.w * r.w);
		float owner = (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		return ((owner != input));
	}

}

//--- End of File ---
