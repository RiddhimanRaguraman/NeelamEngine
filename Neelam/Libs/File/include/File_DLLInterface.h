//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef FILE_DLL_INTERFACE_H
#define FILE_DLL_INTERFACE_H

#ifdef FILE_USE_DLL
#ifdef FILE_LIBRARY_EXPORTS
#define FILE_LIBRARY_API __declspec(dllexport)
#else
#define FILE_LIBRARY_API __declspec(dllimport)
#endif
#else
#define FILE_LIBRARY_API
#endif

#endif

// --- End of File ---
