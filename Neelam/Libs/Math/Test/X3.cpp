//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(X3_Bracket_Read_Hint, TestConfig::ALL)
{
#if X3_Bracket_Read_Hint

	Mat4Hint::Hint h;
	float v;

	{
		Rot R0(Rot1::X, 0.3452f);
		Rot R;
		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m0];
		CHECK(v != -13.0f); // don't care... just testing hint flags
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		v = R[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
	}

	{
		Trans T0(5.0f, 6.0f, 7.0f);
		Trans T;

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		v = T[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
	}

	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Scale S;

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		v = S[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
	}


	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Trans T0(5.0f, 6.0f, 7.0f);
		Mat4 M0 = S0 * T0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		v = M[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
	}

	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Rot R0(Rot1::X, 0.3452f);
		Mat4 M0 = R0 * S0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		v = M[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
	}

	{
		Trans T0(5.0f, 6.0f, 7.0f);
		Rot R0(Rot1::X, 0.3452f);
		Mat4 M0 = R0 * T0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m0];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m1];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m2];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m3];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m4];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m5];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m6];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m7];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m8];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m9];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m10];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m11];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m12];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m13];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m14];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		v = M[m15];
		CHECK(v = -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
	}

	{
		Scale S0(2.0f, 3.0f, 4.0f);
		Trans T0(5.0f, 6.0f, 7.0f);
		Rot R0(Rot1::X, 0.3452f);
		Mat4 M0 = R0 * T0 * S0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		v = M[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
	}

	{
		Mat4 M0(Vec4(1, 2, 3, 4), Vec4(5, 6, 7, 8), Vec4(9, 10, 11, 12), Vec4(13, 14, 15, 16));
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m0];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m1];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m2];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m3];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m4];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m5];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m6];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m7];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m8];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m9];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m10];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m11];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m12];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m13];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m14];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		v = M[m15];
		CHECK(v != -13.0f);
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

#endif
} TEST_END

// ---  End of File ---------------
