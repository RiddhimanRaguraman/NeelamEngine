//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CameraNodeCompareStrategyEnumName.h"
#include "CameraNode.h"

namespace Neelam
{
	bool CameraNodeCompareStrategyEnumName::Compare(Azul::DLink *pRefNode, Azul::DLink *pTargetNode)
	{
		assert(pRefNode);
		assert(pTargetNode);
		
		CameraNode *pDataA = (CameraNode *)pRefNode;
		CameraNode *pDataB = (CameraNode *)pTargetNode;

		bool status = false;

		if(pDataA->GetCamera()->name == pDataB->GetCamera()->name)
		{
			status = true;
		}

		return status;
	}
}

// --- End of File ---

