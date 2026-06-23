using System.Windows.Controls;

namespace NeelamEditor.Editors
{
    // Inspector for the currently-selected game entity. There's only ever one
    // visible instance, exposed as Instance so the scene list (in ProjectLayoutView)
    // can push the selected entity into DataContext on SelectionChanged.
    public partial class GameEntityView : UserControl
    {
        public static GameEntityView Instance { get; private set; }

        public GameEntityView()
        {
            InitializeComponent();
            DataContext = null;
            Instance = this;
        }
    }
}
