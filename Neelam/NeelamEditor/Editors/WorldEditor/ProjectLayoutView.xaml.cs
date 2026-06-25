using System.Windows;
using System.Windows.Controls;
using NeelamEditor.GameProject;
using NeelamEditor.Components;

namespace NeelamEditor.Editors
{
    public partial class ProjectLayoutView : UserControl
    {
        public ProjectLayoutView()
        {
            InitializeComponent();
        }

        // Construct an empty entity and route it through the scene's command so
        // the addition gets an undo/redo entry.
        private void OnAddEntity_Button_Click(object sender, RoutedEventArgs e)
        {
            var btn = sender as Button;
            var scene = btn.DataContext as Scene;
            scene.AddGameEntityCommand.Execute(new GameEntity(scene) { Name = "Empty Game Entity" });
        }

        // Feed the inspector pane: first selected item drives GameEntityView's DataContext.
        private void OnGameEntity_ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var listBox = sender as ListBox;
            GameEntityView.Instance.DataContext = listBox.SelectedItems.Count > 0
                ? listBox.SelectedItems[0]
                : null;
        }

        // Expanding a scene makes it the project's active scene; siblings deactivate.
        // Their expanders auto-collapse via the OneWay IsExpanded binding to IsActive.
        private void OnScene_Expanded(object sender, RoutedEventArgs e)
        {
            var scene = ((Expander)sender).DataContext as Scene;
            if (scene?.Project == null) return;
            foreach (var s in scene.Project.Scenes)
            {
                s.IsActive = (s == scene);
            }
        }
    }
}
