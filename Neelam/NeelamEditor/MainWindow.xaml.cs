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
    }
}