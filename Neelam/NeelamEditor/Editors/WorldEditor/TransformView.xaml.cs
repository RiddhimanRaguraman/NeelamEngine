using System.Diagnostics;
using System.Numerics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using NeelamEditor.Components;
using NeelamEditor.GameProject;
using NeelamEditor.Utilities;

namespace NeelamEditor.Editors
{
    // Inspector body for a Transform. Each VectorBox drives MSTransform (which writes
    // to every selected entity). Undo is captured as one action per gesture: snapshot
    // the before-state on mouse-down (or focus-in), record before→after on mouse-up
    // (or focus-out) — but only if something actually changed.
    public partial class TransformView : UserControl
    {
        private Action _undoAction = null;
        private bool _propertyChanged = false;

        public TransformView()
        {
            InitializeComponent();
            Loaded += OnTransformViewLoaded;
        }

        private void OnTransformViewLoaded(object sender, RoutedEventArgs e)
        {
            Loaded -= OnTransformViewLoaded;
            if (DataContext is MSTransform vm)
            {
                vm.PropertyChanged += (s, args) => _propertyChanged = true;
            }
        }

        // Snapshot the selected components' current value + build the closure that
        // restores it. Returns the undo action, or null if there's no valid VM.
        private Action GetAction(Func<Transform, (Transform transform, Vector3)> selector,
                                 Action<(Transform transform, Vector3)> forEachAction)
        {
            if (!(DataContext is MSTransform vm))
            {
                _undoAction = null;
                _propertyChanged = false;
                return null;
            }

            var selection = vm.SelectedComponents.Select(x => selector(x)).ToList();
            return new Action(() =>
            {
                selection.ForEach(x => forEachAction(x));
                (GameEntityView.Instance.DataContext as MSEntity)?.GetMSComponent<MSTransform>()?.Refresh();
            });
        }

        private Action GetPositionAction() => GetAction(x => (x, x.Position), x => x.transform.Position = x.Item2);
        private Action GetRotationAction() => GetAction(x => (x, x.Rotation), x => x.transform.Rotation = x.Item2);
        private Action GetScaleAction()    => GetAction(x => (x, x.Scale),    x => x.transform.Scale    = x.Item2);

        private void RecordActions(Action redoAction, string name)
        {
            if (_propertyChanged)
            {
                Debug.Assert(_undoAction != null);
                _propertyChanged = false;
                Project.undoredo.Add(new UndoRedoAction(_undoAction, redoAction, name));
            }
        }

        private void OnPosition_VectorBox_PreviewMouse_LBD(object sender, MouseButtonEventArgs e)
        {
            _propertyChanged = false;
            _undoAction = GetPositionAction();
        }

        private void OnPosition_VectorBox_PreviewMouse_LBU(object sender, MouseButtonEventArgs e)
            => RecordActions(GetPositionAction(), "Position Changed");

        private void OnPosition_VectorBox_LostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
        {
            if (_propertyChanged && _undoAction != null)
            {
                OnPosition_VectorBox_PreviewMouse_LBU(sender, null);
            }
        }

        private void OnRotation_VectorBox_PreviewMouse_LBD(object sender, MouseButtonEventArgs e)
        {
            _propertyChanged = false;
            _undoAction = GetRotationAction();
        }

        private void OnRotation_VectorBox_PreviewMouse_LBU(object sender, MouseButtonEventArgs e)
            => RecordActions(GetRotationAction(), "Rotation Changed");

        private void OnRotation_VectorBox_LostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
        {
            if (_propertyChanged && _undoAction != null)
            {
                OnRotation_VectorBox_PreviewMouse_LBU(sender, null);
            }
        }

        private void OnScale_VectorBox_PreviewMouse_LBD(object sender, MouseButtonEventArgs e)
        {
            _propertyChanged = false;
            _undoAction = GetScaleAction();
        }

        private void OnScale_VectorBox_PreviewMouse_LBU(object sender, MouseButtonEventArgs e)
            => RecordActions(GetScaleAction(), "Scale Changed");

        private void OnScale_VectorBox_LostKeyboardFocus(object sender, KeyboardFocusChangedEventArgs e)
        {
            if (_propertyChanged && _undoAction != null)
            {
                OnScale_VectorBox_PreviewMouse_LBU(sender, null);
            }
        }
    }
}
