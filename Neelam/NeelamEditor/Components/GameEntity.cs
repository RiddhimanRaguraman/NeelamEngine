using System.Collections.ObjectModel;
using System.Runtime.Serialization;
using NeelamEditor.Common;
using NeelamEditor.GameProject;

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

        // Wire up the read-only wrapper. Called from the ctor for fresh entities
        // and from the serializer for loaded ones.
        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            if (_components != null)
            {
                Components = new ReadOnlyObservableCollection<Component>(_components);
                OnPropertyChanged(nameof(Components));
            }
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
}
