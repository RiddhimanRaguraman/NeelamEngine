//-----------------------------------------------------------------
// Copyright 2026 by Riddhiman Raguraman
//-----------------------------------------------------------------

#include "Window.h"

namespace Neelam::vk
{
	const char *const Window::privClassName = "NeelamVulkanWindow";

	//-----------------------------------------------------------------
	// The HINSTANCE the window class is registered under.
	//
	// NOT GetModuleHandle(nullptr). That returns the EXE, and this code now
	// lives in NeelamEngine.dll: privWndProc is a DLL address, so binding the
	// class to the EXE would leave a dangling window proc registered under the
	// host's HINSTANCE if the DLL is ever unloaded (the C# editor will do
	// exactly that). It would also collide the moment a host registers a class
	// of its own by the same name.
	//
	// Taking the module FROM an address inside this DLL gets it right in every
	// build shape -- DLL, static lib folded into an exe, or the exe itself --
	// with no DllMain plumbing. UNCHANGED_REFCOUNT because we only want the
	// handle, not to pin the module loaded.
	//-----------------------------------------------------------------
	HINSTANCE Window::privGetOwnModule()
	{
		HMODULE hModule = nullptr;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
						  GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
						  reinterpret_cast<LPCSTR>(&Window::privWndProc),
						  &hModule);

		assert(hModule);
		return (HINSTANCE)hModule;
	}

	Window::Window()
		: privHandle(nullptr),
		  privModule(nullptr),
		  privClassRegistered(false),
		  privIsChild(false)
	{
	}

	Window::~Window()
	{
		this->Destroy();
	}

	//-----------------------------------------------------------------
	// Standalone: a top-level overlapped window that owns the app lifetime.
	//-----------------------------------------------------------------
	bool Window::Create(const char *pTitle, int width, int height)
	{
		this->privModule  = Window::privGetOwnModule();
		this->privIsChild = false;

		if (!this->privRegisterClass())
		{
			return false;
		}

		return this->privCreate(pTitle, WS_OVERLAPPEDWINDOW, 0, nullptr, width, height);
	}

	//-----------------------------------------------------------------
	// Embedded: a child window inside an HWND supplied by the WPF editor.
	//-----------------------------------------------------------------
	bool Window::CreateChild(HWND hParentWnd, int width, int height)
	{
		this->privModule  = Window::privGetOwnModule();
		this->privIsChild = true;

		if (!this->privRegisterClass())
		{
			return false;
		}

		// WS_CHILD + WS_VISIBLE, clipped to siblings so the editor can lay
		// other native panes over/around it without tearing.
		const DWORD style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
		return this->privCreate("", style, 0, hParentWnd, width, height);
	}

	void Window::Destroy()
	{
		if (this->privHandle != nullptr)
		{
			DestroyWindow(this->privHandle);
			this->privHandle = nullptr;
		}

		if (this->privClassRegistered)
		{
			UnregisterClass(Window::privClassName, this->privModule);
			this->privClassRegistered = false;
		}
	}

	bool Window::ProcessMessages()
	{
		MSG msg;

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return false;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return true;
	}

	HWND Window::GetHandle() const
	{
		return this->privHandle;
	}

	HINSTANCE Window::GetModule() const
	{
		return this->privModule;
	}

	//-----------------------------------------------------------------
	// Register the window class once. Idempotent across both Create paths.
	//-----------------------------------------------------------------
	bool Window::privRegisterClass()
	{
		if (this->privClassRegistered)
		{
			return true;
		}

		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = Window::privWndProc;
		wc.hInstance = this->privModule;
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

		// A background brush gives a clean fill while there is no renderer yet.
		// Once Render() clears the swapchain every frame, set this to nullptr
		// to avoid the OS repaint fighting Vulkan (flicker on resize).
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wc.lpszClassName = Window::privClassName;

		if (RegisterClassEx(&wc) == 0)
		{
			Debug::out("Window: RegisterClassEx failed (%lu)\n", GetLastError());
			return false;
		}

		this->privClassRegistered = true;
		return true;
	}

	//-----------------------------------------------------------------
	// Shared CreateWindowEx. Passes `this` as lpParam so the static WndProc
	// can stash it on WM_NCCREATE (see privWndProc).
	//-----------------------------------------------------------------
	bool Window::privCreate(const char* pTitle, DWORD style, DWORD exStyle, HWND hParentWnd, int width, int height)
	{
		int outerW = width;
		int outerH = height;
		int posX = CW_USEDEFAULT;
		int posY = CW_USEDEFAULT;

		if (hParentWnd == nullptr)
		{
			// Top-level: CreateWindowEx takes the OUTER size, so grow the
			// requested client area by the border metrics for this style.
			RECT rect = { 0, 0, width, height };
			AdjustWindowRect(&rect, style, FALSE);
			outerW = rect.right - rect.left;
			outerH = rect.bottom - rect.top;
		}
		else
		{
			// Child: no border, and coordinates are relative to the parent's
			// client area. Sit at the top-left; the editor resizes us later.
			posX = 0;
			posY = 0;
		}

		this->privHandle = CreateWindowEx(
			exStyle,
			Window::privClassName,
			pTitle,
			style,
			posX,
			posY,
			outerW,
			outerH,
			hParentWnd,
			nullptr,
			this->privModule,
			this);				// lpParam -> arrives in WM_NCCREATE

		if (this->privHandle == nullptr)
		{
			Debug::out("Window: CreateWindowEx failed (%lu)\n", GetLastError());
			return false;
		}

		ShowWindow(this->privHandle, SW_SHOW);
		UpdateWindow(this->privHandle);

		return true;
	}

	//-----------------------------------------------------------------
	// Static thunk. On WM_NCCREATE (the first message a window gets) the
	// Window* we passed as lpParam is tucked into GWLP_USERDATA; every later
	// message pulls it back out and dispatches to the instance. This is the
	// standard way to give a C-style WndProc access to `this` -- and it is
	// what a later WM_SIZE handler will use to reach the swapchain.
	//-----------------------------------------------------------------
	LRESULT CALLBACK Window::privWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT *>(lParam);
			Window *pWindow = reinterpret_cast<Window *>(pCreate->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
		}

		Window *pWindow = reinterpret_cast<Window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		if (pWindow != nullptr)
		{
			return pWindow->privHandleMessage(hwnd, msg, wParam, lParam);
		}

		// Messages before WM_NCCREATE arrive with no instance yet.
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	// One viewport window, so a single static tracks its focus state.
	bool Window::privHasFocus = false;

	bool Window::HasFocus()
	{
		return Window::privHasFocus;
	}

	LRESULT Window::privHandleMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_KEYDOWN:
			// ESC quits -- routed through WM_CLOSE so it takes the EXACT same
			// path as the title-bar close button:
			//     WM_CLOSE -> DestroyWindow -> WM_DESTROY -> PostQuitMessage
			//   -> ProcessMessages() returns false -> Engine::Run -> Shutdown()
			// That matters: quitting via PostQuitMessage directly (as the old
			// Azul engine does from WM_CHAR) leaves the HWND alive and skips
			// this window's own teardown, so the two exits would not match.
			//
			// Standalone only. Hosted as a child in the editor, ESC belongs to
			// the host -- tearing the render surface out from under WPF is not
			// ours to do, and WM_DESTROY below would refuse to quit anyway.
			//
			// WM_KEYDOWN rather than Azul's WM_CHAR: ESC only produces a WM_CHAR
			// because its ASCII (27) happens to equal VK_ESCAPE, and that path
			// needs TranslateMessage. WM_KEYDOWN says what it means.
			if (wParam == VK_ESCAPE && !this->privIsChild)
			{
				Debug::out("Window: ESC -> quit\n");
				PostMessage(hwnd, WM_CLOSE, 0, 0);
				return 0;
			}
			break;		// every other key -> DefWindowProc

		case WM_CLOSE:
			DestroyWindow(hwnd);
			return 0;

		case WM_DESTROY:
			// The handle is gone now -- null it so Destroy() does not call
			// DestroyWindow on a stale HWND.
			this->privHandle = nullptr;

			// Only a standalone top-level window drives the message loop, so
			// only it may quit it. A child window in the editor must not, or
			// PostQuitMessage would tear down WPF's whole message loop.
			if (!this->privIsChild)
			{
				PostQuitMessage(0);
			}
			return 0;

		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		case WM_MBUTTONDOWN:
			// A WS_CHILD window does not take keyboard focus on click by default.
			// Do it explicitly so clicking the viewport makes it the input context
			// (and HwndHost relays the focus move to WPF). Standalone windows get
			// focus from normal activation, so only the child needs this.
			if (this->privIsChild)
			{
				SetFocus(hwnd);
			}
			break;

		case WM_SETFOCUS:
			Window::privHasFocus = true;
			break;

		case WM_KILLFOCUS:
			Window::privHasFocus = false;
			break;

		default:
			break;
		}

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

// ---  End of File ---
