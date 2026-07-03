//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//-----------------------------------------------------------------------------  

#ifndef UNIT_TEST_CONFIGURATION_H
#define UNIT_TEST_CONFIGURATION_H

#include "Mat4Hint.h"

#define eq_float(A,B)	Util::isEqual(A,B, MATH_TOLERANCE) 

#define QTEST(A,B) { bool Quat_Check = (eq_float(A[x], B[x]) && \
                           eq_float(A[y], B[y]) && \
                           eq_float(A[z], B[z]) && \
                           eq_float(A[w], B[w])) || \
				          (eq_float(-A[x], B[x]) && \
                           eq_float(-A[y], B[y]) && \
                           eq_float(-A[z], B[z]) && \
                           eq_float(-A[w], B[w])) ; \
                     CHECK( Quat_Check == true ); }

// Make sure all are enabled for final submission...
//      I grade whatever is set in this file - Keenan

#define X1_Bracket_Write_Hint_kill                         true 
#define X2_Accessor_Write_Hint_kill                        true 
#define X3_Bracket_Read_Hint                               true 
#define X4_Accessor_Read_Hint                              true 
#define X5_qW_Accessor_Read                                true
#define X6_qW_Accessor_Write                               true

#define S_Set_Vec4                                         true 
#define S_Set_Row0                                         true 
#define S_Set_Row1                                         true 
#define S_Set_Row2                                         true 
#define S_Set_Row3                                         true 
#define S_Set_Ident                                        true 
#define S_Set_Mat4                                         true 
#define S_Set_T                                            true 
#define S_Set_T0                                           true 
#define S_Set_Inv_General                                  true 
#define S_Set_Inv_Rot                                      true 
#define S_Set_Inv_Trans                                    true 
#define S_Set_Inv_RotTrans                                 true 
#define S_Set_Inv_Scale                                    true 
#define S_Set_Inv_RotScale                                 true 
#define S_Set_Inv_TransScale                               true 
#define S_Set_Inv_Affine                                   true 
							                            	 
#define S0_Hint_M0                                         true 
#define S1_Hint_M1                                         true 
#define S2_Hint_M2                                         true 
#define S3_Hint_M3                                         true 
#define S4_Hint_M4                                         true 
#define S5_Hint_M5                                         true 
#define S6_Hint_M6                                         true 
#define S7_Hint_M7                                         true 
#define S8_Hint_M8                                         true 
#define S9_Hint_M9                                         true 
#define S10_Hint_M10                                       true 
#define S11_Hint_M11                                       true 
#define S12_Hint_M12                                       true 
#define S13_Hint_M13                                       true 
#define S14_Hint_M14                                       true 
#define S15_Hint_M15                                       true 
							                            	 
#define S0_Hint_bracket_M0                                 true 
#define S1_Hint_bracket_M1                                 true 
#define S2_Hint_bracket_M2                                 true 
#define S3_Hint_bracket_M3                                 true 
#define S4_Hint_bracket_M4                                 true 
#define S5_Hint_bracket_M5                                 true 
#define S6_Hint_bracket_M6                                 true 
#define S7_Hint_bracket_M7                                 true 
#define S8_Hint_bracket_M8                                 true 
#define S9_Hint_bracket_M9                                 true 
#define S10_Hint_bracket_M10                               true 
#define S11_Hint_bracket_M11                               true 
#define S12_Hint_bracket_M12                               true 
#define S13_Hint_bracket_M13                               true 
#define S14_Hint_bracket_M14                               true 
#define S15_Hint_bracket_M15                               true 
								                        	 
#define B1_Hint_M_M                                        true 
#define B2_Hint_M_S                                        true 
#define B3_Hint_M_R                                        true 
#define B4_Hint_M_T                                        true 
					                                    	 
#define B5_Hint_S_M                                        true 
#define B6_Hint_S_S                                        true 
#define B7_Hint_S_R                                        true 
#define B8_Hint_S_T                                        true 
					                                    	 
#define B9_Hint_R_M                                        true 
#define B10_Hint_R_S                                       true 
#define B11_Hint_R_R                                       true 
#define B12_Hint_R_T                                       true 
					                                    	 
#define B13_Hint_T_M                                       true 
#define B14_Hint_T_S                                       true 
#define B15_Hint_T_R                                       true 
#define B16_Hint_T_T                                       true 
								                			 
#define BX1_Hint_M_M                                       true 
#define BX2_Hint_M_S                                       true 
#define BX3_Hint_M_R                                       true 
#define BX4_Hint_M_T                                       true 
#define BX5_Hint_S_M                                       true 
#define BX6_Hint_S_S                                       true 
#define BX7_Hint_S_R                                       true 
#define BX8_Hint_S_T                                       true 
#define BX9_Hint_R_M                                       true 
#define BX10_Hint_R_S                                      true 
#define BX11_Hint_R_R                                      true 
#define BX12_Hint_R_T                                      true 
#define BX13_Hint_T_M                                      true 
#define BX14_Hint_T_S                                      true 
#define BX15_Hint_T_R                                      true 
#define BX16_Hint_T_T                                      true 
															 
#define Rot_Times_Mat4                                     true 
#define Rot_Times_Rot                                      true 
#define Rot_Times_Scale                                    true 
#define Rot_Times_Trans                                    true

#define Rot_Times_Quat                                     true
#define Quat_Times_Quat                                    true 
#define Quat_Times_Trans                                   true 
#define Quat_Times_Scale                                   true 
#define Quat_Times_Rot                                     true 

#define Mat4_Times_Mat4                                    true 
#define Scale_Times_Mat4                                   true 
#define Trans_Times_Mat4                                   true 

#define Quat_Times_Mat4                                    true 

#define Mat4_Times_Scale                                   true 
#define Mat4_Times_Trans                                   true 
#define Mat4_Times_Rot                                     true 
#define Mat4_Times_Quat                                    true 

#define Scale_Times_Quat                                   true 
#define Trans_Times_Quat                                   true 
#define Scale_Times_Rot                                    true 
#define Trans_Times_Rot                                    true 
                                                        	 
#define Mat4_TimesEqual_Mat4                               true 
#define Mat4_TimesEqual_Scale                              true 
#define Mat4_TimesEqual_Trans                              true 
#define Mat4_TimesEqual_Rot                                true 

#define Mat4_TimesEqual_Quat                               true 
                      	 
#define Quat_TimesEqual_Rot                                true 
#define Quat_TimesEqual_Quat                               true 
								                        	 
#define	Rot_TimesEqual_Rot                                 true 

#define	Rot_TimesEqual_Quat                                true 

#define	Scale_Times_Scale                                  true 
#define Scale_Times_Trans                                  true 
								                        	 
#define Trans_Times_Trans                                  true 
#define Trans_Times_Scale                                  true 
#define Scale_TimesEqual_Scale                             true 
#define Trans_TimesEqual_Trans                             true 
											            	 
#define SpeedTestInv_Rot                                   true                   
#define SpeedTestInv_Trans                                 true                   
#define SpeedTestInv_Scale                                 true                   
#define SpeedTestInv_RotTrans                              true                   
#define SpeedTestInv_RotScale                              true                   
#define SpeedTestInv_TransScale                            true                   
#define SpeedTestInv_Affine                                true                   
#define SpeedTestInv_General                               true 

#define SpeedTestDet_General                               true
#define SpeedTestDet_Rot                                   true
#define SpeedTestDet_Scale                                 true
#define SpeedTestDet_Trans                                 true
#define SpeedTestDet_RotTrans                              true
#define SpeedTestDet_RotScale                              true
#define SpeedTestDet_TransScale                            true
#define SpeedTestDet_Affine                                true

#define SpeedTest_Mat_TransTrans                           true
#define SpeedTest_Mat_TransMultEqualTrans                  true
#define SpeedTest_Mat_TransRot                             true
#define SpeedTest_Mat_TransScale                           true
#define SpeedTest_Mat_TransMat4                            true
#define SpeedTest_Mat_TransQuat                            true

#define SpeedTest_Mat_ScaleTrans                           true
#define SpeedTest_Mat_ScaleRot                             true
#define SpeedTest_Mat_ScaleScale                           true
#define SpeedTest_Mat_ScaleMultEqualScale                  true
#define SpeedTest_Mat_ScaleMat4                            true
#define SpeedTest_Mat_ScaleQuat                            true

#define SpeedTest_Mat_RotTrans                             true
#define SpeedTest_Mat_RotMultEqualRot                      true
#define SpeedTest_Mat_RotRot                               true
#define SpeedTest_Mat_RotScale                             true
#define SpeedTest_Mat_RotMat4                              true
#define SpeedTest_Mat_RotQuat                              true

#define SpeedTest_Mat_QuatTrans                            true
#define SpeedTest_Mat_QuatRot                              true
#define SpeedTest_Mat_QuatScale                            true
#define SpeedTest_Mat_QuatMat4                             true

#define SpeedTest_Mat_Mat4Rot                              true
#define SpeedTest_Mat_Mat4Scale                            true
#define SpeedTest_Mat_Mat4Trans                            true
#define SpeedTest_Mat_Mat4MultEqualTrans                   true
#define SpeedTest_Mat_Mat4MultEqualScale                   true
#define SpeedTest_Mat_Mat4MultEqualRot                     true

#define Yahtzee                                            true 

#define QuatApp_SlerpDataArray                             true 
#define QuatApp_SlerpDataArray0                            true 
#define QuatApp_SlerpDataArray1                            true 
#define QuatApp_SlerpData                                  true 

#define Vec3App_Lerp                            true
#define Vec3App_Lerp2                           true
#define Vec3App_Lerp3                           true
#define Vec3App_Lerp4                           true

#define Vec3App_LERP_Array                      true
#define Vec3App_LERP_Array0                     true
#define Vec3App_LERP_Array1                     true

#define Combo_Junkfood                          true                                   
#define Combo_VectCrossAddSub                   true                            
#define Combo_VectCrossAddSubMatrixMult         true                  
#define Combo_VectCrossAddSubMatrixMultCross    true             
#define Combo_VectCrossCrossNorm                true                         
#define Combo_VectLine                          true      

#define Mat3_Accessor_Get                       true                                
#define Mat3_Accessor_Get_Const                 true                          
#define Mat3_Accessor_Set                       true                                
#define Mat3_AddEqual_Mat3                      true                             
#define Mat3_Add_Mat3                           true                                  
#define Mat3_AssignmentOperator                 true                          
#define Mat3_Bracket_Get                        true                                 
#define Mat3_Bracket_Get_Const                  true                           
#define Mat3_Bracket_Set                        true                                 
#define Mat3_Copy_Constructor                   true                            
#define Mat3_Default_Constructor                true                         
#define Mat3_Destructor_Constuctor              true                       
#define Mat3_Det                                true  
#define Mat3_GetInverse                         true                                  
#define Mat3_GetTranspose                       true                                
#define Mat3_GET_ROW_0                          true                                   
#define Mat3_GET_ROW_1                          true                                   
#define Mat3_GET_ROW_2                          true                                                                    
#define Mat3_Inverse                            true                                     
#define Mat3_isEqual_false                      true                               
#define Mat3_MultEqual_Mat3                     true                              
#define Mat3_Mult_Mat3                          true                          
#define Mat3_Mult_Scale                         true                                
#define Mat3_Scale_Equals                       true                                
#define Mat3_Scale_Mat3                         true                                
#define Mat3_SET_Identity                       true                                                            
#define Mat3_SET_ROW_0                          true                                   
#define Mat3_SET_ROW_1                          true                                   
#define Mat3_SET_ROW_2                          true                                                                                                 
#define Mat3_SET_Vectors                        true                                 

#define Mat3_Special_isEqual_false2             true                      
#define Mat3_Special_isEqual_true               true                        
#define Mat3_Special_isIdentity_false           true                    
#define Mat3_Special_isIdentity_true            true                     
#define Mat3_Special_Matrix_Identity            true                                       
                               				            	 
#define Mat3_Special_Matrix_Zero                true                                                        
                                                        	 
#define Mat3_SubEqual_Mat3                      true                             
#define Mat3_Sub_Mat3                           true                                  
#define Mat3_Transpose                          true                                                                      
#define Mat3_UnaryMinus                         true                                
#define Mat3_UnaryPlus                          true                                 
#define Mat3_Unary_equal_Minus                  true                         
#define Mat3_Unary_equal_Plus                   true   
#define Mat3_Vector_Constructor                 true   

#define Mat4_Accessor_Get                       true                                
#define Mat4_Accessor_Get_Const                 true                          
#define Mat4_Accessor_Set                       true                                
#define Mat4_AddEqual_Mat4                      true                             
#define Mat4_Add_Mat4                           true                                  
#define Mat4_AssignmentOperator                 true                          
#define Mat4_Bracket_Get                        true                                 
#define Mat4_Bracket_Get_Const                  true                           
#define Mat4_Bracket_Set                        true                                 
#define Mat4_Copy_Constructor                   true                            
#define Mat4_Default_Constructor                true                         
#define Mat4_Destructor_Constuctor              true                       
#define Mat4_Det                                true                                         
#define Mat4_GetInverse                         true                                  
#define Mat4_GetTranspose                       true                                
#define Mat4_GET_ROW_0                          true                                   
#define Mat4_GET_ROW_1                          true                                   
#define Mat4_GET_ROW_2                          true                                   
#define Mat4_GET_ROW_3                          true                                   
#define Mat4_Inverse                            true                                     
#define Mat4_isEqual_false                      true                                                           
#define Mat4_MultEqual_Mat4                     true                              
   											            	 
#define Mat4_Mult_Mat4                          true                          
#define Mat4_Mult_Scale                         true                                
#define Mat4_Scale_Equals                       true                                
#define Mat4_Scale_Mat4                         true                                
#define Mat4_SET_Identity                       true                                
											            	 
#define Rot_Mult_Quat                                      true 
#define Rot_MultEqual_Quat                                 true 

#define Rot_RotAxisAngle                                   true            
#define Rot_RotInverseOrient                               true        
#define Rot_RotOrient                                      true 
#define Rot_SET_RotAxisAngle                               true  
#define Rot_SET_RotInverseOrient                           true 
#define Rot_SET_RotOrient                                  true 
#define ROT_SET_RotXYZ                                     true 
                                   			            	 
#define Mat4_SET_ROW_0                          true                                   
#define Mat4_SET_ROW_1                          true                                   
#define Mat4_SET_ROW_2                          true                                   
#define Mat4_SET_ROW_3                          true                                   
#define Mat4_SET_Vectors                        true                                 
                                 
#define Mat4_Special_isEqual_false2             true                      
#define Mat4_Special_isEqual_true               true                        
#define Mat4_Special_isIdentity_false           true                    
#define Mat4_Special_isIdentity_true            true                     
#define Mat4_Special_Matrix_Identity            true                     
           									            	 
#define Mat4_Special_Matrix_Zero                true                         
             								            	 
#define Mat4_SubEqual_Mat4                      true                             
#define Mat4_Sub_Mat4                           true                                  
#define Mat4_Transpose                          true                                   
#define Mat4_UnaryMinus                         true                                
#define Mat4_UnaryPlus                          true                                 
#define Mat4_Unary_equal_Minus                  true                         
#define Mat4_Unary_equal_Plus                   true   
#define Mat4_Vector_Constructor                 true       
									            
#define Rot_X_Set                               true                                           
#define Rot_Y_Set                               true                                    
#define Rot_Z_Set                               true   
#define Rot_XYZ_Set                             true 
#define Rot_XZY_Set                             true 
#define Rot_YXZ_Set                             true 
#define Rot_YZX_Set                             true 
#define Rot_ZXY_Set                             true 
#define Rot_ZYX_Set                             true 
#define Rot_AxisAngle                           true  
#define Rot_UnitAxisAngle                       true  
#define Rot_InverseOrient                       true                            
#define Rot_Orient                              true  
#define Rot_Set_AxisAngle                       true    
#define Rot_Set_UnitAxisAngle                   true 
#define Rot_Set_InverseOrient                   true                  
#define Rot_Set_Orient                          true  
#define Rot_X_Constructor                       true                         
#define Rot_Y_Constructor                       true                                
#define Rot_Z_Constructor                       true 
#define Rot_XYZ_Constructor                     true 
#define Rot_XZY_Constructor                     true 
#define Rot_YXZ_Constructor                     true 
#define Rot_YZX_Constructor                     true 
#define Rot_ZXY_Constructor                     true 
#define Rot_ZYX_Constructor                     true 
#define Rot_Quat_Constructor                               true 
#define Rot_Assignment_Quat                                true 
#define Rot_Assignment_Rot                                 true 
#define Rot_Set_Rot                                        true 

#define Trans_Set                               true                                   
#define Trans_Set_Vect                          true  
#define Trans_Constructor                       true                                   
#define Trans_Constructor_Vect                  true  

#define Scale_SET_Vect                          true                                   
#define Scale_SET                               true        
#define Scale_Matrix_Constructor                true                        
#define Scale_Matrix_Constructor_Vect           true     
									            
#define Trig_ACos                               true                                        
#define Trig_ASin                               true                                        
#define Trig_ATan                               true                                        
#define Trig_ATan2                              true                                       
#define Trig_Cos                                true                                         
#define Trig_CosSin                             true                                      
#define Trig_InvSqrt                            true                                     
#define Trig_Sin                                true                                         
#define Trig_Sqrt                               true                                        
#define Trig_Tan                                true    

#define Quat_Get_Accessors                                 true 
#define Quat_Get_Accessors_const                           true 
#define Quat_Set_Accessors                                 true 
#define Quat_Set_Accessors_get                             true 
#define Quat_AddSubMultDiv                                 true 
#define Quat_PlusOperator                                  true 
#define Quat_QuatPlusQuat                                  true 
#define Quat_QuatPlusEqualQuat                             true 
#define Quat_QuatPlusConstant                              true 
#define Quat_QuatPlusEqualConstant                         true 
#define Quat_ConstantPlusQuat                              true 
#define Quat_ConstantPlusQuatPlusConstant                  true 
#define Quat_QuatPlusConstPlusQuat                         true 
#define Quat_QuatMinusQuat                                 true 
#define Quat_QuatMinusEqualQuat                            true 
#define Quat_QuatMinusConstant                             true 
#define Quat_QuatMinusEqualConst                           true 
#define Quat_ConstantMinusQuat                             true 
#define Quat_ConstantMinusQuatMinusConstant                true 
#define Quat_QuatMinusConstantMinusQuat                    true 
#define Quat_MinusOperator                                 true 
#define Quat_QuatTimesQuat                                 true 
#define Quat_QuatTimeEqualQuat                             true 
#define Quat_QuatTimeConst                                 true 
#define Quat_QuatTimesEqualConst                           true 
#define Quat_ConstTimesQuat                                true 
#define Quat_QuatTimesRot                                  true 
#define Quat_RotTimesQuat                                  true 
#define Quat_QuatTimesEqualRot                             true 

#define Quat_QuatDivQuat                                   true 
#define Quat_QuatDivEqualQuat                              true 
#define Quat_QuatDivConst                                  true 
#define Quat_QuatDivEqualConst                             true 
#define Quat_ConstDivQuat                                  true 
#define Quat_EqualOperator                                 true 
#define Quat_vectTimesQuat                                 true 
#define Quat_vectTimesEqualQuat                            true 
#define Quat_vectTimesQuat2                                true 
#define Quat_vectTimesEqualQuat2                           true 
#define Quat_Boolean                                       true 
#define Quat_IsEqual                                       true 
#define Quat_IsEqual1                                      true 
#define Quat_IsNegEqual                                    true 
#define Quat_IsNegEqual2                                   true 
#define Quat_IsEquivalent                                  true 
#define Quat_IsEquivalent2                                 true 
#define Quat_IsEquivalent3                                 true 
#define Quat_IsConjugateEqual                              true 
#define Quat_IsConjugateEqual2                             true 
#define Quat_IsIdentity                                    true 
#define Quat_IsIdentity2                                   true 
#define Quat_IsNormalized                                  true 
#define Quat_IsNormalized2                                 true 

#define Quat_Constructor                                   true 
#define Quat_Default_Constructor                           true 
#define Quat_Constructor_Set_Every_Component               true 
#define Quat_Copy_Constructor                              true 
#define Quat_Vect_Comp_Real_Comp_Constructor               true 
#define Quat_From_Rot_Constructor                          true 
#define Quat_IDENTITY_Constructor                          true 
#define Quat_ROTXYZ_Constructor                            true 
#define Quat_SET_ROTXYZ_Constructor                        true 
#define Quat_X_PI2_Constructor                             true 
#define Quat_X_PI_Constructor                              true 
#define Quat_Y_PI2_Constructor                             true 
#define Quat_Y_PI_Constructor                              true 
#define Quat_Z_PI2_Constructor                             true 
#define Quat_Z_PI_Constructor                              true 
#define Quat_X_Constructor                                 true 
#define Quat_Y_Constructor                                 true 
#define Quat_Z_Constructor                                 true 
#define Quat_XY_Constructor                                true 
#define Quat_XZ_Constructor                                true 
#define Quat_YX_Constructor                                true 
#define Quat_YZ_Constructor                                true 
#define Quat_ZX_Constructor                                true 
#define Quat_ZY_Constructor                                true 
#define Quat_XYZ_Constructor                               true 
#define Quat_XZY_Constructor                               true 
#define Quat_YXZ_Constructor                               true 
#define Quat_YZX_Constructor                               true 
#define Quat_ZXY_Constructor                               true 
#define Quat_ZYX_Constructor                               true 
#define Quat_AXIS_ANGLE_Constructor                        true 
#define Quat_ROT_ORIENT_Constructor                        true 
#define Quat_ROT_INVERSE_ORIENT_Constructor                true 
#define Quat_Destructor                                    true 
#define Quat_Functions                                     true 
#define Quat_GetConjugate                                  true 
#define Quat_ConjugateInPlace                              true 
#define Quat_ConjugateByValue                              true 
#define Quat_Mag                                           true 
#define Quat_MagSquared                                    true 
#define Quat_InvMag                                        true 
#define Quat_Norm                                          true 
#define Quat_GetNorm                                       true 
#define Quat_GetInverse                                    true 
#define Quat_Inverse                                       true 
#define Quat_Inverse_3                                     true 
#define Quat_Inverse_Transpose                             true 
#define Quat_Lqcvq_Lqvqc_1                                 true 
#define Quat_Dot                                           true 
#define Quat_Assignment_Rot                                true 
#define Quat_Proxy                                         true 
#define Quat_BracketX_get                                  true 
#define Quat_BracketX_assign                               true 
#define Quat_BracketX_plusEqual                            true 
#define Quat_BracketX_negEqual                             true 
#define Quat_BracketX_multEqual                            true 
#define Quat_BracketX_divEqual                             true 
#define Quat_BracketY_get                                  true 
#define Quat_BracketY_assign                               true 
#define Quat_BracketY_plusEqual                            true 
#define Quat_BracketY_negEqual                             true 
#define Quat_BracketY_multEqual                            true 
#define Quat_BracketY_divEqual                             true 
#define Quat_BracketZ_get                                  true 
#define Quat_BracketZ_assign                               true 
#define Quat_BracketZ_plusEqual                            true 
#define Quat_BracketZ_negEqual                             true 
#define Quat_BracketZ_multEqual                            true 
#define Quat_BracketZ_divEqual                             true 
#define Quat_BracketW_get                                  true 
#define Quat_BracketW_assign                               true 
#define Quat_BracketW_plusEqual                            true 
#define Quat_BracketW_negEqual                             true 
#define Quat_BracketW_multEqual                            true 
#define Quat_BracketW_divEqual                             true 

#define Quat_BracketX_assignment_ConstQuat_Bracket         true 
#define Quat_BracketY_assignment_ConstQuat_Bracket         true 
#define Quat_BracketZ_assignment_ConstQuat_Bracket         true 
#define Quat_BracketW_assignment_ConstQuat_Bracket         true 
#define Quat_BracketX_assignment_Quat_Bracket              true 
#define Quat_BracketY_assignment_Quat_Bracket              true 
#define Quat_BracketZ_assignment_Quat_Bracket              true 
#define Quat_BracketW_assignment_Quat_Bracket              true 
#define Quat_BracketW_assignment_Quat_Bracket_uninit       true 
#define Quat_BracketX_Assignment_Pointers                  true 
#define Quat_BracketY_Assignment_Pointers                  true 
#define Quat_BracketZ_Assignment_Pointers                  true 
#define Quat_BracketW_Assignment_Pointers                  true 
#define Quat_BracketX_Assignment_Pointers_Const            true 
#define Quat_BracketY_Assignment_Pointers_Const            true 
#define Quat_BracketZ_Assignment_Pointers_Const            true 
#define Quat_BracketW_Assignment_Pointers_Const            true 
#define Quat_BracketOperator_plus                          true 
#define Quat_BracketOperator_plus_const                    true 
#define Quat_BracketOperator_minus_const                   true 
#define Quat_BracketOperator_minus                         true 
#define Quat_BracketX_Assignment_Operator_plus_Const       true 
#define Quat_BracketY_Assignment_Operator_plus_Const       true 
#define Quat_BracketZ_Assignment_Operator_plus_Const       true 
#define Quat_BracketW_Assignment_Operator_plus_Const       true 
#define Quat_BracketX_Assignment_Operator_plus             true 
#define Quat_BracketY_Assignment_Operator_plus             true 
#define Quat_BracketZ_Assignment_Operator_plus             true 
#define Quat_BracketW_Assignment_Operator_plus             true 
#define Quat_BracketX_Assignment_Operator_Minus_Const      true 
#define Quat_BracketY_Assignment_Operator_Minus_Const      true 
#define Quat_BracketZ_Assignment_Operator_Minus_Const      true 
#define Quat_BracketW_Assignment_Operator_Minus_Const      true 
#define Quat_BracketX_Assignment_Operator_Minus            true 
#define Quat_BracketY_Assignment_Operator_Minus            true 
#define Quat_BracketZ_Assignment_Operator_Minus            true 
#define Quat_BracketW_Assignment_Operator_Minus            true 
#define Quat_BracketX_Equal_Operator_true                  true 
#define Quat_BracketX_Equal_Operator_false                 true 
#define Quat_BracketY_Equal_Operator_true                  true 
#define Quat_BracketY_Equal_Operator_false                 true 
#define Quat_BracketZ_Equal_Operator_true                  true 
#define Quat_BracketZ_Equal_Operator_false                 true 
#define Quat_BracketW_Equal_Operator_true                  true 
#define Quat_BracketW_Equal_Operator_false                 true 
#define Quat_BracketX_notEqual_Operator_false              true 
#define Quat_BracketX_notEqual_Operator_true               true 
#define Quat_BracketY_notEqual_Operator_false              true 
#define Quat_BracketY_notEqual_Operator_true               true 
#define Quat_BracketZ_notEqual_Operator_false              true 
#define Quat_BracketZ_notEqual_Operator_true               true 
#define Quat_BracketW_notEqual_Operator_false              true 
#define Quat_BracketW_notEqual_Operator_true               true 
#define Quat_BracketX_LessThan_Operator_false              true 
#define Quat_BracketY_LessThan_Operator_false              true 
#define Quat_BracketZ_LessThan_Operator_false              true 
#define Quat_BracketW_LessThan_Operator_false              true 
#define Quat_BracketX_LessThan_Operator_true               true 
#define Quat_BracketY_LessThan_Operator_true               true 
#define Quat_BracketZ_LessThan_Operator_true               true 
#define Quat_BracketW_LessThan_Operator_true               true 
#define Quat_BracketX_LessThanEqual_Operator_true_eq       true 
#define Quat_BracketY_LessThanEqual_Operator_true_eq       true 
#define Quat_BracketZ_LessThanEqual_Operator_true_eq       true 
#define Quat_BracketW_LessThanEqual_Operator_true_eq       true 
#define Quat_BracketX_LessThanEqual_Operator_false         true 
#define Quat_BracketY_LessThanEqual_Operator_false         true 
#define Quat_BracketZ_LessThanEqual_Operator_false         true 
#define Quat_BracketW_LessThanEqual_Operator_false         true 
#define Quat_BracketX_LessThanEqual_Operator_true          true 
#define Quat_BracketY_LessThanEqual_Operator_true          true 
#define Quat_BracketZ_LessThanEqual_Operator_true          true 
#define Quat_BracketW_LessThanEqual_Operator_true          true 
#define Quat_BracketX_GreaterThan_Operator_false           true 
#define Quat_BracketX_GreaterThan_Operator_true            true 
#define Quat_BracketY_GreaterThan_Operator_false           true 
#define Quat_BracketY_GreaterThan_Operator_true            true 
#define Quat_BracketZ_GreaterThan_Operator_false           true 
#define Quat_BracketZ_GreaterThan_Operator_true            true 
#define Quat_BracketW_GreaterThan_Operator_false           true 
#define Quat_BracketW_GreaterThan_Operator_true            true 
#define Quat_BracketX_GreaterThanEq_Operator_true_eq       true 
#define Quat_BracketY_GreaterThanEq_Operator_true_eq       true 
#define Quat_BracketZ_GreaterThanEq_Operator_true_eq       true 
#define Quat_BracketW_GreaterThanEq_Operator_true_eq       true 
#define Quat_BracketX_GreaterThanEqual_Operator_false      true 
#define Quat_BracketY_GreaterThanEqual_Operator_false      true 
#define Quat_BracketZ_GreaterThanEqual_Operator_false      true 
#define Quat_BracketW_GreaterThanEqual_Operator_false      true 
#define Quat_BracketX_GreaterThanEqual_Operator_true       true 
#define Quat_BracketY_GreaterThanEqual_Operator_true       true 
#define Quat_BracketZ_GreaterThanEqual_Operator_true       true 
#define Quat_BracketW_GreaterThanEqual_Operator_true       true 

#define Quat_Set_everyElement                              true 
#define Quat_Set_Vect_Real                                 true 
#define Quat_Set_Quat_From_Rot                             true 
#define Quat_Set_IDENTITY                                  true 

#define Quat_Set_ROT_X_PI2                                 true 
#define Quat_Set_ROT_X_PI                                  true 
#define Quat_Set_ROT_Y_PI2                                 true 
#define Quat_Set_ROT_Y_PI                                  true 
#define Quat_Set_ROT_Z_PI2                                 true 
#define Quat_Set_ROT_Z_PI                                  true 
#define Quat_Set_ROT_X                                     true 
#define Quat_Set_ROT_Y                                     true 
#define Quat_Set_ROT_Z                                     true 
#define Quat_XY_set                                        true 
#define Quat_XZ_set                                        true 
#define Quat_YX_set                                        true 
#define Quat_YZ_set                                        true 
#define Quat_ZX_set                                        true 
#define Quat_ZY_set                                        true 
#define Quat_XYZ_set                                       true 
#define Quat_XZY_set                                       true 
#define Quat_YXZ_set                                       true 
#define Quat_YZX_set                                       true 
#define Quat_ZXY_set                                       true 
#define Quat_ZYX_set                                       true 
#define Quat_AXIS_ANGLE_set                                true 
#define Quat_ROT_ORIENT_set                                true 
#define Quat_ROT_INVERSE_ORIENT_set                        true 
#define Quat_Set_Each_ELEMENT                              true 
#define Quat_Set_From_VECT                                 true 
#define Quat_Get_Vect_elements                             true 
#define Quat_Get_Vect                                      true 
#define Quat_Get_Angle_of_rotation                         true 
#define Quat_Get_Axis_of_rotation                          true 
#define Quat_Get_bracket1                                  true 
#define Quat_Get_bracket2                                  true 
#define Quat_Get_bracket3                                  true 
#define Quat_Get_bracket4                                  true 

#define Vec3_Add_Vec3                           true                                    
#define Vec3_Assignment_Operator                true     
#define Vec3_Assignment_Operator_Vec4           true
#define Vec3_ConstantCheck                      true                               
#define Vec3_Constructor_Copy                   true                            
#define Vec3_Constructor_Default                true                         
#define Vec3_Constructor_Individual             true                       
#define Vec3_Constructor_Vec4                   true                             
#define Vec3_Cross                              true                                       
#define Vec3_Destructor                         true                                  
#define Vec3_Dot                                true                                         
#define Vec3_Get_Accessors                      true                               
#define Vec3_Get_Accessors_const                true                         
#define Vec3_Get_Angle                          true                                   
#define Vec3_Get_Brackets                       true                                
#define Vec3_Get_Brackets_const                 true                          
#define Vec3_Get_Normalize                      true                               
#define Vec3_IsEqualFalse                       true                                
#define Vec3_IsEqualFalse_default               true                        
#define Vec3_IsEqualTrue                        true                                 
#define Vec3_IsEqualTrue_default                true                         
#define Vec3_IsZeroFalse                        true                                 
#define Vec3_IsZeroFalse_default                true                         
#define Vec3_IsZeroTrue_default                 true                          
#define Vec3_IsZeroTrue_True                    true                             
#define Vec3_Len                                true                                         
#define Vec3_MultEqual_Mat3                     true                              
#define Vec3_MultEqual_Mat4                     true                              
#define Vec3_Mult_Mat3                          true                                   
#define Vec3_Mult_Mat4                          true                                   
#define Vec3_Mult_Scale                         true                                  
#define Vec3_Normalize                          true                                   
#define Vec3_PlusEqual_Vect                     true                              
#define Vec3_Proxy                              true                                       
#define Vec3_SampleTest                         true                                  
#define Vec3_ScaleEquals                        true                                 
#define Vec3_Scale_Vect                         true                                  
#define Vec3_Set_3_Elements                     true                              
#define Vec3_Set_Accessors                      true                               
#define Vec3_Set_Accessors_get                  true                           
#define Vec3_Set_Brackets                       true                                
#define Vec3_Set_Brackets_get                   true                            
#define Vec3_Set_Vec3                           true                                    
#define Vec3_Set_Vec4                           true                                    
#define Vec3_SubEqual_Vect                      true                               
#define Vec3_Sub_Vect                           true                                    
#define Vec3_Unary_equal_Minus                  true                           
#define Vec3_Unary_equal_Plus                   true                            
#define Vec3_Unary_Minus                        true                                 
#define Vec3_Unary_Plus                         true    
			            
#define Vec4_Add_Vec4                           true                                    
#define Vec4_Assignment_Operator                true                         
#define Vec4_ConstantCheck                      true                               
#define Vec4_Constructor_Copy                   true  
#define Vec4_Constructor_Default                true                            
#define Vec4_Constructor_Individual             true                      
#define Vec4_Constructor_Vec3                   true
#define Vec4_Destructor                         true                                  
#define Vec4_Dot                                true                                         
#define Vec4_Get_Accessors                      true                               
#define Vec4_Get_Accessors_const                true                         
#define Vec4_Get_Brackets                       true                                
#define Vec4_Get_Brackets_const                 true                          
#define Vec4_Get_Normalize                      true                               
#define Vec4_IsEqualFalse                       true                                
#define Vec4_IsEqualFalse_default               true                        
#define Vec4_IsEqualTrue                        true                                 
#define Vec4_IsEqualTrue_default                true                         
#define Vec4_IsZeroFalse                        true                                 
#define Vec4_IsZeroFalse_default                true                         
#define Vec4_IsZeroTrue_default                 true                          
#define Vec4_IsZeroTrue_True                    true                             
#define Vec4_Len                                true                                         
#define Vec4_MultEqual_Mat4                     true                              
#define Vec4_Mult_Mat4                          true                                   
#define Vec4_Mult_Scale                         true                                  
#define Vec4_Normalize                          true                                   
#define Vec4_PlusEqual_Vec4                     true                              
#define Vec4_Proxy                              true                                       
#define Vec4_SampleTest                         true                                  
#define Vec4_ScaleEquals                        true                                 
#define Vec4_Scale_Vec4                         true                                  
#define Vec4_Set_4_Elements                     true                              
#define Vec4_Set_Accessors                      true                               
#define Vec4_Set_Accessors_Get                  true                           
#define Vec4_Set_Brackets                       true                                
#define Vec4_Set_Brackets_get                   true                            
#define Vec4_Set_Vec3                           true                                    
#define Vec4_Set_Vec4                           true                                    
#define Vec4_SubEqual_Vec4                      true                               
#define Vec4_Sub_Vec4                           true                                    
#define Vec4_Unary_equal_Minus                  true                           
#define Vec4_Unary_equal_Plus                   true                            
#define Vec4_Unary_Minus                        true                                 
#define Vec4_Unary_Plus                         true                                  

#define Rot_Assignment_Rot                      true
#define Rot_RotAxisAngle                        true
#define Rot_RotInverseOrient                    true
#define Rot_RotOrient                           true
#define Rot_SET_RotAxisAngle                    true
#define Rot_SET_RotInverseOrient                true
#define Rot_SET_RotOrient                       true
#define Rot_Set_Rot                             true


#endif

// ---  End of File ---------------
