//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef UNIT_TEST_CONFIGURATION_H
#define UNIT_TEST_CONFIGURATION_H

// Make sure all are enabled for final submission...
//      I grade whatever is set in this file - Keenan

#define GetBaseDir_ERROR_size          true
#define GetBaseDir_ERROR_PTR           true
#define GetBaseDir_SUCCESS             true
#define SetBaseDir_SUCCESS             true
#define SetBaseDir_ERROR_Filename      true
#define SetBaseDir_ERROR_size          true

#define IsHandleValid_SUCCESS true
#define IsHandleValid_ERROR            true

#define Open_NO_Base                   true
#define Open_NO_Base_Close             true
#define Open_NO_Base_ERROR_Filename    true
#define Open_NO_Base_ERROR_Open        true

#define Open_USE_Base                  true
#define Open_USE_Base_COMBO            true
#define Open_USE_Base_ERROR            true
#define Open_USE_Base_ERROR_Filename   true

#define Write_SUCCESS                  true
#define Write_ERROR_SourceBuffer       true
#define Write_ERROR_Fail               true
#define Write_SUCCESS_Read             true
#define Write_ERROR_ReadBuffer         true
#define Write_ERROR_Read               true

#define Write_SUCCESS_ReadSEEK         true

#define Write_ERROR_ReadSeek           true
#define Write_SUCCESS_ReadTell         true

#define Write_ERROR_ReadTell           true
#define Write_SUCCESS_Read2            true
#define Write_SUCCESS_ReadFlush        true

#define Write_ERROR_ReadFlush          true


#define Close_ERROR                    true
#define Close_ERROR_Close              true

#endif

// ---  End of File ---------------
