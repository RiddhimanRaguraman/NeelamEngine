using System.Linq;
using System.Windows;
using System.Windows.Controls;
using NeelamEditor.Components;
using NeelamEditor.GameProject;
using NeelamEditor.Utilities;

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

        // Drive the inspector pane AND push a "Selection changed" entry into the
        // undo stack so the user can step backward/forward through prior selections.
        private void OnGameEntity_ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            // Clear first so the inspector blanks out when nothing is selected.
            GameEntityView.Instance.DataContext = null;

            var listBox = sender as ListBox;
            if (e.AddedItems.Count > 0)
            {
                var firstEntity = listBox.SelectedItems[0] as GameEntity;
                GameEntityView.Instance.DataContext = firstEntity;

                // Activate this entity's scene so the toolbar / Add Entity button
                // operate on the scene the user is actually working in.
                ActivateScene(firstEntity?.ParentScene);
            }

            // Snapshot the current selection set and reconstruct what it was before
            // this event by removing items that just got added and re-including ones
            // that just got removed.
            var newSelection = listBox.SelectedItems.Cast<GameEntity>().ToList();
            var previousSelection = newSelection
                .Except(e.AddedItems.Cast<GameEntity>())
                .Concat(e.RemovedItems.Cast<GameEntity>())
                .ToList();

            Project.undoredo.Add(new UndoRedoAction(
                // Undo: restore the previous selection.
                () =>
                {
                    listBox.UnselectAll();
                    previousSelection.ForEach(x =>
                        (listBox.ItemContainerGenerator.ContainerFromItem(x) as ListBoxItem).IsSelected = true);
                },
                // Redo: re-apply the new selection.
                () =>
                {
                    listBox.UnselectAll();
                    newSelection.ForEach(x =>
                        (listBox.ItemContainerGenerator.ContainerFromItem(x) as ListBoxItem).IsSelected = true);
                },
                "Selection changed"));
        }

        // Expanding a scene makes it the project's active scene; siblings deactivate.
        // Their expanders auto-collapse via the OneWay IsExpanded binding to IsActive.
        private void OnScene_Expanded(object sender, RoutedEventArgs e)
        {
            var scene = ((Expander)sender).DataContext as Scene;
            ActivateScene(scene);
        }

        // Flip IsActive on every scene in the project so only `target` is active.
        // Safe to call with null or a scene whose Project hasn't been wired up yet.
        private static void ActivateScene(Scene target)
        {
            if (target?.Project == null) return;
            foreach (var s in target.Project.Scenes)
            {
                s.IsActive = (s == target);
            }
        }
    }
}
