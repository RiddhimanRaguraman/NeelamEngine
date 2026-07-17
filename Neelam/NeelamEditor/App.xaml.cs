using System.Windows;
using NeelamEditor.EngineWrapper;
using NeelamEditor.GameProject;

namespace NeelamEditor
{
    public partial class App : Application
    {
        private void OnStartup(object sender, StartupEventArgs e)
        {
            // Kick the engine DLL load now so it overlaps with the project browser
            // dialog, instead of stalling the first click that needs it.
            EngineAPI.Preload();

            var mainWindow = new MainWindow();
            mainWindow.Show();
        }
    }
}