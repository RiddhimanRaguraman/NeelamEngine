//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef Camera_NODE_Compare_Strategy_Enum_Name_H
#define Camera_NODE_Compare_Strategy_Enum_Name_H

#include "Manager_DLLInterface.h"
#include "CompareStrategyBase.h"

namespace Neelam
{
	class CameraNodeCompareStrategyEnumName : public Azul::CompareStrategyBase
	{
	public:

		CameraNodeCompareStrategyEnumName() = default;
		CameraNodeCompareStrategyEnumName(const CameraNodeCompareStrategyEnumName &) = default;
		CameraNodeCompareStrategyEnumName &operator = (const CameraNodeCompareStrategyEnumName &) = default;
		virtual ~CameraNodeCompareStrategyEnumName() = default;

		virtual bool Compare(Azul::DLink *pRefNode, Azul::DLink *pTargetNode) override;

	};
}

#endif

// --- End of File ---
