using System.Windows;
using System.Windows.Controls;

namespace NeelamEditor.Utilities
{
    /// <summary>
    /// Interaction logic for LoggerView.xaml
    /// </summary>
    public partial class LoggerView : UserControl
    {
        public LoggerView()
        {
            InitializeComponent();
        }

        private void OnClear_Button_Click(object sender, RoutedEventArgs e)
        {
            Logger.Clear();
        }

        private void OnMessageFilter_Button_Click(object sender, RoutedEventArgs e)
        {
            var filter = 0x0;
            if (toggleinfo.IsChecked == true) filter |= (int)MessageTypes.Info;
            if (togglewarn.IsChecked == true) filter |= (int)MessageTypes.Warning;
            if (toggleerror.IsChecked == true) filter |= (int)MessageTypes.Error;
            Logger.SetMessageFilter(filter);
        }
    }
}
