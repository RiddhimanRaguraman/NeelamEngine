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
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace NeelamEditor.GameProject
{
    // Modal shell shown at startup. Hosts Open / Create tabs and a custom title bar.
    public partial class ProjectBrowserDialog : Window
    {
        // Shared easing for both stages of the tab transition.
        private readonly CubicEase _easing = new CubicEase { EasingMode = EasingMode.EaseInOut };

        public ProjectBrowserDialog()
        {
            InitializeComponent();
            Loaded += OnProjectBrowserDialogLoaded;
        }

        private void OnProjectBrowserDialogLoaded(object sender, RoutedEventArgs e)
        {
            Loaded -= OnProjectBrowserDialogLoaded;

            // Seat the glow under the initially-checked tab with no animation, so the
            // first real switch has a valid Canvas.Left to animate from.
            MoveGlow(openProjectButton, animate: false);

            // No recent projects yet → there's nothing to open. Disable the Open tab
            // and drop the user onto Create Project (this one animates across).
            if (!OpenProject.Projects.Any())
            {
                openProjectButton.IsEnabled = false;
                openProjectView.Visibility = Visibility.Hidden;
                OnToggleButton_Click(createProjectButton, new RoutedEventArgs());
            }
        }

        // Left offset of a tab within the glow canvas (its live layout position).
        private double TabLeft(ToggleButton tab)
            => tab.TransformToVisual(tabGlowCanvas).Transform(new Point(0, 0)).X;

        // Slide the accent glow under the given tab, sized to it. animate:false
        // snaps (used to initialize); otherwise it eases (0.2s).
        private void MoveGlow(ToggleButton tab, bool animate)
        {
            highlightRect.Width = tab.ActualWidth;
            var to = TabLeft(tab);
            if (!animate)
            {
                highlightRect.BeginAnimation(Canvas.LeftProperty, null); // release any clock
                Canvas.SetLeft(highlightRect, to);
                return;
            }
            var from = Canvas.GetLeft(highlightRect);
            if (double.IsNaN(from)) from = to;
            highlightRect.BeginAnimation(Canvas.LeftProperty,
                new DoubleAnimation(from, to, new Duration(TimeSpan.FromSeconds(0.2)))
                { EasingFunction = _easing });
        }

        // Two-stage transition, matching the Primal feel: the glow leads (0.2s),
        // then on its completion the content panel slides to the target margin
        // (0.4s). The panel holds OpenProjectView + NewProjectView side by side,
        // so revealing Create means shifting left by the Open view's width.
        private void AnimateTo(ToggleButton tab, double contentLeft)
        {
            highlightRect.Width = tab.ActualWidth;
            var glow = new DoubleAnimation(
                double.IsNaN(Canvas.GetLeft(highlightRect)) ? TabLeft(tab) : Canvas.GetLeft(highlightRect),
                TabLeft(tab), new Duration(TimeSpan.FromSeconds(0.2)))
            { EasingFunction = _easing };

            glow.Completed += (s, e) =>
            {
                var slide = new ThicknessAnimation(browsercontent.Margin,
                    new Thickness(contentLeft, 0, 0, 0),
                    new Duration(TimeSpan.FromSeconds(0.4)))
                { EasingFunction = _easing };
                browsercontent.BeginAnimation(MarginProperty, slide);
            };

            highlightRect.BeginAnimation(Canvas.LeftProperty, glow);
        }

        // Tab switcher. Each direction runs the glow→content animation once, and
        // only when actually changing tabs (guards against re-clicking the active).
        private void OnToggleButton_Click(object sender, RoutedEventArgs e)
        {
            if (sender == openProjectButton)
            {
                if (createProjectButton.IsChecked == true)
                {
                    createProjectButton.IsChecked = false;
                    AnimateTo(openProjectButton, 0);
                }
                openProjectButton.IsChecked = true;
            }
            else
            {
                if (openProjectButton.IsChecked == true)
                {
                    openProjectButton.IsChecked = false;
                    // Reveal NewProjectView by shifting left one Open-view width.
                    AnimateTo(createProjectButton, -openProjectView.ActualWidth);
                }
                createProjectButton.IsChecked = true;
            }
        }
        // Title-bar close now comes from NeelamDialogStyle (handler in
        // Themes/ControlTemplates.xaml.cs).
    }
}
