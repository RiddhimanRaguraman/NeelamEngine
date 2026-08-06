//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#ifndef WINDOW_H
#define WINDOW_H

//---------------------------------------------------------------------------
// class Window
//
// Owns a single Win32 window: registers the window class, creates the HWND
// and pumps its message queue. Nothing Vulkan lives in here -- the window
// only hands out the HWND / HINSTANCE that Surface needs to build a
// VkSurfaceKHR from.
//
// Two ways to create it:
//   Create()      -- a standalone top-level window that OWNS the app lifetime.
//                    On close it posts WM_QUIT, dropping the standalone loop.
//   CreateChild() -- a child window parented to an HWND handed in from the C#
//                    / WPF editor (its HwndHost). WPF owns the thread's message
//                    loop, so this variant must NOT post WM_QUIT on destroy.
//                    Hand GetHandle() back to WPF's BuildWindowCore().
//
// Windows.h is already pulled in by the force-included Framework.h.
//---------------------------------------------------------------------------

namespace Neelam::vk
{
	class Window
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------
		Window();
		Window(const Window &) = delete;
		Window &operator = (const Window &) = delete;
		~Window();

		//-----------------------------------------------------------------
		// Lifetime
		//-----------------------------------------------------------------

		// Standalone top-level window. width/height are the CLIENT area size
		// -- the border is added on top of that.
		bool Create(const char *pTitle, int width, int height);

		// Embedded child window, parented to hParentWnd (from the WPF editor).
		// width/height are the client size; the parent controls placement.
		bool CreateChild(HWND hParentWnd, int width, int height);

		// Safe to call more than once; the destructor calls it too.
		void Destroy();

		//-----------------------------------------------------------------
		// Message pump
		//-----------------------------------------------------------------

		// Drains every pending message. Returns false once WM_QUIT arrives,
		// which is the signal to drop out of the standalone loop. In embedded
		// mode WPF pumps the messages instead -- do not call this there.
		bool ProcessMessages();

		//-----------------------------------------------------------------
		// Accessors
		//-----------------------------------------------------------------
		HWND GetHandle() const;
		HINSTANCE GetModule() const;

	private:
		// Static thunk: recovers the Window* stashed at creation and forwards
		// to privHandleMessage. See Window.cpp for the this-pointer routing.
		static LRESULT CALLBACK privWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		LRESULT privHandleMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		// The module this code is compiled into -- NeelamEngine.dll, not the
		// host exe. See Window.cpp for why that distinction matters.
		static HINSTANCE privGetOwnModule();

		// Shared helpers behind Create / CreateChild.
		bool privRegisterClass();
		bool privCreate(const char *pTitle, DWORD style, DWORD exStyle, HWND hParentWnd, int width, int height);

		// Name we register the window class under.
		static const char *const privClassName;

		// Data
		HWND      privHandle;
		HINSTANCE privModule;
		bool      privClassRegistered;
		bool      privIsChild;			// embedded: do not PostQuitMessage
	};
}

#endif   // WINDOW_H

// ---  End of File ---
