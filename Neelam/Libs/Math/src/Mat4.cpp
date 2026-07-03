//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "Mat4Hint.h"

namespace Azul
{
	Mat4::Mat4() :
		_v0(0.0f, 0.0f, 0.0f, 0.0f),
		_v1(0.0f, 0.0f, 0.0f, 0.0f),
		_v2(0.0f, 0.0f, 0.0f, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 0.0f)
	{
	}

	Mat4& Mat4::operator=(const Mat4& A)
	{
		this->_v0 = A._v0;
		this->_v1 = A._v1;
		this->_v2 = A._v2;
		this->_v3 = A._v3;
		return *this;
	}

	Mat4::Mat4(const Mat4& tM)
	{
		*this = tM;
	}

	Mat4::~Mat4()
	{
	}

	Mat4::Mat4(const Vec4& tV0, const Vec4& tV1, const Vec4& tV2, const Vec4& tV3) :
		_v0(tV0),
		_v1(tV1),
		_v2(tV2),
		_v3(tV3)
	{
	}

	Mat4::Mat4(const enum Identity_enum)
		: _v0(1.0f, 0.0f, 0.0f, 0.0f),
		_v1(0.0f, 1.0f, 0.0f, 0.0f),
		_v2(0.0f, 0.0f, 1.0f, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 1.0f)
	{

	}

	Mat4::Mat4(const Quat& q)
	{
		this->set(q);
	}

	void Mat4::set(const Mat4& mIn)
	{
		*this = mIn;
	}

	void Mat4::set(const Vec4& V0, const Vec4& V1, const Vec4& V2, const Vec4& V3)
	{
		this->_v0 = V0;
		this->_v1 = V1;
		this->_v2 = V2;
		this->_v3 = V3;
	}

void Mat4::set(const enum Identity_enum)
{

    Mat4Hint::Hint prevHint = ((Mat4Hint&)*this).GetHint();
    this->_v0.set(1.0f, 0.0f, 0.0f, 0.0f);
    this->_v1.set(0.0f, 1.0f, 0.0f, 0.0f);
    this->_v2.set(0.0f, 0.0f, 1.0f, 0.0f);
    this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

    // Ensure m15 stays 1.0f and re-apply hint bits
    this->_m15 = 1.0f;
    this->_u_m15 &= 0xFFFFFFF8u;
    this->_u_m15 |= (unsigned int)prevHint;
}

void Mat4::set(const Row4 type, const Vec4& V)
{
    switch (type)
    {
    case Row4::i0:
        this->_v0.set(V);
        break;
    case Row4::i1:
        this->_v1.set(V);
        break;
    case Row4::i2:
        this->_v2.set(V);
        break;
    case Row4::i3:
        this->_v3.set(V);
        break;
    }
    // Any direct row update generalizes the matrix
    
    ((Mat4Hint&)*this).privSetGeneralHint();
    
}

	Vec4 Mat4::get(const Row4 type) const
	{
		switch (type)
		{
		case Row4::i0:
			return Vec4(this->_m0, this->_m1, this->_m2, this->_m3);
		case Row4::i1:
			return Vec4(this->_m4, this->_m5, this->_m6, this->_m7);
		case Row4::i2:
			return Vec4(this->_m8, this->_m9, this->_m10, this->_m11);
		case Row4::i3:
			return Vec4(this->_m12, this->_m13, this->_m14, this->_m15);
		default:
			// Default case to ensure all code paths return a value
			assert(false);
			return Vec4();
		}
	}

	Mat4Proxy Mat4::operator[] (const enum m0_enum) { return Mat4Proxy(*this, _m0); }
	Mat4Proxy Mat4::operator[] (const enum m1_enum) { return Mat4Proxy(*this, _m1);	}
	Mat4Proxy Mat4::operator[] (const enum m2_enum) { return Mat4Proxy(*this, _m2); }
	Mat4Proxy Mat4::operator[] (const enum m3_enum) { return Mat4Proxy(*this, _m3); }
	Mat4Proxy Mat4::operator[] (const enum m4_enum) { return Mat4Proxy(*this, _m4); }
	Mat4Proxy Mat4::operator[] (const enum m5_enum)	{ return Mat4Proxy(*this, _m5); }
	Mat4Proxy Mat4::operator[] (const enum m6_enum) { return Mat4Proxy(*this, _m6); }
	Mat4Proxy Mat4::operator[] (const enum m7_enum) { return Mat4Proxy(*this, _m7); }
	Mat4Proxy Mat4::operator[] (const enum m8_enum) { return Mat4Proxy(*this, _m8); }
	Mat4Proxy Mat4::operator[] (const enum m9_enum) { return Mat4Proxy(*this, _m9); }
	Mat4Proxy Mat4::operator[] (const enum m10_enum){ return Mat4Proxy(*this, _m10);}
	Mat4Proxy Mat4::operator[] (const enum m11_enum){ return Mat4Proxy(*this, _m11);}
	Mat4Proxy Mat4::operator[] (const enum m12_enum){ return Mat4Proxy(*this, _m12);}
	Mat4Proxy Mat4::operator[] (const enum m13_enum){ return Mat4Proxy(*this, _m13);}
	Mat4Proxy Mat4::operator[] (const enum m14_enum){ return Mat4Proxy(*this, _m14);}
	Mat4Proxy Mat4::operator[] (const enum m15_enum){ return Mat4Proxy(*this, _m15);}

    float Mat4::operator[](const m0_enum)  const { return this->_m0; }
	float Mat4::operator[](const m1_enum)  const { return this->_m1; }
	float Mat4::operator[](const m2_enum)  const { return this->_m2; }
	float Mat4::operator[](const m3_enum)  const { return this->_m3; }
	float Mat4::operator[](const m4_enum)  const { return this->_m4; }
	float Mat4::operator[](const m5_enum)  const { return this->_m5; }
	float Mat4::operator[](const m6_enum)  const { return this->_m6; }
	float Mat4::operator[](const m7_enum)  const { return this->_m7; }
	float Mat4::operator[](const m8_enum)  const { return this->_m8; }
	float Mat4::operator[](const m9_enum)  const { return this->_m9; }
	float Mat4::operator[](const m10_enum) const { return this->_m10; }
	float Mat4::operator[](const m11_enum) const { return this->_m11; }
	float Mat4::operator[](const m12_enum) const { return this->_m12; }
	float Mat4::operator[](const m13_enum) const { return this->_m13; }
	float Mat4::operator[](const m14_enum) const { return this->_m14; }
    float Mat4::operator[](const m15_enum) const { return this->_m15; }

    void Mat4::m0(const float v)  { this->_m0 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m1(const float v)  { this->_m1 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m2(const float v)  { this->_m2 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m3(const float v)  { this->_m3 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m4(const float v)  { this->_m4 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m5(const float v)  { this->_m5 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m6(const float v)  { this->_m6 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m7(const float v)  { this->_m7 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m8(const float v)  { this->_m8 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m9(const float v)  { this->_m9 = v; ((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m10(const float v) { this->_m10 = v;((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m11(const float v) { this->_m11 = v;((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m12(const float v) { this->_m12 = v;((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m13(const float v) { this->_m13 = v;((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m14(const float v) { this->_m14 = v;((Mat4Hint&)*this).privSetGeneralHint(); }
    void Mat4::m15(const float v) { this->_m15 = v;((Mat4Hint&)*this).privSetGeneralHint(); }

	float Mat4::m0() const { return this->_m0; }
	float Mat4::m1() const { return this->_m1; }
	float Mat4::m2() const { return this->_m2; }
	float Mat4::m3() const { return this->_m3; }
	float Mat4::m4() const { return this->_m4; }
	float Mat4::m5() const { return this->_m5; }
	float Mat4::m6() const { return this->_m6; }
	float Mat4::m7() const { return this->_m7; }
	float Mat4::m8() const { return this->_m8; }
	float Mat4::m9() const { return this->_m9; }
	float Mat4::m10() const { return this->_m10; }
	float Mat4::m11() const { return this->_m11; }
	float Mat4::m12() const { return this->_m12; }
	float Mat4::m13() const { return this->_m13; }
	float Mat4::m14() const { return this->_m14; }
	float Mat4::m15() const { return this->_m15; }

float Mat4::det() const
{
    
    const Mat4Hint::Hint h = ((Mat4Hint&)*(const_cast<Mat4*>(this))).GetHint();
    switch (h)
    {
    case Mat4Hint::Hint::Trans:
    case Mat4Hint::Hint::Rot:
    case Mat4Hint::Hint::RotTrans:
        return 1.0f;

    case Mat4Hint::Hint::Scale:
    case Mat4Hint::Hint::TransScale:
        return this->_m0 * this->_m5 * this->_m10;

    case Mat4Hint::Hint::RotScale:
    case Mat4Hint::Hint::Affine:
        return this->_m0 * (this->_m5 * this->_m10 - this->_m6 * this->_m9)
             - this->_m1 * (this->_m4 * this->_m10 - this->_m6 * this->_m8)
             + this->_m2 * (this->_m4 * this->_m9  - this->_m5 * this->_m8);

    case Mat4Hint::Hint::Generalize:
    default:
        {
            const float f0 = _m10 * _m15 - _m14 * _m11;
            const float f1 = _m9 * _m15 - _m13 * _m11;
            const float f2 = _m9 * _m14 - _m13 * _m10;
            const float f3 = _m8 * _m15 - _m12 * _m11;
            const float f4 = _m8 * _m14 - _m12 * _m10;
            const float f5 = _m8 * _m13 - _m12 * _m9;

            const float c0 = _m5 * f0 - _m6 * f1 + _m7 * f2;
            const float c1 = _m4 * f0 - _m6 * f3 + _m7 * f4;
            const float c2 = _m4 * f1 - _m5 * f3 + _m7 * f5;
            const float c3 = _m4 * f2 - _m5 * f4 + _m6 * f5;

            return _m0 * c0 - _m1 * c1 + _m2 * c2 - _m3 * c3;
        }
    }    
}

    // Set matrix from quaternion: builds a pure rotation Mat4
    void Mat4::set(const Quat& q)
    {
        const float qx = q._qx;
        const float qy = q._qy;
        const float qz = q._qz;
        const float qw = q._qw;

        const float xx = qx * qx;
        const float yy = qy * qy;
        const float zz = qz * qz;
        const float xy = qx * qy;
        const float xz = qx * qz;
        const float yz = qy * qz;
        const float wx = qw * qx;
        const float wy = qw * qy;
        const float wz = qw * qz;

        this->_m0 = 1.0f - 2.0f * (yy + zz);
        this->_m1 = 2.0f * (xy + wz);
        this->_m2 = 2.0f * (xz - wy);
        this->_m3 = 0.0f;

        this->_m4 = 2.0f * (xy - wz);
        this->_m5 = 1.0f - 2.0f * (xx + zz);
        this->_m6 = 2.0f * (yz + wx);
        this->_m7 = 0.0f;

        this->_m8  = 2.0f * (xz + wy);
        this->_m9  = 2.0f * (yz - wx);
        this->_m10 = 1.0f - 2.0f * (xx + yy);
        this->_m11 = 0.0f;

        this->_m12 = 0.0f;
        this->_m13 = 0.0f;
        this->_m14 = 0.0f;
        this->_m15 = 1.0f;

        // Mark as rotation matrix using hint system
        ((Mat4Hint&)*this).privSetRotHint();
    }

    Mat4& Mat4::operator=(const Quat& q)
    {
        this->set(q);
        return *this;
    }

	Mat4& Mat4::T(void)
	{
	    // Transpose without triggering generalization via setters
	    float tmp;
	
	    tmp = this->_m1;   this->_m1 = this->_m4;   this->_m4 = tmp;
	    tmp = this->_m2;   this->_m2 = this->_m8;   this->_m8 = tmp;
	    tmp = this->_m3;   this->_m3 = this->_m12;  this->_m12 = tmp;
	    tmp = this->_m6;   this->_m6 = this->_m9;   this->_m9 = tmp;
	    tmp = this->_m7;   this->_m7 = this->_m13;  this->_m13 = tmp;
	    tmp = this->_m11;  this->_m11 = this->_m14; this->_m14 = tmp;
	
	    return *this;
	}

	Mat4 Mat4::getT(void) const
	{
		return Mat4(
			Vec4(this->_m0, this->_m4, this->_m8, this->_m12),
			Vec4(this->_m1, this->_m5, this->_m9, this->_m13),
			Vec4(this->_m2, this->_m6, this->_m10, this->_m14),
			Vec4(this->_m3, this->_m7, this->_m11, this->_m15)
		);
	}

Mat4 Mat4::getInv(void) const
{
    // Fast-path inverse based on matrix hint (SAP pattern)
    
    Mat4Hint::Hint hint = ((Mat4Hint&)*(const_cast<Mat4*>(this))).GetHint();
    Mat4 r;
    switch (hint)
    {
        case Mat4Hint::Hint::Trans:
        {
            // Inverse of translation: negate bottom-row translation, keep identity 3x3
            r._m0 = 1.0f; r._m1 = 0.0f; r._m2 = 0.0f; r._m3 = 0.0f;
            r._m4 = 0.0f; r._m5 = 1.0f; r._m6 = 0.0f; r._m7 = 0.0f;
            r._m8 = 0.0f; r._m9 = 0.0f; r._m10 = 1.0f; r._m11 = 0.0f;
            r._m12 = -this->_m12; r._m13 = -this->_m13; r._m14 = -this->_m14; r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::Scale:
        {
            // Inverse of scale: reciprocals on diagonal
            const float sx = this->_m0;
            const float sy = this->_m5;
            const float sz = this->_m10;
            r._m0 = 1.0f / sx; r._m1 = 0.0f;       r._m2 = 0.0f;       r._m3 = 0.0f;
            r._m4 = 0.0f;       r._m5 = 1.0f / sy; r._m6 = 0.0f;       r._m7 = 0.0f;
            r._m8 = 0.0f;       r._m9 = 0.0f;       r._m10 = 1.0f / sz; r._m11 = 0.0f;
            r._m12 = 0.0f;      r._m13 = 0.0f;      r._m14 = 0.0f;      r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::Rot:
        {
            // Inverse of rotation: transpose 3x3, zero last column and bottom row
            r._m0 = this->_m0; r._m1 = this->_m4; r._m2 = this->_m8;  r._m3 = 0.0f;
            r._m4 = this->_m1; r._m5 = this->_m5; r._m6 = this->_m9;  r._m7 = 0.0f;
            r._m8 = this->_m2; r._m9 = this->_m6; r._m10 = this->_m10; r._m11 = 0.0f;
            r._m12 = 0.0f;     r._m13 = 0.0f;     r._m14 = 0.0f;       r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::RotTrans:
        {
            // Rigid-body inverse: R^T and bottom-row translation = -t * R^T
            const float tx = this->_m12, ty = this->_m13, tz = this->_m14;
            // R^T (transpose the 3x3 block)
            r._m0 = this->_m0; r._m1 = this->_m4; r._m2 = this->_m8;  r._m3 = 0.0f;
            r._m4 = this->_m1; r._m5 = this->_m5; r._m6 = this->_m9;  r._m7 = 0.0f;
            r._m8 = this->_m2; r._m9 = this->_m6; r._m10 = this->_m10; r._m11 = 0.0f;
            // -t * R^T
            r._m12 = -(tx * r._m0 + ty * r._m4 + tz * r._m8);
            r._m13 = -(tx * r._m1 + ty * r._m5 + tz * r._m9);
            r._m14 = -(tx * r._m2 + ty * r._m6 + tz * r._m10);
            r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::TransScale:
        {
            // Scale with translation: S^{-1}, bottom-row translation = -t * S^{-1}
            const float sx = this->_m0;
            const float sy = this->_m5;
            const float sz = this->_m10;
            const float tx = this->_m12, ty = this->_m13, tz = this->_m14;
            const float isx = 1.0f / sx;
            const float isy = 1.0f / sy;
            const float isz = 1.0f / sz;
            r._m0 = isx; r._m1 = 0.0f; r._m2 = 0.0f; r._m3 = 0.0f;
            r._m4 = 0.0f; r._m5 = isy; r._m6 = 0.0f; r._m7 = 0.0f;
            r._m8 = 0.0f; r._m9 = 0.0f; r._m10 = isz; r._m11 = 0.0f;
            r._m12 = -(tx * isx); r._m13 = -(ty * isy); r._m14 = -(tz * isz); r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::RotScale:
        case Mat4Hint::Hint::Affine:
        {
            // General affine inverse: invert 3x3 block and compute bottom-row translation = -t * inv3x3
            const float a = this->_m0, b = this->_m1, c = this->_m2;
            const float d = this->_m4, e = this->_m5, f = this->_m6;
            const float g = this->_m8, h = this->_m9, i = this->_m10;
            const float tx = this->_m12, ty = this->_m13, tz = this->_m14;

            const float C00 = e * i - f * h;
            const float C01 = -(d * i - f * g);
            const float C02 = d * h - e * g;
            const float C10 = -(b * i - c * h);
            const float C11 = a * i - c * g;
            const float C12 = -(a * h - b * g);
            const float C20 = b * f - c * e;
            const float C21 = -(a * f - c * d);
            const float C22 = a * e - b * d;

            const float det3 = a * C00 + b * C01 + c * C02;
            const float invDet3 = 1.0f / det3;

            // inv3x3 = adj(C) / det3 (adjugate is transpose of cofactor matrix)
            r._m0 = C00 * invDet3; r._m1 = C10 * invDet3; r._m2 = C20 * invDet3; r._m3 = 0.0f;
            r._m4 = C01 * invDet3; r._m5 = C11 * invDet3; r._m6 = C21 * invDet3; r._m7 = 0.0f;
            r._m8 = C02 * invDet3; r._m9 = C12 * invDet3; r._m10 = C22 * invDet3; r._m11 = 0.0f;

            // bottom-row translation = -t * inv3x3
            r._m12 = -(tx * r._m0 + ty * r._m4 + tz * r._m8);
            r._m13 = -(tx * r._m1 + ty * r._m5 + tz * r._m9);
            r._m14 = -(tx * r._m2 + ty * r._m6 + tz * r._m10);

            r._m15 = 1.0f;
            return r;
        }
        case Mat4Hint::Hint::Generalize:
        default:
			{
				// Full 4x4 inverse (general case)
				const float A2323 = _m10 * _m15 - _m14 * _m11;
				const float A1323 = _m9 * _m15 - _m13 * _m11;
				const float A1223 = _m9 * _m14 - _m13 * _m10;
				const float A0323 = _m8 * _m15 - _m12 * _m11;
				const float A0223 = _m8 * _m14 - _m12 * _m10;
				const float A0123 = _m8 * _m13 - _m12 * _m9;

				const float A2313 = _m6 * _m15 - _m14 * _m7;
				const float A1313 = _m5 * _m15 - _m13 * _m7;
				const float A1213 = _m5 * _m14 - _m13 * _m6;
				const float A0313 = _m4 * _m15 - _m12 * _m7;
				const float A0213 = _m4 * _m14 - _m12 * _m6;
				const float A0113 = _m4 * _m13 - _m12 * _m5;

				const float A2303 = _m6 * _m11 - _m10 * _m7;
				const float A1303 = _m5 * _m11 - _m9 * _m7;
				const float A1203 = _m5 * _m10 - _m9 * _m6;
				const float A0303 = _m4 * _m11 - _m8 * _m7;
				const float A0203 = _m4 * _m10 - _m8 * _m6;
				const float A0103 = _m4 * _m9 - _m8 * _m5;

				const float c0 = _m5 * A2323 - _m6 * A1323 + _m7 * A1223;
				const float c1 = _m4 * A2323 - _m6 * A0323 + _m7 * A0223;
				const float c2 = _m4 * A1323 - _m5 * A0323 + _m7 * A0123;
				const float c3 = _m4 * A1223 - _m5 * A0223 + _m6 * A0123;

				const float det = _m0 * c0 - _m1 * c1 + _m2 * c2 - _m3 * c3;
				const float invDet = 1.0f / det;

				const float c4 = _m1 * A2323 - _m2 * A1323 + _m3 * A1223;
				const float c5 = _m0 * A2323 - _m2 * A0323 + _m3 * A0223;
				const float c6 = _m0 * A1323 - _m1 * A0323 + _m3 * A0123;
				const float c7 = _m0 * A1223 - _m1 * A0223 + _m2 * A0123;

				const float c8 = _m1 * A2313 - _m2 * A1313 + _m3 * A1213;
				const float c9 = _m0 * A2313 - _m2 * A0313 + _m3 * A0213;
				const float c10 = _m0 * A1313 - _m1 * A0313 + _m3 * A0113;
				const float c11 = _m0 * A1213 - _m1 * A0213 + _m2 * A0113;

				const float c12 = _m1 * A2303 - _m2 * A1303 + _m3 * A1203;
				const float c13 = _m0 * A2303 - _m2 * A0303 + _m3 * A0203;
				const float c14 = _m0 * A1303 - _m1 * A0303 + _m3 * A0103;
				const float c15 = _m0 * A1203 - _m1 * A0203 + _m2 * A0103;

				r._m0 = c0 * invDet;   r._m1 = -c4 * invDet;
				r._m2 = c8 * invDet;   r._m3 = -c12 * invDet;

				r._m4 = -c1 * invDet;   r._m5 = c5 * invDet;
				r._m6 = -c9 * invDet;   r._m7 = c13 * invDet;

				r._m8 = c2 * invDet;   r._m9 = -c6 * invDet;
				r._m10 = c10 * invDet;   r._m11 = -c14 * invDet;

				r._m12 = -c3 * invDet;   r._m13 = c7 * invDet;
				r._m14 = -c11 * invDet;   r._m15 = c15 * invDet;

				return r;
			}
        }
  
    
}

Mat4& Mat4::inv(void)
{
    // Preserve current hint category after inversion when applicable (SAP pattern)
    
    Mat4Hint::Hint prevHint = ((Mat4Hint&)*this).GetHint();
    

    *this = this->getInv();

    
    if (prevHint != Mat4Hint::Hint::Generalize)
    {
        // Re-apply the same hint via SAP helper
        ((Mat4Hint&)*this).privSetNewHint(prevHint, prevHint);
    }
    
    return *this;
}

	bool Mat4::isEqual(const Mat4& rhs, const float epsilon) const
	{
		return  Util::isEqual(_m0, rhs._m0, epsilon) &&
			Util::isEqual(_m1, rhs._m1, epsilon) &&
			Util::isEqual(_m2, rhs._m2, epsilon) &&
			Util::isEqual(_m3, rhs._m3, epsilon) &&

			Util::isEqual(_m4, rhs._m4, epsilon) &&
			Util::isEqual(_m5, rhs._m5, epsilon) &&
			Util::isEqual(_m6, rhs._m6, epsilon) &&
			Util::isEqual(_m7, rhs._m7, epsilon) &&

			Util::isEqual(_m8, rhs._m8, epsilon) &&
			Util::isEqual(_m9, rhs._m9, epsilon) &&
			Util::isEqual(_m10, rhs._m10, epsilon) &&
			Util::isEqual(_m11, rhs._m11, epsilon) &&

			Util::isEqual(_m12, rhs._m12, epsilon) &&
			Util::isEqual(_m13, rhs._m13, epsilon) &&
			Util::isEqual(_m14, rhs._m14, epsilon) &&
			Util::isEqual(_m15, rhs._m15, epsilon);
	}

	bool Mat4::isIdentity(const float epsilon) const
	{
		if (!Util::isEqual(_m0, 1.0f, epsilon)) return false;
		if (!Util::isEqual(_m5, 1.0f, epsilon)) return false;
		if (!Util::isEqual(_m10, 1.0f, epsilon)) return false;
		if (!Util::isEqual(_m15, 1.0f, epsilon)) return false;

		return  Util::isEqual(_m1, 0.0f, epsilon) &&
			Util::isEqual(_m2, 0.0f, epsilon) &&
			Util::isEqual(_m3, 0.0f, epsilon) &&
			Util::isEqual(_m4, 0.0f, epsilon) &&
			Util::isEqual(_m6, 0.0f, epsilon) &&
			Util::isEqual(_m7, 0.0f, epsilon) &&
			Util::isEqual(_m8, 0.0f, epsilon) &&
			Util::isEqual(_m9, 0.0f, epsilon) &&
			Util::isEqual(_m11, 0.0f, epsilon) &&
			Util::isEqual(_m12, 0.0f, epsilon) &&
			Util::isEqual(_m13, 0.0f, epsilon) &&
			Util::isEqual(_m14, 0.0f, epsilon);
	}

	bool Mat4::isRotation(const float epsilon) const
	{
		const Mat4 prod = (*this) * getT();
		return prod.isIdentity(epsilon);
	}

	Mat4 Mat4::operator+(void) const
	{
		return *this;
	}

	Mat4 Mat4::operator+(const Mat4& rhs) const
	{
		Mat4 r;

		r._m0 = _m0 + rhs._m0;   r._m1 = _m1 + rhs._m1;
		r._m2 = _m2 + rhs._m2;   r._m3 = _m3 + rhs._m3;

		r._m4 = _m4 + rhs._m4;   r._m5 = _m5 + rhs._m5;
		r._m6 = _m6 + rhs._m6;   r._m7 = _m7 + rhs._m7;

		r._m8 = _m8 + rhs._m8;   r._m9 = _m9 + rhs._m9;
		r._m10 = _m10 + rhs._m10;  r._m11 = _m11 + rhs._m11;

		r._m12 = _m12 + rhs._m12;  r._m13 = _m13 + rhs._m13;
		r._m14 = _m14 + rhs._m14;  r._m15 = _m15 + rhs._m15;

		return r;
	}

	Mat4& Mat4::operator+=(const Mat4& rhs)
	{
		_m0 += rhs._m0;   _m1 += rhs._m1;   _m2 += rhs._m2;   _m3 += rhs._m3;
		_m4 += rhs._m4;   _m5 += rhs._m5;   _m6 += rhs._m6;   _m7 += rhs._m7;
		_m8 += rhs._m8;   _m9 += rhs._m9;   _m10 += rhs._m10;  _m11 += rhs._m11;
		_m12 += rhs._m12;  _m13 += rhs._m13;  _m14 += rhs._m14;  _m15 += rhs._m15;

		return *this;
	}

	Mat4 Mat4::operator-(void) const
	{
		Mat4 r;

		r._m0 = -_m0;   r._m1 = -_m1;   r._m2 = -_m2;   r._m3 = -_m3;
		r._m4 = -_m4;   r._m5 = -_m5;   r._m6 = -_m6;   r._m7 = -_m7;
		r._m8 = -_m8;   r._m9 = -_m9;   r._m10 = -_m10;  r._m11 = -_m11;
		r._m12 = -_m12;  r._m13 = -_m13;  r._m14 = -_m14;  r._m15 = -_m15;

		return r;
	}

	Mat4 Mat4::operator-(const Mat4& rhs) const
	{
		Mat4 r;

		r._m0 = _m0 - rhs._m0;   r._m1 = _m1 - rhs._m1;
		r._m2 = _m2 - rhs._m2;   r._m3 = _m3 - rhs._m3;

		r._m4 = _m4 - rhs._m4;   r._m5 = _m5 - rhs._m5;
		r._m6 = _m6 - rhs._m6;   r._m7 = _m7 - rhs._m7;

		r._m8 = _m8 - rhs._m8;   r._m9 = _m9 - rhs._m9;
		r._m10 = _m10 - rhs._m10;  r._m11 = _m11 - rhs._m11;

		r._m12 = _m12 - rhs._m12;  r._m13 = _m13 - rhs._m13;
		r._m14 = _m14 - rhs._m14;  r._m15 = _m15 - rhs._m15;

		return r;
	}

	Mat4& Mat4::operator-=(const Mat4& rhs)
	{
		_m0 -= rhs._m0;   _m1 -= rhs._m1;   _m2 -= rhs._m2;   _m3 -= rhs._m3;
		_m4 -= rhs._m4;   _m5 -= rhs._m5;   _m6 -= rhs._m6;   _m7 -= rhs._m7;
		_m8 -= rhs._m8;   _m9 -= rhs._m9;   _m10 -= rhs._m10;  _m11 -= rhs._m11;
		_m12 -= rhs._m12;  _m13 -= rhs._m13;  _m14 -= rhs._m14;  _m15 -= rhs._m15;

		return *this;
	}

	Mat4 Mat4::operator*(const float scale) const
	{
		Mat4 r;

		r._m0 = _m0 * scale;   r._m1 = _m1 * scale;
		r._m2 = _m2 * scale;   r._m3 = _m3 * scale;

		r._m4 = _m4 * scale;   r._m5 = _m5 * scale;
		r._m6 = _m6 * scale;   r._m7 = _m7 * scale;

		r._m8 = _m8 * scale;   r._m9 = _m9 * scale;
		r._m10 = _m10 * scale;   r._m11 = _m11 * scale;

		r._m12 = _m12 * scale;   r._m13 = _m13 * scale;
		r._m14 = _m14 * scale;   r._m15 = _m15 * scale;

		return r;
	}

	Mat4& Mat4::operator*=(const float scale)
	{
		*this = *this * scale;
		return *this;
	}

	Mat4 Mat4::operator*(const Mat4& b) const
	{
		const Mat4& a = *this;
		Mat4 r;
		//A x B

		r._m0 = a._m0 * b._m0 + a._m1 * b._m4 + a._m2 * b._m8 + a._m3 * b._m12;
		r._m1 = a._m0 * b._m1 + a._m1 * b._m5 + a._m2 * b._m9 + a._m3 * b._m13;
		r._m2 = a._m0 * b._m2 + a._m1 * b._m6 + a._m2 * b._m10 + a._m3 * b._m14;
		r._m3 = a._m0 * b._m3 + a._m1 * b._m7 + a._m2 * b._m11 + a._m3 * b._m15;

		// Row 1 - Columns 0-3
		r._m4 = a._m4 * b._m0 + a._m5 * b._m4 + a._m6 * b._m8 + a._m7 * b._m12;
		r._m5 = a._m4 * b._m1 + a._m5 * b._m5 + a._m6 * b._m9 + a._m7 * b._m13;
		r._m6 = a._m4 * b._m2 + a._m5 * b._m6 + a._m6 * b._m10 + a._m7 * b._m14;
		r._m7 = a._m4 * b._m3 + a._m5 * b._m7 + a._m6 * b._m11 + a._m7 * b._m15;

		// Row 2 - Columns 0-3
		r._m8 = a._m8 * b._m0 + a._m9 * b._m4 + a._m10 * b._m8 + a._m11 * b._m12;
		r._m9 = a._m8 * b._m1 + a._m9 * b._m5 + a._m10 * b._m9 + a._m11 * b._m13;
		r._m10 = a._m8 * b._m2 + a._m9 * b._m6 + a._m10 * b._m10 + a._m11 * b._m14;
		r._m11 = a._m8 * b._m3 + a._m9 * b._m7 + a._m10 * b._m11 + a._m11 * b._m15;

		// Row 3 - Columns 0-3
		r._m12 = a._m12 * b._m0 + a._m13 * b._m4 + a._m14 * b._m8 + a._m15 * b._m12;
		r._m13 = a._m12 * b._m1 + a._m13 * b._m5 + a._m14 * b._m9 + a._m15 * b._m13;
		r._m14 = a._m12 * b._m2 + a._m13 * b._m6 + a._m14 * b._m10 + a._m15 * b._m14;
		r._m15 = a._m12 * b._m3 + a._m13 * b._m7 + a._m14 * b._m11 + a._m15 * b._m15;

        // Combine and preserve hints from both operands (SAP pattern)
        
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)a).GetHint(), ((Mat4Hint&)b).GetHint());
        

		//B x A

		//r._m0 = a._m0 * b._m0 + a._m4 * b._m1 + a._m8 * b._m2 + a._m12 * b._m3;
		//r._m1 = a._m1 * b._m0 + a._m5 * b._m1 + a._m9 * b._m2 + a._m13 * b._m3;
		//r._m2 = a._m2 * b._m0 + a._m6 * b._m1 + a._m10 * b._m2 + a._m14 * b._m3;
		//r._m3 = a._m3 * b._m0 + a._m7 * b._m1 + a._m11 * b._m2 + a._m15 * b._m3;

		//r._m4 = a._m0 * b._m4 + a._m4 * b._m5 + a._m8 * b._m6 + a._m12 * b._m7;
		//r._m5 = a._m1 * b._m4 + a._m5 * b._m5 + a._m9 * b._m6 + a._m13 * b._m7;
		//r._m6 = a._m2 * b._m4 + a._m6 * b._m5 + a._m10 * b._m6 + a._m14 * b._m7;
		//r._m7 = a._m3 * b._m4 + a._m7 * b._m5 + a._m11 * b._m6 + a._m15 * b._m7;

		//r._m8 = a._m0 * b._m8 + a._m4 * b._m9 + a._m8 * b._m10 + a._m12 * b._m11;
		//r._m9 = a._m1 * b._m8 + a._m5 * b._m9 + a._m9 * b._m10 + a._m13 * b._m11;
		//r._m10 = a._m2 * b._m8 + a._m6 * b._m9 + a._m10 * b._m10 + a._m14 * b._m11;
		//r._m11 = a._m3 * b._m8 + a._m7 * b._m9 + a._m11 * b._m10 + a._m15 * b._m11;

		//r._m12 = a._m0 * b._m12 + a._m4 * b._m13 + a._m8 * b._m14 + a._m12 * b._m15;
		//r._m13 = a._m1 * b._m12 + a._m5 * b._m13 + a._m9 * b._m14 + a._m13 * b._m15;
		//r._m14 = a._m2 * b._m12 + a._m6 * b._m13 + a._m10 * b._m14 + a._m14 * b._m15;
		//r._m15 = a._m3 * b._m12 + a._m7 * b._m13 + a._m11 * b._m14 + a._m15 * b._m15;

		return r;
	}

	Mat4& Mat4::operator*=(const Mat4& A)
	{
		*this = *this * A;
		return *this;
	}

	// Specialized multiply using hints: right-multiply by Scale
	Mat4 Mat4::operator*(const Scale& b) const
	{
		const Mat4& a = *this;
		Mat4 r;

		const float sx = b._m0;
		const float sy = b._m5;
		const float sz = b._m10;

		// Scale affects columns 0..2; column 3 passes through
		r._m0 = a._m0 * sx;   r._m1 = a._m1 * sy;   r._m2 = a._m2 * sz;   r._m3 = a._m3;
		r._m4 = a._m4 * sx;   r._m5 = a._m5 * sy;   r._m6 = a._m6 * sz;   r._m7 = a._m7;
		r._m8 = a._m8 * sx;   r._m9 = a._m9 * sy;   r._m10 = a._m10 * sz;  r._m11 = a._m11;
		r._m12 = a._m12 * sx; r._m13 = a._m13 * sy; r._m14 = a._m14 * sz;  r._m15 = a._m15;

        // Combine hints
        
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Scale);
        
		return r;
	}

	Mat4& Mat4::operator*=(const Scale& b)
	{
		// In-place right-multiply by Scale: scales columns 0..2, column 3 passes through
		const float sx = b._m0;
		const float sy = b._m5;
		const float sz = b._m10;

		// Column 0
		this->_m0  *= sx;  this->_m4  *= sx;  this->_m8  *= sx;  this->_m12 *= sx;
		// Column 1
		this->_m1  *= sy;  this->_m5  *= sy;  this->_m9  *= sy;  this->_m13 *= sy;
		// Column 2
		this->_m2  *= sz;  this->_m6  *= sz;  this->_m10 *= sz;  this->_m14 *= sz;
		// Column 3 unchanged
		// _m3, _m7, _m11, _m15 stay the same

        // Combine hints with Scale
        
        ((Mat4Hint&)*this).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Scale);
        
		return *this;
	}

	// Specialized multiply using hints: right-multiply by Rot
	Mat4 Mat4::operator*(const Rot& b) const
	{
		const Mat4& a = *this;
		Mat4 r;

		// Columns 0..2 are 3x3 rotation, column 3 passes through
		r._m0  = a._m0 * b._m0  + a._m1 * b._m4  + a._m2 * b._m8;   r._m3  = a._m3;
		r._m1  = a._m0 * b._m1  + a._m1 * b._m5  + a._m2 * b._m9;   
		r._m2  = a._m0 * b._m2  + a._m1 * b._m6  + a._m2 * b._m10;  

		r._m4  = a._m4 * b._m0  + a._m5 * b._m4  + a._m6 * b._m8;   r._m7  = a._m7;
		r._m5  = a._m4 * b._m1  + a._m5 * b._m5  + a._m6 * b._m9;   
		r._m6  = a._m4 * b._m2  + a._m5 * b._m6  + a._m6 * b._m10;  

		r._m8  = a._m8 * b._m0  + a._m9 * b._m4  + a._m10 * b._m8;  r._m11 = a._m11;
		r._m9  = a._m8 * b._m1  + a._m9 * b._m5  + a._m10 * b._m9;  
		r._m10 = a._m8 * b._m2  + a._m9 * b._m6  + a._m10 * b._m10; 

		r._m12 = a._m12 * b._m0 + a._m13 * b._m4 + a._m14 * b._m8;  r._m15 = a._m15;
		r._m13 = a._m12 * b._m1 + a._m13 * b._m5 + a._m14 * b._m9;  
		r._m14 = a._m12 * b._m2 + a._m13 * b._m6 + a._m14 * b._m10; 

        // Combine hints
        
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);
        
		return r;
	}

	Mat4& Mat4::operator*=(const Rot& b)
	{
		// In-place right-multiply by Rot: rotate columns 0..2, column 3 passes through
		// Cache current columns 0..2 to avoid overwrite hazards
		const float a0  = this->_m0;  const float a1  = this->_m1;  const float a2  = this->_m2;
		const float a4  = this->_m4;  const float a5  = this->_m5;  const float a6  = this->_m6;
		const float a8  = this->_m8;  const float a9  = this->_m9;  const float a10 = this->_m10;
		const float a12 = this->_m12; const float a13 = this->_m13; const float a14 = this->_m14;

		// Compute rotated columns (3x3 multiply); last column unchanged
		this->_m0  = a0  * b._m0 + a1  * b._m4 + a2  * b._m8;
		this->_m1  = a0  * b._m1 + a1  * b._m5 + a2  * b._m9;
		this->_m2  = a0  * b._m2 + a1  * b._m6 + a2  * b._m10;

		this->_m4  = a4  * b._m0 + a5  * b._m4 + a6  * b._m8;
		this->_m5  = a4  * b._m1 + a5  * b._m5 + a6  * b._m9;
		this->_m6  = a4  * b._m2 + a5  * b._m6 + a6  * b._m10;

		this->_m8  = a8  * b._m0 + a9  * b._m4 + a10 * b._m8;
		this->_m9  = a8  * b._m1 + a9  * b._m5 + a10 * b._m9;
		this->_m10 = a8  * b._m2 + a9  * b._m6 + a10 * b._m10;

		this->_m12 = a12 * b._m0 + a13 * b._m4 + a14 * b._m8;
		this->_m13 = a12 * b._m1 + a13 * b._m5 + a14 * b._m9;
		this->_m14 = a12 * b._m2 + a13 * b._m6 + a14 * b._m10;
		// _m3, _m7, _m11, _m15 stay the same

        // Combine hints with Rot
        
        ((Mat4Hint&)*this).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);
        
		return *this;
	}

	// Specialized multiply using hints: right-multiply by Trans
	Mat4 Mat4::operator*(const Trans& b) const
	{
	    const Mat4& a = *this;
	    Mat4 r;
	
	    const float tx = b._m12;
	    const float ty = b._m13;
	    const float tz = b._m14;
	
	    r._m0  = a._m0  + a._m3  * tx;   r._m1  = a._m1  + a._m3  * ty;   r._m2  = a._m2  + a._m3  * tz;   r._m3  = a._m3;
	    r._m4  = a._m4  + a._m7  * tx;   r._m5  = a._m5  + a._m7  * ty;   r._m6  = a._m6  + a._m7  * tz;   r._m7  = a._m7;
	    r._m8  = a._m8  + a._m11 * tx;   r._m9  = a._m9  + a._m11 * ty;   r._m10 = a._m10 + a._m11 * tz;   r._m11 = a._m11;
	    r._m12 = a._m12 + a._m15 * tx;   r._m13 = a._m13 + a._m15 * ty;   r._m14 = a._m14 + a._m15 * tz;   r._m15 = a._m15;
	
    // Combine hints
    
    ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Trans);
    
	    return r;
	}

	Mat4& Mat4::operator*=(const Trans& b)
	{
		// In-place right multiply by translation (bottom-row convention)
		const float tx = b._m12;
		const float ty = b._m13;
		const float tz = b._m14;

		// Cache last column of current matrix (used in update)
		const float a3  = this->_m3;
		const float a7  = this->_m7;
		const float a11 = this->_m11;
		const float a15 = this->_m15;

		// Update rows 0..2
		this->_m0  += a3 * tx;   this->_m1  += a3 * ty;   this->_m2  += a3 * tz;   /* _m3 unchanged */
		this->_m4  += a7 * tx;   this->_m5  += a7 * ty;   this->_m6  += a7 * tz;   /* _m7 unchanged */
		this->_m8  += a11 * tx;  this->_m9  += a11 * ty;  this->_m10 += a11 * tz;  /* _m11 unchanged */

		// Update bottom row
		this->_m12 += a15 * tx;  this->_m13 += a15 * ty;  this->_m14 += a15 * tz;  /* _m15 unchanged */

        // Combine hints
        
        ((Mat4Hint&)*this).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Trans);
        
		return *this;
	}

	// Right-multiply by quaternion: rotate columns 0..2, column 3 passes through
	Mat4 Mat4::operator*(const Quat& q) const
	{
		const Mat4& a = *this;
		Mat4 r;

		// Build 3x3 rotation from quaternion (same convention as set(const Quat&))
		const float qx = q._qx;
		const float qy = q._qy;
		const float qz = q._qz;
		const float qw = q._qw;

		const float xx = qx * qx;
		const float yy = qy * qy;
		const float zz = qz * qz;
		const float xy = qx * qy;
		const float xz = qx * qz;
		const float yz = qy * qz;
		const float wx = qw * qx;
		const float wy = qw * qy;
		const float wz = qw * qz;

		const float b00 = 1.0f - 2.0f * (yy + zz);
		const float b01 = 2.0f * (xy + wz);
		const float b02 = 2.0f * (xz - wy);
		const float b10 = 2.0f * (xy - wz);
		const float b11 = 1.0f - 2.0f * (xx + zz);
		const float b12 = 2.0f * (yz + wx);
		const float b20 = 2.0f * (xz + wy);
		const float b21 = 2.0f * (yz - wx);
		const float b22 = 1.0f - 2.0f * (xx + yy);

		// Columns 0..2 are rotated; column 3 passes through
		r._m0  = a._m0 * b00 + a._m1 * b10 + a._m2 * b20;   r._m3  = a._m3;
		r._m1  = a._m0 * b01 + a._m1 * b11 + a._m2 * b21;
		r._m2  = a._m0 * b02 + a._m1 * b12 + a._m2 * b22;

		r._m4  = a._m4 * b00 + a._m5 * b10 + a._m6 * b20;   r._m7  = a._m7;
		r._m5  = a._m4 * b01 + a._m5 * b11 + a._m6 * b21;
		r._m6  = a._m4 * b02 + a._m5 * b12 + a._m6 * b22;

		r._m8  = a._m8 * b00 + a._m9 * b10 + a._m10 * b20;  r._m11 = a._m11;
		r._m9  = a._m8 * b01 + a._m9 * b11 + a._m10 * b21;
		r._m10 = a._m8 * b02 + a._m9 * b12 + a._m10 * b22;

		r._m12 = a._m12 * b00 + a._m13 * b10 + a._m14 * b20; r._m15 = a._m15;
		r._m13 = a._m12 * b01 + a._m13 * b11 + a._m14 * b21;
		r._m14 = a._m12 * b02 + a._m13 * b12 + a._m14 * b22;

		// Combine hints: original with Rot
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);

		return r;
	}

	Mat4& Mat4::operator*=(const Quat& q)
	{
		// Cache current columns 0..2
		const float a0  = this->_m0;  const float a1  = this->_m1;  const float a2  = this->_m2;
		const float a4  = this->_m4;  const float a5  = this->_m5;  const float a6  = this->_m6;
		const float a8  = this->_m8;  const float a9  = this->_m9;  const float a10 = this->_m10;
		const float a12 = this->_m12; const float a13 = this->_m13; const float a14 = this->_m14;

		// Build 3x3 rotation from quaternion
		const float qx = q._qx;
		const float qy = q._qy;
		const float qz = q._qz;
		const float qw = q._qw;

		const float xx = qx * qx;
		const float yy = qy * qy;
		const float zz = qz * qz;
		const float xy = qx * qy;
		const float xz = qx * qz;
		const float yz = qy * qz;
		const float wx = qw * qx;
		const float wy = qw * qy;
		const float wz = qw * qz;

		const float b00 = 1.0f - 2.0f * (yy + zz);
		const float b01 = 2.0f * (xy + wz);
		const float b02 = 2.0f * (xz - wy);
		const float b10 = 2.0f * (xy - wz);
		const float b11 = 1.0f - 2.0f * (xx + zz);
		const float b12 = 2.0f * (yz + wx);
		const float b20 = 2.0f * (xz + wy);
		const float b21 = 2.0f * (yz - wx);
		const float b22 = 1.0f - 2.0f * (xx + yy);

		// Apply rotation to columns 0..2; column 3 stays unchanged
		this->_m0  = a0  * b00 + a1  * b10 + a2  * b20;
		this->_m1  = a0  * b01 + a1  * b11 + a2  * b21;
		this->_m2  = a0  * b02 + a1  * b12 + a2  * b22;

		this->_m4  = a4  * b00 + a5  * b10 + a6  * b20;
		this->_m5  = a4  * b01 + a5  * b11 + a6  * b21;
		this->_m6  = a4  * b02 + a5  * b12 + a6  * b22;

		this->_m8  = a8  * b00 + a9  * b10 + a10 * b20;
		this->_m9  = a8  * b01 + a9  * b11 + a10 * b21;
		this->_m10 = a8  * b02 + a9  * b12 + a10 * b22;

		this->_m12 = a12 * b00 + a13 * b10 + a14 * b20;
		this->_m13 = a12 * b01 + a13 * b11 + a14 * b21;
		this->_m14 = a12 * b02 + a13 * b12 + a14 * b22;
		// _m3, _m7, _m11, _m15 unchanged

		// Combine hint with Rot
		((Mat4Hint&)*this).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);

		return *this;
	}

	void Mat4::Print(const char* pName) const
	{
#define CLIP(val)  ((fabsf(val) >= MATH_PRINT_TOLERANCE) ? (val) : 0.0f)

		float v00 = CLIP(m0());  float v01 = CLIP(m1());
		float v02 = CLIP(m2());  float v03 = CLIP(m3());

		float v10 = CLIP(m4());  float v11 = CLIP(m5());
		float v12 = CLIP(m6());  float v13 = CLIP(m7());

		float v20 = CLIP(m8());   float v21 = CLIP(m9());
		float v22 = CLIP(m10());  float v23 = CLIP(m11());

		float v30 = CLIP(m12());  float v31 = CLIP(m13());
		float v32 = CLIP(m14());  float v33 = CLIP(m15());

#undef CLIP

		if (pName != 0) { Trace::out("%s:\n", pName); }

		Trace::out("( %f , %f , %f , %f )\n", v00, v01, v02, v03);
		Trace::out("( %f , %f , %f , %f )\n", v10, v11, v12, v13);
		Trace::out("( %f , %f , %f , %f )\n", v20, v21, v22, v23);
		Trace::out("( %f , %f , %f , %f )\n", v30, v31, v32, v33);

	}

	Mat4 operator*(const float scale, const Mat4& A)
	{
		return A * scale;
	}
}

// ---  End of File ---
