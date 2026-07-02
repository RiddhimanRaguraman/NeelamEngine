using System.Windows.Controls;

namespace NeelamEditor.Editors
{
    // WPF host for the Vulkan renderer. The actual native surface will be
    // parented under here via HwndHost once the engine hooks are wired up.
    public partial class RenderView : UserControl
    {
        public RenderView()
        {
            InitializeComponent();
        }
    }
}
