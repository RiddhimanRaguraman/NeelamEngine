using System.ComponentModel;
using System.Text;
using System.Windows;
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