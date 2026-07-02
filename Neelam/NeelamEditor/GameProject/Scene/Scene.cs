using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Runtime.Serialization;
using System.Windows.Input;
using NeelamEditor.Common;
using NeelamEditor.Components;
using NeelamEditor.Utilities;

namespace NeelamEditor.GameProject
{
    // One scene inside a Project. Owns a list of GameEntities and commands to
    // mutate them with full undo/redo support.
    [DataContract]
    class Scene : ViewModelBase
    {
        [DataMember]
        private string _name;
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

        // Back-reference to the owning project. Forms a cycle — handled by
        // ViewModelBase's IsReference=true so the serializer doesn't recurse.
        [DataMember]
        public Project Project { get; private set; }

        private bool _isActive;
        [DataMember]
        public bool IsActive
        {
            get => _isActive;
            set
            {
                if (_isActive != value)
                {
                    _isActive = value;
                    OnPropertyChanged(nameof(IsActive));
                }
            }
        }

        // Persisted entities; the public GameEntities is a read-only wrapper.
        [DataMember(Name = "GameEntities")]
        private ObservableCollection<GameEntity> _gameEntities = new ObservableCollection<GameEntity>();
        public ReadOnlyObservableCollection<GameEntity> GameEntities { get; private set; }

        public ICommand AddGameEntityCommand { get; private set; }
        public ICommand RemoveGameEntityCommand { get; private set; }

        private void AddGameEntity(GameEntity entity)
        {
            Debug.Assert(!_gameEntities.Contains(entity));
            _gameEntities.Add(entity);
        }

        private void RemoveGameEntity(GameEntity entity)
        {
            Debug.Assert(_gameEntities.Contains(entity));
            _gameEntities.Remove(entity);
        }

        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            // Templates pre-Game-Entities-era have no list; create an empty one
            // so older projects still load cleanly.
            if (_gameEntities == null) _gameEntities = new ObservableCollection<GameEntity>();
            GameEntities = new ReadOnlyObservableCollection<GameEntity>(_gameEntities);
            OnPropertyChanged(nameof(GameEntities));

            // Add — caller supplies a pre-constructed entity (could be any subclass).
            AddGameEntityCommand = new RelayCommand<GameEntity>(x =>
            {
                AddGameEntity(x);
                var entityIndex = _gameEntities.Count - 1;
                Project.undoredo.Add(new UndoRedoAction(
                    () => RemoveGameEntity(x),
                    () => _gameEntities.Insert(entityIndex, x),
                    $"Add {x.Name} to {Name}"));
            });

            // Remove — capture original index so undo can re-insert at the same spot.
            RemoveGameEntityCommand = new RelayCommand<GameEntity>(x =>
            {
                var entityIndex = _gameEntities.IndexOf(x);
                RemoveGameEntity(x);
                Project.undoredo.Add(new UndoRedoAction(
                    () => _gameEntities.Insert(entityIndex, x),
                    () => RemoveGameEntity(x),
                    $"Remove {x.Name}"));
            });
        }

        public Scene(Project project, string name)
        {
            Debug.Assert(project != null);
            Project = project;
            Name = name;
            OnDeserialized(new StreamingContext());
        }
    }
}
