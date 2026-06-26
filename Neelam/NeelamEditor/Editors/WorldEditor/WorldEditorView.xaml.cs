using System.Collections.Specialized;
using System.Windows;
using System.Windows.Controls;
using NeelamEditor.GameProject;

namespace NeelamEditor.Editors
{
    public partial class WorldEditorView : UserControl
    {
        // Singleton-ish: only one shell exists. 
        public static WorldEditorView Instance { get; private set; }

        public WorldEditorView()
        { 
            InitializeComponent();
            Instance = this;
            Loaded += OnWorldEditorViewLoaded;
        }

        private void OnWorldEditorViewLoaded(object sender, RoutedEventArgs e)
        {
            Loaded -= OnWorldEditorViewLoaded;  // one-shot

            // KeyBindings only fire when the bound element has keyboard focus.
            Focus();

            // Any change to the undo stack (a new action, an undo, or a redo) can
            // remove the focused element from the tree, dropping keyboard focus.
            // Re-grab it whenever the list mutates so Ctrl+Z/Y keep working.
            ((INotifyCollectionChanged)Project.undoredo.UndoList)
                .CollectionChanged += (s, e) => Focus();
        }
    }
}
