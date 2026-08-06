//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CAMERA_NODE_MAN_H
#define CAMERA_NODE_MAN_H 

#include "ManBase.h"
#include "CameraNode.h"
#include "Camera.h"

// EngineDLLInterface.h / AZUL_ENGINE_LIBRARY_API dropped -- app source, not a DLL export.

namespace Neelam
{

	class CameraNodeMan : public Azul::ManBase
	{
	public:
		// public interface --------------------------------------------------
		static void         Create(int reserveNum = 0, int reserveGrow = 1);
		static void         Destroy();

		static CameraNode* Add(Camera::Name _name, Camera* pCamera);
		static Camera* Find(Camera::Name _name);
		static void         Remove(CameraNode* pNode);
		static void         Update();                 // call once per frame
		static void         Dump();

		// big four deleted - manager lives through singleton ----------------
		CameraNodeMan(const CameraNodeMan&) = delete;
		CameraNodeMan& operator=(const CameraNodeMan&) = delete;
		virtual ~CameraNodeMan();

		static void         SetCurrent(Camera::Name name, Camera::Type type);
		static Camera*		GetCurrent(Camera::Type type);
		static void			SetMoveSpeed(float speed);

	private:            // only singleton can create/destroy itself
		CameraNodeMan(int reserveNum, int reserveGrow);
		CameraNodeMan() = delete;
		
		static CameraNodeMan* privGetInstance();

		void ProcessInput();

		// ManBase override --------------------------------------------------
		virtual Azul::DLink* derivedCreateNode() override;

	private:
		CameraNode* poNodeCompare;
		static CameraNodeMan* posInstance;
		static Azul::CompareStrategyBase *posEnumNameCompare;

		Camera* pCamOrthographic;
		Camera* pCamPerspective;

		float moveSpeed;
		float zoomSpeed;
	};
}

#endif

// --- End of File ---
