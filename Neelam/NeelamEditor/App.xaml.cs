using System.IO;
using System.Windows;
using System.Windows.Threading;
using NeelamEditor.EngineWrapper;
using NeelamEditor.GameProject;

namespace NeelamEditor
{
    public partial class App : Application
    {
        private void OnStartup(object sender, StartupEventArgs e)
        {
            // Several ctors (NewProject, OpenProject) log-and-rethrow on bad installs.
            // Those throws land in WPF event handlers, where an unhandled exception kills
            // the process with no window and no message -- a packaged build just "does
            // nothing", and the only trace is an 0xe0434352 in Event Viewer. Catch them
            // here so the failure is readable.
            DispatcherUnhandledException += OnDispatcherUnhandledException;
            AppDomain.CurrentDomain.UnhandledException += (s, args) =>
                ReportFatal(args.ExceptionObject as Exception);

            // Kick the engine DLL load now so it overlaps with the project browser
            // dialog, instead of stalling the first click that needs it.
            EngineAPI.Preload();

            var mainWindow = new MainWindow();
            mainWindow.Show();
        }

        private void OnDispatcherUnhandledException(object sender, DispatcherUnhandledExceptionEventArgs e)
        {
            ReportFatal(e.Exception);
            e.Handled = true;   // we've told the user; shut down cleanly rather than crash
            Shutdown(1);
        }

        // Show the fault and drop a copy next to the exe, so a user can send the file
        // instead of describing the symptom.
        private static void ReportFatal(Exception ex)
        {
            var text = ex?.ToString() ?? "Unknown fatal error.";

            try
            {
                var log = Path.Combine(AppContext.BaseDirectory, "NeelamEditor.crash.log");
                File.WriteAllText(log, $"{DateTime.Now:u}{Environment.NewLine}{text}");
            }
            catch { /* logging must never mask the original fault */ }

            MessageBox.Show(text, "NeelamEditor - unhandled error",
                            MessageBoxButton.OK, MessageBoxImage.Error);
        }
    }
}