//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "ShaderObjectNodeCompareStrategyEnumName.h"
#include "ShaderObjectNode.h"

namespace Neelam::vk
{
	bool ShaderObjectNodeCompareStrategyEnumName::Compare(Azul::DLink *pRefNode, Azul::DLink *pTargetNode)
	{
		assert(pRefNode);
		assert(pTargetNode);

		ShaderObjectNode *pDataA = (ShaderObjectNode *)pRefNode;
		ShaderObjectNode *pDataB = (ShaderObjectNode *)pTargetNode;

		return (pDataA->GetShaderName() == pDataB->GetShaderName());
	}
}

// ---  End of File ---
