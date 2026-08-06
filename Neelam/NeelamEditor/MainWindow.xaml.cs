using System.ComponentModel;
using System.Text;
using System.Windows;
using NeelamEditor.EngineWrapper;
using NeelamEditor.GameProject;

namespace NeelamEditor
{
    public partial class MainWindow : Window
    {
        // DataContext is injected by App.OnStartup after the project browser closes.
        public MainWindow()
        {
            InitializeComponent();
            this.Loaded += OnMainWindowLoaded;
            this.Closing += OnMainWindowClosing;
        }

        private void OnMainWindowLoaded(object sender, RoutedEventArgs e)
        {
            this.Loaded -= OnMainWindowLoaded;
            OpenProjectBrowserDialog();
        }
        // Tear the active project down on shell close.
        private void OnMainWindowClosing(object sender, CancelEventArgs e)
        {
            Closing -= OnMainWindowClosing;

            // Belt and braces for the renderer. RenderView.Unloaded normally disposes
            // the HwndHost, which shuts the engine down -- but WPF does not guarantee
            // Unloaded fires for the content tree when a window closes. Skipping
            // Shutdown would leave Vulkan objects alive at process exit and turn the
            // framework's leak report red. EngineShutdown is idempotent, so calling it
            // here as well is free when the view already did it.
            EngineAPI.ShutdownRenderer();

            Project.Current?.Unload();
        }
        private void OpenProjectBrowserDialog()
        {
            var projectBrowser = new ProjectBrowserDialog();
            if (projectBrowser.ShowDialog() == false || projectBrowser.DataContext == null)
            {
                Application.Current.Shutdown();
            }
            else
            {
                Project.Current?.Unload();
                DataContext = projectBrowser.DataContext;
            }
        }

        // Custom-titlebar button handlers (we removed the OS chrome via WindowStyle="None").
        private void OnMinimize_Click(object sender, RoutedEventArgs e)
            => WindowState = WindowState.Minimized;

        private void OnMaximize_Click(object sender, RoutedEventArgs e)
            => WindowState = WindowState == WindowState.Maximized
                ? WindowState.Normal
                : WindowState.Maximized;

        private void OnClose_Click(object sender, RoutedEventArgs e) => Close();
    }
}