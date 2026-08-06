//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CompareStrategyBase.h"

namespace Azul
{

	bool CompareStrategyBase::Compare(DLink *pRefNode,DLink *pTargetNode)
	{
		AZUL_UNUSED_VAR(pRefNode);
		AZUL_UNUSED_VAR(pTargetNode);
		
		// implement in the derived class
		assert(false);
		return false;
	}

}

// --- End of File ---
