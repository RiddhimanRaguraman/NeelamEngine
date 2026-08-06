//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef Compare_Strategy_Base_H
#define Compare_Strategy_Base_H

#include "Manager_DLLInterface.h"
#include "DLink.h"

namespace Azul
{
	class CompareStrategyBase
	{
	public:

		MANAGER_LIBRARY_API CompareStrategyBase() = default;
		MANAGER_LIBRARY_API CompareStrategyBase(const CompareStrategyBase &) = default;
		MANAGER_LIBRARY_API CompareStrategyBase &operator = (const CompareStrategyBase &) = default;
		MANAGER_LIBRARY_API virtual ~CompareStrategyBase() = default;

		MANAGER_LIBRARY_API virtual bool Compare(DLink *pRefNode, DLink *pTargetNode);

	};
}

#endif

// --- End of File ---
