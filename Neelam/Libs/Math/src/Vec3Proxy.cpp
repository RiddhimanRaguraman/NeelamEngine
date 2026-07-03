//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	Vec3Proxy::Vec3Proxy(float a, float b, float c)
		: x(a), y(b), z(c)
	{
	}

	Vec3Proxy::operator float() const
	{
		return Azul::Trig::sqrt((x * x) + (y * y) + (z * z));
	}

	float Vec3Proxy::operator*(const Vec3Proxy& r) const
	{
		const float lenA = static_cast<float>(*this);   // |a|
		const float lenB = static_cast<float>(r);       // |b|
		return lenA * lenB;
	}

	bool Vec3Proxy::operator>(const Vec3Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z) > (r.x * r.x + r.y * r.y + r.z * r.z));
	}

	bool Vec3Proxy::operator<(const Vec3Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z) < (r.x * r.x + r.y * r.y + r.z * r.z));;
	}

	bool Vec3Proxy::operator==(const Vec3Proxy& r) const
	{
		float input = (r.x * r.x + r.y * r.y + r.z * r.z);
		float owner = (this->x * this->x + this->y * this->y + this->z * this->z);
		return ((owner == input));
	}

	bool Vec3Proxy::operator>=(const Vec3Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z) >= (r.x * r.x + r.y * r.y + r.z * r.z));
	}

	bool Vec3Proxy::operator<=(const Vec3Proxy& r) const
	{
		return ((this->x * this->x + this->y * this->y + this->z * this->z) <= (r.x * r.x + r.y * r.y + r.z * r.z));
	}

	bool Vec3Proxy::operator!=(const Vec3Proxy& r) const
	{
		float input = (r.x * r.x + r.y * r.y + r.z * r.z);
		float owner = (this->x * this->x + this->y * this->y + this->z * this->z);
		return ((owner != input));
	}
}

//--- End of File ---
