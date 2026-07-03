//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef ANIM_TIME_DLL_INTERFACE_H
#define ANIM_TIME_DLL_INTERFACE_H

#ifdef ANIM_TIME_USE_DLL
#ifdef ANIM_TIME_LIBRARY_EXPORTS
#define ANIM_TIME_LIBRARY_API __declspec(dllexport)
#else
#define ANIM_TIME_LIBRARY_API __declspec(dllimport)
#endif
#else
#define ANIM_TIME_LIBRARY_API
#endif

#endif  

// ---  End of File ---
