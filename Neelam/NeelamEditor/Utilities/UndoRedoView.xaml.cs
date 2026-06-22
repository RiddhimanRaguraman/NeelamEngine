using System.Windows.Controls;

namespace NeelamEditor.Utilities
{
    // History panel for the editor's UndoRedo stack. Bind its DataContext to
    // an UndoRedo instance (typically Project.undoredo) to render the lists.
    public partial class UndoRedoView : UserControl
    {
        public UndoRedoView()
        {
            InitializeComponent();
        }
    }
}
