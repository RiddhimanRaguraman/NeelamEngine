using NeelamEditor.Common;
using NeelamEditor.EngineWrapper;
using NeelamEditor.GameProject;
using NeelamEditor.Utilities;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.Runtime.Serialization;
using System.Windows.Input;

namespace NeelamEditor.Components
{
    // An object living inside a Scene. Holds a list of Components — at minimum a
    // Transform — that define its data and behaviour in the game world.
    // KnownType entries tell the serializer which concrete Component subclasses
    // can appear in the polymorphic _components list. Add one per new component type.
    [DataContract]
    [KnownType(typeof(Transform))]
    class GameEntity : ViewModelBase
    {
        private int _entityId = Id.INVALID_ID;
        public int EntityId
        {
            get => _entityId;
            set
            {
                if (_entityId != value)
                {
                    _entityId = value;
                    OnPropertyChanged(nameof(EntityId));
                }
            }
        }
        private bool _isActive;
        public bool IsActive
        {
            get => _isActive;
            set
            {
                if (_isActive != value)
                {
                    _isActive = value;
                    if(_isActive)
                    {
                        EntityId = EngineAPI.CreateGameEntity(this);
                        Debug.Assert(Id.IsValid(_entityId));
                    }
                    else
                    {
                        EngineAPI.RemoveGameEntity(this);
                    }
                    OnPropertyChanged(nameof(IsActive));
                }
            }
        }

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

        // Component lookup by type. GetComponent<T> underpins the multi-select proxies:
        // MSComponent<T> pulls the same-typed component from every selected entity.
        public Component GetComponent(Type type) => Components.FirstOrDefault(c => c.GetType() == type);
        public T GetComponent<T>() where T : Component => GetComponent(typeof(T)) as T;

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

    abstract class MSEntity : ViewModelBase
    {
        private bool _enableEntities = false;
        private bool? _isEnabled = true;
        public bool? IsEnabled
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
        //[DataMember]
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

        private ObservableCollection<IMSComponent> _components = new ObservableCollection<IMSComponent>();
        public ReadOnlyObservableCollection<IMSComponent> Components { get; private set; }
        public List<GameEntity> SelectedEntities { get; }
       
        // Returns the shared value across all entities, or null when they differ
        // (a "mixed" selection), so the UI can show a blank/indeterminate field.
        // Generic over the list element so it works for both a GameEntity selection
        // (Name/IsEnabled) and a component selection (MSTransform reads Transform.X…).
        public static float? GetMixedValue<T>(List<T> list, Func<T, float> getProperty)
        {
            var value = getProperty(list.First());
            foreach (var item in list.Skip(1))
            {
                // Mixed → blank. (Float compares via IsTheSameAs to tolerate FP noise.)
                if (!value.IsTheSameAs(getProperty(item)))
                {
                    return null;
                }
            }
            return value;
        }

        public static bool? GetMixedValue<T>(List<T> list, Func<T, bool> getProperty)
        {
            var value = getProperty(list.First());
            foreach (var item in list.Skip(1))
            {
                if (value != getProperty(item))
                {
                    return null;
                }
            }
            return value;
        }

        public static string GetMixedValue<T>(List<T> list, Func<T, string> getProperty)
        {
            var value = getProperty(list.First());
            foreach (var item in list.Skip(1))
            {
                if (value != getProperty(item))
                {
                    return null;
                }
            }
            return value;
        }

        protected virtual bool UpdateMSGameEntity()
        {
            IsEnabled = GetMixedValue(SelectedEntities, new Func<GameEntity, bool>(x => x.IsEnabled));
            Name = GetMixedValue(SelectedEntities, new Func<GameEntity, string>(x => x.Name));

            return true;
        }

        protected virtual bool UpdateGameEntities(string propertyName)
        {
            switch (propertyName)
            {
                case nameof(IsEnabled): SelectedEntities.ForEach(x => x.IsEnabled = IsEnabled.Value); return true;
                case nameof(Name): SelectedEntities.ForEach(x => x.Name = Name); return true;
            }
            return false;
        }

        public void Refresh()
        {
            _enableEntities = false;
            UpdateMSGameEntity();
            MakeComponentList();
            _enableEntities = true;
        }

        // One MS proxy per component type shared by ALL selected entities. A component
        // present on only some of the selection isn't editable as a group, so it's
        // skipped. The proxies (e.g. MSTransform) are what the inspector binds to.
        private void MakeComponentList()
        {
            _components.Clear();
            var firstEntity = SelectedEntities.FirstOrDefault();
            if (firstEntity == null) return;

            foreach (var component in firstEntity.Components)
            {
                var type = component.GetType();
                if (!SelectedEntities.Skip(1).Any(entity => entity.GetComponent(type) == null))
                {
                    _components.Add(component.GetMultiselectionComponent(this));
                }
            }
        }

        // The MS proxy of a given type, for the inspector's undo/redo refresh path.
        public T GetMSComponent<T>() where T : IMSComponent
            => (T)Components.FirstOrDefault(x => x.GetType() == typeof(T));



        protected MSEntity(List<GameEntity> entities)
        {
            Debug.Assert(entities?.Any() == true);
            Components = new ReadOnlyObservableCollection<IMSComponent>(_components);
            SelectedEntities = entities;
            PropertyChanged += (s, e) => { if (_enableEntities) UpdateGameEntities(e.PropertyName); };
        }
    }

    class MSGameEntity : MSEntity
    {
        public MSGameEntity(List<GameEntity> entities) : base(entities)
        {
            Refresh();
        }

    }
}
