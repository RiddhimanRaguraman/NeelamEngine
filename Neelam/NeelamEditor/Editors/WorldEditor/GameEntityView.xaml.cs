using NeelamEditor.Components;
using NeelamEditor.Utilities;
using NeelamEditor.GameProject;
using System.Windows.Controls;

namespace NeelamEditor.Editors
{
    // Inspector for the currently-selected game entity. There's only ever one
    // visible instance, exposed as Instance so the scene list (in ProjectLayoutView)
    // can push the selected entity into DataContext on SelectionChanged.
    public partial class GameEntityView : UserControl
    {
        private Action _undoAction;
        private string _propertyName;
        public static GameEntityView Instance { get; private set; }

        public GameEntityView()
        {
            InitializeComponent();
            DataContext = null;
            Instance = this;
            DataContextChanged += (_, __) =>
            {
                if(DataContext != null)
                {
                    (DataContext as MSEntity).PropertyChanged += (s, e) => _propertyName = e.PropertyName;
                }
            };
        }

        private Action GetRenameAction()
        {
            var vm = DataContext as MSEntity;
            var Selection = vm.SelectedEntities.Select(entity => (entity, entity.Name)).ToList();
            return  new Action(() =>
            {
                Selection.ForEach(item => item.entity.Name = item.Name);
                (DataContext as MSEntity).Refresh();
            });
        }

        private Action GetIsEnabledAction()
        {
            var vm = DataContext as MSEntity;
            var Selection = vm.SelectedEntities.Select(entity => (entity, entity.IsEnabled)).ToList();
            return  new Action(() =>
            {
                Selection.ForEach(item => item.entity.IsEnabled = item.IsEnabled);
                (DataContext as MSEntity).Refresh();
            });
        }

        private void OnName_Textbox_GotKeyboardFocus(object sender, System.Windows.Input.KeyboardFocusChangedEventArgs e)
        {
            _undoAction = GetRenameAction();
        }

        private void OnName_Textbox_LostKeyboardFocus(object sender, System.Windows.Input.KeyboardFocusChangedEventArgs e)
        {
            if(_propertyName == nameof(MSEntity.Name) && _undoAction != null)
            {
                var redoAction = GetRenameAction();
                Project.undoredo.Add(new UndoRedoAction (_undoAction, redoAction, "Rename Game Entity"));
                _propertyName = null;
            }
            _undoAction = null;
        }

        private void OnIsEnabled_CheckBox_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            var undoAction = GetIsEnabledAction();
            var vm = DataContext as MSEntity;
            vm.IsEnabled = (sender as CheckBox).IsChecked == true;
            var redoAction = GetIsEnabledAction();
            Project.undoredo.Add(new UndoRedoAction(undoAction, redoAction,
                vm.IsEnabled == true ? "Enable Game Entity" : "Disable Game Entity"));
        }
    }
}
