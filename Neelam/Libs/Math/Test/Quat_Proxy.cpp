//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h" 

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST( Quat_Proxy, TestConfig::ALL)
{
#if Quat_Proxy

	// Quat Proxy tests:
	CHECK( 1 );

#endif
} TEST_END



TEST( Quat_BracketX_get, TestConfig::ALL)
{
#if Quat_BracketX_get	

	// Quat v[x]: get
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat C;
	volatile float tmpf;
	
	// Test uninitialized const B[x] should work
	tmpf = B[x] + 5.0f;
	
	CHECK( tmpf == 7.0f );
	
	CHECK( B[x] == 2.0f );
	CHECK( B[y] == 3.0f );
	CHECK( B[z] == 4.0f );
	CHECK( B[w] == 5.0f );
	
	// TODO: Figure out how to automate this.
	// Test uninitialize mutable C[x] should assert
	//tmpf = C[x] + 5.0f;

#endif
} TEST_END



TEST( Quat_BracketX_assign, TestConfig::ALL)
{
#if Quat_BracketX_assign

	//Quat v[x] assignment:
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	
	// Test uninitialize mutable A[x] should work!
	A[x] = 1.0f;
	
	CHECK( A[x] == 1.0f );

	// Test uninitialize const B[x] should Not compile
	//	B[x] = 5.0f;

#endif
} TEST_END



TEST( Quat_BracketX_plusEqual, TestConfig::ALL)
{	
#if Quat_BracketX_plusEqual

	//Quat v[x]: += 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test += operator
	
	// Should runtime assert
//	D[x] += 1.0f;
	
	// Compiler error
//	B[x] += 1.0f;
	
	// Should work
	E[x] += 10.0f;
	CHECK( E[x] == 12.0f );
	
#endif
} TEST_END



TEST( Quat_BracketX_negEqual, TestConfig::ALL)
{	
#if Quat_BracketX_negEqual

	//Quat v[x]: -= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test -= operator
	
	// Should runtime assert
//	D[x] -= 1.0f;
	
	// Compiler error
//	B[x] -= 1.0f;
	
	// Should work
	E[x] -= 10.0f;
	CHECK( E[x] == -8.0f );

#endif
} TEST_END



TEST( Quat_BracketX_multEqual, TestConfig::ALL)
{	
#if Quat_BracketX_multEqual

	//Quat v[x]: *= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test *= operator
	
	// Should runtime assert
//	D[x] *= 1.0f;
	
	// Compiler error
//	B[x] *= 1.0f;
	
	// Should work
	E[x] *= 10.0f;
	CHECK( E[x] == 20.0f );
	
#endif
} TEST_END



TEST( Quat_BracketX_divEqual, TestConfig::ALL)
{	
#if Quat_BracketX_divEqual

	//Quat v[x]: /= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test /= operator
	
	// Should runtime assert
//	D[x] /= 1.0f;
	
	// Compiler error
//	B[x] /= 1.0f;
	
	// Should work
	E[x] /= 10.0f;
	CHECK( eq_float(E[x],0.20f) );

#endif
}   TEST_END



TEST( Quat_BracketY_get, TestConfig::ALL)
{
#if Quat_BracketY_get	

	//Quat v[y]: get
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat C;
	volatile float tmpf;
	
	// Test uninitialized const B[y] should work
	tmpf = B[y] + 5.0f;
	
	CHECK( tmpf == 8.0f );
	
	CHECK( B[x] == 2.0f );
	CHECK( B[y] == 3.0f );
	CHECK( B[z] == 4.0f );
	CHECK( B[w] == 5.0f );
	
	// TODO: Figure out how to automate this.
	// Test uninitialize mutable C[y] should assert
	//	tmpf = C[y] + 5.0f;

#endif
} TEST_END



TEST( Quat_BracketY_assign, TestConfig::ALL)
{
#if Quat_BracketY_assign

	//Quat v[y] assignment:
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	
	// Test uninitialize mutable A[y] should work!
	A[y] = 1.0f;
	
	CHECK( A[y] == 1.0f );
	
	// Test uninitialize const B[y] should Not compile
	//	B[y] = 5.0f;

#endif
} TEST_END



TEST( Quat_BracketY_plusEqual, TestConfig::ALL)
{
#if Quat_BracketY_plusEqual

	//Quat v[y]: += 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test += operator
	
	// Should runtime assert
//	D[y] += 1.0f;
	
	// Compiler error
//	B[y] += 1.0f;
	
	// Should work
	E[y] += 10.0f;
	CHECK( E[y] == 13.0f );
	
#endif
}   TEST_END



TEST( Quat_BracketY_negEqual, TestConfig::ALL)
{	
#if Quat_BracketY_negEqual

	//Quat v[y]: -= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test -= operator
	
	// Should runtime assert
//	D[y] -= 1.0f;
	
	// Compiler error
//	B[y] -= 1.0f;
	
	// Should work
	E[y] -= 10.0f;
	CHECK( E[y] == -7.0f );
	
#endif
}   TEST_END



TEST( Quat_BracketY_multEqual, TestConfig::ALL)
{	
#if Quat_BracketY_multEqual

	//Quat v[y]: *= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test *= operator
	
	// Should runtime assert
//	D[y] *= 1.0f;
	
	// Compiler error
//	B[y] *= 1.0f;
	
	// Should work
	E[y] *= 10.0f;
	CHECK( E[y] == 30.0f );
	
#endif	
}   TEST_END



TEST( Quat_BracketY_divEqual, TestConfig::ALL)
{	
#if Quat_BracketY_divEqual

	//Quat v[y]: /= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test /= operator
	
	// Should runtime assert
//	D[y] /= 1.0f;
	
	// Compiler error
//	B[y] /= 1.0f;
	
	// Should work
	E[y] /= 10.0f;
	CHECK( eq_float(E[y],0.30f) );
	
#endif	
}   TEST_END



TEST( Quat_BracketZ_get, TestConfig::ALL)
{ 
#if Quat_BracketZ_get
	

	//Quat v[z]: get
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat C;
	volatile float tmpf;
	
	// Test uninitialized const B[z] should work
	tmpf = B[z] + 5.0f;
	
	CHECK( tmpf == 9.0f );
	
	CHECK( B[x] == 2.0f );
	CHECK( B[y] == 3.0f );
	CHECK( B[z] == 4.0f );
	CHECK( B[w] == 5.0f );
	
	// TODO: Figure out how to automate this.
	// Test uninitialize mutable C[z] should assert
	//	tmpf = C[z] + 5.0f;

#endif
} TEST_END



TEST( Quat_BracketZ_assign, TestConfig::ALL)
{
#if Quat_BracketZ_assign

	//Quat v[z] assignment:
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	
	// Test uninitialize mutable A[z] should work!
	A[z] = 1.0f;
	
	CHECK( A[z] == 1.0f );
	
	// Test uninitialize const B[z] should Not compile
	//	B[z] = 5.0f;

#endif
} TEST_END



TEST( Quat_BracketZ_plusEqual, TestConfig::ALL)
{
#if Quat_BracketZ_plusEqual

	//Quat v[z]: += 
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test += operator
	
	// Should runtime assert
//	D[z] += 1.0f;
	
	// Compiler error
//	B[z] += 1.0f;
	
	// Should work
	E[z] += 10.0f;
	CHECK( E[z] == 14.0f );
	
#endif
}   TEST_END



TEST( Quat_BracketZ_negEqual, TestConfig::ALL)
{	
#if Quat_BracketZ_negEqual

	//Quat v[z]: -= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test -= operator
	
	// Should runtime assert
//	D[z] -= 1.0f;
	
	// Compiler error
//	B[z] -= 1.0f;
	
	// Should work
	E[z] -= 10.0f;
	CHECK( E[z] == -6.0f );
	
#endif
}  TEST_END



TEST( Quat_BracketZ_multEqual, TestConfig::ALL)
{	
#if Quat_BracketZ_multEqual

	//Quat v[z]: *= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test *= operator
	
	// Should runtime assert
//	D[z] *= 1.0f;
	
	// Compiler error
//	B[z] *= 1.0f;
	
	// Should work
	E[z] *= 10.0f;
	CHECK( E[z] == 40.0f );
	
#endif	
}   TEST_END



TEST( Quat_BracketZ_divEqual, TestConfig::ALL)
{	
#if Quat_BracketZ_divEqual

	//Quat v[z]: /= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test /= operator
	
	// Should runtime assert
//	D[z] /= 1.0f;
	
	// Compiler error
//	B[z] /= 1.0f;
	
	// Should work
	E[z] /= 10.0f;
	CHECK( eq_float(E[z],0.40f) );
	
#endif
}  TEST_END



TEST( Quat_BracketW_get, TestConfig::ALL)
{
#if Quat_BracketW_get	

	//Quat v[w]: get
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat C;
	volatile float tmpf;
	
	// Test uninitialized const B[z] should work
	tmpf = B[w] + 5.0f;
	
	CHECK( tmpf == 10.0f );
	
	CHECK( B[x] == 2.0f );
	CHECK( B[y] == 3.0f );
	CHECK( B[z] == 4.0f );
	CHECK( B[w] == 5.0f );
	
	// TODO: Figure out how to automate this.
	// Test uninitialize mutable C[w] should assert
	//	tmpf = C[w] + 5.0f;

#endif
} TEST_END



TEST( Quat_BracketW_assign, TestConfig::ALL)
{
#if Quat_BracketW_assign

	//Quat v[w] assignment:
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	
	// Test uninitialize mutable A[w] should work!
	A[w] = 1.0f;
	
	CHECK( A[w] == 1.0f );
	
	// Test uninitialize const B[w] should Not compile
	//	B[w] = 5.0f;

#endif
} TEST_END



TEST( Quat_BracketW_plusEqual, TestConfig::ALL)
{
#if Quat_BracketW_plusEqual

	//Quat v[w]: += 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test += operator
	
	// Should runtime assert
//	D[w] += 1.0f;
	
	// Compiler error
//	B[w] += 1.0f;
	
	// Should work
	E[w] += 10.0f;
	CHECK( E[w] == 15.0f );
	
#endif
}   TEST_END



TEST( Quat_BracketW_negEqual, TestConfig::ALL)
{	
#if Quat_BracketW_negEqual_Test

	//Quat v[w]: -= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test -= operator
	
	// Should runtime assert
//	D[w] -= 1.0f;
	
	// Compiler error
//	B[w] -= 1.0f;
	
	// Should work
	E[w] -= 10.0f;
	CHECK( E[w] == -5.0f );

#endif
}  TEST_END



TEST( Quat_BracketW_multEqual, TestConfig::ALL)
{	
#if Quat_BracketW_multEqual

	//Quat v[w]: *= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test *= operator
	
	// Should runtime assert
//	D[w] *= 1.0f;
	
	// Compiler error
//	B[w] *= 1.0f;
	
	// Should work
	E[w] *= 10.0f;
	CHECK( E[w] == 50.0f );
	
#endif	
} TEST_END



TEST( Quat_BracketW_divEqual, TestConfig::ALL)
{	
#if Quat_BracketW_divEqual

	//Quat v[w]: /= 
	
	const Quat B(2.0f,3.0f,4.0f,5.0f);
	Quat D;
	Quat E(2.0f,3.0f,4.0f,5.0f);
	// Test /= operator
	
	// Should runtime assert
//	D[w] /= 1.0f;
	
	// Compiler error
//	B[w] /= 1.0f;
	
	// Should work
	E[w] /= 10.0f;
	CHECK( eq_float(E[w],0.50f) );

#endif
} TEST_END



TEST( Quat_BracketX_assignment_ConstQuat_Bracket, TestConfig::ALL)
{
#if Quat_BracketX_assignment_ConstQuat_Bracket

	//A[x] = B[x]
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloatx = vFloatx
	A[x] = B[x];	
	CHECK( A[x] == 2.0f );
	
	A[x] = B[y];
	CHECK( A[x] == 3.0f );
	
	A[x] = B[z];
	CHECK( A[x] == 4.0f );
	
	A[x] = B[w];
	CHECK( A[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_assignment_ConstQuat_Bracket, TestConfig::ALL)
{
#if Quat_BracketY_assignment_ConstQuat_Bracket

	//A[y] = B[x]
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[y] = B[x];	
	CHECK( A[y] == 2.0f );
	
	A[y] = B[y];
	CHECK( A[y] == 3.0f );
	
	A[y] = B[z];
	CHECK( A[y] == 4.0f );
	
	A[y] = B[w];
	CHECK( A[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_assignment_ConstQuat_Bracket, TestConfig::ALL)
{
#if Quat_BracketZ_assignment_ConstQuat_Bracket

	//A[z] = B[x]
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[z] = B[x];	
	CHECK( A[z] == 2.0f );
	
	A[z] = B[y];
	CHECK( A[z] == 3.0f );
	
	A[z] = B[z];
	CHECK( A[z] == 4.0f );
	
	A[z] = B[w];
	CHECK( A[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_assignment_ConstQuat_Bracket, TestConfig::ALL)
{
#if Quat_BracketW_assignment_ConstQuat_Bracket

	//A[w] = B[x]
	Quat A;
	const Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[w] = B[x];	
	CHECK( A[w] == 2.0f );
	
	A[w] = B[y];
	CHECK( A[w] == 3.0f );
	
	A[w] = B[z];
	CHECK( A[w] == 4.0f );
	
	A[w] = B[w];
	CHECK( A[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_assignment_Quat_Bracket, TestConfig::ALL)
{
#if Quat_BracketX_assignment_Quat_Bracket

	//A[x] = B[x]
	Quat A;
	Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloatx = vFloatx
	A[x] = B[x];	
	CHECK( A[x] == 2.0f );
	
	A[x] = B[y];
	CHECK( A[x] == 3.0f );
	
	A[x] = B[z];
	CHECK( A[x] == 4.0f );
	
	A[x] = B[w];
	CHECK( A[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_assignment_Quat_Bracket, TestConfig::ALL)
{
#if Quat_BracketY_assignment_Quat_Bracket

	//A[y] = B[x]
	Quat A;
	Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[y] = B[x];	
	CHECK( A[y] == 2.0f );
	
	A[y] = B[y];
	CHECK( A[y] == 3.0f );
	
	A[y] = B[z];
	CHECK( A[y] == 4.0f );
	
	A[y] = B[w];
	CHECK( A[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_assignment_Quat_Bracket, TestConfig::ALL)
{
#if Quat_BracketZ_assignment_Quat_Bracket

	//A[z] = B[x]
	Quat A;
	Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[z] = B[x];	
	CHECK( A[z] == 2.0f );
	
	A[z] = B[y];
	CHECK( A[z] == 3.0f );
	
	A[z] = B[z];
	CHECK( A[z] == 4.0f );
	
	A[z] = B[w];
	CHECK( A[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_assignment_Quat_Bracket, TestConfig::ALL)
{
#if Quat_BracketW_assignment_Quat_Bracket

	//A[w] = B[x]
	Quat A;
	Quat B(2.0f,3.0f,4.0f,5.0f);

	// vFloaty = vFloatx
	A[w] = B[x];	
	CHECK( A[w] == 2.0f );
	
	A[w] = B[y];
	CHECK( A[w] == 3.0f );
	
	A[w] = B[z];
	CHECK( A[w] == 4.0f );
	
	A[w] = B[w];
	CHECK( A[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_assignment_Quat_Bracket_uninit, TestConfig::ALL)
{
#if Quat_BracketW_assignment_Quat_Bracket_uninit

	//A[w] = B[x]
	Quat A(1.50f, 2.0f, 3.0f, 4.0f);
	Quat B;

	// Should all assert, next 20 statements
	CHECK(A[x] != B[x]);
	CHECK(A[y] != B[y]);
	CHECK(A[z] != B[z]);
	CHECK(A[w] != B[w]);
	
	CHECK(A[x] != B[x]);	
	CHECK(A[x] != B[y]);
	CHECK(A[x] != B[z]);
	CHECK(A[x] != B[w]);

	CHECK(A[y] != B[x]);	
	CHECK(A[y] != B[y]);
	CHECK(A[y] != B[z]);
	CHECK(A[y] != B[w]);

	CHECK(A[z] != B[x]);	
	CHECK(A[z] != B[y]);
	CHECK(A[z] != B[z]);
	CHECK(A[z] != B[w]);

	CHECK(A[w] != B[x]);	
	CHECK(A[w] != B[y]);
	CHECK(A[w] != B[z]);
	CHECK(A[w] != B[w]);

	CHECK( 1.0f == 1.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Pointers, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Pointers

	//(*pB)[x] = (*pA)[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[x] = (*pA)[x];
	CHECK( B[x] == 2.0f );
	
	(*pB)[x] = (*pA)[y];
	CHECK( B[x] == 3.0f );
	
	(*pB)[x] = (*pA)[z];
	CHECK( B[x] == 4.0f );
	
	(*pB)[x] = (*pA)[w];
	CHECK( B[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_Assignment_Pointers, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Pointers

	//(*pB)[y] = (*pA)[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[y] = (*pA)[x];
	CHECK( B[y] == 2.0f );
	
	(*pB)[y] = (*pA)[y];
	CHECK( B[y] == 3.0f );
	
	(*pB)[y] = (*pA)[z];
	CHECK( B[y] == 4.0f );
	
	(*pB)[y] = (*pA)[w];
	CHECK( B[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Pointers, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Pointers

	//(*pB)[z] = (*pA)[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[z] = (*pA)[x];
	CHECK( B[z] == 2.0f );
	
	(*pB)[z] = (*pA)[y];
	CHECK( B[z] == 3.0f );
	
	(*pB)[z] = (*pA)[z];
	CHECK( B[z] == 4.0f );
	
	(*pB)[z] = (*pA)[w];
	CHECK( B[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Pointers, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Pointers

	//(*pB)[w] = (*pA)[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[w] = (*pA)[x];
	CHECK( B[w] == 2.0f );
	
	(*pB)[w] = (*pA)[y];
	CHECK( B[w] == 3.0f );
	
	(*pB)[w] = (*pA)[z];
	CHECK( B[w] == 4.0f );
	
	(*pB)[w] = (*pA)[w];
	CHECK( B[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Pointers_Const, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Pointers_Const

	//(*pB)[x] = (*pA)[x]
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	const Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[x] = (*pA)[x];
	CHECK( B[x] == 2.0f );
	
	(*pB)[x] = (*pA)[y];
	CHECK( B[x] == 3.0f );
	
	(*pB)[x] = (*pA)[z];
	CHECK( B[x] == 4.0f );
	
	(*pB)[x] = (*pA)[w];
	CHECK( B[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_Assignment_Pointers_Const, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Pointers_Const

	//(*pB)[y] = (*pA)[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	const Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[y] = (*pA)[x];
	CHECK( B[y] == 2.0f );
	
	(*pB)[y] = (*pA)[y];
	CHECK( B[y] == 3.0f );
	
	(*pB)[y] = (*pA)[z];
	CHECK( B[y] == 4.0f );
	
	(*pB)[y] = (*pA)[w];
	CHECK( B[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Pointers_Const, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Pointers_Const

	//(*pB)[z] = (*pA)[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	const Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[z] = (*pA)[x];
	CHECK( B[z] == 2.0f );
	
	(*pB)[z] = (*pA)[y];
	CHECK( B[z] == 3.0f );
	
	(*pB)[z] = (*pA)[z];
	CHECK( B[z] == 4.0f );
	
	(*pB)[z] = (*pA)[w];
	CHECK( B[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Pointers_Const, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Pointers_Const

	//(*pB)[w] = (*pA)[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	const Quat *pA = &A;
	Quat *pB = &B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	(*pB)[w] = (*pA)[x];
	CHECK( B[w] == 2.0f );
	
	(*pB)[w] = (*pA)[y];
	CHECK( B[w] == 3.0f );
	
	(*pB)[w] = (*pA)[z];
	CHECK( B[w] == 4.0f );
	
	(*pB)[w] = (*pA)[w];
	CHECK( B[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketOperator_plus, TestConfig::ALL)
{
#if Quat_BracketOperator_plus

	//y = +A[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	float yy;
	
	yy = +A[x];
	CHECK( yy == 2.0f );
	
	yy = +A[y];
	CHECK( yy == 3.0f );
	
	yy = +A[z];
	CHECK( yy == 4.0f );
	
	yy = +A[w];
	CHECK( yy == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketOperator_plus_const, TestConfig::ALL)
{
#if Quat_BracketOperator_plus_const

	//y = +A[x]
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	float yy;
	
	yy = +A[x];
	CHECK( yy == 2.0f );
	
	yy = +A[y];
	CHECK( yy == 3.0f );
	
	yy = +A[z];
	CHECK( yy == 4.0f );
	
	yy = +A[w];
	CHECK( yy == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketOperator_minus_const, TestConfig::ALL)
{
#if Quat_BracketOperator_minus_const

	//y = -A[x]
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	float yy;
	
	yy = -A[x];
	CHECK( yy == -2.0f );
	
	yy = -A[y];
	CHECK( yy == -3.0f );
	
	yy = -A[z];
	CHECK( yy == -4.0f );
	
	yy = -A[w];
	CHECK( yy == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketOperator_minus, TestConfig::ALL)
{
#if Quat_BracketOperator_minus

	//y = -A[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	float yy;
	
	yy = -A[x];
	CHECK( yy == -2.0f );
	
	yy = -A[y];
	CHECK( yy == -3.0f );
	
	yy = -A[z];
	CHECK( yy == -4.0f );
	
	yy = -A[w];
	CHECK( yy == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Operator_plus_Const, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Operator_plus_Const

	// B[x] = +A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[x] = +A[x];
	CHECK( B[x] == 2.0f );
	
	B[x] = +A[y];
	CHECK( B[x] == 3.0f );
	
	B[x] = +A[z];
	CHECK( B[x] == 4.0f );
	
	B[x] = +A[w];
	CHECK( B[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_Assignment_Operator_plus_Const, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Operator_plus_Const

	//B[y] = +A[x]
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[y] = +A[x];
	CHECK( B[y] == 2.0f );
	
	B[y] = +A[y];
	CHECK( B[y] == 3.0f );
	
	B[y] = +A[z];
	CHECK( B[y] == 4.0f );
	
	B[y] = +A[w];
	CHECK( B[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Operator_plus_Const, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Operator_plus_Const

	//B[z] = +A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[z] = +A[x];
	CHECK( B[z] == 2.0f );
	
	B[z] = +A[y];
	CHECK( B[z] == 3.0f );
	
	B[z] = +A[z];
	CHECK( B[z] == 4.0f );
	
	B[z] = +A[w];
	CHECK( B[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Operator_plus_Const, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Operator_plus_Const

	//B[w] = +A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[w] = +A[x];
	CHECK( B[w] == 2.0f );
	
	B[w] = +A[y];
	CHECK( B[w] == 3.0f );
	
	B[w] = +A[z];
	CHECK( B[w] == 4.0f );
	
	B[w] = +A[w];
	CHECK( B[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Operator_plus, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Operator_plus

	//B[x] = +A[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[x] = +A[x];
	CHECK( B[x] == 2.0f );
	
	B[x] = +A[y];
	CHECK( B[x] == 3.0f );
	
	B[x] = +A[z];
	CHECK( B[x] == 4.0f );
	
	B[x] = +A[w];
	CHECK( B[x] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_Assignment_Operator_plus, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Operator_plus

	//B[y] = +A[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[y] = +A[x];
	CHECK( B[y] == 2.0f );
	
	B[y] = +A[y];
	CHECK( B[y] == 3.0f );
	
	B[y] = +A[z];
	CHECK( B[y] == 4.0f );
	
	B[y] = +A[w];
	CHECK( B[y] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Operator_plus, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Operator_plus

	//B[z] = +A[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[z] = +A[x];
	CHECK( B[z] == 2.0f );
	
	B[z] = +A[y];
	CHECK( B[z] == 3.0f );
	
	B[z] = +A[z];
	CHECK( B[z] == 4.0f );
	
	B[z] = +A[w];
	CHECK( B[z] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Operator_plus, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Operator_plus

	//B[w] = +A[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[w] = +A[x];
	CHECK( B[w] == 2.0f );
	
	B[w] = +A[y];
	CHECK( B[w] == 3.0f );
	
	B[w] = +A[z];
	CHECK( B[w] == 4.0f );
	
	B[w] = +A[w];
	CHECK( B[w] == 5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Operator_Minus_Const, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Operator_Minus_Const

	//B[x] = -A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[x] = -A[x];
	CHECK( B[x] == -2.0f );
	
	B[x] = -A[y];
	CHECK( B[x] == -3.0f );
	
	B[x] = -A[z];
	CHECK( B[x] == -4.0f );
	
	B[x] = -A[w];
	CHECK( B[x] == -5.0f );

#endif
} TEST_END



TEST(Quat_BracketY_Assignment_Operator_Minus_Const, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Operator_Minus_Const

	//B[y] = -A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[y] = -A[x];
	CHECK( B[y] == -2.0f );
	
	B[y] = -A[y];
	CHECK( B[y] == -3.0f );
	
	B[y] = -A[z];
	CHECK( B[y] == -4.0f );
	
	B[y] = -A[w];
	CHECK( B[y] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Operator_Minus_Const, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Operator_Minus_Const

	//B[z] = -A[x]
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[z] = -A[x];
	CHECK( B[z] == -2.0f );
	
	B[z] = -A[y];
	CHECK( B[z] == -3.0f );
	
	B[z] = -A[z];
	CHECK( B[z] == -4.0f );
	
	B[z] = -A[w];
	CHECK( B[z] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Operator_Minus_Const, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Operator_Minus_Const

	//B[w] = -A[x];
	const Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[w] = -A[x];
	CHECK( B[w] == -2.0f );
	
	B[w] = -A[y];
	CHECK( B[w] == -3.0f );
	
	B[w] = -A[z];
	CHECK( B[w] == -4.0f );
	
	B[w] = -A[w];
	CHECK( B[w] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Assignment_Operator_Minus, TestConfig::ALL)
{
#if Quat_BracketX_Assignment_Operator_Minus

	//B[x] = -A[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[x] = -A[x];
	CHECK( B[x] == -2.0f );
	
	B[x] = -A[y];
	CHECK( B[x] == -3.0f );
	
	B[x] = -A[z];
	CHECK( B[x] == -4.0f );
	
	B[x] = -A[w];
	CHECK( B[x] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketY_Assignment_Operator_Minus, TestConfig::ALL)
{
#if Quat_BracketY_Assignment_Operator_Minus

	//B[y] = -A[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[y] = -A[x];
	CHECK( B[y] == -2.0f );
	
	B[y] = -A[y];
	CHECK( B[y] == -3.0f );
	
	B[y] = -A[z];
	CHECK( B[y] == -4.0f );
	
	B[y] = -A[w];
	CHECK( B[y] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketZ_Assignment_Operator_Minus, TestConfig::ALL)
{
#if Quat_BracketZ_Assignment_Operator_Minus

	//B[z] = -A[x]
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[z] = -A[x];
	CHECK( B[z] == -2.0f );
	
	B[z] = -A[y];
	CHECK( B[z] == -3.0f );
	
	B[z] = -A[z];
	CHECK( B[z] == -4.0f );
	
	B[z] = -A[w];
	CHECK( B[z] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketW_Assignment_Operator_Minus, TestConfig::ALL)
{
#if Quat_BracketW_Assignment_Operator_Minus

	//B[w] = -A[x];
	Quat A(2.0f, 3.0f, 4.0f, 5.0f);
	Quat B;
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 4.0f );
	CHECK( A[w] == 5.0f );
	
	B[w] = -A[x];
	CHECK( B[w] == -2.0f );
	
	B[w] = -A[y];
	CHECK( B[w] == -3.0f );
	
	B[w] = -A[z];
	CHECK( B[w] == -4.0f );
	
	B[w] = -A[w];
	CHECK( B[w] == -5.0f );

#endif
} TEST_END



TEST( Quat_BracketX_Equal_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_Equal_Operator_true

	//B[w] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] == B[x] );
	CHECK( status == true );
	status = ( A[x] == B[y] );
	CHECK( status == true );
	status = ( A[x] == B[z] );
	CHECK( status == true );
	status = ( A[x] == B[w] );
	CHECK( status == true );
	
	status = ( A[x] == cB[x] );
	CHECK( status == true );
	status = ( A[x] == cB[y] );
	CHECK( status == true );
	status = ( A[x] == cB[z] );
	CHECK( status == true );
	status = ( A[x] == cB[w] );
	CHECK( status == true );
	
	status = ( cA[x] == B[x] );
	CHECK( status == true );
	status = ( cA[x] == B[y] );
	CHECK( status == true );
	status = ( cA[x] == B[z] );
	CHECK( status == true );
	status = ( cA[x] == B[w] );
	CHECK( status == true );
	
	status = ( cA[x] == cB[x] );
	CHECK( status == true );
	status = ( cA[x] == cB[y] );
	CHECK( status == true );
	status = ( cA[x] == cB[z] );
	CHECK( status == true );
	status = ( cA[x] == cB[w] );
	CHECK( status == true );
	
#endif
} TEST_END



TEST( Quat_BracketX_Equal_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_Equal_Operator_false

	//B[w] == C[x]
	
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	bool status;
	
	status = ( A[x] == C[x] );
	CHECK( status == false );
	status = ( A[x] == C[y] );
	CHECK( status == false );
	status = ( A[x] == C[z] );
	CHECK( status == false );
	status = ( A[x] == C[w] );
	CHECK( status == false );
	
	status = ( cA[x] == C[x] );
	CHECK( status == false );
	status = ( cA[x] == C[y] );
	CHECK( status == false );
	status = ( cA[x] == C[z] );
	CHECK( status == false );
	status = ( cA[x] == C[w] );
	CHECK( status == false );
	
	status = ( A[x] == cC[x] );
	CHECK( status == false );
	status = ( A[x] == cC[y] );
	CHECK( status == false );
	status = ( A[x] == cC[z] );
	CHECK( status == false );
	status = ( A[x] == cC[w] );
	CHECK( status == false );
	
	status = ( cA[x] == cC[x] );
	CHECK( status == false );
	status = ( cA[x] == cC[y] );
	CHECK( status == false );
	status = ( cA[x] == cC[z] );
	CHECK( status == false );
	status = ( cA[x] == cC[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_Equal_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_Equal_Operator_true

	//B[y] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] == B[x] );
	CHECK( status == true );
	status = ( A[y] == B[y] );
	CHECK( status == true );
	status = ( A[y] == B[z] );
	CHECK( status == true );
	status = ( A[y] == B[w] );
	CHECK( status == true );
	
	status = ( A[y] == cB[x] );
	CHECK( status == true );
	status = ( A[y] == cB[y] );
	CHECK( status == true );
	status = ( A[y] == cB[z] );
	CHECK( status == true );
	status = ( A[y] == cB[w] );
	CHECK( status == true );
	
	status = ( cA[y] == B[x] );
	CHECK( status == true );
	status = ( cA[y] == B[y] );
	CHECK( status == true );
	status = ( cA[y] == B[z] );
	CHECK( status == true );
	status = ( cA[y] == B[w] );
	CHECK( status == true );
	
	status = ( cA[y] == cB[x] );
	CHECK( status == true );
	status = ( cA[y] == cB[y] );
	CHECK( status == true );
	status = ( cA[y] == cB[z] );
	CHECK( status == true );
	status = ( cA[y] == cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_Equal_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_Equal_Operator_false

	//B[y] == C[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] == C[x] );
	CHECK( status == false );
	status = ( A[y] == C[y] );
	CHECK( status == false );
	status = ( A[y] == C[z] );
	CHECK( status == false );
	status = ( A[y] == C[w] );
	CHECK( status == false );
	
	status = ( cA[y] == C[x] );
	CHECK( status == false );
	status = ( cA[y] == C[y] );
	CHECK( status == false );
	status = ( cA[y] == C[z] );
	CHECK( status == false );
	status = ( cA[y] == C[w] );
	CHECK( status == false );
	
	status = ( A[y] == cC[x] );
	CHECK( status == false );
	status = ( A[y] == cC[y] );
	CHECK( status == false );
	status = ( A[y] == cC[z] );
	CHECK( status == false );
	status = ( A[y] == cC[w] );
	CHECK( status == false );
	
	status = ( cA[y] == cC[x] );
	CHECK( status == false );
	status = ( cA[y] == cC[y] );
	CHECK( status == false );
	status = ( cA[y] == cC[z] );
	CHECK( status == false );
	status = ( cA[y] == cC[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_Equal_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_Equal_Operator_true

	//B[z] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] == B[x] );
	CHECK( status == true );
	status = ( A[z] == B[y] );
	CHECK( status == true );
	status = ( A[z] == B[z] );
	CHECK( status == true );
	status = ( A[z] == B[w] );
	CHECK( status == true );
	
	status = ( A[z] == cB[x] );
	CHECK( status == true );
	status = ( A[z] == cB[y] );
	CHECK( status == true );
	status = ( A[z] == cB[z] );
	CHECK( status == true );
	status = ( A[z] == cB[w] );
	CHECK( status == true );
	
	status = ( cA[z] == B[x] );
	CHECK( status == true );
	status = ( cA[z] == B[y] );
	CHECK( status == true );
	status = ( cA[z] == B[z] );
	CHECK( status == true );
	status = ( cA[z] == B[w] );
	CHECK( status == true );
	
	status = ( cA[z] == cB[x] );
	CHECK( status == true );
	status = ( cA[z] == cB[y] );
	CHECK( status == true );
	status = ( cA[z] == cB[z] );
	CHECK( status == true );
	status = ( cA[z] == cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_Equal_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_Equal_Operator_false

	//B[z] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[z] == C[x] );
	CHECK( status == false );
	status = ( A[z] == C[y] );
	CHECK( status == false );
	status = ( A[z] == C[z] );
	CHECK( status == false );
	status = ( A[z] == C[w] );
	CHECK( status == false );
	
	status = ( cA[z] == C[x] );
	CHECK( status == false );
	status = ( cA[z] == C[y] );
	CHECK( status == false );
	status = ( cA[z] == C[z] );
	CHECK( status == false );
	status = ( cA[z] == C[w] );
	CHECK( status == false );
	
	status = ( A[z] == cC[x] );
	CHECK( status == false );
	status = ( A[z] == cC[y] );
	CHECK( status == false );
	status = ( A[z] == cC[z] );
	CHECK( status == false );
	status = ( A[z] == cC[w] );
	CHECK( status == false );
	
	status = ( cA[z] == cC[x] );
	CHECK( status == false );
	status = ( cA[z] == cC[y] );
	CHECK( status == false );
	status = ( cA[z] == cC[z] );
	CHECK( status == false );
	status = ( cA[z] == cC[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_Equal_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_Equal_Operator_true

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] == B[x] );
	CHECK( status == true );
	status = ( A[w] == B[y] );
	CHECK( status == true );
	status = ( A[w] == B[z] );
	CHECK( status == true );
	status = ( A[w] == B[w] );
	CHECK( status == true );
	
	status = ( A[w] == cB[x] );
	CHECK( status == true );
	status = ( A[w] == cB[y] );
	CHECK( status == true );
	status = ( A[w] == cB[z] );
	CHECK( status == true );
	status = ( A[w] == cB[w] );
	CHECK( status == true );
	
	status = ( cA[w] == B[x] );
	CHECK( status == true );
	status = ( cA[w] == B[y] );
	CHECK( status == true );
	status = ( cA[w] == B[z] );
	CHECK( status == true );
	status = ( cA[w] == B[w] );
	CHECK( status == true );
	
	status = ( cA[w] == cB[x] );
	CHECK( status == true );
	status = ( cA[w] == cB[y] );
	CHECK( status == true );
	status = ( cA[w] == cB[z] );
	CHECK( status == true );
	status = ( cA[w] == cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_Equal_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_Equal_Operator_false

	//B[w] == C[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[w] == C[x] );
	CHECK( status == false );
	status = ( A[w] == C[y] );
	CHECK( status == false );
	status = ( A[w] == C[z] );
	CHECK( status == false );
	status = ( A[w] == C[w] );
	CHECK( status == false );
	
	status = ( cA[w] == C[x] );
	CHECK( status == false );
	status = ( cA[w] == C[y] );
	CHECK( status == false );
	status = ( cA[w] == C[z] );
	CHECK( status == false );
	status = ( cA[w] == C[w] );
	CHECK( status == false );
	
	status = ( A[w] == cC[x] );
	CHECK( status == false );
	status = ( A[w] == cC[y] );
	CHECK( status == false );
	status = ( A[w] == cC[z] );
	CHECK( status == false );
	status = ( A[w] == cC[w] );
	CHECK( status == false );
	
	status = ( cA[w] == cC[x] );
	CHECK( status == false );
	status = ( cA[w] == cC[y] );
	CHECK( status == false );
	status = ( cA[w] == cC[z] );
	CHECK( status == false );
	status = ( cA[w] == cC[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketX_notEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_notEqual_Operator_false

	//B[w] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] != B[x] );
	CHECK( status == false );
	status = ( A[x] != B[y] );
	CHECK( status == false );
	status = ( A[x] != B[z] );
	CHECK( status == false );
	status = ( A[x] != B[w] );
	CHECK( status == false );
	
	status = ( A[x] != cB[x] );
	CHECK( status == false );
	status = ( A[x] != cB[y] );
	CHECK( status == false );
	status = ( A[x] != cB[z] );
	CHECK( status == false );
	status = ( A[x] != cB[w] );
	CHECK( status == false );
	
	status = ( cA[x] != B[x] );
	CHECK( status == false );
	status = ( cA[x] != B[y] );
	CHECK( status == false );
	status = ( cA[x] != B[z] );
	CHECK( status == false );
	status = ( cA[x] != B[w] );
	CHECK( status == false );
	
	status = ( cA[x] != cB[x] );
	CHECK( status == false );
	status = ( cA[x] != cB[y] );
	CHECK( status == false );
	status = ( cA[x] != cB[z] );
	CHECK( status == false );
	status = ( cA[x] != cB[w] );
	CHECK( status == false );

#endif	
} TEST_END



TEST( Quat_BracketX_notEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_notEqual_Operator_true

	//B[w] == C[x]
	
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	bool status;
	
	status = ( A[x] != C[x] );
	CHECK( status == true );
	status = ( A[x] != C[y] );
	CHECK( status == true );
	status = ( A[x] != C[z] );
	CHECK( status == true );
	status = ( A[x] != C[w] );
	CHECK( status == true );
	
	status = ( cA[x] != C[x] );
	CHECK( status == true );
	status = ( cA[x] != C[y] );
	CHECK( status == true );
	status = ( cA[x] != C[z] );
	CHECK( status == true );
	status = ( cA[x] != C[w] );
	CHECK( status == true );
	
	status = ( A[x] != cC[x] );
	CHECK( status == true );
	status = ( A[x] != cC[y] );
	CHECK( status == true );
	status = ( A[x] != cC[z] );
	CHECK( status == true );
	status = ( A[x] != cC[w] );
	CHECK( status == true );
	
	status = ( cA[x] != cC[x] );
	CHECK( status == true );
	status = ( cA[x] != cC[y] );
	CHECK( status == true );
	status = ( cA[x] != cC[z] );
	CHECK( status == true );
	status = ( cA[x] != cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_notEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_notEqual_Operator_false

	//B[y] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] != B[x] );
	CHECK( status == false );
	status = ( A[y] != B[y] );
	CHECK( status == false );
	status = ( A[y] != B[z] );
	CHECK( status == false );
	status = ( A[y] != B[w] );
	CHECK( status == false );
	
	status = ( A[y] != cB[x] );
	CHECK( status == false );
	status = ( A[y] != cB[y] );
	CHECK( status == false );
	status = ( A[y] != cB[z] );
	CHECK( status == false );
	status = ( A[y] != cB[w] );
	CHECK( status == false );
	
	status = ( cA[y] != B[x] );
	CHECK( status == false );
	status = ( cA[y] != B[y] );
	CHECK( status == false );
	status = ( cA[y] != B[z] );
	CHECK( status == false );
	status = ( cA[y] != B[w] );
	CHECK( status == false );
	
	status = ( cA[y] != cB[x] );
	CHECK( status == false );
	status = ( cA[y] != cB[y] );
	CHECK( status == false );
	status = ( cA[y] != cB[z] );
	CHECK( status == false );
	status = ( cA[y] != cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_notEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_notEqual_Operator_true

	//B[y] == C[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] != C[x] );
	CHECK( status == true );
	status = ( A[y] != C[y] );
	CHECK( status == true );
	status = ( A[y] != C[z] );
	CHECK( status == true );
	status = ( A[y] != C[w] );
	CHECK( status == true );
	
	status = ( cA[y] != C[x] );
	CHECK( status == true );
	status = ( cA[y] != C[y] );
	CHECK( status == true );
	status = ( cA[y] != C[z] );
	CHECK( status == true );
	status = ( cA[y] != C[w] );
	CHECK( status == true );
	
	status = ( A[y] != cC[x] );
	CHECK( status == true );
	status = ( A[y] != cC[y] );
	CHECK( status == true );
	status = ( A[y] != cC[z] );
	CHECK( status == true );
	status = ( A[y] != cC[w] );
	CHECK( status == true );
	
	status = ( cA[y] != cC[x] );
	CHECK( status == true );
	status = ( cA[y] != cC[y] );
	CHECK( status == true );
	status = ( cA[y] != cC[z] );
	CHECK( status == true );
	status = ( cA[y] != cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_notEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_notEqual_Operator_false

	//B[z] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] != B[x] );
	CHECK( status == false );
	status = ( A[z] != B[y] );
	CHECK( status == false );
	status = ( A[z] != B[z] );
	CHECK( status == false );
	status = ( A[z] != B[w] );
	CHECK( status == false );
	
	status = ( A[z] != cB[x] );
	CHECK( status == false );
	status = ( A[z] != cB[y] );
	CHECK( status == false );
	status = ( A[z] != cB[z] );
	CHECK( status == false );
	status = ( A[z] != cB[w] );
	CHECK( status == false );
	
	status = ( cA[z] != B[x] );
	CHECK( status == false );
	status = ( cA[z] != B[y] );
	CHECK( status == false );
	status = ( cA[z] != B[z] );
	CHECK( status == false );
	status = ( cA[z] != B[w] );
	CHECK( status == false );
	
	status = ( cA[z] != cB[x] );
	CHECK( status == false );
	status = ( cA[z] != cB[y] );
	CHECK( status == false );
	status = ( cA[z] != cB[z] );
	CHECK( status == false );
	status = ( cA[z] != cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_notEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_notEqual_Operator_true

	//B[z] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[z] != C[x] );
	CHECK( status == true );
	status = ( A[z] != C[y] );
	CHECK( status == true );
	status = ( A[z] != C[z] );
	CHECK( status == true );
	status = ( A[z] != C[w] );
	CHECK( status == true );
	
	status = ( cA[z] != C[x] );
	CHECK( status == true );
	status = ( cA[z] != C[y] );
	CHECK( status == true );
	status = ( cA[z] != C[z] );
	CHECK( status == true );
	status = ( cA[z] != C[w] );
	CHECK( status == true );
	
	status = ( A[z] != cC[x] );
	CHECK( status == true );
	status = ( A[z] != cC[y] );
	CHECK( status == true );
	status = ( A[z] != cC[z] );
	CHECK( status == true );
	status = ( A[z] != cC[w] );
	CHECK( status == true );
	
	status = ( cA[z] != cC[x] );
	CHECK( status == true );
	status = ( cA[z] != cC[y] );
	CHECK( status == true );
	status = ( cA[z] != cC[z] );
	CHECK( status == true );
	status = ( cA[z] != cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_notEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_notEqual_Operator_false

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] != B[x] );
	CHECK( status == false );
	status = ( A[w] != B[y] );
	CHECK( status == false );
	status = ( A[w] != B[z] );
	CHECK( status == false );
	status = ( A[w] != B[w] );
	CHECK( status == false );
	
	status = ( A[w] != cB[x] );
	CHECK( status == false );
	status = ( A[w] != cB[y] );
	CHECK( status == false );
	status = ( A[w] != cB[z] );
	CHECK( status == false );
	status = ( A[w] != cB[w] );
	CHECK( status == false );
	
	status = ( cA[w] != B[x] );
	CHECK( status == false );
	status = ( cA[w] != B[y] );
	CHECK( status == false );
	status = ( cA[w] != B[z] );
	CHECK( status == false );
	status = ( cA[w] != B[w] );
	CHECK( status == false );
	
	status = ( cA[w] != cB[x] );
	CHECK( status == false );
	status = ( cA[w] != cB[y] );
	CHECK( status == false );
	status = ( cA[w] != cB[z] );
	CHECK( status == false );
	status = ( cA[w] != cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_notEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_notEqual_Operator_true

	//B[w] == C[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[w] != C[x] );
	CHECK( status == true );
	status = ( A[w] != C[y] );
	CHECK( status == true );
	status = ( A[w] != C[z] );
	CHECK( status == true );
	status = ( A[w] != C[w] );
	CHECK( status == true );
	
	status = ( cA[w] != C[x] );
	CHECK( status == true );
	status = ( cA[w] != C[y] );
	CHECK( status == true );
	status = ( cA[w] != C[z] );
	CHECK( status == true );
	status = ( cA[w] != C[w] );
	CHECK( status == true );
	
	status = ( A[w] != cC[x] );
	CHECK( status == true );
	status = ( A[w] != cC[y] );
	CHECK( status == true );
	status = ( A[w] != cC[z] );
	CHECK( status == true );
	status = ( A[w] != cC[w] );
	CHECK( status == true );
	
	status = ( cA[w] != cC[x] );
	CHECK( status == true );
	status = ( cA[w] != cC[y] );
	CHECK( status == true );
	status = ( cA[w] != cC[z] );
	CHECK( status == true );
	status = ( cA[w] != cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketX_LessThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_LessThan_Operator_false

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] < B[x] );
	CHECK( status == false );
	status = ( A[x] < B[y] );
	CHECK( status == false );
	status = ( A[x] < B[z] );
	CHECK( status == false );
	status = ( A[x] < B[w] );
	CHECK( status == false );
	
	status = ( A[x] < cB[x] );
	CHECK( status == false );
	status = ( A[x] < cB[y] );
	CHECK( status == false );
	status = ( A[x] < cB[z] );
	CHECK( status == false );
	status = ( A[x] < cB[w] );
	CHECK( status == false );
	
	status = ( cA[x] < B[x] );
	CHECK( status == false );
	status = ( cA[x] < B[y] );
	CHECK( status == false );
	status = ( cA[x] < B[z] );
	CHECK( status == false );
	status = ( cA[x] < B[w] );
	CHECK( status == false );
	
	status = ( cA[x] < cB[x] );
	CHECK( status == false );
	status = ( cA[x] < cB[y] );
	CHECK( status == false );
	status = ( cA[x] < cB[z] );
	CHECK( status == false );
	status = ( cA[x] < cB[w] );
	CHECK( status == false );
	
#endif
} TEST_END



TEST( Quat_BracketX_LessThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_LessThan_Operator_true

	//B[w] == C[x];
	
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	bool status;
	
	status = ( A[x] < C[x] );
	CHECK( status == true );
	status = ( A[x] < C[y] );
	CHECK( status == true );
	status = ( A[x] < C[z] );
	CHECK( status == true );
	status = ( A[x] < C[w] );
	CHECK( status == true );
	
	status = ( cA[x] < C[x] );
	CHECK( status == true );
	status = ( cA[x] < C[y] );
	CHECK( status == true );
	status = ( cA[x] < C[z] );
	CHECK( status == true );
	status = ( cA[x] < C[w] );
	CHECK( status == true );
	
	status = ( A[x] < cC[x] );
	CHECK( status == true );
	status = ( A[x] < cC[y] );
	CHECK( status == true );
	status = ( A[x] < cC[z] );
	CHECK( status == true );
	status = ( A[x] < cC[w] );
	CHECK( status == true );
	
	status = ( cA[x] < cC[x] );
	CHECK( status == true );
	status = ( cA[x] < cC[y] );
	CHECK( status == true );
	status = ( cA[x] < cC[z] );
	CHECK( status == true );
	status = ( cA[x] < cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_LessThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_LessThan_Operator_false

	//B[y] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] < B[x] );
	CHECK( status == false );
	status = ( A[y] < B[y] );
	CHECK( status == false );
	status = ( A[y] < B[z] );
	CHECK( status == false );
	status = ( A[y] < B[w] );
	CHECK( status == false );
	
	status = ( A[y] < cB[x] );
	CHECK( status == false );
	status = ( A[y] < cB[y] );
	CHECK( status == false );
	status = ( A[y] < cB[z] );
	CHECK( status == false );
	status = ( A[y] < cB[w] );
	CHECK( status == false );
	
	status = ( cA[y] < B[x] );
	CHECK( status == false );
	status = ( cA[y] < B[y] );
	CHECK( status == false );
	status = ( cA[y] < B[z] );
	CHECK( status == false );
	status = ( cA[y] < B[w] );
	CHECK( status == false );
	
	status = ( cA[y] < cB[x] );
	CHECK( status == false );
	status = ( cA[y] < cB[y] );
	CHECK( status == false );
	status = ( cA[y] < cB[z] );
	CHECK( status == false );
	status = ( cA[y] < cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_LessThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_LessThan_Operator_true

	//B[y] == C[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] < C[x] );
	CHECK( status == true );
	status = ( A[y] < C[y] );
	CHECK( status == true );
	status = ( A[y] < C[z] );
	CHECK( status == true );
	status = ( A[y] < C[w] );
	CHECK( status == true );
	
	status = ( cA[y] < C[x] );
	CHECK( status == true );
	status = ( cA[y] < C[y] );
	CHECK( status == true );
	status = ( cA[y] < C[z] );
	CHECK( status == true );
	status = ( cA[y] < C[w] );
	CHECK( status == true );
	
	status = ( A[y] < cC[x] );
	CHECK( status == true );
	status = ( A[y] < cC[y] );
	CHECK( status == true );
	status = ( A[y] < cC[z] );
	CHECK( status == true );
	status = ( A[y] < cC[w] );
	CHECK( status == true );
	
	status = ( cA[y] < cC[x] );
	CHECK( status == true );
	status = ( cA[y] < cC[y] );
	CHECK( status == true );
	status = ( cA[y] < cC[z] );
	CHECK( status == true );
	status = ( cA[y] < cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_LessThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_LessThan_Operator_false

	//B[z] == A[x];
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] < B[x] );
	CHECK( status == false );
	status = ( A[z] < B[y] );
	CHECK( status == false );
	status = ( A[z] < B[z] );
	CHECK( status == false );
	status = ( A[z] < B[w] );
	CHECK( status == false );
	
	status = ( A[z] < cB[x] );
	CHECK( status == false );
	status = ( A[z] < cB[y] );
	CHECK( status == false );
	status = ( A[z] < cB[z] );
	CHECK( status == false );
	status = ( A[z] < cB[w] );
	CHECK( status == false );
	
	status = ( cA[z] < B[x] );
	CHECK( status == false );
	status = ( cA[z] < B[y] );
	CHECK( status == false );
	status = ( cA[z] < B[z] );
	CHECK( status == false );
	status = ( cA[z] < B[w] );
	CHECK( status == false );
	
	status = ( cA[z] < cB[x] );
	CHECK( status == false );
	status = ( cA[z] < cB[y] );
	CHECK( status == false );
	status = ( cA[z] < cB[z] );
	CHECK( status == false );
	status = ( cA[z] < cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_LessThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_LessThan_Operator_true

	//B[z] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[z] < C[x] );
	CHECK( status == true );
	status = ( A[z] < C[y] );
	CHECK( status == true );
	status = ( A[z] < C[z] );
	CHECK( status == true );
	status = ( A[z] < C[w] );
	CHECK( status == true );
	
	status = ( cA[z] < C[x] );
	CHECK( status == true );
	status = ( cA[z] < C[y] );
	CHECK( status == true );
	status = ( cA[z] < C[z] );
	CHECK( status == true );
	status = ( cA[z] < C[w] );
	CHECK( status == true );
	
	status = ( A[z] < cC[x] );
	CHECK( status == true );
	status = ( A[z] < cC[y] );
	CHECK( status == true );
	status = ( A[z] < cC[z] );
	CHECK( status == true );
	status = ( A[z] < cC[w] );
	CHECK( status == true );
	
	status = ( cA[z] < cC[x] );
	CHECK( status == true );
	status = ( cA[z] < cC[y] );
	CHECK( status == true );
	status = ( cA[z] < cC[z] );
	CHECK( status == true );
	status = ( cA[z] < cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_LessThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_LessThan_Operator_false

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] < B[x] );
	CHECK( status == false );
	status = ( A[w] < B[y] );
	CHECK( status == false );
	status = ( A[w] < B[z] );
	CHECK( status == false );
	status = ( A[w] < B[w] );
	CHECK( status == false );
	
	status = ( A[w] < cB[x] );
	CHECK( status == false );
	status = ( A[w] < cB[y] );
	CHECK( status == false );
	status = ( A[w] < cB[z] );
	CHECK( status == false );
	status = ( A[w] < cB[w] );
	CHECK( status == false );
	
	status = ( cA[w] < B[x] );
	CHECK( status == false );
	status = ( cA[w] < B[y] );
	CHECK( status == false );
	status = ( cA[w] < B[z] );
	CHECK( status == false );
	status = ( cA[w] < B[w] );
	CHECK( status == false );
	
	status = ( cA[w] < cB[x] );
	CHECK( status == false );
	status = ( cA[w] < cB[y] );
	CHECK( status == false );
	status = ( cA[w] < cB[z] );
	CHECK( status == false );
	status = ( cA[w] < cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_LessThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_LessThan_Operator_true

	//B[w] == C[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[w] < C[x] );
	CHECK( status == true );
	status = ( A[w] < C[y] );
	CHECK( status == true );
	status = ( A[w] < C[z] );
	CHECK( status == true );
	status = ( A[w] < C[w] );
	CHECK( status == true );
	
	status = ( cA[w] < C[x] );
	CHECK( status == true );
	status = ( cA[w] < C[y] );
	CHECK( status == true );
	status = ( cA[w] < C[z] );
	CHECK( status == true );
	status = ( cA[w] < C[w] );
	CHECK( status == true );
	
	status = ( A[w] < cC[x] );
	CHECK( status == true );
	status = ( A[w] < cC[y] );
	CHECK( status == true );
	status = ( A[w] < cC[z] );
	CHECK( status == true );
	status = ( A[w] < cC[w] );
	CHECK( status == true );
	
	status = ( cA[w] < cC[x] );
	CHECK( status == true );
	status = ( cA[w] < cC[y] );
	CHECK( status == true );
	status = ( cA[w] < cC[z] );
	CHECK( status == true );
	status = ( cA[w] < cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketX_LessThanEqual_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketX_LessThanEqual_Operator_true_eq

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] <= B[x] );
	CHECK( status == true );
	status = ( A[x] <= B[y] );
	CHECK( status == true );
	status = ( A[x] <= B[z] );
	CHECK( status == true );
	status = ( A[x] <= B[w] );
	CHECK( status == true );
	
	status = ( A[x] <= cB[x] );
	CHECK( status == true );
	status = ( A[x] <= cB[y] );
	CHECK( status == true );
	status = ( A[x] <= cB[z] );
	CHECK( status == true );
	status = ( A[x] <= cB[w] );
	CHECK( status == true );
	
	status = ( cA[x] <= B[x] );
	CHECK( status == true );
	status = ( cA[x] <= B[y] );
	CHECK( status == true );
	status = ( cA[x] <= B[z] );
	CHECK( status == true );
	status = ( cA[x] <= B[w] );
	CHECK( status == true );
	
	status = ( cA[x] <= cB[x] );
	CHECK( status == true );
	status = ( cA[x] <= cB[y] );
	CHECK( status == true );
	status = ( cA[x] <= cB[z] );
	CHECK( status == true );
	status = ( cA[x] <= cB[w] );
	CHECK( status == true );
	
#endif
} TEST_END



TEST( Quat_BracketX_LessThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_LessThanEqual_Operator_false

	//B[w] == A[x]
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 3.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 3.0f );
	CHECK( A[w] == 3.0f );
	
	bool status;
	
	status = ( A[x] <= B[x] );
	CHECK( status == false );
	status = ( A[x] <= B[y] );
	CHECK( status == false );
	status = ( A[x] <= B[z] );
	CHECK( status == false );
	status = ( A[x] <= B[w] );
	CHECK( status == false );
	
	status = ( A[x] <= cB[x] );
	CHECK( status == false );
	status = ( A[x] <= cB[y] );
	CHECK( status == false );
	status = ( A[x] <= cB[z] );
	CHECK( status == false );
	status = ( A[x] <= cB[w] );
	CHECK( status == false );
	
	status = ( cA[x] <= B[x] );
	CHECK( status == false );
	status = ( cA[x] <= B[y] );
	CHECK( status == false );
	status = ( cA[x] <= B[z] );
	CHECK( status == false );
	status = ( cA[x] <= B[w] );
	CHECK( status == false );
	
	status = ( cA[x] <= cB[x] );
	CHECK( status == false );
	status = ( cA[x] <= cB[y] );
	CHECK( status == false );
	status = ( cA[x] <= cB[z] );
	CHECK( status == false );
	status = ( cA[x] <= cB[w] );
	CHECK( status == false );
	
#endif
} TEST_END



TEST( Quat_BracketX_LessThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_LessThanEqual_Operator_true

	//B[w] == C[x]
	
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	bool status;
	
	status = ( A[x] <= C[x] );
	CHECK( status == true );
	status = ( A[x] <= C[y] );
	CHECK( status == true );
	status = ( A[x] <= C[z] );
	CHECK( status == true );
	status = ( A[x] <= C[w] );
	CHECK( status == true );
	
	status = ( cA[x] <= C[x] );
	CHECK( status == true );
	status = ( cA[x] <= C[y] );
	CHECK( status == true );
	status = ( cA[x] <= C[z] );
	CHECK( status == true );
	status = ( cA[x] <= C[w] );
	CHECK( status == true );
	
	status = ( A[x] <= cC[x] );
	CHECK( status == true );
	status = ( A[x] <= cC[y] );
	CHECK( status == true );
	status = ( A[x] <= cC[z] );
	CHECK( status == true );
	status = ( A[x] <= cC[w] );
	CHECK( status == true );
	
	status = ( cA[x] <= cC[x] );
	CHECK( status == true );
	status = ( cA[x] <= cC[y] );
	CHECK( status == true );
	status = ( cA[x] <= cC[z] );
	CHECK( status == true );
	status = ( cA[x] <= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_LessThanEqual_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketY_LessThanEqual_Operator_true_eq

	//B[y] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] <= B[x] );
	CHECK( status == true );
	status = ( A[y] <= B[y] );
	CHECK( status == true );
	status = ( A[y] <= B[z] );
	CHECK( status == true );
	status = ( A[y] <= B[w] );
	CHECK( status == true );
	
	status = ( A[y] <= cB[x] );
	CHECK( status == true );
	status = ( A[y] <= cB[y] );
	CHECK( status == true );
	status = ( A[y] <= cB[z] );
	CHECK( status == true );
	status = ( A[y] <= cB[w] );
	CHECK( status == true );
	
	status = ( cA[y] <= B[x] );
	CHECK( status == true );
	status = ( cA[y] <= B[y] );
	CHECK( status == true );
	status = ( cA[y] <= B[z] );
	CHECK( status == true );
	status = ( cA[y] <= B[w] );
	CHECK( status == true );
	
	status = ( cA[y] <= cB[x] );
	CHECK( status == true );
	status = ( cA[y] <= cB[y] );
	CHECK( status == true );
	status = ( cA[y] <= cB[z] );
	CHECK( status == true );
	status = ( cA[y] <= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_LessThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_LessThanEqual_Operator_false

	//B[y] == A[x];
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 3.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 3.0f );
	CHECK( A[w] == 3.0f );
	
	bool status;
	
	status = ( A[y] <= B[x] );
	CHECK( status == false );
	status = ( A[y] <= B[y] );
	CHECK( status == false );
	status = ( A[y] <= B[z] );
	CHECK( status == false );
	status = ( A[y] <= B[w] );
	CHECK( status == false );
	
	status = ( A[y] <= cB[x] );
	CHECK( status == false );
	status = ( A[y] <= cB[y] );
	CHECK( status == false );
	status = ( A[y] <= cB[z] );
	CHECK( status == false );
	status = ( A[y] <= cB[w] );
	CHECK( status == false );
	
	status = ( cA[y] <= B[x] );
	CHECK( status == false );
	status = ( cA[y] <= B[y] );
	CHECK( status == false );
	status = ( cA[y] <= B[z] );
	CHECK( status == false );
	status = ( cA[y] <= B[w] );
	CHECK( status == false );
	
	status = ( cA[y] <= cB[x] );
	CHECK( status == false );
	status = ( cA[y] <= cB[y] );
	CHECK( status == false );
	status = ( cA[y] <= cB[z] );
	CHECK( status == false );
	status = ( cA[y] <= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_LessThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_LessThanEqual_Operator_true

	//B[y] == C[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] <= C[x] );
	CHECK( status == true );
	status = ( A[y] <= C[y] );
	CHECK( status == true );
	status = ( A[y] <= C[z] );
	CHECK( status == true );
	status = ( A[y] <= C[w] );
	CHECK( status == true );
	
	status = ( cA[y] <= C[x] );
	CHECK( status == true );
	status = ( cA[y] <= C[y] );
	CHECK( status == true );
	status = ( cA[y] <= C[z] );
	CHECK( status == true );
	status = ( cA[y] <= C[w] );
	CHECK( status == true );
	
	status = ( A[y] <= cC[x] );
	CHECK( status == true );
	status = ( A[y] <= cC[y] );
	CHECK( status == true );
	status = ( A[y] <= cC[z] );
	CHECK( status == true );
	status = ( A[y] <= cC[w] );
	CHECK( status == true );
	
	status = ( cA[y] <= cC[x] );
	CHECK( status == true );
	status = ( cA[y] <= cC[y] );
	CHECK( status == true );
	status = ( cA[y] <= cC[z] );
	CHECK( status == true );
	status = ( cA[y] <= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_LessThanEqual_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketZ_LessThanEqual_Operator_true_eq

	//B[z] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] <= B[x] );
	CHECK( status == true );
	status = ( A[z] <= B[y] );
	CHECK( status == true );
	status = ( A[z] <= B[z] );
	CHECK( status == true );
	status = ( A[z] <= B[w] );
	CHECK( status == true );
	
	status = ( A[z] <= cB[x] );
	CHECK( status == true );
	status = ( A[z] <= cB[y] );
	CHECK( status == true );
	status = ( A[z] <= cB[z] );
	CHECK( status == true );
	status = ( A[z] <= cB[w] );
	CHECK( status == true );
	
	status = ( cA[z] <= B[x] );
	CHECK( status == true );
	status = ( cA[z] <= B[y] );
	CHECK( status == true );
	status = ( cA[z] <= B[z] );
	CHECK( status == true );
	status = ( cA[z] <= B[w] );
	CHECK( status == true );
	
	status = ( cA[z] <= cB[x] );
	CHECK( status == true );
	status = ( cA[z] <= cB[y] );
	CHECK( status == true );
	status = ( cA[z] <= cB[z] );
	CHECK( status == true );
	status = ( cA[z] <= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_LessThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_LessThanEqual_Operator_false

	//B[z] == A[x]
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 3.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 3.0f );
	CHECK( A[w] == 3.0f );
	
	bool status;
	
	status = ( A[z] <= B[x] );
	CHECK( status == false );
	status = ( A[z] <= B[y] );
	CHECK( status == false );
	status = ( A[z] <= B[z] );
	CHECK( status == false );
	status = ( A[z] <= B[w] );
	CHECK( status == false );
	
	status = ( A[z] <= cB[x] );
	CHECK( status == false );
	status = ( A[z] <= cB[y] );
	CHECK( status == false );
	status = ( A[z] <= cB[z] );
	CHECK( status == false );
	status = ( A[z] <= cB[w] );
	CHECK( status == false );
	
	status = ( cA[z] <= B[x] );
	CHECK( status == false );
	status = ( cA[z] <= B[y] );
	CHECK( status == false );
	status = ( cA[z] <= B[z] );
	CHECK( status == false );
	status = ( cA[z] <= B[w] );
	CHECK( status == false );
	
	status = ( cA[z] <= cB[x] );
	CHECK( status == false );
	status = ( cA[z] <= cB[y] );
	CHECK( status == false );
	status = ( cA[z] <= cB[z] );
	CHECK( status == false );
	status = ( cA[z] <= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_LessThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_LessThanEqual_Operator_true

	//B[z] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[z] <= C[x] );
	CHECK( status == true );
	status = ( A[z] <= C[y] );
	CHECK( status == true );
	status = ( A[z] <= C[z] );
	CHECK( status == true );
	status = ( A[z] <= C[w] );
	CHECK( status == true );
	
	status = ( cA[z] <= C[x] );
	CHECK( status == true );
	status = ( cA[z] <= C[y] );
	CHECK( status == true );
	status = ( cA[z] <= C[z] );
	CHECK( status == true );
	status = ( cA[z] <= C[w] );
	CHECK( status == true );
	
	status = ( A[z] <= cC[x] );
	CHECK( status == true );
	status = ( A[z] <= cC[y] );
	CHECK( status == true );
	status = ( A[z] <= cC[z] );
	CHECK( status == true );
	status = ( A[z] <= cC[w] );
	CHECK( status == true );
	
	status = ( cA[z] <= cC[x] );
	CHECK( status == true );
	status = ( cA[z] <= cC[y] );
	CHECK( status == true );
	status = ( cA[z] <= cC[z] );
	CHECK( status == true );
	status = ( cA[z] <= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_LessThanEqual_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketW_LessThanEqual_Operator_true_eq

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] <= B[x] );
	CHECK( status == true );
	status = ( A[w] <= B[y] );
	CHECK( status == true );
	status = ( A[w] <= B[z] );
	CHECK( status == true );
	status = ( A[w] <= B[w] );
	CHECK( status == true );
	
	status = ( A[w] <= cB[x] );
	CHECK( status == true );
	status = ( A[w] <= cB[y] );
	CHECK( status == true );
	status = ( A[w] <= cB[z] );
	CHECK( status == true );
	status = ( A[w] <= cB[w] );
	CHECK( status == true );
	
	status = ( cA[w] <= B[x] );
	CHECK( status == true );
	status = ( cA[w] <= B[y] );
	CHECK( status == true );
	status = ( cA[w] <= B[z] );
	CHECK( status == true );
	status = ( cA[w] <= B[w] );
	CHECK( status == true );
	
	status = ( cA[w] <= cB[x] );
	CHECK( status == true );
	status = ( cA[w] <= cB[y] );
	CHECK( status == true );
	status = ( cA[w] <= cB[z] );
	CHECK( status == true );
	status = ( cA[w] <= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_LessThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_LessThanEqual_Operator_false

	//B[w] == A[x]
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 3.0f );
	CHECK( A[y] == 3.0f );
	CHECK( A[z] == 3.0f );
	CHECK( A[w] == 3.0f );
	
	bool status;
	
	status = ( A[w] <= B[x] );
	CHECK( status == false );
	status = ( A[w] <= B[y] );
	CHECK( status == false );
	status = ( A[w] <= B[z] );
	CHECK( status == false );
	status = ( A[w] <= B[w] );
	CHECK( status == false );
	
	status = ( A[w] <= cB[x] );
	CHECK( status == false );
	status = ( A[w] <= cB[y] );
	CHECK( status == false );
	status = ( A[w] <= cB[z] );
	CHECK( status == false );
	status = ( A[w] <= cB[w] );
	CHECK( status == false );
	
	status = ( cA[w] <= B[x] );
	CHECK( status == false );
	status = ( cA[w] <= B[y] );
	CHECK( status == false );
	status = ( cA[w] <= B[z] );
	CHECK( status == false );
	status = ( cA[w] <= B[w] );
	CHECK( status == false );
	
	status = ( cA[w] <= cB[x] );
	CHECK( status == false );
	status = ( cA[w] <= cB[y] );
	CHECK( status == false );
	status = ( cA[w] <= cB[z] );
	CHECK( status == false );
	status = ( cA[w] <= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_LessThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_LessThanEqual_Operator_true

	//B[w] == C[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	status = ( A[w] <= C[x] );
	CHECK( status == true );
	status = ( A[w] <= C[y] );
	CHECK( status == true );
	status = ( A[w] <= C[z] );
	CHECK( status == true );
	status = ( A[w] <= C[w] );
	CHECK( status == true );
	
	status = ( cA[w] <= C[x] );
	CHECK( status == true );
	status = ( cA[w] <= C[y] );
	CHECK( status == true );
	status = ( cA[w] <= C[z] );
	CHECK( status == true );
	status = ( cA[w] <= C[w] );
	CHECK( status == true );
	
	status = ( A[w] <= cC[x] );
	CHECK( status == true );
	status = ( A[w] <= cC[y] );
	CHECK( status == true );
	status = ( A[w] <= cC[z] );
	CHECK( status == true );
	status = ( A[w] <= cC[w] );
	CHECK( status == true );
	
	status = ( cA[w] <= cC[x] );
	CHECK( status == true );
	status = ( cA[w] <= cC[y] );
	CHECK( status == true );
	status = ( cA[w] <= cC[z] );
	CHECK( status == true );
	status = ( cA[w] <= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketX_GreaterThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_GreaterThan_Operator_false

	//B[w] == A[x]
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] > B[x] );
	CHECK( status == false );
	status = ( A[x] > B[y] );
	CHECK( status == false );
	status = ( A[x] > B[z] );
	CHECK( status == false );
	status = ( A[x] > B[w] );
	CHECK( status == false );
	
	status = ( A[x] > cB[x] );
	CHECK( status == false );
	status = ( A[x] > cB[y] );
	CHECK( status == false );
	status = ( A[x] > cB[z] );
	CHECK( status == false );
	status = ( A[x] > cB[w] );
	CHECK( status == false );
	
	status = ( cA[x] > B[x] );
	CHECK( status == false );
	status = ( cA[x] > B[y] );
	CHECK( status == false );
	status = ( cA[x] > B[z] );
	CHECK( status == false );
	status = ( cA[x] > B[w] );
	CHECK( status == false );
	
	status = ( cA[x] > cB[x] );
	CHECK( status == false );
	status = ( cA[x] > cB[y] );
	CHECK( status == false );
	status = ( cA[x] > cB[z] );
	CHECK( status == false );
	status = ( cA[x] > cB[w] );
	CHECK( status == false );
	
#endif
} TEST_END



TEST( Quat_BracketX_GreaterThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_GreaterThan_Operator_true

	//B[w] == C[x]
	
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	bool status;
	
	status = ( A[x] > C[x] );
	CHECK( status == true );
	status = ( A[x] > C[y] );
	CHECK( status == true );
	status = ( A[x] > C[z] );
	CHECK( status == true );
	status = ( A[x] > C[w] );
	CHECK( status == true );
	
	status = ( cA[x] > C[x] );
	CHECK( status == true );
	status = ( cA[x] > C[y] );
	CHECK( status == true );
	status = ( cA[x] > C[z] );
	CHECK( status == true );
	status = ( cA[x] > C[w] );
	CHECK( status == true );
	
	status = ( A[x] > cC[x] );
	CHECK( status == true );
	status = ( A[x] > cC[y] );
	CHECK( status == true );
	status = ( A[x] > cC[z] );
	CHECK( status == true );
	status = ( A[x] > cC[w] );
	CHECK( status == true );
	
	status = ( cA[x] > cC[x] );
	CHECK( status == true );
	status = ( cA[x] > cC[y] );
	CHECK( status == true );
	status = ( cA[x] > cC[z] );
	CHECK( status == true );
	status = ( cA[x] > cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_GreaterThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_GreaterThan_Operator_false	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] > B[x] );
	CHECK( status == false );
	status = ( A[y] > B[y] );
	CHECK( status == false );
	status = ( A[y] > B[z] );
	CHECK( status == false );
	status = ( A[y] > B[w] );
	CHECK( status == false );
	
	status = ( A[y] > cB[x] );
	CHECK( status == false );
	status = ( A[y] > cB[y] );
	CHECK( status == false );
	status = ( A[y] > cB[z] );
	CHECK( status == false );
	status = ( A[y] > cB[w] );
	CHECK( status == false );
	
	status = ( cA[y] > B[x] );
	CHECK( status == false );
	status = ( cA[y] > B[y] );
	CHECK( status == false );
	status = ( cA[y] > B[z] );
	CHECK( status == false );
	status = ( cA[y] > B[w] );
	CHECK( status == false );
	
	status = ( cA[y] > cB[x] );
	CHECK( status == false );
	status = ( cA[y] > cB[y] );
	CHECK( status == false );
	status = ( cA[y] > cB[z] );
	CHECK( status == false );
	status = ( cA[y] > cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_GreaterThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_GreaterThan_Operator_true

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[y] > C[x] );
	CHECK( status == true );
	status = ( A[y] > C[y] );
	CHECK( status == true );
	status = ( A[y] > C[z] );
	CHECK( status == true );
	status = ( A[y] > C[w] );
	CHECK( status == true );
	
	status = ( cA[y] > C[x] );
	CHECK( status == true );
	status = ( cA[y] > C[y] );
	CHECK( status == true );
	status = ( cA[y] > C[z] );
	CHECK( status == true );
	status = ( cA[y] > C[w] );
	CHECK( status == true );
	
	status = ( A[y] > cC[x] );
	CHECK( status == true );
	status = ( A[y] > cC[y] );
	CHECK( status == true );
	status = ( A[y] > cC[z] );
	CHECK( status == true );
	status = ( A[y] > cC[w] );
	CHECK( status == true );
	
	status = ( cA[y] > cC[x] );
	CHECK( status == true );
	status = ( cA[y] > cC[y] );
	CHECK( status == true );
	status = ( cA[y] > cC[z] );
	CHECK( status == true );
	status = ( cA[y] > cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_GreaterThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_GreaterThan_Operator_false

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] > B[x] );
	CHECK( status == false );
	status = ( A[z] > B[y] );
	CHECK( status == false );
	status = ( A[z] > B[z] );
	CHECK( status == false );
	status = ( A[z] > B[w] );
	CHECK( status == false );
	
	status = ( A[z] > cB[x] );
	CHECK( status == false );
	status = ( A[z] > cB[y] );
	CHECK( status == false );
	status = ( A[z] > cB[z] );
	CHECK( status == false );
	status = ( A[z] > cB[w] );
	CHECK( status == false );
	
	status = ( cA[z] > B[x] );
	CHECK( status == false );
	status = ( cA[z] > B[y] );
	CHECK( status == false );
	status = ( cA[z] > B[z] );
	CHECK( status == false );
	status = ( cA[z] > B[w] );
	CHECK( status == false );
	
	status = ( cA[z] > cB[x] );
	CHECK( status == false );
	status = ( cA[z] > cB[y] );
	CHECK( status == false );
	status = ( cA[z] > cB[z] );
	CHECK( status == false );
	status = ( cA[z] > cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_GreaterThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_GreaterThan_Operator_true

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	status = ( A[z] > C[x] );
	CHECK( status == true );
	status = ( A[z] > C[y] );
	CHECK( status == true );
	status = ( A[z] > C[z] );
	CHECK( status == true );
	status = ( A[z] > C[w] );
	CHECK( status == true );
	
	status = ( cA[z] > C[x] );
	CHECK( status == true );
	status = ( cA[z] > C[y] );
	CHECK( status == true );
	status = ( cA[z] > C[z] );
	CHECK( status == true );
	status = ( cA[z] > C[w] );
	CHECK( status == true );
	
	status = ( A[z] > cC[x] );
	CHECK( status == true );
	status = ( A[z] > cC[y] );
	CHECK( status == true );
	status = ( A[z] > cC[z] );
	CHECK( status == true );
	status = ( A[z] > cC[w] );
	CHECK( status == true );
	
	status = ( cA[z] > cC[x] );
	CHECK( status == true );
	status = ( cA[z] > cC[y] );
	CHECK( status == true );
	status = ( cA[z] > cC[z] );
	CHECK( status == true );
	status = ( cA[z] > cC[w] );
	CHECK( status == true );

#endif
} TEST_END


TEST( Quat_BracketW_GreaterThan_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_GreaterThan_Operator_false	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] > B[x] );
	CHECK( status == false );
	status = ( A[w] > B[y] );
	CHECK( status == false );
	status = ( A[w] > B[z] );
	CHECK( status == false );
	status = ( A[w] > B[w] );
	CHECK( status == false );
	
	status = ( A[w] > cB[x] );
	CHECK( status == false );
	status = ( A[w] > cB[y] );
	CHECK( status == false );
	status = ( A[w] > cB[z] );
	CHECK( status == false );
	status = ( A[w] > cB[w] );
	CHECK( status == false );
	
	status = ( cA[w] > B[x] );
	CHECK( status == false );
	status = ( cA[w] > B[y] );
	CHECK( status == false );
	status = ( cA[w] > B[z] );
	CHECK( status == false );
	status = ( cA[w] > B[w] );
	CHECK( status == false );
	
	status = ( cA[w] > cB[x] );
	CHECK( status == false );
	status = ( cA[w] > cB[y] );
	CHECK( status == false );
	status = ( cA[w] > cB[z] );
	CHECK( status == false );
	status = ( cA[w] > cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_GreaterThan_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_GreaterThan_Operator_true	

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	status = ( A[w] > C[x] );
	CHECK( status == true );
	status = ( A[w] > C[y] );
	CHECK( status == true );
	status = ( A[w] > C[z] );
	CHECK( status == true );
	status = ( A[w] > C[w] );
	CHECK( status == true );
	
	status = ( cA[w] > C[x] );
	CHECK( status == true );
	status = ( cA[w] > C[y] );
	CHECK( status == true );
	status = ( cA[w] > C[z] );
	CHECK( status == true );
	status = ( cA[w] > C[w] );
	CHECK( status == true );
	
	status = ( A[w] > cC[x] );
	CHECK( status == true );
	status = ( A[w] > cC[y] );
	CHECK( status == true );
	status = ( A[w] > cC[z] );
	CHECK( status == true );
	status = ( A[w] > cC[w] );
	CHECK( status == true );
	
	status = ( cA[w] > cC[x] );
	CHECK( status == true );
	status = ( cA[w] > cC[y] );
	CHECK( status == true );
	status = ( cA[w] > cC[z] );
	CHECK( status == true );
	status = ( cA[w] > cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketX_GreaterThanEq_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketX_GreaterThanEq_Operator_true_eq	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[x] >= B[x] );
	CHECK( status == true );
	status = ( A[x] >= B[y] );
	CHECK( status == true );
	status = ( A[x] >= B[z] );
	CHECK( status == true );
	status = ( A[x] >= B[w] );
	CHECK( status == true );
	
	status = ( A[x] >= cB[x] );
	CHECK( status == true );
	status = ( A[x] >= cB[y] );
	CHECK( status == true );
	status = ( A[x] >= cB[z] );
	CHECK( status == true );
	status = ( A[x] >= cB[w] );
	CHECK( status == true );
	
	status = ( cA[x] >= B[x] );
	CHECK( status == true );
	status = ( cA[x] >= B[y] );
	CHECK( status == true );
	status = ( cA[x] >= B[z] );
	CHECK( status == true );
	status = ( cA[x] >= B[w] );
	CHECK( status == true );
	
	status = ( cA[x] >= cB[x] );
	CHECK( status == true );
	status = ( cA[x] >= cB[y] );
	CHECK( status == true );
	status = ( cA[x] >= cB[z] );
	CHECK( status == true );
	status = ( cA[x] >= cB[w] );
	CHECK( status == true );
	
#endif
} TEST_END



TEST( Quat_BracketX_GreaterThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketX_GreaterThanEqual_Operator_false	

	Quat B(3.0f, 3.0f, 3.0f, 3.0f);
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cB(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[x] >= B[x] );
	CHECK( status == false );
	status = ( A[x] >= B[y] );
	CHECK( status == false );
	status = ( A[x] >= B[z] );
	CHECK( status == false );
	status = ( A[x] >= B[w] );
	CHECK( status == false );
	
	status = ( A[x] >= cB[x] );
	CHECK( status == false );
	status = ( A[x] >= cB[y] );
	CHECK( status == false );
	status = ( A[x] >= cB[z] );
	CHECK( status == false );
	status = ( A[x] >= cB[w] );
	CHECK( status == false );
	
	status = ( cA[x] >= B[x] );
	CHECK( status == false );
	status = ( cA[x] >= B[y] );
	CHECK( status == false );
	status = ( cA[x] >= B[z] );
	CHECK( status == false );
	status = ( cA[x] >= B[w] );
	CHECK( status == false );
	
	status = ( cA[x] >= cB[x] );
	CHECK( status == false );
	status = ( cA[x] >= cB[y] );
	CHECK( status == false );
	status = ( cA[x] >= cB[z] );
	CHECK( status == false );
	status = ( cA[x] >= cB[w] );
	CHECK( status == false );
	
#endif
} TEST_END



TEST( Quat_BracketX_GreaterThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketX_GreaterThanEqual_Operator_true	
	
	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	bool status;
	
	status = ( A[x] >= C[x] );
	CHECK( status == true );
	status = ( A[x] >= C[y] );
	CHECK( status == true );
	status = ( A[x] >= C[z] );
	CHECK( status == true );
	status = ( A[x] >= C[w] );
	CHECK( status == true );
	
	status = ( cA[x] >= C[x] );
	CHECK( status == true );
	status = ( cA[x] >= C[y] );
	CHECK( status == true );
	status = ( cA[x] >= C[z] );
	CHECK( status == true );
	status = ( cA[x] >= C[w] );
	CHECK( status == true );
	
	status = ( A[x] >= cC[x] );
	CHECK( status == true );
	status = ( A[x] >= cC[y] );
	CHECK( status == true );
	status = ( A[x] >= cC[z] );
	CHECK( status == true );
	status = ( A[x] >= cC[w] );
	CHECK( status == true );
	
	status = ( cA[x] >= cC[x] );
	CHECK( status == true );
	status = ( cA[x] >= cC[y] );
	CHECK( status == true );
	status = ( cA[x] >= cC[z] );
	CHECK( status == true );
	status = ( cA[x] >= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_GreaterThanEq_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketY_GreaterThanEq_Operator_true_eq	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[y] >= B[x] );
	CHECK( status == true );
	status = ( A[y] >= B[y] );
	CHECK( status == true );
	status = ( A[y] >= B[z] );
	CHECK( status == true );
	status = ( A[y] >= B[w] );
	CHECK( status == true );
	
	status = ( A[y] >= cB[x] );
	CHECK( status == true );
	status = ( A[y] >= cB[y] );
	CHECK( status == true );
	status = ( A[y] >= cB[z] );
	CHECK( status == true );
	status = ( A[y] >= cB[w] );
	CHECK( status == true );
	
	status = ( cA[y] >= B[x] );
	CHECK( status == true );
	status = ( cA[y] >= B[y] );
	CHECK( status == true );
	status = ( cA[y] >= B[z] );
	CHECK( status == true );
	status = ( cA[y] >= B[w] );
	CHECK( status == true );
	
	status = ( cA[y] >= cB[x] );
	CHECK( status == true );
	status = ( cA[y] >= cB[y] );
	CHECK( status == true );
	status = ( cA[y] >= cB[z] );
	CHECK( status == true );
	status = ( cA[y] >= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketY_GreaterThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketY_GreaterThanEqual_Operator_false	

	Quat B(3.0f, 3.0f, 3.0f, 3.0f);
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cB(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[y] >= B[x] );
	CHECK( status == false );
	status = ( A[y] >= B[y] );
	CHECK( status == false );
	status = ( A[y] >= B[z] );
	CHECK( status == false );
	status = ( A[y] >= B[w] );
	CHECK( status == false );
	
	status = ( A[y] >= cB[x] );
	CHECK( status == false );
	status = ( A[y] >= cB[y] );
	CHECK( status == false );
	status = ( A[y] >= cB[z] );
	CHECK( status == false );
	status = ( A[y] >= cB[w] );
	CHECK( status == false );
	
	status = ( cA[y] >= B[x] );
	CHECK( status == false );
	status = ( cA[y] >= B[y] );
	CHECK( status == false );
	status = ( cA[y] >= B[z] );
	CHECK( status == false );
	status = ( cA[y] >= B[w] );
	CHECK( status == false );
	
	status = ( cA[y] >= cB[x] );
	CHECK( status == false );
	status = ( cA[y] >= cB[y] );
	CHECK( status == false );
	status = ( cA[y] >= cB[z] );
	CHECK( status == false );
	status = ( cA[y] >= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketY_GreaterThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketY_GreaterThanEqual_Operator_true	

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[y] >= C[x] );
	CHECK( status == true );
	status = ( A[y] >= C[y] );
	CHECK( status == true );
	status = ( A[y] >= C[z] );
	CHECK( status == true );
	status = ( A[y] >= C[w] );
	CHECK( status == true );
	
	status = ( cA[y] >= C[x] );
	CHECK( status == true );
	status = ( cA[y] >= C[y] );
	CHECK( status == true );
	status = ( cA[y] >= C[z] );
	CHECK( status == true );
	status = ( cA[y] >= C[w] );
	CHECK( status == true );
	
	status = ( A[y] >= cC[x] );
	CHECK( status == true );
	status = ( A[y] >= cC[y] );
	CHECK( status == true );
	status = ( A[y] >= cC[z] );
	CHECK( status == true );
	status = ( A[y] >= cC[w] );
	CHECK( status == true );
	
	status = ( cA[y] >= cC[x] );
	CHECK( status == true );
	status = ( cA[y] >= cC[y] );
	CHECK( status == true );
	status = ( cA[y] >= cC[z] );
	CHECK( status == true );
	status = ( cA[y] >= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_GreaterThanEq_Operator_true_eq, TestConfig::ALL)
{
#if Quat_BracketZ_GreaterThanEq_Operator_true_eq	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[z] >= B[x] );
	CHECK( status == true );
	status = ( A[z] >= B[y] );
	CHECK( status == true );
	status = ( A[z] >= B[z] );
	CHECK( status == true );
	status = ( A[z] >= B[w] );
	CHECK( status == true );
	
	status = ( A[z] >= cB[x] );
	CHECK( status == true );
	status = ( A[z] >= cB[y] );
	CHECK( status == true );
	status = ( A[z] >= cB[z] );
	CHECK( status == true );
	status = ( A[z] >= cB[w] );
	CHECK( status == true );
	
	status = ( cA[z] >= B[x] );
	CHECK( status == true );
	status = ( cA[z] >= B[y] );
	CHECK( status == true );
	status = ( cA[z] >= B[z] );
	CHECK( status == true );
	status = ( cA[z] >= B[w] );
	CHECK( status == true );
	
	status = ( cA[z] >= cB[x] );
	CHECK( status == true );
	status = ( cA[z] >= cB[y] );
	CHECK( status == true );
	status = ( cA[z] >= cB[z] );
	CHECK( status == true );
	status = ( cA[z] >= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketZ_GreaterThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketZ_GreaterThanEqual_Operator_false	

	Quat B(3.0f, 3.0f, 3.0f, 3.0f);
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cB(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[z] >= B[x] );
	CHECK( status == false );
	status = ( A[z] >= B[y] );
	CHECK( status == false );
	status = ( A[z] >= B[z] );
	CHECK( status == false );
	status = ( A[z] >= B[w] );
	CHECK( status == false );
	
	status = ( A[z] >= cB[x] );
	CHECK( status == false );
	status = ( A[z] >= cB[y] );
	CHECK( status == false );
	status = ( A[z] >= cB[z] );
	CHECK( status == false );
	status = ( A[z] >= cB[w] );
	CHECK( status == false );
	
	status = ( cA[z] >= B[x] );
	CHECK( status == false );
	status = ( cA[z] >= B[y] );
	CHECK( status == false );
	status = ( cA[z] >= B[z] );
	CHECK( status == false );
	status = ( cA[z] >= B[w] );
	CHECK( status == false );
	
	status = ( cA[z] >= cB[x] );
	CHECK( status == false );
	status = ( cA[z] >= cB[y] );
	CHECK( status == false );
	status = ( cA[z] >= cB[z] );
	CHECK( status == false );
	status = ( cA[z] >= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketZ_GreaterThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketZ_GreaterThanEqual_Operator_true	

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	

	bool status;
	status = ( A[z] >= C[x] );
	CHECK( status == true );
	status = ( A[z] >= C[y] );
	CHECK( status == true );
	status = ( A[z] >= C[z] );
	CHECK( status == true );
	status = ( A[z] >= C[w] );
	CHECK( status == true );
	
	status = ( cA[z] >= C[x] );
	CHECK( status == true );
	status = ( cA[z] >= C[y] );
	CHECK( status == true );
	status = ( cA[z] >= C[z] );
	CHECK( status == true );
	status = ( cA[z] >= C[w] );
	CHECK( status == true );
	
	status = ( A[z] >= cC[x] );
	CHECK( status == true );
	status = ( A[z] >= cC[y] );
	CHECK( status == true );
	status = ( A[z] >= cC[z] );
	CHECK( status == true );
	status = ( A[z] >= cC[w] );
	CHECK( status == true );
	
	status = ( cA[z] >= cC[x] );
	CHECK( status == true );
	status = ( cA[z] >= cC[y] );
	CHECK( status == true );
	status = ( cA[z] >= cC[z] );
	CHECK( status == true );
	status = ( cA[z] >= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST(Quat_BracketW_GreaterThanEq_Operator_true_eq, TestConfig::ALL)
{
#if  Quat_BracketW_GreaterThanEq_Operator_true_eq	

	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	CHECK( A[x] == 2.0f );
	CHECK( A[y] == 2.0f );
	CHECK( A[z] == 2.0f );
	CHECK( A[w] == 2.0f );
	
	bool status;
	
	status = ( A[w] >= B[x] );
	CHECK( status == true );
	status = ( A[w] >= B[y] );
	CHECK( status == true );
	status = ( A[w] >= B[z] );
	CHECK( status == true );
	status = ( A[w] >= B[w] );
	CHECK( status == true );
	
	status = ( A[w] >= cB[x] );
	CHECK( status == true );
	status = ( A[w] >= cB[y] );
	CHECK( status == true );
	status = ( A[w] >= cB[z] );
	CHECK( status == true );
	status = ( A[w] >= cB[w] );
	CHECK( status == true );
	
	status = ( cA[w] >= B[x] );
	CHECK( status == true );
	status = ( cA[w] >= B[y] );
	CHECK( status == true );
	status = ( cA[w] >= B[z] );
	CHECK( status == true );
	status = ( cA[w] >= B[w] );
	CHECK( status == true );
	
	status = ( cA[w] >= cB[x] );
	CHECK( status == true );
	status = ( cA[w] >= cB[y] );
	CHECK( status == true );
	status = ( cA[w] >= cB[z] );
	CHECK( status == true );
	status = ( cA[w] >= cB[w] );
	CHECK( status == true );

#endif
} TEST_END



TEST( Quat_BracketW_GreaterThanEqual_Operator_false, TestConfig::ALL)
{
#if Quat_BracketW_GreaterThanEqual_Operator_false

	Quat B(3.0f, 3.0f, 3.0f, 3.0f);
	Quat A(2.0f, 2.0f, 2.0f, 2.0f);
	Quat C(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cB(3.0f, 3.0f, 3.0f, 3.0f);
	const Quat cA(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cC(3.0f, 3.0f, 3.0f, 3.0f);
	
	bool status;
	
	status = ( A[w] >= B[x] );
	CHECK( status == false );
	status = ( A[w] >= B[y] );
	CHECK( status == false );
	status = ( A[w] >= B[z] );
	CHECK( status == false );
	status = ( A[w] >= B[w] );
	CHECK( status == false );
	
	status = ( A[w] >= cB[x] );
	CHECK( status == false );
	status = ( A[w] >= cB[y] );
	CHECK( status == false );
	status = ( A[w] >= cB[z] );
	CHECK( status == false );
	status = ( A[w] >= cB[w] );
	CHECK( status == false );
	
	status = ( cA[w] >= B[x] );
	CHECK( status == false );
	status = ( cA[w] >= B[y] );
	CHECK( status == false );
	status = ( cA[w] >= B[z] );
	CHECK( status == false );
	status = ( cA[w] >= B[w] );
	CHECK( status == false );
	
	status = ( cA[w] >= cB[x] );
	CHECK( status == false );
	status = ( cA[w] >= cB[y] );
	CHECK( status == false );
	status = ( cA[w] >= cB[z] );
	CHECK( status == false );
	status = ( cA[w] >= cB[w] );
	CHECK( status == false );

#endif
} TEST_END



TEST( Quat_BracketW_GreaterThanEqual_Operator_true, TestConfig::ALL)
{
#if Quat_BracketW_GreaterThanEqual_Operator_true	

	Quat C(2.0f, 2.0f, 2.0f, 2.0f);
	Quat B(2.0f, 2.0f, 2.0f, 2.0f);
	Quat A(3.0f, 3.0f, 3.0f, 3.0f);
	
	const Quat cC(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cB(2.0f, 2.0f, 2.0f, 2.0f);
	const Quat cA(3.0f, 3.0f, 3.0f, 3.0f);
	

	bool status;
	status = ( A[w] >= C[x] );
	CHECK( status == true );
	status = ( A[w] >= C[y] );
	CHECK( status == true );
	status = ( A[w] >= C[z] );
	CHECK( status == true );
	status = ( A[w] >= C[w] );
	CHECK( status == true );
	
	status = ( cA[w] >= C[x] );
	CHECK( status == true );
	status = ( cA[w] >= C[y] );
	CHECK( status == true );
	status = ( cA[w] >= C[z] );
	CHECK( status == true );
	status = ( cA[w] >= C[w] );
	CHECK( status == true );
	
	status = ( A[w] >= cC[x] );
	CHECK( status == true );
	status = ( A[w] >= cC[y] );
	CHECK( status == true );
	status = ( A[w] >= cC[z] );
	CHECK( status == true );
	status = ( A[w] >= cC[w] );
	CHECK( status == true );
	
	status = ( cA[w] >= cC[x] );
	CHECK( status == true );
	status = ( cA[w] >= cC[y] );
	CHECK( status == true );
	status = ( cA[w] >= cC[z] );
	CHECK( status == true );
	status = ( cA[w] >= cC[w] );
	CHECK( status == true );

#endif
} TEST_END



// ---  End of File ---------------

