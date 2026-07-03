//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
#include "Mat4Test.h"

using namespace Azul;

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifdef NDEBUG
#define	numMat_QuatScale 1000000
#else
#define	numMat_QuatScale 1
#endif

TEST(SpeedTest_Mat_QuatScale, TestConfig::ALL)
{
#if SpeedTest_Mat_QuatScale

	Quat A(Rot3::YXZ, 0.233f, -1.22f, 0.567f);
	Scale B(2.0f, 7.0f, 4.0f);
	Mat4 out;
	Mat4Test out2;

	Quat *pA = &A;
	Scale *pB = &B;
	Mat4 *pOut = &out;

	Rot tmp(A);
	Mat4Test *pA2   = (Mat4Test *)&tmp;
	Mat4Test *pB2   = (Mat4Test *)&B;
	Mat4Test *pOut2 = (Mat4Test *)&out2;

	PerformanceTimer tA0;
	PerformanceTimer tA1;
	PerformanceTimer tA2;

	PerformanceTimer tA3;
	PerformanceTimer tA4;
	PerformanceTimer tA5;

	PerformanceTimer tA6;
	PerformanceTimer tA7;
	PerformanceTimer tA8;

	PerformanceTimer tB;

	*pOut = (*pA) * (*pB);
	*pOut2 = (*pA2) * (*pB2);

	CHECK(eq_float(pOut->m0(), 0.8126f));
	CHECK(eq_float(pOut->m1(), 0.0116f));
	CHECK(eq_float(pOut->m2(), 3.6548f));
	CHECK(eq_float(pOut->m3(), 0.0f));
	CHECK(eq_float(pOut->m4(), -1.0451f));
	CHECK(eq_float(pOut->m5(), 5.7450f));
	CHECK(eq_float(pOut->m6(), 0.9235f));
	CHECK(eq_float(pOut->m7(), 0.0f));
	CHECK(eq_float(pOut->m8(), -1.4990f));
	CHECK(eq_float(pOut->m9(), -3.9992f));
	CHECK(eq_float(pOut->m10(), 1.3374f));
	CHECK(eq_float(pOut->m11(), 0.0f));
	CHECK(eq_float(pOut->m12(), 0.0f));
	CHECK(eq_float(pOut->m13(), 0.0f));
	CHECK(eq_float(pOut->m14(), 0.0f));
	CHECK(eq_float(pOut->m15(), 1.0f));

	CHECK(eq_float(pOut->m0(), pOut2->_m0));
	CHECK(eq_float(pOut->m1(), pOut2->_m1));
	CHECK(eq_float(pOut->m2(), pOut2->_m2));
	CHECK(eq_float(pOut->m3(), pOut2->_m3));
	CHECK(eq_float(pOut->m4(), pOut2->_m4));
	CHECK(eq_float(pOut->m5(), pOut2->_m5));
	CHECK(eq_float(pOut->m6(), pOut2->_m6));
	CHECK(eq_float(pOut->m7(), pOut2->_m7));
	CHECK(eq_float(pOut->m8(), pOut2->_m8));
	CHECK(eq_float(pOut->m9(), pOut2->_m9));
	CHECK(eq_float(pOut->m10(), pOut2->_m10));
	CHECK(eq_float(pOut->m11(), pOut2->_m11));
	CHECK(eq_float(pOut->m12(), pOut2->_m12));
	CHECK(eq_float(pOut->m13(), pOut2->_m13));
	CHECK(eq_float(pOut->m14(), pOut2->_m14));
	CHECK(eq_float(pOut->m15(), pOut2->_m15));

	tA0.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA0.Toc();

	tA1.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA1.Toc();

	tA2.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA2.Toc();

	tA3.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA3.Toc();

	tA4.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA4.Toc();

	tA5.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA5.Toc();

	tA6.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA6.Toc();

	tA7.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA7.Toc();

	tA8.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut = (*pA) * (*pB);
	}
	tA8.Toc();

	tB.Tic();
	for (int i = 0; i < numMat_QuatScale; i++)
	{
		*pOut2 = (*pA2) * (*pB2);
	}
	tB.Toc();

	float ratio0 = (float) tB.TimeInSeconds() / (float) tA0.TimeInSeconds();
	float ratio1 = (float) tB.TimeInSeconds() / (float) tA1.TimeInSeconds();
	float ratio2 = (float) tB.TimeInSeconds() / (float) tA2.TimeInSeconds();
	float ratio3 = (float) tB.TimeInSeconds() / (float) tA3.TimeInSeconds();
	float ratio4 = (float) tB.TimeInSeconds() / (float) tA4.TimeInSeconds();
	float ratio5 = (float) tB.TimeInSeconds() / (float) tA5.TimeInSeconds();
	float ratio6 = (float) tB.TimeInSeconds() / (float) tA6.TimeInSeconds();
	float ratio7 = (float) tB.TimeInSeconds() / (float) tA7.TimeInSeconds();
	float ratio8 = (float) tB.TimeInSeconds() / (float) tA8.TimeInSeconds();

	float ratio = ratio0;
	if (ratio1 > ratio0)
	{
		ratio = ratio1;
	}

	if (ratio2 > ratio)
	{
		ratio = ratio2;
	}

	if (ratio3 > ratio)
	{
		ratio = ratio3;
	}

	if (ratio4 > ratio)
	{
		ratio = ratio4;
	}

	if (ratio5 > ratio)
	{
		ratio = ratio5;
	}

	if (ratio6 > ratio)
	{
		ratio = ratio6;
	}

	if (ratio7 > ratio)
	{
		ratio = ratio7;
	}

	if (ratio8 > ratio)
	{
		ratio = ratio8;
	}

#ifdef NDEBUG
#ifdef MATH_SPEED_TEST
	Trace::out2("         ratio: %f \n", ratio );
	CHECK(ratio > 1.15f);
#endif
#endif

#endif
} TEST_END

// ---  End of File ---
