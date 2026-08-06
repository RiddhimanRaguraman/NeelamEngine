//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CAMERA_NULL_H
#define CAMERA_NULL_H
// EngineDLLInterface.h / AZUL_ENGINE_LIBRARY_API dropped -- app source, not a DLL export.

#include "Camera.h"

namespace Neelam
{

	class CameraNull : public Camera
	{
	public:
		CameraNull();
		CameraNull(const CameraNull &) = delete;
		CameraNull &operator=(const CameraNull &other) = delete;
		virtual ~CameraNull();

		static CameraNull& Instance();


	private:

	};

}

#endif

// --- End of File ---
