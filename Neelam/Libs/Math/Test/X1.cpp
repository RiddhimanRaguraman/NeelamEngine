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

TEST(X1_Bracket_Write_Hint_kill, TestConfig::ALL)
{
#if X1_Bracket_Write_Hint_kill

	Mat4Hint::Hint h;

	{
		Rot R0(Rot1::X, 0.3452f);
		Rot R;
		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m0] = 5.0f;
		h = ((Mat4Hint &) R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &) R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m1] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m2] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m3] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m4] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m5] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m6] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m7] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m8] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m9] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m10] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m11] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m12] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m13] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m14] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		R = R0;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Rot);
		R[m15] = 5.0f;
		h = ((Mat4Hint &)R).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

	{
		Trans T0(5.0f, 6.0f, 7.0f);
		Trans T;

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m0] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m1] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m2] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m3] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m4] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m5] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m6] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m7] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m8] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m9] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m10] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m11] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m12] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m13] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m14] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		T = T0;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Trans);
		T[m15] = 5.0f;
		h = ((Mat4Hint &)T).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Scale S;

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m0] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m1] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m2] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m3] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m4] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m5] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m6] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m7] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m8] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m9] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m10] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m11] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m12] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m13] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m14] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		S = S0;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Scale);
		S[m15] = 5.0f;
		h = ((Mat4Hint &)S).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}


	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Trans T0(5.0f, 6.0f, 7.0f);
		Mat4 M0 = S0 * T0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m0] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m1] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m2] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m3] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m4] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m5] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m6] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m7] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m8] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m9] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m10] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m11] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m12] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m13] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m14] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::TransScale);
		M[m15] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

	{
		Scale S0(5.0f, 6.0f, 7.0f);
		Rot R0(Rot1::X, 0.3452f);
		Mat4 M0 = R0 * S0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m0] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m1] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m2] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m3] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m4] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m5] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m6] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m7] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m8] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m9] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m10] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m11] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m12] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m13] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m14] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotScale);
		M[m15] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

	{
		Trans T0(5.0f, 6.0f, 7.0f);
		Rot R0(Rot1::X, 0.3452f);
		Mat4 M0 = R0 * T0;
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m0] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m1] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m2] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m3] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m4] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m5] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m6] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m7] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m8] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m9] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m10] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m11] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m12] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m13] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m14] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::RotTrans);
		M[m15] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
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
		M[m0] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m1] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m2] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m3] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m4] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m5] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m6] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m7] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m8] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m9] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m10] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m11] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m12] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m13] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m14] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Affine);
		M[m15] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

	{
		Mat4 M0(Vec4(1, 2, 3, 4), Vec4(5, 6, 7, 8), Vec4(9, 10, 11, 12), Vec4(13, 14, 15, 16));
		Mat4 M;

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m0] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m1] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m2] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m3] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m4] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m5] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m6] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m7] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m8] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m9] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m10] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m11] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m12] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m13] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m14] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);

		M = M0;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
		M[m15] = 5.0f;
		h = ((Mat4Hint &)M).GetHint();
		CHECK(h == Mat4Hint::Hint::Generalize);
	}

#endif
} TEST_END

// ---  End of File ---------------
