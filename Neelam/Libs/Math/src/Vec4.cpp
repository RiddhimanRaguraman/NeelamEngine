//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	Vec4::Vec4() :
		_vx(0.0f), _vy(0.0f), _vz(0.0f), _vw(0.0f)
	{
	}
	Vec4::Vec4(const Vec4& inV) :
		_vx(inV._vx), _vy(inV._vy), _vz(inV._vz), _vw(inV._vw)
	{
	}
	Vec4& Vec4::operator=(const Vec4& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		this->_vw = v._vw;
		return *this;
	}
	Vec4::~Vec4()
	{
	}

	Vec4::Vec4(const float in_x, const float in_y, const float in_z, const float in_w)
		: _vx(in_x),
		_vy(in_y),
		_vz(in_z),
		_vw(in_w)
	{
	}

	Vec4::Vec4(const Vec3& inV, const float w) :
		_vx(inV._vx), _vy(inV._vy), _vz(inV._vz), _vw(w)
	{
	}

	float& Vec4::operator[](x_enum) { return _vx; }
	float& Vec4::operator[](y_enum) { return _vy; }
	float& Vec4::operator[](z_enum) { return _vz; }
	float& Vec4::operator[](w_enum) { return _vw; }

	float  Vec4::operator[](x_enum) const { return _vx; }
	float  Vec4::operator[](y_enum) const { return _vy; }
	float  Vec4::operator[](z_enum) const { return _vz; }
	float  Vec4::operator[](w_enum) const { return _vw; }

	void Vec4::x(const float v) { this->_vx = v; }
	void Vec4::y(const float v) { this->_vy = v; }
	void Vec4::z(const float v) { this->_vz = v; }
	void Vec4::w(const float v) { this->_vw = v; }

	float Vec4::x() const { return this->_vx; }
	float Vec4::y() const { return this->_vy; }
	float Vec4::z() const { return this->_vz; }
	float Vec4::w() const { return this->_vw; }

	Vec4 Vec4::operator+(void) const
	{
		return *this;
	}

	Vec4 Vec4::operator+(const Vec4& inV) const
	{
		return Vec4((this->_vx + inV._vx), (this->_vy + inV._vy), (this->_vz + inV._vz), (this->_vw + inV._vw));
	}

	Vec4& Vec4::operator+=(const Vec4& inV)
	{
		this->_vx += inV._vx;
		this->_vy += inV._vy;
		this->_vz += inV._vz;
		this->_vw += inV._vw;
		return *this;
	}

	Vec4 Vec4::operator-(const Vec4& inV) const
	{
		return Vec4((this->_vx - inV._vx), (this->_vy - inV._vy), (this->_vz - inV._vz), (this->_vw - inV._vw));
	}

	Vec4 Vec4::operator-(void) const
	{
		return Vec4(-this->_vx, -this->_vy, -this->_vz, -this->_vw);
	}

	Vec4& Vec4::operator-=(const Vec4& inV)
	{
		this->_vx -= inV._vx;
		this->_vy -= inV._vy;
		this->_vz -= inV._vz;
		this->_vw -= inV._vw;
		return *this;
	}


	Vec4 Vec4::operator*(const float scale) const
	{
		return Vec4((this->_vx * scale), (this->_vy * scale), (this->_vz * scale), (this->_vw * scale));
	}

	Vec4 operator*(const float scale, const Vec4& inV)
	{
		return Vec4((inV._vx * scale), (inV._vy * scale), (inV._vz * scale), (inV._vw * scale));
	}

	Vec4& Vec4::operator*=(const float scale)
	{
		this->_vx *= scale;
		this->_vy *= scale;
		this->_vz *= scale;
		this->_vw *= scale;
		return *this;
	}

	Vec4 Vec4::operator*(const Mat4& m) const
	{
		const float rx = _vx * m.m0() + _vy * m.m4() + _vz * m.m8() + _vw * m.m12();
		const float ry = _vx * m.m1() + _vy * m.m5() + _vz * m.m9() + _vw * m.m13();
		const float rz = _vx * m.m2() + _vy * m.m6() + _vz * m.m10() + _vw * m.m14();
		const float rw = _vx * m.m3() + _vy * m.m7() + _vz * m.m11() + _vw * m.m15();

		return Vec4(rx, ry, rz, rw);
	}

	Vec4& Vec4::operator*=(const Mat4& m)
	{
		float x = _vx;
		float y = _vy;
		float z = _vz;
		float w = _vw;

		_vx = x * m.m0() + y * m.m4() + z * m.m8() + w * m.m12();
		_vy = x * m.m1() + y * m.m5() + z * m.m9() + w * m.m13();
		_vz = x * m.m2() + y * m.m6() + z * m.m10() + w * m.m14();
		_vw = x * m.m3() + y * m.m7() + z * m.m11() + w * m.m15();
		return *this;
	}



	Vec4& Vec4::norm(void)
	{
		float lenSq = this->dot(*this);
		if (lenSq > MATH_TOLERANCE)
		{
			lenSq = Azul::Trig::rsqrt(lenSq);
			_vx *= lenSq;
			_vy *= lenSq;
			_vz *= lenSq;
			_vw *= lenSq;
		}
		return *this;
	}

	Vec4 Vec4::getNorm(void) const
	{
		float lenSq = this->dot(*this);
		if (lenSq > MATH_TOLERANCE)
		{
			lenSq = Azul::Trig::rsqrt(lenSq);
		}
		return Vec4(_vx * lenSq, _vy * lenSq, _vz * lenSq, _vw * lenSq);
	}

	float Vec4::dot(const Vec4& vIn) const
	{
		return ((this->_vx * vIn._vx) + (this->_vy * vIn._vy) + (this->_vz * vIn._vz) + (this->_vw * vIn._vw));
	}

	Vec4Proxy Vec4::len() const
	{
		return Vec4Proxy(_vx, _vy, _vz, _vw);
	}

	void Vec4::set(const float inX, const float inY, const float inZ, const float inW)
	{
		this->_vx = inX;
		this->_vy = inY;
		this->_vz = inZ;
		this->_vw = inW;
		return;

	}

	void Vec4::set(const Vec4& A)
	{
		*this = A;
	}

	void Vec4::set(const Vec3& v, const float w)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		this->_vw = w;
	}

	bool Vec4::isEqual(const Vec4& v, const float epsilon) const
	{
		return  Azul::Util::isEqual(this->_vx, v._vx, epsilon) &&
			Azul::Util::isEqual(this->_vy, v._vy, epsilon) &&
			Azul::Util::isEqual(this->_vz, v._vz, epsilon) &&
			Azul::Util::isEqual(this->_vw, v._vw, epsilon);
	}

	bool Vec4::isZero(const float epsilon) const
	{
		return  Azul::Util::isEqual(this->_vx, 0.0f, epsilon) &&
			Azul::Util::isEqual(this->_vy, 0.0f, epsilon) &&
			Azul::Util::isEqual(this->_vz, 0.0f, epsilon) &&
			Azul::Util::isEqual(this->_vw, 0.0f, epsilon);
	}

	void Vec4::Print(const char* pName) const
	{
		const float px = (fabs(_vx) >= MATH_PRINT_TOLERANCE) ? _vx : 0.0f;
		const float py = (fabs(_vy) >= MATH_PRINT_TOLERANCE) ? _vy : 0.0f;
		const float pz = (fabs(_vz) >= MATH_PRINT_TOLERANCE) ? _vz : 0.0f;
		const float pw = (fabs(_vw) >= MATH_PRINT_TOLERANCE) ? _vw : 0.0f;

		if (pName != nullptr)
		{
			Trace::out("%s: ( %f , %f , %f , %f )\n", pName,
				static_cast<double>(px),
				static_cast<double>(py),
				static_cast<double>(pz),
				static_cast<double>(pw));
		}
		else
		{
			Trace::out("( %f , %f , %f , %f )\n",
				static_cast<double>(px),
				static_cast<double>(py),
				static_cast<double>(pz),
				static_cast<double>(pw));
		}
	}
}

//--- End of File ---
