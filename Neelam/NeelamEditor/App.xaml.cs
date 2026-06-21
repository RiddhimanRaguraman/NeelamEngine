using System.Windows;
using NeelamEditor.GameProject;

namespace NeelamEditor
{
    public partial class App : Application
    {
        private void OnStartup(object sender, StartupEventArgs e)
        {
            var projectBrowser = new ProjectBrowserDialog();
            if (projectBrowser.ShowDialog() == false)
            {
                Shutdown();
            }
            else
            {
                var mainWindow = new MainWindow();
                mainWindow.Show();
            }
        }
    }
}
