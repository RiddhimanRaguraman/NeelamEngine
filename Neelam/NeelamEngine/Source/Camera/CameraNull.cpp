//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CameraNull.h"

namespace Neelam
{

	CameraNull::CameraNull()
		: Camera(Camera::Type::PERSPECTIVE_3D)
	{

	}

	CameraNull::~CameraNull()
	{
		// remove anything dynamic here
	}
	CameraNull& CameraNull::Instance()
	{
		static CameraNull theNull;
		return theNull;
	}
}

// --- End of File ---
