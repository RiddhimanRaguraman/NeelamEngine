//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "CameraNode.h"

namespace Neelam
{

    CameraNode::CameraNode()
        : Azul::DLink(),
        poCamera(nullptr)
    {
        this->privClear();
    }

    CameraNode::~CameraNode()
    {
        this->privClear();
    }

    void CameraNode::Set(Camera::Name name, Camera *pCam)
    {
        assert(pCam);
        this->poCamera = pCam;

        this->poCamera->SetName(name);
    }

    void CameraNode::SetName(Camera::Name _name)
    {
        this->poCamera->SetName(_name);
    }

    Camera *CameraNode::GetCamera()
    {
        return this->poCamera;
    }

    void CameraNode::privClear()
    {
        if(this->poCamera)
        {
            delete this->poCamera;
        }
        this->poCamera = nullptr;
    }

    // char*, not const char*, to match the Azul::DLink override it implements.
    // The cast is safe: Camera::GetName returns a string literal.
    char *CameraNode::GetName()
    {
        const char *pName = "CameraNode::<empty>";

        if(this->poCamera)
        {
            pName = this->poCamera->GetName();
        }

        return (char *)pName;
    }

    void CameraNode::Wash()
    {
        this->privClear();
    }



    void CameraNode::Dump()
    {
        Debug::out("      CameraNode(%p)\n", this);

        // Data:
        if(this->poCamera)
        {
            Debug::out("      Camera(%p) \n", this->poCamera);
            // was StringMe(this->poCamera->name) -- Camera::GetName() now
            // does that switch itself, so StringThis.h is no longer needed.
            Debug::out("      Name: %s \n", this->poCamera->GetName());
        }
        else
        {
            Debug::out("      Name: %s \n", "null");
        }

        Azul::DLink::Dump();
    }

}

// --- End of File ---
