//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef SHADER_OBJECT_NODE_COMPARE_STRATEGY_ENUM_NAME_H
#define SHADER_OBJECT_NODE_COMPARE_STRATEGY_ENUM_NAME_H

#include "CompareStrategyBase.h"

// NO MANAGER_LIBRARY_API on this class. It is app-side code that merely
// INHERITS from the Manager DLL -- wearing the DLL's export macro here makes it
// __declspec(dllimport) and the linker then wants a symbol Manager.dll never
// exports (C4273 + LNK2019). Same trap the camera port hit.

namespace Neelam::vk
{
	class ShaderObjectNodeCompareStrategyEnumName : public Azul::CompareStrategyBase
	{
	public:
		ShaderObjectNodeCompareStrategyEnumName() = default;
		ShaderObjectNodeCompareStrategyEnumName(const ShaderObjectNodeCompareStrategyEnumName &) = default;
		ShaderObjectNodeCompareStrategyEnumName &operator = (const ShaderObjectNodeCompareStrategyEnumName &) = default;
		virtual ~ShaderObjectNodeCompareStrategyEnumName() = default;

		virtual bool Compare(Azul::DLink *pRefNode, Azul::DLink *pTargetNode) override;
	};
}

#endif   // SHADER_OBJECT_NODE_COMPARE_STRATEGY_ENUM_NAME_H

// ---  End of File ---
