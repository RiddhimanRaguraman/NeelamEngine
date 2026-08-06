//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef CAMERA_H
#define CAMERA_H

// was a DX11 engine-DLL class (EngineDLLInterface.h + AZUL_ENGINE_LIBRARY_API).
// Here the camera is app source, not a DLL export, so both are gone.
// Vulkan types (VkCommandBuffer, vkCmdSetViewport) come from the force-included
// Framework.h -- see its VULKAN FRAMEWORK section.
#include "MathEngine.h"

namespace Neelam
{

	class Camera : public Align16
	{
	public:
		enum class Type
		{
			PERSPECTIVE_3D,
			ORTHOGRAPHIC_2D
		};

		enum class Name
		{
			CAMERA_0,
			CAMERA_1,
			CAMERA_2,
			NOT_INITIALIZED,
			NullCamera
		};

	public:
		// Default constructor
		Camera() = delete;
		Camera(const Camera &) = delete;
		Camera &operator = (const Camera &) = delete;
		virtual ~Camera();
		Camera(Camera::Type _camType);

		// Setup on single camera
		void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
		// 2D Camera
		void setOrthographic(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax);

		
		// under DX11 this pushed the viewport straight to the immediate
		// context (RSSetViewports). Vulkan has no immediate context -- viewport is
		// DYNAMIC STATE recorded into a command buffer -- so this now only STORES
		// the rectangle, and SetActive() below applies it during frame recording.
		void setViewport(const int inX, const int inY, const int width, const int height);

		// replaces privSetViewState()/RSSetViewports. Records this camera's
		// viewport + scissor into the command buffer. Mirrors the project's
		// existing ShaderObject::SetActive(cmd) idiom.
		void SetActive(VkCommandBuffer cmd) const;

		void setOrientAndPosition(const Azul::Vec3 &Up_vect, const Azul::Vec3 &inLookAt_pt, const Azul::Vec3 &pos_pt);

		// update camera system
		void updateCamera(void);

		// Get the matrices for rendering
		Azul::Mat4 &getViewMatrix();
		Azul::Mat4 &getProjMatrix();

		// accessors
		void getPos(Azul::Vec3 &outPos) const;
		void getDir(Azul::Vec3 &outDir) const;
		void getUp(Azul::Vec3 &outUp) const;
		void getLookAt(Azul::Vec3 &outLookAt) const;
		void getRight(Azul::Vec3 &outRight) const;

		int getScreenWidth() const;
		int getScreenHeight() const;

		// Why no SETS?  Pos,Dir,Up,LookAt, Right
		//   They have to be adjust together in setOrientAndPosition()

		// Aspect ratio only. Use these for a window resize rather than
		// setPerspective(), which also rewrites fovy and would stomp the zoom.
		// Actual field of view is GetFovY / SetFovY.
		void getAspectRatio(float &Value) const;
		void setAspectRatio(const float Value);

		void getNearDist(float &Value) const;
		void setNearDist(const float Value);

		// accessors

		Camera::Type getType() const;

		// Returns a string literal, not a static buffer -- safe to call from any
		// thread and safe to use twice in one printf.
		const char *GetName() const;
		void SetName(Camera::Name name);

		// helper functions
		void GetHelper(Azul::Vec3 &up, Azul::Vec3 &tar, Azul::Vec3 &pos, Azul::Vec3 &upNorm, Azul::Vec3 &forwardNorm, Azul::Vec3 &rightNorm);
		void SetHelper(Azul::Vec3 &up, Azul::Vec3 &tar, Azul::Vec3 &pos);

		void getNearTopLeft(Azul::Vec3 &vOut) const;
		void getNearTopRight(Azul::Vec3 &vOut) const;
		void getNearBottomLeft(Azul::Vec3 &vOut) const;
		void getNearBottomRight(Azul::Vec3 &vOut) const;
		void getFarTopLeft(Azul::Vec3 &vOut) const;
		void getFarTopRight(Azul::Vec3 &vOut) const;
		void getFarBottomLeft(Azul::Vec3 &vOut) const;
		void getFarBottomRight(Azul::Vec3 &vOut) const;
		float GetFovY() const
		{
			return this->fovy;
		}
		void SetFovY(float f)
		{
			this->fovy = f;
			this->privDirty = true;		// Z/C zoom -- must rebuild the projection
		}

	private:  // methods should never be public
		// privSetViewState() is gone -- see SetActive() above.
		void privCalcPlaneHeightWidth(void);
		void privCalcFrustumVerts(void);
		void privCalcFrustumCollisionNormals(void);
		void privUpdateProjectionMatrix(void);
		void privUpdateViewMatrix(void);

	private:  // data  (Keep it private)

		char vPtrPad[8]; // virtual ptr adjustment to keep aligned

		// -------------------------------------------------------
		// 16-bit aligned data below this point:
		// -------------------------------------------------------

		// Projection Matrix
		Azul::Mat4	projMatrix;
		Azul::Mat4	viewMatrix;

		// camera unit vectors (up, dir, right)
		Azul::Vec3	vDir;
		Azul::Vec3	vRight;  // derived by up and dir


		Azul::Vec3	vUp;      // Up vector
		Azul::Vec3	vPos;     // pos pt
		Azul::Vec3	vLookAt;  // target pt

		// world space coords for viewing frustum
		Azul::Vec3	nearTopLeft;
		Azul::Vec3	nearTopRight;
		Azul::Vec3	nearBottomLeft;

		Azul::Vec3	nearBottomRight;
		Azul::Vec3	farTopLeft;
		Azul::Vec3	farTopRight;
		Azul::Vec3	farBottomLeft;

		Azul::Vec3	farBottomRight;

		// Normals of the frustum
		Azul::Vec3	frontNorm;
		Azul::Vec3	backNorm;
		Azul::Vec3	rightNorm;

		Azul::Vec3	leftNorm;
		Azul::Vec3	topNorm;
		Azul::Vec3	bottomNorm;

		// -------------------------------------------------------
		// unaligned data below this point:
		// -------------------------------------------------------

		Camera::Type camType;

		// Define the frustum inputs
		float	nearDist;
		float	farDist;
		float	fovy;  // aka view angle along y axis in radians
		float	aspectRatio;

		// Screen size in world space
		float	near_height;
		float	near_width;
		float	far_height;
		float	far_width;

		// Ortho hacks 
		float	xMin;
		float	yMin;
		float	zMin;
		float	xMax;
		float	yMax;
		float	zMax;

		// viewports
		int		viewport_x;
		int		viewport_y;
		int		viewport_width;
		int		viewport_height;

		// Set by every mutator; updateCamera() early-outs when clear.
		bool	privDirty;

		// Name
	public:
		Camera::Name name;

		// Align16 with hand-balanced padding: privDirty above took one byte, so
		// this dropped from 12 to 11. Adjust the two together.
		char pad[11];
	};

}


/*

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

        const float moveSpeed = 0.1f;
        const float zoomSpeed = 0.05f;    // adjust to taste
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
            Azul::Vec3 delta = forwardNorm * moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('S') & 0x8000)
        {
            Azul::Vec3 delta = forwardNorm * moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }

        if (GetKeyState('A') & 0x8000)
        {
            Azul::Vec3 delta = rightNorm * moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }

        if (GetKeyState('D') & 0x8000)
        {
            Azul::Vec3 delta = rightNorm * moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('E') & 0x8000)
        {
            Azul::Vec3 delta = upNorm * moveSpeed;
            pos = pos + delta;
            tar = tar + delta;
            up  = up  + delta;
            moved = true;
        }

        if (GetKeyState('Q') & 0x8000)
        {
            Azul::Vec3 delta = upNorm * moveSpeed;
            pos = pos - delta;
            tar = tar - delta;
            up  = up  - delta;
            moved = true;
        }
        // zoom (fish-eye)
        if (GetKeyState('C') & 0x8000)
        {
            float fov = pCam->GetFovY();
            pCam->SetFovY(fov - zoomSpeed);
        }
        if (GetKeyState('Z') & 0x8000)
        {
            float fov = pCam->GetFovY();
            pCam->SetFovY(fov + zoomSpeed);
        }

        // if anything changed, push it back into the camera
        if (moved)
        {
            pCam->SetHelper(up, tar, pos);
        }
    }


*/

#endif

// --- End of File ---
