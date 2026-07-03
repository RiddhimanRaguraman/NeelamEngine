//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MATRIX_3x3_H
#define ENGINE_MATH_MATRIX_3x3_H

#include "Math_DLLInterface.h"

#include "Vec4.h"
#include "Mat4.h"

namespace Azul
{
	class Mat3 final : public Align16
	{
	public:

		// Do your magic here

		// Big 4
		MATH_LIBRARY_API Mat3();
		MATH_LIBRARY_API Mat3 &operator = (const Mat3 &A);
		MATH_LIBRARY_API Mat3(const Mat3 &tM);
		MATH_LIBRARY_API ~Mat3();

		// Big 6
		MATH_LIBRARY_API Mat3(Mat3 &&) = default;
		MATH_LIBRARY_API Mat3 &operator=(Mat3 &&) = default;

		MATH_LIBRARY_API Mat3(const Vec3 &tV0, const Vec3 &tV1, const Vec3 &tV2);

		MATH_LIBRARY_API explicit Mat3(const Mat4 &m);
		MATH_LIBRARY_API explicit Mat3(const enum Identity_enum);

		// Get
		MATH_LIBRARY_API Vec3 get(const Row3 type) const;

		// Set 
		MATH_LIBRARY_API void set(const Mat3 &mIn);
		MATH_LIBRARY_API void set(const enum Identity_enum);
		MATH_LIBRARY_API void set(const Row3 type, const Vec3 &V);
		MATH_LIBRARY_API void set(const Vec3 &V0, const Vec3 &V1, const Vec3 &V2);

		// bracket operators	
		MATH_LIBRARY_API float &operator[] (const enum m0_enum);
		MATH_LIBRARY_API float &operator[] (const enum m1_enum);
		MATH_LIBRARY_API float &operator[] (const enum m2_enum);

		MATH_LIBRARY_API float &operator[] (const enum m4_enum);
		MATH_LIBRARY_API float &operator[] (const enum m5_enum);
		MATH_LIBRARY_API float &operator[] (const enum m6_enum);

		MATH_LIBRARY_API float &operator[] (const enum m8_enum);
		MATH_LIBRARY_API float &operator[] (const enum m9_enum);
		MATH_LIBRARY_API float &operator[] (const enum m10_enum);

		MATH_LIBRARY_API float operator[] (const enum m0_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m1_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m2_enum) const;

		MATH_LIBRARY_API float operator[] (const enum m4_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m5_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m6_enum) const;

		MATH_LIBRARY_API float operator[] (const enum m8_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m9_enum) const;
		MATH_LIBRARY_API float operator[] (const enum m10_enum) const;

		// Accessor	
		MATH_LIBRARY_API void m0(const float v);
		MATH_LIBRARY_API void m1(const float v);
		MATH_LIBRARY_API void m2(const float v);

		MATH_LIBRARY_API void m4(const float v);
		MATH_LIBRARY_API void m5(const float v);
		MATH_LIBRARY_API void m6(const float v);

		MATH_LIBRARY_API void m8(const float v);
		MATH_LIBRARY_API void m9(const float v);
		MATH_LIBRARY_API void m10(const float v);

		MATH_LIBRARY_API float m0() const;
		MATH_LIBRARY_API float m1() const;
		MATH_LIBRARY_API float m2() const;

		MATH_LIBRARY_API float m4() const;
		MATH_LIBRARY_API float m5() const;
		MATH_LIBRARY_API float m6() const;

		MATH_LIBRARY_API float m8() const;
		MATH_LIBRARY_API float m9() const;
		MATH_LIBRARY_API float m10() const;

		// Determinant
		MATH_LIBRARY_API float det() const;

		// Transpose
		MATH_LIBRARY_API Mat3 &T(void);
		MATH_LIBRARY_API Mat3 getT(void)const;

		// Inverse
		MATH_LIBRARY_API Mat3 getInv(void) const;
		MATH_LIBRARY_API Mat3 &inv(void);

		// Comparison
		MATH_LIBRARY_API bool isEqual(const Mat3 &A, const float epsilon = MATH_TOLERANCE) const;
		MATH_LIBRARY_API bool isIdentity(const float epsilon = MATH_TOLERANCE) const;

		// Add operators
		MATH_LIBRARY_API Mat3 operator + (void) const;
		MATH_LIBRARY_API Mat3 operator + (const Mat3 &A) const;
		MATH_LIBRARY_API Mat3 &operator += (const Mat3 &A);

		// Sub operators
		MATH_LIBRARY_API Mat3 operator - (void) const;
		MATH_LIBRARY_API Mat3 operator - (const Mat3 &A) const;
		MATH_LIBRARY_API Mat3 &operator -= (const Mat3 &A);

		// Scale operators
		MATH_LIBRARY_API Mat3 operator * (const float s) const;
		MATH_LIBRARY_API friend Mat3 operator *(const float scale, const Mat3 &A);
		MATH_LIBRARY_API Mat3 &operator *= (const float scale);

		// Multiply
		MATH_LIBRARY_API Mat3 operator * (const Mat3 &A) const;
		MATH_LIBRARY_API Mat3 &operator *= (const Mat3 &A);

		// For printing
		MATH_LIBRARY_API void Print(const char *pName) const;

	private:
		Mat3 privGetAdj(void) const;

	private:

		friend Mat4;
		friend Vec3;
		friend Vec4;

		union
		{
			/*     | m0  m1  m2   0 | */
			/* m = | m4  m5  m6   0 | */
			/*     | m8  m9  m10  0 | */
			/*     | 0   0   0    1 | */

			struct
			{
				Vec4 _rows[4];
			};


			struct
			{
				Vec4 _v0;
				Vec4 _v1;
				Vec4 _v2;
				Vec4 _v3;
			};

			struct
			{
				float _m0;
				float _m1;
				float _m2;
				float _m3;
				float _m4;
				float _m5;
				float _m6;
				float _m7;
				float _m8;
				float _m9;
				float _m10;
				float _m11;
				float _m12;
				float _m13;
				float _m14;
				float _m15;
			};
		};
	};
}

#endif

//--- End of File ---
