//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "Mat4Hint.h"

namespace Azul
{
	// Do your magic here

	Scale::Scale()
	{
		_m0 = 1.0f;   _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f;   _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f;  _m10 = 1.0f;   _m11 = 0.0f;
		_m12 = 0.0f; _m13 = 0.0f; _m14 = 0.0f; _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
	}

	Scale::Scale(const float sx, const float sy, const float sz)
	{
		_m0 = sx;   _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = sy;   _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = sz;   _m11 = 0.0f;
		_m12 = 0.0f; _m13 = 0.0f; _m14 = 0.0f; _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
    
	}

	Scale::Scale(const Vec3& s)
	{
		_m0 = s.x();   _m1 = 0.0f;  _m2 = 0.0f;  _m3 = 0.0f;
		_m4 = 0.0f;    _m5 = s.y(); _m6 = 0.0f;  _m7 = 0.0f;
		_m8 = 0.0f;    _m9 = 0.0f;  _m10 = s.z(); _m11 = 0.0f;
		_m12 = 0.0f;    _m13 = 0.0f;  _m14 = 0.0f;  _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
    
	}

	Scale::Scale(const enum Identity_enum)
	{
		_m0 = 1.0f;   _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f;   _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f;  _m10 = 1.0f;   _m11 = 0.0f;
		_m12 = 0.0f; _m13 = 0.0f; _m14 = 0.0f; _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
    
	}

	void Scale::set(const float sx, const float sy, const float sz)
	{
		_m0 = sx;   _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = sy;   _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = sz;   _m11 = 0.0f;
		_m12 = 0.0f; _m13 = 0.0f; _m14 = 0.0f; _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
    
	}

	void Scale::set(const Vec3& s)
	{
		_m0 = s.x();   _m1 = 0.0f;  _m2 = 0.0f;  _m3 = 0.0f;
		_m4 = 0.0f;    _m5 = s.y(); _m6 = 0.0f;  _m7 = 0.0f;
		_m8 = 0.0f;    _m9 = 0.0f;  _m10 = s.z(); _m11 = 0.0f;
		_m12 = 0.0f;    _m13 = 0.0f;  _m14 = 0.0f;  _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
	}

	void Scale::set(const enum Identity_enum)
	{
		_m0 = 1.0f;   _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f;   _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f;  _m10 = 1.0f;   _m11 = 0.0f;
		_m12 = 0.0f; _m13 = 0.0f; _m14 = 0.0f; _m15 = 1.0f;
		((Mat4Hint&)*this).privSetScaleHint();
	}

	// Multiply with hints
	Mat4 Scale::operator*(const Mat4& A) const
	{
		Mat4 r;

		const float sx = this->_m0;
		const float sy = this->_m5;
		const float sz = this->_m10;

		// Left-multiply by Scale: scale rows of A
		r._m0 = sx * A._m0;   r._m1 = sx * A._m1;   r._m2 = sx * A._m2;   r._m3 = sx * A._m3;
		r._m4 = sy * A._m4;   r._m5 = sy * A._m5;   r._m6 = sy * A._m6;   r._m7 = sy * A._m7;
		r._m8 = sz * A._m8;   r._m9 = sz * A._m9;   r._m10 = sz * A._m10;  r._m11 = sz * A._m11;
		r._m12 = A._m12;       r._m13 = A._m13;       r._m14 = A._m14;       r._m15 = A._m15;

		// Combine hints
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), ((Mat4Hint&)A).GetHint());
    
		return r;
	}

	Scale Scale::operator*(const Scale& A) const
	{
		Scale r;
		r._m0 = this->_m0 * A._m0;
		r._m5 = this->_m5 * A._m5;
		r._m10 = this->_m10 * A._m10;
		r._m1 = r._m2 = r._m3 = 0.0f;
		r._m4 = r._m6 = r._m7 = 0.0f;
		r._m8 = r._m9 = r._m11 = 0.0f;
		r._m12 = r._m13 = r._m14 = 0.0f;
		r._m15 = 1.0f;
		// set hint
        ((Mat4Hint&)r).privSetScaleHint();
        
		return r;
	}

	Mat4 Scale::operator*(const Rot& A) const
	{
		Mat4 r;

		const float sx = this->_m0;
		const float sy = this->_m5;
		const float sz = this->_m10;

		// r = S * R; scale rows of rotation
		r._m0  = sx * A._m0;   r._m1  = sx * A._m1;   r._m2  = sx * A._m2;   r._m3  = sx * A._m3;
		r._m4  = sy * A._m4;   r._m5  = sy * A._m5;   r._m6  = sy * A._m6;   r._m7  = sy * A._m7;
		r._m8  = sz * A._m8;   r._m9  = sz * A._m9;   r._m10 = sz * A._m10;  r._m11 = sz * A._m11;
		r._m12 = A._m12;       r._m13 = A._m13;       r._m14 = A._m14;       r._m15 = A._m15;

		// Combine hints
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);
    
		return r;
	}

	Mat4 Scale::operator*(const Trans& A) const
	{
		Mat4 r;

		const float sx = this->_m0;
		const float sy = this->_m5;
		const float sz = this->_m10;

		const float tx = A._m12;
		const float ty = A._m13;
		const float tz = A._m14;

		// r = S * T; upper-left 3x3 stays as scale, bottom row becomes translation
		r._m0 = sx;    r._m1 = 0.0f;  r._m2 = 0.0f;  r._m3 = 0.0f;
		r._m4 = 0.0f;  r._m5 = sy;    r._m6 = 0.0f;  r._m7 = 0.0f;
		r._m8 = 0.0f;  r._m9 = 0.0f;  r._m10 = sz;   r._m11 = 0.0f;
		r._m12 = tx;   r._m13 = ty;   r._m14 = tz;   r._m15 = 1.0f;

		// Combine hints
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Trans);
    
		return r;
	}

	Mat4 Scale::operator*(const Quat& q) const
	{
		Mat4 r;

		// Extract scale factors from diagonal
		const float sx = this->_m0;
		const float sy = this->_m5;
		const float sz = this->_m10;

		// Build rotation components from quaternion (same convention as Mat4::set(const Quat&))
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

		const float r00 = 1.0f - 2.0f * (yy + zz);
		const float r01 = 2.0f * (xy + wz);
		const float r02 = 2.0f * (xz - wy);

		const float r10 = 2.0f * (xy - wz);
		const float r11 = 1.0f - 2.0f * (xx + zz);
		const float r12 = 2.0f * (yz + wx);

		const float r20 = 2.0f * (xz + wy);
		const float r21 = 2.0f * (yz - wx);
		const float r22 = 1.0f - 2.0f * (xx + yy);

		// r = S * R(q): scale rows of rotation, pass through last row
		r._m0 = sx * r00;  r._m1 = sx * r01;  r._m2 = sx * r02;  r._m3 = 0.0f;
		r._m4 = sy * r10;  r._m5 = sy * r11;  r._m6 = sy * r12;  r._m7 = 0.0f;
		r._m8 = sz * r20;  r._m9 = sz * r21;  r._m10 = sz * r22; r._m11 = 0.0f;

		r._m12 = 0.0f;     r._m13 = 0.0f;     r._m14 = 0.0f;    r._m15 = 1.0f;

		// Combine hints: left is Scale, right is Rot
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);

		return r;
	}

	Scale& Scale::operator*=(const Scale& A)
	{
		// In-place combine scales: multiply diagonal components
		this->_m0  *= A._m0;
		this->_m5  *= A._m5;
		this->_m10 *= A._m10;

		// Ensure pure scale matrix layout is preserved
		this->_m1 = this->_m2 = this->_m3 = 0.0f;
		this->_m4 = this->_m6 = this->_m7 = 0.0f;
		this->_m8 = this->_m9 = this->_m11 = 0.0f;
		this->_m12 = this->_m13 = this->_m14 = 0.0f;
		this->_m15 = 1.0f;

		// Maintain scale hint for fast paths
		((Mat4Hint&)*this).privSetScaleHint();
    
		return *this;
	}

}

// ---  End of File ---
