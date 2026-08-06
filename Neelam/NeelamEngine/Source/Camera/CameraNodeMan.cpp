//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CameraNodeMan.h"
#include "CameraNull.h"
#include "Camera.h"
#include "ManBase.h"
#include "DLinkMan.h"
#include "CameraNodeCompareStrategyEnumName.h"

namespace Neelam 
{
    CameraNodeMan* CameraNodeMan::posInstance = nullptr;
	Azul::CompareStrategyBase *CameraNodeMan::posEnumNameCompare = nullptr;

    CameraNodeMan::CameraNodeMan(int reserveNum, int reserveGrow)
        : Azul::ManBase(new Azul::DLinkMan(), new Azul::DLinkMan(), reserveNum, reserveGrow),
        poNodeCompare(nullptr),
        pCamOrthographic(nullptr),
        pCamPerspective(nullptr),
        moveSpeed(0.1f),
        zoomSpeed(0.05f)
    {
        // Pre?fill reserve pool so we dont new()/delete() at runtime
        this->proFillReservedPool(reserveNum);

        // comparison node stays around for lifetime of manager
        this->poNodeCompare = new CameraNode();
        // ensure compare node has a valid Camera so SetName/Compare are safe
        // CameraNull, not an arbitrary perspective camera -- this node only
        // ever carries a NAME for baseFind() to compare against, and the
        // null-object says so. (Heap, not CameraNull::Instance(): CameraNode
        // deletes the Camera it holds, and the singleton must not be deleted.)
        Camera* pCmpCam = new CameraNull();
        this->poNodeCompare->Set(Camera::Name::NullCamera, pCmpCam);
    }

    CameraNodeMan::~CameraNodeMan()
    {
        delete this->poNodeCompare;
        this->poNodeCompare = nullptr;

        Azul::Iterator* pIt = this->baseGetActiveIterator();

        Azul::DLink* pNode = pIt->First();

        // Walk through the nodes
        while (!pIt->IsDone())
        {
            CameraNode* pDeleteMe = (CameraNode*)pIt->Curr();
            pNode = pIt->Next();
            delete pDeleteMe;
        }

        pIt = this->baseGetReserveIterator();

        pNode = pIt->First();

        // Walk through the nodes
        while (!pIt->IsDone())
        {
            CameraNode* pDeleteMe = (CameraNode*)pIt->Curr();
            pNode = pIt->Next();
            delete pDeleteMe;
        }
      
    }

    //--------------------------------------------------------------
    // Singleton helpers
    //--------------------------------------------------------------
    void CameraNodeMan::Create(int reserveNum, int reserveGrow)
    {
        assert(reserveNum >= 0);
        assert(reserveGrow > 0);
        assert(posInstance == nullptr);

        if (posInstance == nullptr)
        {
            posInstance = new CameraNodeMan(reserveNum, reserveGrow);
        }

		if (posEnumNameCompare == nullptr)
		{
			posEnumNameCompare = new CameraNodeCompareStrategyEnumName();
		}
    }

    void CameraNodeMan::Destroy()
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        assert(pMan != nullptr);
        AZUL_UNUSED_VAR(pMan);

		delete CameraNodeMan::posEnumNameCompare;
		CameraNodeMan::posEnumNameCompare = nullptr;

        delete CameraNodeMan::posInstance;
        CameraNodeMan::posInstance = nullptr;
    }

    CameraNodeMan* CameraNodeMan::privGetInstance()
    {
        assert(posInstance != nullptr);
        return posInstance;
    }

    //--------------------------------------------------------------
    // Add / Find / Remove
    //--------------------------------------------------------------
    CameraNode* CameraNodeMan::Add(Camera::Name _name, Camera* pCamera)
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        assert(pMan);
        assert(pCamera);

        CameraNode* pNode = static_cast<CameraNode*>(pMan->baseAddToFront());
        pNode->Set(_name, pCamera);
        return pNode;
    }

    Camera* CameraNodeMan::Find(Camera::Name _name)
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        assert(pMan);

		// set strategy
		pMan->pCompareStrategy = CameraNodeMan::posEnumNameCompare;
		assert(pMan->pCompareStrategy);

        pMan->poNodeCompare->SetName(_name);
        CameraNode* pNode = static_cast<CameraNode*>(pMan->baseFind(pMan->poNodeCompare));
        
        if (pNode)
            return pNode->GetCamera();
        return nullptr;
    }

    void CameraNodeMan::Remove(CameraNode* pNode)
    {
        assert(pNode);
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        pMan->baseRemove(pNode);
    }


    void CameraNodeMan::Update()
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        pMan->ProcessInput();
        Azul::Iterator* pIt = pMan->baseGetActiveIterator();

        for (Azul::DLink* pNode = pIt->First(); !pIt->IsDone(); pNode = pIt->Next())
        {
            CameraNode* pCamNode = static_cast<CameraNode*>(pNode);
            Camera* pCam = pCamNode->GetCamera();
            assert(pCam);
            pCam->updateCamera();
        }
    }

    void CameraNodeMan::Dump()
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        assert(pMan);

        Debug::out("\n   ------ CameraNodeMan Dump ------\n");
        pMan->baseDump();
    }


    //--------------------------------------------------------------
    // Setters and Getters
    //--------------------------------------------------------------

    void CameraNodeMan::SetCurrent(Camera::Name name, Camera::Type type)
    {
        CameraNodeMan* pCamMan = CameraNodeMan::privGetInstance();
        assert(pCamMan);

        Camera* pCam = CameraNodeMan::Find(name);
        assert(pCam);

        switch (type)
        {
        case Camera::Type::PERSPECTIVE_3D:
            assert(pCam->getType() == Camera::Type::PERSPECTIVE_3D);
            pCamMan->pCamPerspective = pCam;
            break;

        case Camera::Type::ORTHOGRAPHIC_2D:
            assert(pCam->getType() == Camera::Type::ORTHOGRAPHIC_2D);
            pCamMan->pCamOrthographic = pCam;
            break;

        default:
            assert(false);
            break;
        }
    }

    void CameraNodeMan::SetMoveSpeed(float speed)
    {
        CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
        assert(pMan);
        pMan->moveSpeed = speed;
    }

    Camera* CameraNodeMan::GetCurrent(Camera::Type type)
    {
        Camera* pCam = nullptr;
        switch (type)
        {
        case Camera::Type::PERSPECTIVE_3D:
            pCam = CameraNodeMan::privGetInstance()->pCamPerspective;
            break;

        case Camera::Type::ORTHOGRAPHIC_2D:
            pCam = CameraNodeMan::privGetInstance()->pCamOrthographic;
            break;

        default:
            assert(false);
            break;
        }

        assert(pCam != nullptr);
        return pCam;
    }

    Azul::DLink* CameraNodeMan::derivedCreateNode()
    {
        return new CameraNode();
    }

    void CameraNodeMan::ProcessInput()
    {
        // grab the one active camera
        // Assuming we control the perspective camera with inputs
        Camera* pCam = this->pCamPerspective;
        if (!pCam)
            return;

        // get its helper data
        Azul::Vec3  up, tar, pos;
        Azul::Vec3  upNorm, forwardNorm, rightNorm;
        pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

        const float _moveSpeed = this->moveSpeed;
        const float _zoomSpeed = this->zoomSpeed;
        bool    moved = false;

        // Mouse input: separate control per button
        static bool  isDragLeft   = false;
        static bool  isDragRight  = false;
        static bool  isDragMiddle = false;
        static POINT lastLeft     = { 0, 0 };
        static POINT lastRight    = { 0, 0 };
        static POINT lastMiddle   = { 0, 0 };

        const float mouseSensitivity = 0.005f;

        // Left button: Y-axis rotation (yaw around up axis) using horizontal movement
        if (GetKeyState(VK_LBUTTON) & 0x8000)
        {
            POINT cur; GetCursorPos(&cur);
            if (!isDragLeft)
            {
                isDragLeft = true; lastLeft = cur;
            }
            else
            {
                int deltaX = cur.x - lastLeft.x;
                if (abs(deltaX) > 0)
                {
                    float yawDelta = deltaX * mouseSensitivity;
                    Azul::Trans  T1(tar);
                    Azul::Trans  T2(-tar);
                    Azul::Rot    R;  R.set(Azul::Axis::AxisAngle, upNorm, -yawDelta);
                    Azul::Mat4   M = T2 * R * T1;
                    pos = Azul::Vec4(pos, 1.0f) * M;
                    tar = Azul::Vec4(tar, 1.0f) * M;
                    up  = Azul::Vec4(up, 1.0f) * M;
                    moved = true;
                }
                lastLeft = cur;
            }
        }
        else
        {
            isDragLeft = false;
        }

        // Right button: Z-axis rotation (roll around forward axis) using horizontal movement
        if (GetKeyState(VK_RBUTTON) & 0x8000)
        {
            POINT cur; GetCursorPos(&cur);
            if (!isDragRight)
            {
                isDragRight = true; lastRight = cur;
            }
            else
            {
                int deltaX = cur.x - lastRight.x;
                if (abs(deltaX) > 0)
                {
                    float rollDelta = deltaX * mouseSensitivity;
                    Azul::Trans  T1(tar);
                    Azul::Trans  T2(-tar);
                    Azul::Rot    R;  R.set(Azul::Axis::AxisAngle, forwardNorm, -rollDelta);
                    Azul::Mat4   M = T2 * R * T1;
                    pos = Azul::Vec4(pos, 1.0f) * M;
                    tar = Azul::Vec4(tar, 1.0f) * M;
                    up  = Azul::Vec4(up, 1.0f) * M;
                    moved = true;
                }
                lastRight = cur;
            }
        }
        else
        {
            isDragRight = false;
        }

        // Middle button: X-axis rotation (pitch around right axis) using vertical movement
        if (GetKeyState(VK_MBUTTON) & 0x8000)
        {
            POINT cur; GetCursorPos(&cur);
            if (!isDragMiddle)
            {
                isDragMiddle = true; lastMiddle = cur;
            }
            else
            {
                int deltaY = cur.y - lastMiddle.y;
                if (abs(deltaY) > 0)
                {
                    float pitchDelta = deltaY * mouseSensitivity;
                    Azul::Trans  T1(tar);
                    Azul::Trans  T2(-tar);
                    Azul::Rot    R;  R.set(Azul::Axis::AxisAngle, rightNorm, pitchDelta);
                    Azul::Mat4   M = T2 * R * T1;
                    pos = Azul::Vec4(pos, 1.0f) * M;
                    tar = Azul::Vec4(tar, 1.0f) * M;
                    up  = Azul::Vec4(up, 1.0f) * M;
                    moved = true;
                }
                lastMiddle = cur;
            }
        }
        else
        {
            isDragMiddle = false;
        }

        // Keyboard input for camera translation (existing code)
        if (GetKeyState('W') & 0x8000)
        {
            Azul::Vec3 delta = forwardNorm * _moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('S') & 0x8000)
        {
            Azul::Vec3 delta = forwardNorm * _moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }

        if (GetKeyState('A') & 0x8000)
        {
            Azul::Vec3 delta = rightNorm * _moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }

        if (GetKeyState('D') & 0x8000)
        {
            Azul::Vec3 delta = rightNorm * _moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('E') & 0x8000)
        {
            Azul::Vec3 delta = upNorm * _moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('Q') & 0x8000)
        {
            Azul::Vec3 delta = upNorm * _moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }
        // zoom (fish-eye) 
        if (GetKeyState('C') & 0x8000)
        {
            float fov = pCam->GetFovY();
            pCam->SetFovY(fov - _zoomSpeed);
        }
        if (GetKeyState('Z') & 0x8000)
        {
            float fov = pCam->GetFovY();
            pCam->SetFovY(fov + _zoomSpeed);
        }

        // if anything changed, push it back into the camera
        if (moved)
        {
            pCam->SetHelper(up, tar, pos);
        }
    }

}

// --- End of File ---
