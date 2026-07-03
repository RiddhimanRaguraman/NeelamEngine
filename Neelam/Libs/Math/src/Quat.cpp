//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "Mat4Hint.h"

namespace Azul
{

	// Do your magic here
	Quat::Quat(void)
		: _qx(0.0f), _qy(0.0f), _qz(0.0f), _qw(1.0f)
	{
	}

	Quat::~Quat(void)
	{
	}

    Quat Quat::operator*(const Quat& b) const
    {
        return Quat(
            this->_qV3 * b._qw + b._qV3 * this->_qw + b._qV3.cross(this->_qV3),
            this->_qw * b._qw - this->_qV3.dot(b._qV3)
        );
    }

    Quat& Quat::operator*=(const Quat& b)
    {
        // Snapshot current components, then compute inline
        const Vec3 oldV = this->_qV3;
        const float oldW = this->_qw;
        this->_qV3 = oldV * b._qw + b._qV3 * oldW + b._qV3.cross(oldV);
        this->_qw  = oldW * b._qw - oldV.dot(b._qV3);
        return *this;
    }

	Quat::Quat(const Quat& qIn)
		: _qx(qIn._qx), _qy(qIn._qy), _qz(qIn._qz), _qw(qIn._qw)
	{
	}

	Quat::Quat(const Vec3& vect, const float real)
		: _qx(vect[x]), _qy(vect[y]), _qz(vect[z]), _qw(real)
	{
	}

	Quat::Quat(const float vx, const float vy, const float vz, const float real)
		: _qx(vx), _qy(vy), _qz(vz), _qw(real)
	{
	}

	Quat::Quat(const enum Identity_enum)
		: _qx(0.0f), _qy(0.0f), _qz(0.0f), _qw(1.0f)
	{
	}

	Quat::Quat(const Rot& r)
	{
		const float trace = r._m0 + r._m5 + r._m10;
		if (trace > 0.0f)
		{
			const float S = 2.0f * Trig::sqrt(trace + 1.0f);
			this->_qw = 0.25f * S;
			this->_qx = -(r._m9 - r._m6) / S;
			this->_qy = -(r._m2 - r._m8) / S;
			this->_qz = -(r._m4 - r._m1) / S;
		}
		else if ((r._m0 > r._m5) && (r._m0 > r._m10))
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m0 - r._m5 - r._m10);
			this->_qw = -(r._m9 - r._m6) / S;
			this->_qx = 0.25f * S;
			this->_qy = (r._m1 + r._m4) / S;
			this->_qz = (r._m2 + r._m8) / S;
		}
		else if (r._m5 > r._m10)
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m5 - r._m0 - r._m10);
			this->_qw = -(r._m2 - r._m8) / S;
			this->_qx = (r._m1 + r._m4) / S;
			this->_qy = 0.25f * S;
			this->_qz = (r._m6 + r._m9) / S;
		}
		else
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m10 - r._m0 - r._m5);
			this->_qw = -(r._m4 - r._m1) / S;
			this->_qx = (r._m2 + r._m8) / S;
			this->_qy = (r._m6 + r._m9) / S;
			this->_qz = 0.25f * S;
		}
	}

	Quat::Quat(const Rot1 type, const float angle)
	{
		const float half = 0.5f * angle;
		float c, s;
		Trig::cossin(c, s, half);
		this->_qw = c;
		switch (type)
		{
		case Rot1::X:
			this->_qx = s; this->_qy = 0.0f; this->_qz = 0.0f;
			break;
		case Rot1::Y:
			this->_qx = 0.0f; this->_qy = s; this->_qz = 0.0f;
			break;
		case Rot1::Z:
			this->_qx = 0.0f; this->_qy = 0.0f; this->_qz = s;
			break;
		}
	}

	Quat::Quat(const Rot3 type, const float angle_x, const float angle_y, const float angle_z)
	{
        Quat qx(Rot1::X, angle_x);
        Quat qy(Rot1::Y, angle_y);
        Quat qz(Rot1::Z, angle_z);
        switch (type)
        {
        case Rot3::XYZ:
            *this = (qx * qy) * qz;
            break;
        case Rot3::XZY:
            *this = (qx * qz) * qy;
            break;
        case Rot3::YXZ:
            *this = (qy * qx) * qz;
            break;
        case Rot3::YZX:
            *this = (qy * qz) * qx;
            break;
        case Rot3::ZXY:
            *this = (qz * qx) * qy;
            break;
        case Rot3::ZYX:
            *this = (qz * qy) * qx;
            break;
		case Rot3::Uninitialized:
			// no rotataion on the gameobject
			break;
        }
    }

	Quat::Quat(const Axis type, const Vec3& vAxis, const float angle_radians)
	{
		Vec3 n(vAxis);
		if (type == Axis::AxisAngle)
		{
			n.norm();
		}
		else
		{
			assert(Util::isEqual(n.len(), 1.0f, MATH_TOLERANCE));
		}
		float c, s;
		Trig::cossin(c, s, 0.5f * angle_radians);
		n *= s;
		this->_qx = n[x];
		this->_qy = n[y];
		this->_qz = n[z];
		this->_qw = c;
	}

	Quat& Quat::operator=(const Quat& q)
	{
		this->_qx = q._qx;
		this->_qy = q._qy;
		this->_qz = q._qz;
		this->_qw = q._qw;
		return *this;
	}

	Quat& Quat::operator=(const Rot& r)
	{
		const float trace = r._m0 + r._m5 + r._m10;
		if (trace > 0.0f)
		{
			const float S = 2.0f * Trig::sqrt(trace + 1.0f);
			this->_qw = 0.25f * S;
			this->_qx = -(r._m9 - r._m6) / S;
			this->_qy = -(r._m2 - r._m8) / S;
			this->_qz = -(r._m4 - r._m1) / S;
		}
		else if ((r._m0 > r._m5) && (r._m0 > r._m10))
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m0 - r._m5 - r._m10);
			this->_qw = -(r._m9 - r._m6) / S;
			this->_qx = 0.25f * S;
			this->_qy = (r._m1 + r._m4) / S;
			this->_qz = (r._m2 + r._m8) / S;
		}
		else if (r._m5 > r._m10)
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m5 - r._m0 - r._m10);
			this->_qw = -(r._m2 - r._m8) / S;
			this->_qx = (r._m1 + r._m4) / S;
			this->_qy = 0.25f * S;
			this->_qz = (r._m6 + r._m9) / S;
		}
		else
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m10 - r._m0 - r._m5);
			this->_qw = -(r._m4 - r._m1) / S;
			this->_qx = (r._m2 + r._m8) / S;
			this->_qy = (r._m6 + r._m9) / S;
			this->_qz = 0.25f * S;
		}
		return *this;
	}

	Quat::Quat(const Orient type, const Vec3& dof, const Vec3& up)
	{
		Rot r(type, dof, up);
		const float trace = r._m0 + r._m5 + r._m10;
		if (trace > 0.0f)
		{
			const float S = 2.0f * Trig::sqrt(trace + 1.0f);
			this->_qw = 0.25f * S;
			this->_qx = -(r._m9 - r._m6) / S;
			this->_qy = -(r._m2 - r._m8) / S;
			this->_qz = -(r._m4 - r._m1) / S;
		}
		else if ((r._m0 > r._m5) && (r._m0 > r._m10))
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m0 - r._m5 - r._m10);
			this->_qw = -(r._m9 - r._m6) / S;
			this->_qx = 0.25f * S;
			this->_qy = (r._m1 + r._m4) / S;
			this->_qz = (r._m2 + r._m8) / S;
		}
		else if (r._m5 > r._m10)
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m5 - r._m0 - r._m10);
			this->_qw = -(r._m2 - r._m8) / S;
			this->_qx = (r._m1 + r._m4) / S;
			this->_qy = 0.25f * S;
			this->_qz = (r._m6 + r._m9) / S;
		}
		else
		{
			const float S = 2.0f * Trig::sqrt(1.0f + r._m10 - r._m0 - r._m5);
			this->_qw = -(r._m4 - r._m1) / S;
			this->_qx = (r._m2 + r._m8) / S;
			this->_qy = (r._m6 + r._m9) / S;
			this->_qz = 0.25f * S;
		}
	}

    // Set functions
    void Quat::set(const enum Identity_enum)
    {
        this->_qx = 0.0f;
        this->_qy = 0.0f;
        this->_qz = 0.0f;
        this->_qw = 1.0f;
    }

    void Quat::set(const Rot& r)
    {
        *this = r;
    }

    void Quat::set(const Rot1 type, const float angle)
    {
        const float half = 0.5f * angle;
        float c, s;
        Trig::cossin(c, s, half);
        this->_qw = c;
        switch (type)
        {
        case Rot1::X:
            this->_qx = s; this->_qy = 0.0f; this->_qz = 0.0f;
            break;
        case Rot1::Y:
            this->_qx = 0.0f; this->_qy = s; this->_qz = 0.0f;
            break;
        case Rot1::Z:
            this->_qx = 0.0f; this->_qy = 0.0f; this->_qz = s;
            break;
        }
    }

    void Quat::set(const Rot3 type, const float angle_x, const float angle_y, const float angle_z)
    {
        Quat qx(Rot1::X, angle_x);
        Quat qy(Rot1::Y, angle_y);
        Quat qz(Rot1::Z, angle_z);
        switch (type)
        {
        case Rot3::XYZ:
            *this = (qx * qy) * qz;
            break;
        case Rot3::XZY:
            *this = (qx * qz) * qy;
            break;
        case Rot3::YXZ:
            *this = (qy * qx) * qz;
            break;
        case Rot3::YZX:
            *this = (qy * qz) * qx;
            break;
        case Rot3::ZXY:
            *this = (qz * qx) * qy;
            break;
        case Rot3::ZYX:
            *this = (qz * qy) * qx;
            break;
		case Rot3::Uninitialized:
			// no rotataion on the gameobject
			break;
        }
    }

    void Quat::set(const Axis type, const Vec3& vAxis, const float angle_radians)
    {
        Vec3 n(vAxis);
        if (type == Axis::AxisAngle)
        {
            n.norm();
        }
        else
        {
            assert(Util::isEqual(n.len(), 1.0f, MATH_TOLERANCE));
        }
        float c, s;
        Trig::cossin(c, s, 0.5f * angle_radians);
        n *= s;
        this->_qx = n[x];
        this->_qy = n[y];
        this->_qz = n[z];
        this->_qw = c;
    }

    void Quat::set(const Orient type, const Vec3& dof, const Vec3& up)
    {
        Rot r(type, dof, up);
        *this = r;
    }

    void Quat::set(const float vx, const float vy, const float vz, const float real)
    {
        this->_qx = vx;
        this->_qy = vy;
        this->_qz = vz;
        this->_qw = real;
    }

    // Non-const bracket operators
    float& Quat::operator[](const x_enum)
    {
        return this->_qx;
    }
    float& Quat::operator[](const y_enum)
    {
        return this->_qy;
    }
    float& Quat::operator[](const z_enum)
    {
        return this->_qz;
    }
    float& Quat::operator[](const w_enum)
    {
        return this->_qw;
    }

    // Mutators
    void Quat::qx(const float v)
    {
        this->_qx = v;
    }
    void Quat::qy(const float v)
    {
        this->_qy = v;
    }
    void Quat::qz(const float v)
    {
        this->_qz = v;
    }
    void Quat::qw(const float v)
    {
        this->_qw = v;
    }
    void Quat::real(const float v)
    {
        this->_real = v;
    }

    void Quat::setVec3(const Vec3& vect)
    {
        this->_qx = vect[x];
        this->_qy = vect[y];
        this->_qz = vect[z];
    }

    void Quat::set(const Vec3& vect, const float real)
    {
        this->_qx = vect[x];
        this->_qy = vect[y];
        this->_qz = vect[z];
        this->_qw = real;
    }

	float Quat::operator[](const x_enum value) const
	{
		return this->_qx;
	}
	float Quat::operator[](const y_enum value) const
	{
		return this->_qy;
	}
	float Quat::operator[](const z_enum value) const
	{
		return this->_qz;
	}
	float Quat::operator[](const w_enum value) const
	{
		return this->_qw;
	}
	
	// Accessor getters expected by tests
	float Quat::qx() const
	{
		return this->_qx;
	}

	float Quat::qy() const
	{
		return this->_qy;
	}

	float Quat::qz() const
	{
		return this->_qz;
	}

	float Quat::qw() const
	{
		return this->_qw;
	}

	float Quat::real() const
	{
		return this->_real;
	}

	// Magnitude helpers
	float Quat::magSquared(void) const
	{
		return this->_qx * this->_qx
			+ this->_qy * this->_qy
			+ this->_qz * this->_qz
			+ this->_qw * this->_qw;
	}

	float Quat::mag(void) const
	{
		return Trig::sqrt(this->magSquared());
	}

	float Quat::invMag(void) const
	{
		const float msq = this->magSquared();
		if (msq > MATH_TOLERANCE)
		{
			return Trig::rsqrt(msq);
		}
		return 0.0f;
	}

	// Normalize in place
	Quat& Quat::norm(void)
	{
		const float msq = this->magSquared();
		if (msq > MATH_TOLERANCE)
		{
			const float inv = Trig::rsqrt(msq);
			this->_qx *= inv;
			this->_qy *= inv;
			this->_qz *= inv;
			this->_qw *= inv;
		}
		return *this;
	}

	Quat Quat::getNorm(void) const
	{
		const float msq = this->magSquared();
		if (msq > MATH_TOLERANCE)
		{
			const float inv = Trig::rsqrt(msq);
			return Quat(this->_qx * inv, this->_qy * inv, this->_qz * inv, this->_qw * inv);
		}
		return Quat(*this);
	}

	// Conjugate in place
	Quat &Quat::conj(void)
	{
		this->_qx = -this->_qx;
		this->_qy = -this->_qy;
		this->_qz = -this->_qz;
		return *this;
	}

	// Return conjugate
	Quat Quat::getConj(void) const
	{
		return Quat(-this->_qx, -this->_qy, -this->_qz, this->_qw);
	}

	// Inverse in place
	Quat &Quat::inv(void)
	{
		const float msq = this->magSquared();
		if (msq > MATH_TOLERANCE)
		{
			const float invMsq = 1.0f / msq;
			this->_qx = -this->_qx * invMsq;
			this->_qy = -this->_qy * invMsq;
			this->_qz = -this->_qz * invMsq;
			this->_qw =  this->_qw * invMsq;
		}
		return *this;
	}

	// Return inverse
	Quat Quat::getInv(void) const 
	{
		const float msq = this->magSquared();
		if (msq > MATH_TOLERANCE)
		{
			const float invMsq = 1.0f / msq;
			return Quat(-this->_qx * invMsq, -this->_qy * invMsq, -this->_qz * invMsq, this->_qw * invMsq);
		}
		return Quat(*this);
	}

	float Quat::getAngle(void) const
	{
		const float m = this->mag();
		if (m > MATH_TOLERANCE)
		{
			float wNorm = this->_qw / m;
			if (wNorm > 1.0f) wNorm = 1.0f;
			if (wNorm < -1.0f) wNorm = -1.0f;
			return 2.0f * Trig::acos(wNorm);
		}
		return 0.0f;
	}

	 float Quat::dot(const Quat& qin) const
	{
		 return this->_qx * qin._qx
			 + this->_qy * qin._qy
			 + this->_qz * qin._qz
			 + this->_qw * qin._qw;
	}

	void Quat::getVec3(Vec3& vOut) const
	{
		vOut.set(this->_qx, this->_qy, this->_qz);
	}

	void Quat::getAxis(Vec3& vOut) const
	{
		const float m = this->mag();
		if (m <= MATH_TOLERANCE)
		{
			vOut.set(1.0f, 0.0f, 0.0f);
			return;
		}
		const float angle = this->getAngle();
		const float sinHalf = Trig::sin(0.5f * angle);
		if (sinHalf > MATH_TOLERANCE)
		{
			const float inv = 1.0f / (m * sinHalf);
			vOut.set(this->_qx * inv, this->_qy * inv, this->_qz * inv);
		}
		else
		{
			vOut.set(1.0f, 0.0f, 0.0f);
		}
	}

	// Implement comparison functions
	bool Quat::isEqual(const Quat& qin, const float epsilon) const
	{
		return Util::isEqual(this->_qx, qin._qx, epsilon)
			&& Util::isEqual(this->_qy, qin._qy, epsilon)
			&& Util::isEqual(this->_qz, qin._qz, epsilon)
			&& Util::isEqual(this->_qw, qin._qw, epsilon);
	}

	bool Quat::isNegEqual(const Quat& qin, const float epsilon) const
	{
		return Util::isEqual(this->_qx, -qin._qx, epsilon)
			&& Util::isEqual(this->_qy, -qin._qy, epsilon)
			&& Util::isEqual(this->_qz, -qin._qz, epsilon)
			&& Util::isEqual(this->_qw, -qin._qw, epsilon);
	}

	bool Quat::isEquivalent(const Quat& qin, const float epsilon) const
	{
		return this->isEqual(qin, epsilon) || this->isNegEqual(qin, epsilon);
	}

	bool Quat::isConjugateEqual(const Quat& qin, const float epsilon) const
	{
		return Util::isEqual(-this->_qx, qin._qx, epsilon)
			&& Util::isEqual(-this->_qy, qin._qy, epsilon)
			&& Util::isEqual(-this->_qz, qin._qz, epsilon)
			&& Util::isEqual(this->_qw, qin._qw, epsilon);
	}

	

	bool Quat::isIdentity(const float epsilon) const
	{
		return Util::isEqual(this->_qx, 0.0f, epsilon)
			&& Util::isEqual(this->_qy, 0.0f, epsilon)
			&& Util::isEqual(this->_qz, 0.0f, epsilon)
			&& Util::isEqual(this->_qw, 1.0f, epsilon);
	}

	// vOut = Quat * vIn * Quat.conj()
	void Quat::Lqvqc(const Vec3 &vIn, Vec3 &vOut) const
	{
		vOut = (vIn * (this->_qw * this->_qw - this->_qV3.dot(this->_qV3))) 
					+ (this->_qV3 * (2.0f * this->_qV3.dot(vIn))) 
					+ (vIn.cross(this->_qV3) * (2.0f * this->_qw));
	}

	// vOut = Quat.conj() * vIn * Quat
	void Quat::Lqcvq(const Vec3 &vIn, Vec3 &vOut) const
	{
		vOut = (vIn * (this->_qw * this->_qw - this->_qV3.dot(this->_qV3))) 
					+ (this->_qV3 * (2.0f * this->_qV3.dot(vIn))) 
			        + (this->_qV3.cross(vIn) * (2.0f * this->_qw));
	}

	bool Quat::isNormalized(const float epsilon) const
	{
		const float msq = this->_qx * this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw;
		return Util::isEqual(msq, 1.0f, epsilon);
	}

	// Unary and binary +
	Quat Quat::operator+(void) const
	{
		return *this;
	}

	Quat Quat::operator+(const Quat& q) const
	{
		return Quat(this->_qx + q._qx, this->_qy + q._qy, this->_qz + q._qz, this->_qw + q._qw);
	}

	Quat& Quat::operator+=(const Quat& q)
	{
		this->_qx += q._qx;
		this->_qy += q._qy;
		this->_qz += q._qz;
		this->_qw += q._qw;
		return *this;
	}

	Quat Quat::operator+(const float a) const
	{
		return Quat(this->_qx + a, this->_qy + a, this->_qz + a, this->_qw + a);
	}

	Quat& Quat::operator+=(const float a)
	{
		this->_qx += a;
		this->_qy += a;
		this->_qz += a;
		this->_qw += a;
		return *this;
	}

	// Unary and binary -
	Quat Quat::operator-(void) const
	{
		return Quat(-this->_qx, -this->_qy, -this->_qz, -this->_qw);
	}

	Quat Quat::operator-(const Quat& q) const
	{
		return Quat(this->_qx - q._qx, this->_qy - q._qy, this->_qz - q._qz, this->_qw - q._qw);
	}

	Quat& Quat::operator-=(const Quat& q)
	{
		this->_qx -= q._qx;
		this->_qy -= q._qy;
		this->_qz -= q._qz;
		this->_qw -= q._qw;
		return *this;
	}

	Quat Quat::operator-(const float a) const
	{
		return Quat(this->_qx - a, this->_qy - a, this->_qz - a, this->_qw - a);
	}

	Quat& Quat::operator-=(const float a)
	{
		this->_qx -= a;
		this->_qy -= a;
		this->_qz -= a;
		this->_qw -= a;
		return *this;
	}

	// Scalar *
	Quat Quat::operator*(const float a) const
	{
		return Quat(this->_qx * a, this->_qy * a, this->_qz * a, this->_qw * a);
	}

	Quat& Quat::operator*=(const float a)
	{
		this->_qx *= a;
		this->_qy *= a;
		this->_qz *= a;
		this->_qw *= a;
		return *this;
	}

	Mat4 Quat::operator*(const Mat4& m) const
	{
		Mat4 r;

		// Row 0
		r._m0 = (1.0f - 2.0f * (_qy * _qy + _qz * _qz)) * m._m0 + (2.0f * (_qx * _qy + _qw * _qz)) * m._m4 + (2.0f * (_qx * _qz - _qw * _qy)) * m._m8;
		r._m1 = (1.0f - 2.0f * (_qy * _qy + _qz * _qz)) * m._m1 + (2.0f * (_qx * _qy + _qw * _qz)) * m._m5 + (2.0f * (_qx * _qz - _qw * _qy)) * m._m9;
		r._m2 = (1.0f - 2.0f * (_qy * _qy + _qz * _qz)) * m._m2 + (2.0f * (_qx * _qy + _qw * _qz)) * m._m6 + (2.0f * (_qx * _qz - _qw * _qy)) * m._m10;
		r._m3 = (1.0f - 2.0f * (_qy * _qy + _qz * _qz)) * m._m3 + (2.0f * (_qx * _qy + _qw * _qz)) * m._m7 + (2.0f * (_qx * _qz - _qw * _qy)) * m._m11;

		// Row 1
		r._m4 = (2.0f * (_qx * _qy - _qw * _qz)) * m._m0 + (1.0f - 2.0f * (_qx * _qx + _qz * _qz)) * m._m4 + (2.0f * (_qy * _qz + _qw * _qx)) * m._m8;
		r._m5 = (2.0f * (_qx * _qy - _qw * _qz)) * m._m1 + (1.0f - 2.0f * (_qx * _qx + _qz * _qz)) * m._m5 + (2.0f * (_qy * _qz + _qw * _qx)) * m._m9;
		r._m6 = (2.0f * (_qx * _qy - _qw * _qz)) * m._m2 + (1.0f - 2.0f * (_qx * _qx + _qz * _qz)) * m._m6 + (2.0f * (_qy * _qz + _qw * _qx)) * m._m10;
		r._m7 = (2.0f * (_qx * _qy - _qw * _qz)) * m._m3 + (1.0f - 2.0f * (_qx * _qx + _qz * _qz)) * m._m7 + (2.0f * (_qy * _qz + _qw * _qx)) * m._m11;

		// Row 2
		r._m8 = (2.0f * (_qx * _qz + _qw * _qy)) * m._m0 + (2.0f * (_qy * _qz - _qw * _qx)) * m._m4 + (1.0f - 2.0f * (_qx * _qx + _qy * _qy)) * m._m8;
		r._m9 = (2.0f * (_qx * _qz + _qw * _qy)) * m._m1 + (2.0f * (_qy * _qz - _qw * _qx)) * m._m5 + (1.0f - 2.0f * (_qx * _qx + _qy * _qy)) * m._m9;
		r._m10 = (2.0f * (_qx * _qz + _qw * _qy)) * m._m2 + (2.0f * (_qy * _qz - _qw * _qx)) * m._m6 + (1.0f - 2.0f * (_qx * _qx + _qy * _qy)) * m._m10;
		r._m11 = (2.0f * (_qx * _qz + _qw * _qy)) * m._m3 + (2.0f * (_qy * _qz - _qw * _qx)) * m._m7 + (1.0f - 2.0f * (_qx * _qx + _qy * _qy)) * m._m11;

		// Row 3 passes through
		r._m12 = m._m12;
		r._m13 = m._m13;
		r._m14 = m._m14;
		r._m15 = m._m15;

		((Mat4Hint&)r).privSetNewHint(Mat4Hint::Hint::Rot, ((Mat4Hint&)m).GetHint());
		return r;
	}

	Mat4 Quat::operator*(const Scale& m) const
	{
		Mat4 r;

		r._m0 = (1.0f - 2.0f * (_qy * _qy + _qz * _qz)) * m._m0;
		r._m1 = (2.0f * (_qx * _qy + _qw * _qz)) * m._m5;
		r._m2 = (2.0f * (_qx * _qz - _qw * _qy)) * m._m10;
		r._m3 = 0.0f;

		r._m4 = (2.0f * (_qx * _qy - _qw * _qz)) * m._m0;
		r._m5 = (1.0f - 2.0f * (_qx * _qx + _qz * _qz)) * m._m5;
		r._m6 = (2.0f * (_qy * _qz + _qw * _qx)) * m._m10;
		r._m7 = 0.0f;

		r._m8 = (2.0f * (_qx * _qz + _qw * _qy)) * m._m0;
		r._m9 = (2.0f * (_qy * _qz - _qw * _qx)) * m._m5;
		r._m10 = (1.0f - 2.0f * (_qx * _qx + _qy * _qy)) * m._m10;
		r._m11 = 0.0f;

		r._m12 = 0.0f;
		r._m13 = 0.0f;
		r._m14 = 0.0f;
		r._m15 = 1.0f;

		((Mat4Hint&)r).privSetNewHint(Mat4Hint::Hint::Rot, Mat4Hint::Hint::Scale);

		return r;
	}

	Quat& Quat::operator*=(const Rot& m)
	{
		Quat rq(m);
		*this = *this * rq;
		return *this;
	}

	Rot Quat::operator*(const Rot& m) const
	{
		// Compose using quaternion multiplication then convert back to Rot
		Quat rq(m);
		Quat qOut = *this * rq;
		return Rot(qOut);
	}

	Mat4 Quat::operator*(const Trans& m) const
	{
		// Specialized left-multiply: R(q) * T
		Mat4 r;

		// Build rotation rows from quaternion (inlined)
		r._m0 = 1.0f - 2.0f * (_qy * _qy + _qz * _qz);
		r._m1 = 2.0f * (_qx * _qy + _qw * _qz);
		r._m2 = 2.0f * (_qx * _qz - _qw * _qy);
		r._m3 = 0.0f;

		r._m4 = 2.0f * (_qx * _qy - _qw * _qz);
		r._m5 = 1.0f - 2.0f * (_qx * _qx + _qz * _qz);
		r._m6 = 2.0f * (_qy * _qz + _qw * _qx);
		r._m7 = 0.0f;

		r._m8 = 2.0f * (_qx * _qz + _qw * _qy);
		r._m9 = 2.0f * (_qy * _qz - _qw * _qx);
		r._m10 = 1.0f - 2.0f * (_qx * _qx + _qy * _qy);
		r._m11 = 0.0f;

		// Translation from Trans on bottom row
		r._m12 = m._m12;
		r._m13 = m._m13;
		r._m14 = m._m14;
		r._m15 = 1.0f;

		// Combine hints: left is rotation, right is translation
		((Mat4Hint&)r).privSetNewHint(Mat4Hint::Hint::Rot, Mat4Hint::Hint::Trans);

		return r;
	}


	// Element-wise division
	Quat Quat::operator/(const Quat& q) const
	{
		return Quat(this->_qx / q._qx, this->_qy / q._qy, this->_qz / q._qz, this->_qw / q._qw);
	}

	Quat& Quat::operator/=(const Quat& q)
	{
		this->_qx /= q._qx;
		this->_qy /= q._qy;
		this->_qz /= q._qz;
		this->_qw /= q._qw;
		return *this;
	}

	Quat Quat::operator/(const float a) const
	{
		return Quat(this->_qx / a, this->_qy / a, this->_qz / a, this->_qw / a);
	}

	Quat& Quat::operator/=(const float a)
	{
		this->_qx /= a;
		this->_qy /= a;
		this->_qz /= a;
		this->_qw /= a;
		return *this;
	}

    // Friend free functions matching declarations in Quat.h
    Quat operator+(const float a, const Quat& q)
    {
        return Quat(q._qx + a, q._qy + a, q._qz + a, q._qw + a);
    }

    Quat operator-(const float a, const Quat& q)
    {
        return Quat(a - q._qx, a - q._qy, a - q._qz, a - q._qw);
    }

    Quat operator*(const float a, const Quat& q)
    {
        return Quat(q._qx * a, q._qy * a, q._qz * a, q._qw * a);
    }

    Quat operator/(const float a, const Quat& q)
    {
        return Quat(a / q._qx, a / q._qy, a / q._qz, a / q._qw);
    }

}

//--- End of File ---
