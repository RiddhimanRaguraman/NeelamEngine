//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "Mat4Hint.h"

namespace Azul
{
	// Do your magic here

	Trans::Trans()
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetTransHint();
         
	}

	Trans::Trans(const float tx, const float ty, const float tz)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = tx;   _m13 = ty;   _m14 = tz;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetTransHint();
         
	}

	Trans::Trans(const Vec3& vTrans)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = vTrans.x(); _m13 = vTrans.y();   _m14 = vTrans.z();   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetTransHint();
         
	}

	Trans::Trans(const enum Identity_enum)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetTransHint();
         
	}

	void Trans::set(const float tx, const float ty, const float tz)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = tx;   _m13 = ty;   _m14 = tz;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetTransHint();
         
	}

	void Trans::set(const Vec3& vTrans)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = vTrans.x(); _m13 = vTrans.y();   _m14 = vTrans.z();   _m15 = 1.0f;
		((Mat4Hint&)*this).privSetTransHint();
	}

	void Trans::set(const enum Identity_enum)
	{
		_m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
		_m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
		_m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
		_m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
		((Mat4Hint&)*this).privSetTransHint();
	}

	// Multiply with hints
	Mat4 Trans::operator*(const Mat4& A) const
	{
		Mat4 r;
		const float tx = this->_m12;
		const float ty = this->_m13;
		const float tz = this->_m14;

		// Left-multiply by Trans: rows 0..2 pass through from A
		r._m0 = A._m0;   r._m1 = A._m1;   r._m2  = A._m2;   r._m3  = A._m3;
		r._m4 = A._m4;   r._m5 = A._m5;   r._m6  = A._m6;   r._m7  = A._m7;
		r._m8 = A._m8;   r._m9 = A._m9;   r._m10 = A._m10;  r._m11 = A._m11;

		// Bottom row = [tx ty tz 1] * A
		r._m12 = tx * A._m0 + ty * A._m4 + tz * A._m8  + A._m12;
		r._m13 = tx * A._m1 + ty * A._m5 + tz * A._m9  + A._m13;
		r._m14 = tx * A._m2 + ty * A._m6 + tz * A._m10 + A._m14;
		r._m15 = tx * A._m3 + ty * A._m7 + tz * A._m11 + A._m15;

		// Combine hints
     
    ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), ((Mat4Hint&)A).GetHint());
     
    return r;
	}

	Mat4 Trans::operator*(const Scale& A) const
	{
		Mat4 r;
		const float sx = A._m0;
		const float sy = A._m5;
		const float sz = A._m10;
		const float tx = this->_m12;
		const float ty = this->_m13;
		const float tz = this->_m14;

		// r = T * S; upper-left 3x3 is scale, translation is scaled by S
		r._m0 = sx;    r._m1 = 0.0f;  r._m2 = 0.0f;  r._m3 = 0.0f;
		r._m4 = 0.0f;  r._m5 = sy;    r._m6 = 0.0f;  r._m7 = 0.0f;
		r._m8 = 0.0f;  r._m9 = 0.0f;  r._m10 = sz;   r._m11 = 0.0f;
		r._m12 = tx * sx; r._m13 = ty * sy; r._m14 = tz * sz; r._m15 = 1.0f;

		// Combine hints
     
    ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Scale);
     
    return r;
	}

	Mat4 Trans::operator*(const Rot& A) const
	{
		Mat4 r;
		const float tx = this->_m12;
		const float ty = this->_m13;
		const float tz = this->_m14;

		// r = T * R; copy rotation rows, compute translated bottom row
		r._m0 = A._m0;   r._m1 = A._m1;   r._m2  = A._m2;   r._m3  = A._m3;
		r._m4 = A._m4;   r._m5 = A._m5;   r._m6  = A._m6;   r._m7  = A._m7;
		r._m8 = A._m8;   r._m9 = A._m9;   r._m10 = A._m10;  r._m11 = A._m11;
		r._m12 = tx * A._m0 + ty * A._m4 + tz * A._m8;
		r._m13 = tx * A._m1 + ty * A._m5 + tz * A._m9;
		r._m14 = tx * A._m2 + ty * A._m6 + tz * A._m10;
		r._m15 = 1.0f;

		// Combine hints
     
    ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);
     
    return r;
	}

	Trans Trans::operator*(const Trans& A) const
	{
		Trans r;
		// combine translations; rotation remains identity
		r._m12 = this->_m12 + A._m12;
		r._m13 = this->_m13 + A._m13;
		r._m14 = this->_m14 + A._m14;
		r._m0 = r._m5 = r._m10 = r._m15 = 1.0f;
		r._m1 = r._m2 = r._m3 = 0.0f;
		r._m4 = r._m6 = r._m7 = 0.0f;
		r._m8 = r._m9 = r._m11 = 0.0f;
		// set hint
         
        ((Mat4Hint&)r).privSetTransHint();
         
    return r;
	}

	Trans& Trans::operator*=(const Trans& A)
	{
		// In-place combine translations; rotation remains identity
		this->_m12 += A._m12;
		this->_m13 += A._m13;
		this->_m14 += A._m14;

		// Ensure matrix stays a pure translation
		this->_m0 = 1.0f; this->_m1 = 0.0f; this->_m2 = 0.0f; this->_m3 = 0.0f;
		this->_m4 = 0.0f; this->_m5 = 1.0f; this->_m6 = 0.0f; this->_m7 = 0.0f;
		this->_m8 = 0.0f; this->_m9 = 0.0f; this->_m10 = 1.0f; this->_m11 = 0.0f;
		this->_m15 = 1.0f;

		// Maintain hint as translation
     
    ((Mat4Hint&)*this).privSetTransHint();
     
		return *this;
	}

	Mat4 Trans::operator*(const Quat& q) const
	{
		Mat4 r;

		// Upper-left 3x3 rotation rows from q (inline, no temporaries)
		r._m0 = 1.0f - 2.0f * (q._qy * q._qy + q._qz * q._qz);
		r._m1 = 2.0f * ((q._qx * q._qy) + (q._qw * q._qz));
		r._m2 = 2.0f * ((q._qx * q._qz) - (q._qw * q._qy));
		r._m3 = 0.0f;

		r._m4 = 2.0f * ((q._qx * q._qy) - (q._qw * q._qz));
		r._m5 = 1.0f - 2.0f * ((q._qx * q._qx) + (q._qz * q._qz));
		r._m6 = 2.0f * ((q._qy * q._qz) + (q._qw * q._qx));
		r._m7 = 0.0f;

		r._m8  = 2.0f * ((q._qx * q._qz) + (q._qw * q._qy));
		r._m9  = 2.0f * ((q._qy * q._qz) - (q._qw * q._qx));
		r._m10 = 1.0f - 2.0f * ((q._qx * q._qx) + (q._qy * q._qy));
		r._m11 = 0.0f;

		// Bottom row: [tx ty tz 1] * R(q) using this->_m12/13/14 directly
		r._m12 = this->_m12 * r._m0 + this->_m13 * r._m4 + this->_m14 * r._m8;
		r._m13 = this->_m12 * r._m1 + this->_m13 * r._m5 + this->_m14 * r._m9;
		r._m14 = this->_m12 * r._m2 + this->_m13 * r._m6 + this->_m14 * r._m10;
		r._m15 = 1.0f;

		// Combine hints: left is translation, right is rotation
		((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Rot);
		return r;
	}

}



// ---  End of File ---
