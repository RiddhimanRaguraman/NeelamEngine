using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Interop;
using System.Windows.Media;
using NeelamEditor.EngineWrapper;

namespace NeelamEditor.Editors
{
    // Hosts the engine's native render surface.
    //
    // HwndHost is WPF's airspace bridge: it carves a hole in the WPF visual tree
    // and lets a raw HWND own those pixels. That is exactly the shape the engine
    // was built for -- Window::CreateChild makes a WS_CHILD window and never
    // posts WM_QUIT, so the host keeps ownership of the message loop.
    internal sealed class EngineHwndHost : HwndHost
    {
        private bool _ticking;

        // WPF calls this once the control has a real parent window. Bringing the
        // engine up HERE (rather than in the RenderView constructor) is what makes
        // the child/parent relationship correct: the engine needs the parent HWND
        // at CreateWindowEx time, and this is the first moment it exists.
        protected override HandleRef BuildWindowCore(HandleRef hwndParent)
        {
            var hwnd = EngineAPI.InitializeRenderer(hwndParent.Handle);

            // Drive frames off the composition clock. WPF raises this on the UI
            // thread, which is the same thread that just called Initialize -- so
            // the engine's "all Vulkan on one thread" rule is satisfied for free.
            CompositionTarget.Rendering += OnRendering;
            _ticking = true;

            return new HandleRef(this, hwnd);
        }

        // HwndHost's contract is that this destroys the window. EngineShutdown does,
        // via Engine::Shutdown -> Window::Destroy, after tearing Vulkan down in
        // reverse order -- so there is nothing to DestroyWindow here afterwards.
        protected override void DestroyWindowCore(HandleRef hwnd)
        {
            if (_ticking)
            {
                CompositionTarget.Rendering -= OnRendering;
                _ticking = false;
            }

            EngineAPI.ShutdownRenderer();
        }

        // Resizing needs no code: WPF repositions the child HWND for us, the frame
        // loop gets VK_ERROR_OUT_OF_DATE_KHR on the next present, and Engine::Tic
        // rebuilds the swapchain from the window's current client rect.
        private void OnRendering(object sender, EventArgs e) => EngineAPI.Tic();
    }

    // WPF host for the Vulkan renderer.
    public partial class RenderView : UserControl
    {
        private EngineHwndHost _host;

        public RenderView()
        {
            InitializeComponent();

            // Deferred to Loaded so the designer never tries to spin up Vulkan, and
            // so the host is only built when the view is genuinely on screen.
            //
            // Neither handler unsubscribes: WPF raises Loaded/Unloaded every time a
            // control is re-parented, not just once. Unsubscribing after the first
            // pair would leave a permanently black viewport the next time the view
            // came back. Both are written to be idempotent instead.
            Loaded += OnLoaded;
            Unloaded += OnUnloaded;
        }

        private void OnLoaded(object sender, RoutedEventArgs e)
        {
            if (_host != null) return;

            _host = new EngineHwndHost();
            _surfaceHost.Children.Add(_host);
        }

        // Dropping the HwndHost is what calls DestroyWindowCore, which shuts the
        // engine down. Without this the surface would outlive the view -- closing a
        // project and opening another would leave the first renderer running.
        private void OnUnloaded(object sender, RoutedEventArgs e)
        {
            if (_host == null) return;

            _surfaceHost.Children.Remove(_host);
            _host.Dispose();
            _host = null;
        }
    }
}
