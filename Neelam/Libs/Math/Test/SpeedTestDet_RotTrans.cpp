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
#define	numDETRotTrans 10000000
#else
#define	numDETRotTrans 1
#endif

TEST(SpeedTestDet_RotTrans, TestConfig::ALL)
{
#if SpeedTestDet_RotTrans

	Trans B(3.0f, 5.0f, 2.0f);
	Rot A(Rot3::YXZ, 0.233f, -1.22f, 0.567f);
	Mat4 C = A * B;
	volatile float out;
	volatile float out2;

	Mat4 *pA = &C;
	volatile float *pOut = &out;

	Mat4Test *pA2 = (Mat4Test *) &C;
	volatile float *pOut2 = &out2;
	
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

	*pOut = pA->det();
	CHECK(eq_float(*pOut, 1.0f));

	*pOut2 = pA2->det();
	CHECK(eq_float(*pOut2, 1.0f));

	CHECK(eq_float(*pOut, *pOut2));

	tA0.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA0.Toc();

	tA1.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA1.Toc();

	tA2.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA2.Toc();

	tA3.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA3.Toc();

	tA4.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA4.Toc();

	tA5.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA5.Toc();

	tA6.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA6.Toc();

	tA7.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA7.Toc();

	tA8.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut = pA->det();
	}
	tA8.Toc();

	tB.Tic();
	for (int i = 0; i < numDETRotTrans; i++)
	{
		*pOut2 = pA2->det();
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
	Trace::out2("         ratio: %f\n", ratio	);
	CHECK(ratio > 1.5f);
#endif
#endif

#endif
} TEST_END

// ---  End of File ---
