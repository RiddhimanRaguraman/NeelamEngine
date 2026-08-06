//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef MANAGER_DLL_INTERFACE_H
#define MANAGER_DLL_INTERFACE_H

#ifdef MANAGER_USE_DLL
#ifdef MANAGER_LIBRARY_EXPORTS
#define MANAGER_LIBRARY_API __declspec(dllexport)
#else
#define MANAGER_LIBRARY_API __declspec(dllimport)
#endif
#else
#define MANAGER_LIBRARY_API
#endif

#endif

// --- End of MANAGER ---
