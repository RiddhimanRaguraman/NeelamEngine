//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "Mat4Hint.h"

namespace Azul
{
    // Do your magic here
    Rot::Rot()
    {
        _m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
        _m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
        _m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
        _m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetRotHint();
         
    }

    Rot::Rot(const enum Identity_enum)
    {
        _m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
        _m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
        _m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
        _m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
         
        ((Mat4Hint&)*this).privSetRotHint();
         
    }

    Rot::Rot(const Quat& q)
    {
        this->set(q);
    }

    Mat4 Rot::operator*(const Scale& A) const
    {
        // r = R * S; scale columns of R by (sx, sy, sz)
        const Mat4& Rm = *this;
        Mat4 r;

        const float sx = A._m0;
        const float sy = A._m5;
        const float sz = A._m10;

        r._m0  = Rm._m0 * sx;   r._m1  = Rm._m1 * sy;   r._m2  = Rm._m2 * sz;   r._m3  = Rm._m3;
        r._m4  = Rm._m4 * sx;   r._m5  = Rm._m5 * sy;   r._m6  = Rm._m6 * sz;   r._m7  = Rm._m7;
        r._m8  = Rm._m8 * sx;   r._m9  = Rm._m9 * sy;   r._m10 = Rm._m10 * sz;  r._m11 = Rm._m11;
        r._m12 = Rm._m12 * sx;  r._m13 = Rm._m13 * sy;  r._m14 = Rm._m14 * sz;  r._m15 = Rm._m15;

        // Combine hints
         
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Scale);
         
        return r;
    }

    Mat4 Rot::operator*(const Trans& A) const
    {
        // r = R * T; rotation stays, bottom row becomes translation
        const Mat4& Rm = *this;
        Mat4 r;

        const float tx = A._m12;
        const float ty = A._m13;
        const float tz = A._m14;

        r._m0 = Rm._m0;   r._m1 = Rm._m1;   r._m2  = Rm._m2;   r._m3  = Rm._m3;
        r._m4 = Rm._m4;   r._m5 = Rm._m5;   r._m6  = Rm._m6;   r._m7  = Rm._m7;
        r._m8 = Rm._m8;   r._m9 = Rm._m9;   r._m10 = Rm._m10;  r._m11 = Rm._m11;

        r._m12 = tx; r._m13 = ty; r._m14 = tz; r._m15 = 1.0f;

        // Combine hints
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), Mat4Hint::Hint::Trans);
        return r;
    }

    
    //Rot Rot::operator*(const Rot& A) const
    //{
    //    // Compose via quaternion multiplication to match Quat conventions
    //    return Rot(Quat(*this) * Quat(A));
    //}

    //Rot& Rot::operator*=(const Rot& A)
    //{
    //    // In-place compose via quaternion multiplication
    //    this->set(Quat(*this) * Quat(A));
    //    return *this;
    //}
    

    Rot Rot::operator*(const Rot& A) const
    {
        Rot r;

        // Row 0
        r._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8;
        r._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9;
        r._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10;
        r._m3 = 0.0f;

        // Row 1
        r._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8;
        r._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9;
        r._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10;
        r._m7 = 0.0f;

        // Row 2
        r._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8;
        r._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9;
        r._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10;
        r._m11 = 0.0f;

        // Homogeneous components
        r._m12 = 0.0f;
        r._m13 = 0.0f;
        r._m14 = 0.0f;
        r._m15 = 1.0f;

        ((Mat4Hint&)r).privSetRotHint();
        return r;
    }

    Rot& Rot::operator*=(const Rot& A)
    {
        // Save original values before overwriting
        const float m0 = this->_m0, m1 = this->_m1, m2 = this->_m2;
        const float m4 = this->_m4, m5 = this->_m5, m6 = this->_m6;
        const float m8 = this->_m8, m9 = this->_m9, m10 = this->_m10;

        // Perform in-place 3x3 rotation multiply
        this->_m0 = m0 * A._m0 + m1 * A._m4 + m2 * A._m8;
        this->_m1 = m0 * A._m1 + m1 * A._m5 + m2 * A._m9;
        this->_m2 = m0 * A._m2 + m1 * A._m6 + m2 * A._m10;
        this->_m3 = 0.0f;

        this->_m4 = m4 * A._m0 + m5 * A._m4 + m6 * A._m8;
        this->_m5 = m4 * A._m1 + m5 * A._m5 + m6 * A._m9;
        this->_m6 = m4 * A._m2 + m5 * A._m6 + m6 * A._m10;
        this->_m7 = 0.0f;

        this->_m8 = m8 * A._m0 + m9 * A._m4 + m10 * A._m8;
        this->_m9 = m8 * A._m1 + m9 * A._m5 + m10 * A._m9;
        this->_m10 = m8 * A._m2 + m9 * A._m6 + m10 * A._m10;
        this->_m11 = 0.0f;

        this->_m12 = 0.0f;
        this->_m13 = 0.0f;
        this->_m14 = 0.0f;
        this->_m15 = 1.0f;

        ((Mat4Hint&)*this).privSetRotHint();
        return *this;
    }


    // Multiply with quaternion: convert this Rot to Quat, multiply, then convert back
    Rot Rot::operator*(const Quat& A) const
    {
        Quat qLeft(*this);       // convert rotation matrix to quaternion
        Quat qOut = qLeft * A;   // quaternion multiply (matches Keenan’s convention)
        return Rot(qOut);        // convert back to rotation matrix
    }

    Rot& Rot::operator*=(const Quat& A)
    {
        Quat qLeft(*this);
        Quat qOut = qLeft * A;
        this->set(qOut);
        return *this;
    }



    Mat4 Rot::operator*(const Mat4& A) const
    {
        // Specialized left-multiply by rotation: rows 0..2 are rotated combinations; row 3 passes through
        const Mat4& Rm = *this;
        Mat4 r;

        // Row 0
        r._m0 = Rm._m0 * A._m0 + Rm._m1 * A._m4 + Rm._m2 * A._m8  + Rm._m3 * A._m12;
        r._m1 = Rm._m0 * A._m1 + Rm._m1 * A._m5 + Rm._m2 * A._m9  + Rm._m3 * A._m13;
        r._m2 = Rm._m0 * A._m2 + Rm._m1 * A._m6 + Rm._m2 * A._m10 + Rm._m3 * A._m14;
        r._m3 = Rm._m0 * A._m3 + Rm._m1 * A._m7 + Rm._m2 * A._m11 + Rm._m3 * A._m15;

        // Row 1
        r._m4 = Rm._m4 * A._m0 + Rm._m5 * A._m4 + Rm._m6 * A._m8  + Rm._m7 * A._m12;
        r._m5 = Rm._m4 * A._m1 + Rm._m5 * A._m5 + Rm._m6 * A._m9  + Rm._m7 * A._m13;
        r._m6 = Rm._m4 * A._m2 + Rm._m5 * A._m6 + Rm._m6 * A._m10 + Rm._m7 * A._m14;
        r._m7 = Rm._m4 * A._m3 + Rm._m5 * A._m7 + Rm._m6 * A._m11 + Rm._m7 * A._m15;

        // Row 2
        r._m8  = Rm._m8 * A._m0 + Rm._m9 * A._m4 + Rm._m10 * A._m8  + Rm._m11 * A._m12;
        r._m9  = Rm._m8 * A._m1 + Rm._m9 * A._m5 + Rm._m10 * A._m9  + Rm._m11 * A._m13;
        r._m10 = Rm._m8 * A._m2 + Rm._m9 * A._m6 + Rm._m10 * A._m10 + Rm._m11 * A._m14;
        r._m11 = Rm._m8 * A._m3 + Rm._m9 * A._m7 + Rm._m10 * A._m11 + Rm._m11 * A._m15;

        // Row 3 passes through from A (since last row of rotation is [0 0 0 1])
        r._m12 = A._m12; r._m13 = A._m13; r._m14 = A._m14; r._m15 = A._m15;

        // Combine hints
         
        ((Mat4Hint&)r).privSetNewHint(((Mat4Hint&)*this).GetHint(), ((Mat4Hint&)A).GetHint());
         
        return r;
    }

    Rot::Rot(const Rot1 type, const float angle)
    {
        float c, s;
        Trig::cossin(c, s, angle);

        _m0 = _m5 = _m10 = _m15 = 1.0f;
        _m1 = _m2 = _m3 = _m4 = _m6 = _m7 =
            _m8 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;

        switch (type)
        {
        case Rot1::X:
            _m5 = c;   _m6 = s;
            _m9 = -s;   _m10 = c;
            break;

        case Rot1::Y:
            _m0 = c;   _m8 = s;
            _m2 = -s;   _m10 = c;
            break;

        case Rot1::Z:
            _m0 = c;   _m1 = s;
            _m4 = -s;   _m5 = c;
            break;
        }
         
        ((Mat4Hint&)*this).privSetRotHint();
         
    }

    Rot::Rot(const Rot3 mode, const float angle_x, const float angle_y, const float angle_z)
    {
        Rot Rx(Rot1::X, angle_x);
        Rot Ry(Rot1::Y, angle_y);
        Rot Rz(Rot1::Z, angle_z);

        switch (mode)
        {
        case Rot3::XYZ:
            *this = Rx * Ry * Rz;
            break;
        case Rot3::XZY:
            *this = Rx * Rz * Ry;
            break;
        case Rot3::YXZ:
            *this = Ry * Rx * Rz;
            break;
        case Rot3::YZX:
            *this = Ry * Rz * Rx;
            break;
        case Rot3::ZXY:
            *this = Rz * Rx * Ry;
            break;
        case Rot3::ZYX:
            *this = Rz * Ry * Rx;
            break;
        case Rot3::Uninitialized:
            // no rotataion on the gameobject
            break;
        }
         
        ((Mat4Hint&)*this).privSetRotHint();
         
    }

    Rot::Rot(const Axis mode, const Vec3& vAxis, const float angle_radians)
    {
        Vec3 n(vAxis);

        if (mode == Axis::AxisAngle)
        {
            n.norm();
        }
        else
        {
            float len = n.len();
            (void)len; // prevent unused-variable warning in Release builds
            assert(Util::isEqual(len, 1.0f, MATH_TOLERANCE));
        }

        float half = 0.5f * angle_radians;
        float c, s;
        Trig::cossin(c, s, half);

        n *= s;

        const float qx = n[x];
        const float qy = n[y];
        const float qz = n[z];
        const float qw = c;

        const float xx = qx * qx;
        const float yy = qy * qy;
        const float zz = qz * qz;
        const float xy = qx * qy;
        const float xz = qx * qz;
        const float yz = qy * qz;
        const float wx = qw * qx;
        const float wy = qw * qy;
        const float wz = qw * qz;

        _m0 = 1.0f - 2.0f * (yy + zz);
        _m1 = 2.0f * (xy + wz);
        _m2 = 2.0f * (xz - wy);
        _m3 = 0.0f;

        _m4 = 2.0f * (xy - wz);
        _m5 = 1.0f - 2.0f * (xx + zz);
        _m6 = 2.0f * (yz + wx);
        _m7 = 0.0f;

        _m8 = 2.0f * (xz + wy);
        _m9 = 2.0f * (yz - wx);
        _m10 = 1.0f - 2.0f * (xx + yy);
        _m11 = 0.0f;

        _m12 = 0.0f;
        _m13 = 0.0f;
        _m14 = 0.0f;
        _m15 = 1.0f;
    }

    Rot::Rot(const Orient type, const Vec3& dof, const Vec3& up)
    {
        Mat4::Mat4();
        switch (type)
        {
        case Orient::LocalToWorld:
            privSetRotOrient(dof, up);
            break;

        case Orient::WorldToLocal:
            privSetRotInvOrient(dof, up);
            break;
        }
    }

    void Rot::privSetRotOrient(const Vec3& dof, const Vec3& up)
    {
        Vec3 forward(dof);
        forward.norm();

        Vec3 right;
        right = up.cross(forward);
        right.norm();

        Vec3 temp(forward);

        Vec3 up_final;
        up_final = temp.cross(right);
        up_final.norm();


        _m0 = right.x(); _m1 = right.y(); _m2 = right.z(); _m3 = 0.0f;
        _m4 = up_final.x(); _m5 = up_final.y(); _m6 = up_final.z(); _m7 = 0.0f;
        _m8 = forward.x(); _m9 = forward.y(); _m10 = forward.z(); _m11 = 0.0f;
        _m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;

    }

    void Rot::privSetRotInvOrient(const Vec3& dof, const Vec3& up)
    {
        Vec3 forward(dof);
        forward.norm();

        Vec3 right;
        right = up.cross(forward);
        right.norm();

        Vec3 temp(forward);

        Vec3 up_final;
        up_final = forward.cross(right);
        up_final.norm();

        _m0 = right.x(); _m1 = right.y(); _m2 = right.z(); _m3 = 0.0f;
        _m4 = up_final.x(); _m5 = up_final.y(); _m6 = up_final.z(); _m7 = 0.0f;
        _m8 = forward.x(); _m9 = forward.y(); _m10 = forward.z(); _m11 = 0.0f;
        _m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;

        this->T();

        _m12 = 0.0f;
        _m13 = 0.0f;
        _m14 = 0.0f;
        _m15 = 1.0f;
    }

    void Rot::set(const enum Identity_enum)
    {
        _m0 = 1.0f; _m1 = 0.0f; _m2 = 0.0f; _m3 = 0.0f;
        _m4 = 0.0f; _m5 = 1.0f; _m6 = 0.0f; _m7 = 0.0f;
        _m8 = 0.0f; _m9 = 0.0f; _m10 = 1.0f; _m11 = 0.0f;
        _m12 = 0.0f;   _m13 = 0.0f;   _m14 = 0.0f;   _m15 = 1.0f;
        // Set rotation hint for identity rotation
        ((Mat4Hint&)*this).privSetRotHint();
    }

    void Rot::set(const Rot& r)
    {
        *this = r;
    }

    void Rot::set(const Rot1 type, const float angle)
    {
        const float c = Trig::cos(angle);
        const float s = Trig::sin(angle);

        _m0 = _m5 = _m10 = _m15 = 1.0f;
        _m1 = _m2 = _m3 = _m4 = _m6 = _m7 =
            _m8 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;
        switch (type)
        {
        case Rot1::X:
            _m5 = c;   _m6 = s;
            _m9 = -s;   _m10 = c;
            break;

        case Rot1::Y:
            _m0 = c;   _m8 = s;
            _m2 = -s;   _m10 = c;
            break;

        case Rot1::Z:
            _m0 = c;   _m1 = s;
            _m4 = -s;   _m5 = c;
            break;
        }
        // Ensure rotation hint is set after mutating elements
        ((Mat4Hint&)*this).privSetRotHint();
    }

    void Rot::set(const Rot3 mode, const float angle_x, const float angle_y, const float angle_z)
    {
        Rot Rx(Rot1::X, angle_x);
        Rot Ry(Rot1::Y, angle_y);
        Rot Rz(Rot1::Z, angle_z);

        switch (mode)
        {
        case Rot3::XYZ:
            *this = Rx * Ry * Rz;
            break;
        case Rot3::XZY:
            *this = Rx * Rz * Ry;
            break;
        case Rot3::YXZ:
            *this = Ry * Rx * Rz;
            break;
        case Rot3::YZX:
            *this = Ry * Rz * Rx;
            break;
        case Rot3::ZXY:
            *this = Rz * Rx * Ry;
            break;
        case Rot3::ZYX:
            *this = Rz * Ry * Rx;
            break;
        case Rot3::Uninitialized:
            // no rotataion on the gameobject
            break;
        }
        ((Mat4Hint&)*this).privSetRotHint();
    }

    void Rot::set(const Axis mode, const Vec3& vAxis, const float angle_radians)
    {
        Vec3 n(vAxis);

        if (mode == Axis::AxisAngle)
        {
            n.norm();
        }
        else
        {
            float len = n.len();
            (void)len; // prevent unused-variable warning in Release builds
            assert(Util::isEqual(len, 1.0f, MATH_TOLERANCE));
        }

        float half = 0.5f * angle_radians;
        float c, s;
        Trig::cossin(c, s, half);

        n *= s;

        const float qx = n[x];
        const float qy = n[y];
        const float qz = n[z];
        const float qw = c;

        const float xx = qx * qx;
        const float yy = qy * qy;
        const float zz = qz * qz;
        const float xy = qx * qy;
        const float xz = qx * qz;
        const float yz = qy * qz;
        const float wx = qw * qx;
        const float wy = qw * qy;
        const float wz = qw * qz;

        _m0 = 1.0f - 2.0f * (yy + zz);
        _m1 = 2.0f * (xy + wz);
        _m2 = 2.0f * (xz - wy);
        _m3 = 0.0f;

        _m4 = 2.0f * (xy - wz);
        _m5 = 1.0f - 2.0f * (xx + zz);
        _m6 = 2.0f * (yz + wx);
        _m7 = 0.0f;

        _m8 = 2.0f * (xz + wy);
        _m9 = 2.0f * (yz - wx);
        _m10 = 1.0f - 2.0f * (xx + yy);
        _m11 = 0.0f;

        _m12 = 0.0f;
        _m13 = 0.0f;
        _m14 = 0.0f;
        _m15 = 1.0f;

        // Set rotation hint for axis-angle setter
         
        ((Mat4Hint&)*this).privSetRotHint();
         
    }

    void Rot::set(const Quat& q)
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

        _m0 = 1.0f - 2.0f * (yy + zz);
        _m1 = 2.0f * (xy + wz);
        _m2 = 2.0f * (xz - wy);
        _m3 = 0.0f;

        _m4 = 2.0f * (xy - wz);
        _m5 = 1.0f - 2.0f * (xx + zz);
        _m6 = 2.0f * (yz + wx);
        _m7 = 0.0f;

        _m8  = 2.0f * (xz + wy);
        _m9  = 2.0f * (yz - wx);
        _m10 = 1.0f - 2.0f * (xx + yy);
        _m11 = 0.0f;

        _m12 = 0.0f;
        _m13 = 0.0f;
        _m14 = 0.0f;
        _m15 = 1.0f;

        // Mark as rotation
        ((Mat4Hint&)*this).privSetRotHint();
    }

    Rot& Rot::operator=(const Quat& q)
    {
        this->set(q);
        return *this;
    }

    void Rot::set(const Orient type, const Vec3& dof, const Vec3& up)
    {
        Mat4::Mat4();
        switch (type)
        {
        case Orient::LocalToWorld:
            privSetRotOrient(dof, up);
            break;

        case Orient::WorldToLocal:
            privSetRotInvOrient(dof, up);
            break;
        }
    }

}

// ---  End of File ---
