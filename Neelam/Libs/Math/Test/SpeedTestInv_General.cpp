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
#define	numINVGeneral 1000000
#else
#define	numINVGeneral 1
#endif

TEST(SpeedTestInv_General, TestConfig::ALL)
{
#if SpeedTestInv_General

	Mat4 A;
	Mat4 A0;
	Mat4 B;
	Mat4 B2;
	Mat4 C;

	A.set(Vec4(5, 2, 6, 2),
		  Vec4(6, 2, 6, 3),
		  Vec4(6, 2, 1, 6),
		  Vec4(8, 5, 8, 7));

	Mat4 *pA = &A;
	Mat4 *pB = &B;

	Mat4Test *pA2 = (Mat4Test *) &A;
	Mat4Test *pB2 = (Mat4Test *) &B2;

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

	tA0.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA0.Toc();

	tA1.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA1.Toc();

	tA2.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA2.Toc();

	tA3.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA3.Toc();

	tA4.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA4.Toc();

	tA5.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA5.Toc();

	tA6.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA6.Toc();

	tA7.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA7.Toc();

	tA8.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB = pA->getInv();
	}
	tA8.Toc();

	tB.Tic();
	for (int i = 0; i < numINVGeneral; i++)
	{
		*pB2 = pA2->getInv2();
	}
	tB.Toc();

	//Trace::out("    4x4 Mat4 -> M = M; \n");

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
	Trace::out2("         ratio: %f\n", ratio);
#endif
#endif

	C = A * B;

	CHECK(true == C.isIdentity());

	C = A * B2;

	CHECK(true == C.isIdentity());

#endif
} TEST_END

// ---  End of File ---
