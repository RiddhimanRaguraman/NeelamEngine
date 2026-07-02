using System.Collections.ObjectModel;
using System.Runtime.Serialization;
using System.Windows.Input;
using NeelamEditor.Common;
using NeelamEditor.GameProject;
using NeelamEditor.Utilities;

namespace NeelamEditor.Components
{
    // An object living inside a Scene. Holds a list of Components — at minimum a
    // Transform — that define its data and behaviour in the game world.
    // KnownType entries tell the serializer which concrete Component subclasses
    // can appear in the polymorphic _components list. Add one per new component type.
    [DataContract]
    [KnownType(typeof(Transform))]
    public class GameEntity : ViewModelBase
    {
        private bool _isEnabled = true;
        [DataMember]
        public bool IsEnabled
        {
            get => _isEnabled;
            set
            {
                if (_isEnabled != value)
                {
                    _isEnabled = value;
                    OnPropertyChanged(nameof(IsEnabled));
                }
            }
        }
        private string _name;
        [DataMember]
        public string Name
        {
            get => _name;
            set
            {
                if (_name != value)
                {
                    _name = value;
                    OnPropertyChanged(nameof(Name));
                }
            }
        }

        // Back-reference to the owning scene.
        [DataMember]
        public Scene ParentScene { get; private set; }

        // Backing storage; the public Components is a read-only wrapper for bindings.
        [DataMember(Name = nameof(Components))]
        private ObservableCollection<Component> _components = new ObservableCollection<Component>();
        public ReadOnlyObservableCollection<Component> Components { get; private set; }

        // Bound to the entity's name TextBox; wraps the assignment in an undo entry
        // that uses the reflection-based UndoRedoAction overload.
        public ICommand RenameCommand { get; private set; }
        public ICommand IsEnabledCommand { get; private set; }

        // Wire up the read-only wrapper + commands. Called from the ctor for fresh
        // entities and from the serializer for loaded ones.
        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            if (_components != null)
            {
                Components = new ReadOnlyObservableCollection<Component>(_components);
                OnPropertyChanged(nameof(Components));
            }

            RenameCommand = new RelayCommand<string>(x =>
            {
                var oldName = _name;
                Name = x;
                Project.undoredo.Add(new UndoRedoAction(
                    nameof(Name), this, oldName, x,
                    $"Rename entity '{oldName}' to '{x}'"));
            }, x => x != _name);

            IsEnabledCommand = new RelayCommand<bool>(x =>
            {
                var oldValue= _isEnabled;
                _isEnabled = x;
                Project.undoredo.Add(new UndoRedoAction(
                    nameof(IsEnabled), this, oldValue, x,
                    x ? $"Enable {Name}": $"Disable {Name}"));
            });
        }

        public GameEntity(Scene scene)
        {
            System.Diagnostics.Debug.Assert(scene != null);
            ParentScene = scene;
            // Every entity gets a transform out of the gate.
            _components.Add(new Transform(this));
            OnDeserialized(new StreamingContext());
        }
    }

    abstract class MSEntity : ViewModelBase
    { }

    class MSGameEntity : MSEntity
    {

    }
}
