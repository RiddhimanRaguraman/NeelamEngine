#include "CommonHeaders.h"

//---------------------------------------------------------------------------
// Nothing to do here -- deliberately.
//
// The obvious use for DLL_PROCESS_ATTACH would be Debug::Create(), because the
// thread framework's Debug singleton is a header-inline Meyers singleton and
// this DLL therefore has its OWN instance, separate from the exe's, whose
// thread-name Dictionary starts as a bare nullptr. That does have to be
// created somewhere or the first Debug::out from the engine is an access
// violation -- but NOT here.
//
// DLL_PROCESS_DETACH is too late to free it. MemTrace::ProcessEnd walks the
// whole shared debug heap and records every live block, and it runs from the
// _StaticMem destructor in each module -- so the EXE's copy runs first, at
// exit(), while this DLL is still fully loaded. Anything this DLL still owns at
// that instant is snapshotted and reported as a leak no matter what DllMain
// frees afterwards. (Measured: exactly the 336 bytes of the Dictionary, its
// std::map and the map's nodes.)
//
// So the engine's Debug dictionary is created and destroyed inside
// Engine::Initialize / Engine::Shutdown instead -- a window that is entirely
// inside main(), which is the only lifetime the tracker will accept.
//
// The consequence to know about: the engine may only Debug::out BETWEEN
// Initialize and Shutdown. Nothing in the component layer (Entity, Transform,
// EngineAPI) prints today, and that is what keeps it true.
//---------------------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD ul_reason_for_call, LPVOID /*lpReserved*/)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
