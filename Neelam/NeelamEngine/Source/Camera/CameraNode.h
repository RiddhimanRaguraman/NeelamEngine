//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CAMERA_NODE_H
#define CAMERA_NODE_H
// EngineDLLInterface.h / AZUL_ENGINE_LIBRARY_API dropped -- app source, not a DLL export.

#include "DLink.h"
#include "Camera.h"

namespace Neelam
{

	class CameraNode : public Azul::DLink
	{
	public:
		CameraNode();
		CameraNode(const CameraNode &) = delete;
		CameraNode &operator = (const CameraNode &) = delete;
		virtual ~CameraNode();

		void Set(Camera::Name name, Camera *pCam);
		void SetName(Camera::Name _name);
		Camera *GetCamera();

		virtual char *GetName() override;
		virtual void Wash() override;

		virtual void Dump() override;

	private:
		void privClear();

		//--------------------------------------------------
		// Data
		//--------------------------------------------------
		Camera *poCamera;
	};

}

#endif

// --- End of File ---
