using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace NeelamEditor.GameProject
{
    // Modal shell shown at startup. Hosts Open / Create tabs and a custom title bar.
    public partial class ProjectBrowserDialog : Window
    {
        public ProjectBrowserDialog()
        {
            InitializeComponent();
            Loaded += OnProjectBrowserDialogLoaded;
        }

        private void OnProjectBrowserDialogLoaded(object sender, RoutedEventArgs e)
        {
            Loaded -= OnProjectBrowserDialogLoaded;
            if(OpenProject.Projects.Any())
            {
                openProjectButton.IsEnabled = false;
                openProjectView.Visibility = Visibility.Hidden;
                OnToggleButton_Click(createProjectButton, new RoutedEventArgs());
                
            }
        }

        // Tab switcher. Slides the content row by ±800px to swap between the
        // OpenProjectView and NewProjectView; the parent grid clips the overflow.
        private void OnToggleButton_Click(object sender, RoutedEventArgs e)
        {
            if (sender == openProjectButton)
            {
                if (createProjectButton.IsChecked == true)
                {
                    createProjectButton.IsChecked = false;
                    browsercontent.Margin = new Thickness(0);
                }
                openProjectButton.IsChecked = true;
            }
            else
            {
                if (openProjectButton.IsChecked == true)
                {
                    openProjectButton.IsChecked = false;
                    browsercontent.Margin = new Thickness(-800,0,0,0);
                }
                createProjectButton.IsChecked = true;
            }
        }

        // Custom title-bar close button (system chrome is hidden via WindowChrome).
        private void OnCloseButton_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
