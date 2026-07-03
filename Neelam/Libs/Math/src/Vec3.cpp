//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	Vec3::Vec3() :
		_vx(0.0f),
		_vy(0.0f),
		_vz(0.0f)
	{

	}

	Vec3::Vec3(const Vec3& inV)
		: _mv(inV._mv)
	{
	}

	Vec3& Vec3::operator=(const Vec3& v)
	{
		if (this != &v)
		{
			_mv = v._mv;
		}
		return *this;
	}

	Vec3::~Vec3()
	{
	}

	Vec3::Vec3(const float in_x, const float in_y, const float in_z)
		: _vx(in_x),
		_vy(in_y),
		_vz(in_z)
	{
	}

	Vec3::Vec3(const Vec4& v)
		: _vx(v._vx),
		_vy(v._vy),
		_vz(v._vz)
	{

	}

	Vec3& Vec3::operator=(const Vec4& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		return *this;
	}



	float& Vec3::operator[](x_enum) { return _vx; }
	float& Vec3::operator[](y_enum) { return _vy; }
	float& Vec3::operator[](z_enum) { return _vz; }

	float  Vec3::operator[](x_enum) const { return _vx; }
	float  Vec3::operator[](y_enum) const { return _vy; }
	float  Vec3::operator[](z_enum) const { return _vz; }

	void Vec3::x(const float v)
	{
		this->_vx = v;
	}

	void Vec3::y(const float v)
	{
		this->_vy = v;
	}

	void Vec3::z(const float v)
	{
		this->_vz = v;
	}

	float Vec3::x() const
	{
		return _vx;
	}

	float Vec3::y() const
	{
		return _vy;
	}

	float Vec3::z() const
	{
		return _vz;
	}

	Vec3 Vec3::operator+(void) const
	{
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& inV) const
	{
		return Vec3(this->_vx + inV._vx, this->_vy + inV._vy, this->_vz + inV._vz);
	}

	Vec3& Vec3::operator+=(const Vec3& inV)
	{
		this->_vx += inV._vx;
		this->_vy += inV._vy;
		this->_vz += inV._vz;
		return *this;
	}

	Vec3 Vec3::operator-(void) const
	{
		return Vec3(-_vx, -_vy, -_vz);
	}

	Vec3 Vec3::operator-(const Vec3& inV) const
	{
		return Vec3(this->_vx - inV._vx, this->_vy - inV._vy, this->_vz - inV._vz);
	}

	Vec3& Vec3::operator-=(const Vec3& inV)
	{
		this->_vx -= inV._vx;
		this->_vy -= inV._vy;
		this->_vz -= inV._vz;
		return *this;
	}

	Vec3 Vec3::operator*(const float scale) const
	{
		return Vec3(_vx * scale, _vy * scale, _vz * scale);
	}

	Vec3 operator*(const float scale, const Vec3& inV)
	{
		return Vec3(scale * inV[x], scale * inV[y], scale * inV[z]);
	}

	Vec3& Vec3::operator*=(const float scale)
	{
		this->_vx *= scale;
		this->_vy *= scale;
		this->_vz *= scale;
		return *this;
	}

	Vec3 Vec3::operator*(const Mat3& m) const
	{
		const float rx = _vx * m.m0() + _vy * m.m4() + _vz * m.m8();
		const float ry = _vx * m.m1() + _vy * m.m5() + _vz * m.m9();
		const float rz = _vx * m.m2() + _vy * m.m6() + _vz * m.m10();

		return Vec3(rx, ry, rz);
	}

	Vec3& Vec3::operator*=(const Mat3& m)
	{
		float x = _vx;
		float y = _vy;
		float z = _vz;

		_vx = x * m.m0() + y * m.m4() + z * m.m8();
		_vy = x * m.m1() + y * m.m5() + z * m.m9();
		_vz = x * m.m2() + y * m.m6() + z * m.m10();

		return *this;
	}

	// Rotate vector by quaternion: v' = v + w*(2*u x v) + u x (2*u x v)
	Vec3 Vec3::operator*(const Quat& q) const
	{
		const Vec3 u(q.qx(), q.qy(), q.qz());
		const float w = q.qw();
		const Vec3 t = 2.0f * u.cross(*this);
		return (*this + w * t) + u.cross(t);
	}

	Vec3& Vec3::operator*=(const Quat& q)
	{
		*this = (*this) * q;
		return *this;
	}

	Vec3& Vec3::norm(void)
	{
		constexpr float kEpsilon = 1.0e-6f;
		const float lenSq = this->dot(*this);
		if (lenSq > kEpsilon)
		{
			const float invLen = 1.0f / Azul::Trig::sqrt(lenSq);
			this->_vx *= invLen;
			this->_vy *= invLen;
			this->_vz *= invLen;
		}
		return *this;

	}

	Vec3 Vec3::getNorm(void) const
	{
		float lenSq = this->dot(*this);
		constexpr float kEpsilon = 1.0e-6f;
		if (lenSq > kEpsilon)
		{
			lenSq = Azul::Trig::rsqrt(lenSq);
		}
		return Vec3(_vx * lenSq, _vy * lenSq, _vz * lenSq);
	}

	float Vec3::dot(const Vec3& vIn) const
	{
		return (this->_vx * vIn._vx + this->_vy * vIn._vy + this->_vz * vIn._vz);
	}

	Vec3 Vec3::cross(const Vec3& rhs) const
	{
		const float cx = (_vy * rhs._vz) - (_vz * rhs._vy);
		const float cy = (_vz * rhs._vx) - (_vx * rhs._vz);
		const float cz = (_vx * rhs._vy) - (_vy * rhs._vx);

		return Vec3(cx, cy, cz);
	}

	Vec3Proxy Vec3::len(void) const
	{
		return Vec3Proxy(_vx, _vy, _vz);
	}

	float Vec3::getAngle(const Vec3& vIn) const
	{
		constexpr float kEpsilon = 1.0e-6f;
		const float dotProd = this->dot(vIn);
		const float denom = this->len() * vIn.len();

		if (denom < kEpsilon)
			return 0.0f;

		float cosTheta = dotProd / denom;
		if (cosTheta > 1.0f) cosTheta = 1.0f;
		if (cosTheta < -1.0f) cosTheta = -1.0f;

		return Azul::Trig::acos(cosTheta);
	}

	void Vec3::set(const float inX, const float inY, const float inZ)
	{
		this->_vx = inX;
		this->_vy = inY;
		this->_vz = inZ;
		return;
	}

	void Vec3::set(const Vec3& A)
	{
		*this = A;
		return;
	}

	void Vec3::set(const Vec4& A)
	{
		this->_vx = A._vx;
		this->_vy = A._vy;
		this->_vz = A._vz;
		return;
	}

	bool Vec3::isEqual(const Vec3& v, const float epsilon) const
	{
		return  Azul::Util::isEqual(_vx, v._vx, epsilon) &&
			Azul::Util::isEqual(_vy, v._vy, epsilon) &&
			Azul::Util::isEqual(_vz, v._vz, epsilon);
	}

	bool Vec3::isZero(const float epsilon) const
	{
		return  Azul::Util::isEqual(_vx, 0.0f, epsilon) &&
			Azul::Util::isEqual(_vy, 0.0f, epsilon) &&
			Azul::Util::isEqual(_vz, 0.0f, epsilon);
	}

	void Vec3::Print(const char* pName) const
	{
		const float px = (fabs(_vx) >= MATH_PRINT_TOLERANCE) ? _vx : 0.0f;
		const float py = (fabs(_vy) >= MATH_PRINT_TOLERANCE) ? _vy : 0.0f;
		const float pz = (fabs(_vz) >= MATH_PRINT_TOLERANCE) ? _vz : 0.0f;

		if (pName != nullptr)
		{
			Trace::out("%s: ( %f , %f , %f )\n", pName,
				static_cast<double>(px),
				static_cast<double>(py),
				static_cast<double>(pz));
		}
		else
		{
			Trace::out("( %f , %f , %f )\n",
				static_cast<double>(px),
				static_cast<double>(py),
				static_cast<double>(pz));
		}
	}

}
//--- End of File ---
