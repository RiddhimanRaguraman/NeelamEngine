using NeelamEditor.Common;
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
        public static float? GetMixedValue(List<GameEntity> entities, Func<GameEntity, float> getProperty)
        {
            var value = getProperty(entities.First());
            foreach (var entity in entities.Skip(1))
            {
                if (value.IsTheSameAs(getProperty(entity)))
                {
                    return null;
                }
            }
            return value;
        }

        public static bool? GetMixedValue(List<GameEntity> entities, Func<GameEntity, bool> getProperty)
        {
            var value = getProperty(entities.First());
            foreach (var entity in entities.Skip(1))
            {
                if (value != getProperty(entity))
                {
                    return null;
                }
            }
            return value;
        }

        public static string GetMixedValue(List<GameEntity> entities, Func<GameEntity, string> getProperty)
        {
            var value = getProperty(entities.First());
            foreach (var entity in entities.Skip(1))
            {
                if (value != getProperty(entity))
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
            _enableEntities = true;
        }



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
