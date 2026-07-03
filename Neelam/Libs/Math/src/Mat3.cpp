//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	// Do your magic here

	Mat3::Mat3() :
		_v0(0.0f, 0.0f, 0.0f, 0.0f),
		_v1(0.0f, 0.0f, 0.0f, 0.0f),
		_v2(0.0f, 0.0f, 0.0f, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}

	Mat3& Mat3::operator=(const Mat3& A)
	{
		this->_v0 = A._v0;
		this->_v1 = A._v1;
		this->_v2 = A._v2;
		this->_v3 = A._v3;
		return *this;
	}

	Mat3::Mat3(const Mat3& tM)
	{
		*this = tM;
	}

	Mat3::~Mat3()
	{
	}

	Mat3::Mat3(const Vec3& tV0, const Vec3& tV1, const Vec3& tV2)
		: _v0(tV0, 0.0f),
		_v1(tV1, 0.0f),
		_v2(tV2, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 1.0f)
	{

	}

	Mat3::Mat3(const Mat4& m)
		: _v0(m._m0, m._m1, m._m2, 0.0f),
		_v1(m._m4, m._m5, m._m6, 0.0f),
		_v2(m._m8, m._m9, m._m10, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 1.0f)
	{
	}

	Vec3 Mat3::get(const Row3 type) const
	{
		switch (type)
		{
		case Row3::i0:
			return Vec3(this->_m0, this->_m1, this->_m2);
		case Row3::i1:
			return Vec3(this->_m4, this->_m5, this->_m6);
		case Row3::i2:
			return Vec3(this->_m8, this->_m9, this->_m10);
		default:
			// Default case to ensure all code paths return a value
			assert(false);
			return Vec3();
		}
	}

	void Mat3::set(const Mat3& mIn)
	{
		*this = mIn;
	}

	void Mat3::set(const enum Identity_enum)
	{
		this->_v0.set(1.0f, 0.0f, 0.0f, 0.0f);
		this->_v1.set(0.0f, 1.0f, 0.0f, 0.0f);
		this->_v2.set(0.0f, 0.0f, 1.0f, 0.0f);
		this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void Mat3::set(const Row3 type, const Vec3& V)
	{
		switch (type)
		{
		case Row3::i0:
			this->_v0.set(V, 0);
			break;
		case Row3::i1:
			this->_v1.set(V, 0);
			break;
		case Row3::i2:
			this->_v2.set(V, 0);
			break;
		}
	}

	void Mat3::set(const Vec3& V0, const Vec3& V1, const Vec3& V2)
	{
		this->_v0.set(V0, 0);
		this->_v1.set(V1, 0);
		this->_v2.set(V2, 0);
		this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);
	}

	Mat3::Mat3(const enum Identity_enum)
		: _v0(1.0f, 0.0f, 0.0f, 0.0f),
		_v1(0.0f, 1.0f, 0.0f, 0.0f),
		_v2(0.0f, 0.0f, 1.0f, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 1.0f)
	{

	}

	float& Mat3::operator[](const m0_enum) { return this->_m0; }
	float& Mat3::operator[](const m1_enum) { return this->_m1; }
	float& Mat3::operator[](const m2_enum) { return this->_m2; }
	float& Mat3::operator[](const m4_enum) { return this->_m4; }
	float& Mat3::operator[](const m5_enum) { return this->_m5; }
	float& Mat3::operator[](const m6_enum) { return this->_m6; }
	float& Mat3::operator[](const m8_enum) { return this->_m8; }
	float& Mat3::operator[](const m9_enum) { return this->_m9; }
	float& Mat3::operator[](const m10_enum) { return this->_m10; }

	float Mat3::operator[](const m0_enum)  const { return this->_m0; }
	float Mat3::operator[](const m1_enum)  const { return this->_m1; }
	float Mat3::operator[](const m2_enum)  const { return this->_m2; }
	float Mat3::operator[](const m4_enum)  const { return this->_m4; }
	float Mat3::operator[](const m5_enum)  const { return this->_m5; }
	float Mat3::operator[](const m6_enum)  const { return this->_m6; }
	float Mat3::operator[](const m8_enum)  const { return this->_m8; }
	float Mat3::operator[](const m9_enum)  const { return this->_m9; }
	float Mat3::operator[](const m10_enum) const { return this->_m10; }

	void Mat3::m0(const float v) { this->_m0 = v; }
	void Mat3::m1(const float v) { this->_m1 = v; }
	void Mat3::m2(const float v) { this->_m2 = v; }
	void Mat3::m4(const float v) { this->_m4 = v; }
	void Mat3::m5(const float v) { this->_m5 = v; }
	void Mat3::m6(const float v) { this->_m6 = v; }
	void Mat3::m8(const float v) { this->_m8 = v; }
	void Mat3::m9(const float v) { this->_m9 = v; }
	void Mat3::m10(const float v) { this->_m10 = v; }

	float Mat3::m0() const { return this->_m0; }
	float Mat3::m1() const { return this->_m1; }
	float Mat3::m2() const { return this->_m2; }
	float Mat3::m4() const { return this->_m4; }
	float Mat3::m5() const { return this->_m5; }
	float Mat3::m6() const { return this->_m6; }
	float Mat3::m8() const { return this->_m8; }
	float Mat3::m9() const { return this->_m9; }
	float Mat3::m10() const { return this->_m10; }

	float Mat3::det() const
	{
		return (this->_m5 * this->_m10 - this->_m9 * this->_m6) * this->_m0
			- (this->_m4 * this->_m10 - this->_m8 * this->_m6) * this->_m1
			+ (this->_m4 * this->_m9 - this->_m8 * this->_m5) * this->_m2;
	}

	Mat3& Mat3::T(void)
	{
		{
			float tmp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = tmp;
		}

		{
			float tmp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = tmp;
		}

		{
			float tmp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = tmp;
		}

		return *this;
	}

	Mat3 Mat3::getT(void) const
	{
		return Mat3(
			Vec3(this->_m0, this->_m4, this->_m8),
			Vec3(this->_m1, this->_m5, this->_m9),
			Vec3(this->_m2, this->_m6, this->_m10)
		);
	}

	Mat3 Mat3::getInv(void) const
	{
		const float detVal = this->det();
		const float invDet = 1.0f / detVal;
		Mat3 inv = this->privGetAdj();
		inv *= invDet;
		return inv;
	}

	Mat3& Mat3::inv(void)
	{
		const float detVal = this->det();
		const float invDet = 1.0f / detVal;
		Mat3 adj = this->privGetAdj();
		adj *= invDet;
		*this = adj;
		return *this;
	}

	Mat3 Mat3::privGetAdj() const
	{
		const float c00 = _m5 * _m10 - _m6 * _m9;
		const float c01 = _m6 * _m8 - _m4 * _m10;
		const float c02 = _m4 * _m9 - _m5 * _m8;

		const float c10 = _m2 * _m9 - _m1 * _m10;
		const float c11 = _m0 * _m10 - _m2 * _m8;
		const float c12 = _m1 * _m8 - _m0 * _m9;

		const float c20 = _m1 * _m6 - _m2 * _m5;
		const float c21 = _m2 * _m4 - _m0 * _m6;
		const float c22 = _m0 * _m5 - _m1 * _m4;

		return Mat3(
			Vec3(c00, c10, c20),
			Vec3(c01, c11, c21),
			Vec3(c02, c12, c22)
		);
	}

	bool Mat3::isEqual(const Mat3& A, const float epsilon) const
	{
		return Util::isEqual(_m0, A._m0, epsilon) &&
			Util::isEqual(_m1, A._m1, epsilon) &&
			Util::isEqual(_m2, A._m2, epsilon) &&

			Util::isEqual(_m4, A._m4, epsilon) &&
			Util::isEqual(_m5, A._m5, epsilon) &&
			Util::isEqual(_m6, A._m6, epsilon) &&

			Util::isEqual(_m8, A._m8, epsilon) &&
			Util::isEqual(_m9, A._m9, epsilon) &&
			Util::isEqual(_m10, A._m10, epsilon);
	}

	bool Mat3::isIdentity(const float epsilon) const
	{
		return Util::isEqual(_m0, 1.0f, epsilon) &&
			Util::isEqual(_m1, 0.0f, epsilon) &&
			Util::isEqual(_m2, 0.0f, epsilon) &&

			Util::isEqual(_m4, 0.0f, epsilon) &&
			Util::isEqual(_m5, 1.0f, epsilon) &&
			Util::isEqual(_m6, 0.0f, epsilon) &&

			Util::isEqual(_m8, 0.0f, epsilon) &&
			Util::isEqual(_m9, 0.0f, epsilon) &&
			Util::isEqual(_m10, 1.0f, epsilon);
	}

	Mat3 Mat3::operator+(void) const
	{
		return *this;
	}

	Mat3 Mat3::operator+(const Mat3& A) const
	{
		const Vec3 r0(_m0 + A._m0, _m1 + A._m1, _m2 + A._m2);
		const Vec3 r1(_m4 + A._m4, _m5 + A._m5, _m6 + A._m6);
		const Vec3 r2(_m8 + A._m8, _m9 + A._m9, _m10 + A._m10);
		return Mat3(r0, r1, r2);
	}

	Mat3& Mat3::operator+=(const Mat3& A)
	{
		_m0 += A._m0;
		_m1 += A._m1;
		_m2 += A._m2;
		_m3 = 0.0f;

		_m4 += A._m4;
		_m5 += A._m5;
		_m6 += A._m6;
		_m7 = 0.0f;

		_m8 += A._m8;
		_m9 += A._m9;
		_m10 += A._m10;
		_m11 = 0.0f;

		_m12 = 0.0f;
		_m13 = 0.0f;
		_m14 = 0.0f;
		_m15 = 1.0f;

		return *this;
	}

	Mat3 Mat3::operator-(void) const
	{
		const Vec3 r0(-_m0, -_m1, -_m2);
		const Vec3 r1(-_m4, -_m5, -_m6);
		const Vec3 r2(-_m8, -_m9, -_m10);
		return Mat3(r0, r1, r2);
	}

	Mat3 Mat3::operator-(const Mat3& A) const
	{
		const Vec3 r0(_m0 - A._m0, _m1 - A._m1, _m2 - A._m2);
		const Vec3 r1(_m4 - A._m4, _m5 - A._m5, _m6 - A._m6);
		const Vec3 r2(_m8 - A._m8, _m9 - A._m9, _m10 - A._m10);
		return Mat3(r0, r1, r2);
	}

	Mat3& Mat3::operator-=(const Mat3& A)
	{
		_m0 -= A._m0;
		_m1 -= A._m1;
		_m2 -= A._m2;
		_m3 = 0.0f;

		_m4 -= A._m4;
		_m5 -= A._m5;
		_m6 -= A._m6;
		_m7 = 0.0f;

		_m8 -= A._m8;
		_m9 -= A._m9;
		_m10 -= A._m10;
		_m11 = 0.0f;

		_m12 = 0.0f;
		_m13 = 0.0f;
		_m14 = 0.0f;
		_m15 = 1.0f;

		return *this;
	}

	Mat3 Mat3::operator*(const float s) const
	{
		const Vec3 r0(_m0 * s, _m1 * s, _m2 * s);
		const Vec3 r1(_m4 * s, _m5 * s, _m6 * s);
		const Vec3 r2(_m8 * s, _m9 * s, _m10 * s);
		return Mat3(r0, r1, r2);
	}

	Mat3& Mat3::operator*=(const float scale)
	{
		_m0 *= scale;
		_m1 *= scale;
		_m2 *= scale;
		_m3 = 0.0f;

		_m4 *= scale;
		_m5 *= scale;
		_m6 *= scale;
		_m7 = 0.0f;

		_m8 *= scale;
		_m9 *= scale;
		_m10 *= scale;
		_m11 = 0.0f;

		_m12 = 0.0f;
		_m13 = 0.0f;
		_m14 = 0.0f;
		_m15 = 1.0f;

		return *this;
	}

	Mat3 Mat3::operator*(const Mat3& rhs) const
	{
		const Vec3 r0(_m0 * rhs._m0 + _m1 * rhs._m4 + _m2 * rhs._m8,
			_m0 * rhs._m1 + _m1 * rhs._m5 + _m2 * rhs._m9,
			_m0 * rhs._m2 + _m1 * rhs._m6 + _m2 * rhs._m10);

		const Vec3 r1(_m4 * rhs._m0 + _m5 * rhs._m4 + _m6 * rhs._m8,
			_m4 * rhs._m1 + _m5 * rhs._m5 + _m6 * rhs._m9,
			_m4 * rhs._m2 + _m5 * rhs._m6 + _m6 * rhs._m10);

		const Vec3 r2(_m8 * rhs._m0 + _m9 * rhs._m4 + _m10 * rhs._m8,
			_m8 * rhs._m1 + _m9 * rhs._m5 + _m10 * rhs._m9,
			_m8 * rhs._m2 + _m9 * rhs._m6 + _m10 * rhs._m10);

		return Mat3(r0, r1, r2);
	}

	Mat3& Mat3::operator*=(const Mat3& rhs)
	{
		_v0.set(
			_m0 * rhs._m0 + _m1 * rhs._m4 + _m2 * rhs._m8,
			_m0 * rhs._m1 + _m1 * rhs._m5 + _m2 * rhs._m9,
			_m0 * rhs._m2 + _m1 * rhs._m6 + _m2 * rhs._m10,
			0.0f);

		_v1.set(
			_m4 * rhs._m0 + _m5 * rhs._m4 + _m6 * rhs._m8,
			_m4 * rhs._m1 + _m5 * rhs._m5 + _m6 * rhs._m9,
			_m4 * rhs._m2 + _m5 * rhs._m6 + _m6 * rhs._m10,
			0.0f);

		_v2.set(
			_m8 * rhs._m0 + _m9 * rhs._m4 + _m10 * rhs._m8,
			_m8 * rhs._m1 + _m9 * rhs._m5 + _m10 * rhs._m9,
			_m8 * rhs._m2 + _m9 * rhs._m6 + _m10 * rhs._m10,
			0.0f);

		_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

		return *this;
	}

	void Mat3::Print(const char* pName) const
	{
		const float a00 = (fabs(_m0) >= MATH_PRINT_TOLERANCE) ? _m0 : 0.0f;
		const float a01 = (fabs(_m1) >= MATH_PRINT_TOLERANCE) ? _m1 : 0.0f;
		const float a02 = (fabs(_m2) >= MATH_PRINT_TOLERANCE) ? _m2 : 0.0f;

		const float a10 = (fabs(_m4) >= MATH_PRINT_TOLERANCE) ? _m4 : 0.0f;
		const float a11 = (fabs(_m5) >= MATH_PRINT_TOLERANCE) ? _m5 : 0.0f;
		const float a12 = (fabs(_m6) >= MATH_PRINT_TOLERANCE) ? _m6 : 0.0f;

		const float a20 = (fabs(_m8) >= MATH_PRINT_TOLERANCE) ? _m8 : 0.0f;
		const float a21 = (fabs(_m9) >= MATH_PRINT_TOLERANCE) ? _m9 : 0.0f;
		const float a22 = (fabs(_m10) >= MATH_PRINT_TOLERANCE) ? _m10 : 0.0f;

		Trace::out("\n%s\n", pName);
		Trace::out("   % .5f % .5f % .5f\n", a00, a01, a02);
		Trace::out("   % .5f % .5f % .5f\n", a10, a11, a12);
		Trace::out("   % .5f % .5f % .5f\n\n", a20, a21, a22);
	}

	Mat3 operator*(const float s, const Mat3& m)
	{
		const Vec3 r0(s * m._m0, s * m._m1, s * m._m2);
		const Vec3 r1(s * m._m4, s * m._m5, s * m._m6);
		const Vec3 r2(s * m._m8, s * m._m9, s * m._m10);
		return Mat3(r0, r1, r2);
	}

}

// ---  End of File ---
