using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;
using System.IO;

namespace NeelamEditor.GameProject
{
    // Code-behind for the Create-Project tab. View logic only — VM is NewProject.
    public partial class NewProjectView : UserControl
    {
        public NewProjectView()
        {
            InitializeComponent();
        }

        // Build the project, register it in the recent list, close the dialog
        // with DialogResult=true on success so the editor shell knows to load it.
        private void OnCreate_Button_Click (object sender, RoutedEventArgs e)
        {
            var vm = DataContext as NewProject;
            var projectPath = vm.CreateProject(templateListBox.SelectedItem as ProjectTemplate);
            bool dialogResult = false;
            var win = Window.GetWindow(this);
            if(!string.IsNullOrEmpty(projectPath))
            {
                dialogResult = true;
                var project = OpenProject.Open(new ProjectData() { ProjectName = vm.ProjectName, ProjectPath = projectPath });
                win.DataContext = project;

            }
            win.DialogResult = dialogResult;
            win.Close();
        }

        // Opens the native Windows folder picker; the selection is pushed into
        // the VM's ProjectPath, which re-runs validation through its setter.
        private void OnBrowse_Button_Click(object sender, RoutedEventArgs e)
        {
            var vm = DataContext as NewProject;

            var dialog = new OpenFolderDialog
            {
                Title = "Select project location",
                Multiselect = false,
            };

            // Seed the dialog with the current path if it points at a real folder,
            // otherwise let the dialog use its own default (last-used location).
            if (Directory.Exists(vm.ProjectPath))
            {
                dialog.InitialDirectory = vm.ProjectPath;
            }

            if (dialog.ShowDialog(Window.GetWindow(this)) == true)
            {
                // OpenFolderDialog returns a path without a trailing separator;
                // ValidateProjectPath happily appends one, so either form is fine.
                vm.ProjectPath = dialog.FolderName;
            }
        }
    }
}
