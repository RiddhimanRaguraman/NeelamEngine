using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Windows;
using System.Windows.Input;
using NeelamEditor.Common;
using NeelamEditor.Utilities;

namespace NeelamEditor.GameProject
{
    // The loaded game project. Serializes as <Game>...</Game> in the .neelam file.
    [DataContract(Name = "Game")]
    public class Project : ViewModelBase
    {
        // File extension used for project manifests on disk.
        public static string Extension { get; } = ".neelam";

        [DataMember] public string Name { get; private set; } = "NewProject";

        // Project's own folder (e.g. C:\Foo\MyProject\), not its parent.
        [DataMember] public string Path { get; private set; }

        // Absolute path to the .neelam manifest file.
        // Path is the project's own folder (e.g. C:\Foo\NewProject\), so this
        // resolves to C:\Foo\NewProject\NewProject.neelam.
        public string FullPath => $@"{Path}{Name}{Extension}";

        // Backing storage for scenes; private so the public Scenes is read-only.
        [DataMember(Name = "Scenes")]
        private ObservableCollection<Scene> _scenes = new ObservableCollection<Scene>();

        // Read-only view of scenes exposed to bindings.
        public ReadOnlyObservableCollection<Scene> Scenes { get; private set; }

        // Convenience access to the project currently loaded in the editor shell.
        public static Project Current => Application.Current.MainWindow.DataContext as Project;

        private Scene _activeScene;
        // Scene currently being edited; persisted so the editor can restore focus on reload.
        [DataMember]
        public Scene ActiveScene
        {
            get => _activeScene;
            set
            {
                if (_activeScene != value)
                {
                    _activeScene = value;
                    OnPropertyChanged(nameof(ActiveScene));
                }
            }
        }

        // Shared undo/redo for this Project — kept static so any view can reach it
        // without holding a Project reference.
        public static UndoRedo undoredo { get; } = new UndoRedo();

        // Commands the UI binds to. Set in OnDeserialized so they survive both
        // first-time construction and round-tripping through the serializer.
        public ICommand UndoCommand { get; private set; }
        public ICommand RedoCommand { get; private set; }
        public ICommand SaveCommand { get; private set; }
        public ICommand AddSceneCommand { get; private set; }
        public ICommand RemoveSceneCommand { get; private set; }

        private void AddSceneInternal(string sceneName)
        {
            Debug.Assert(!string.IsNullOrEmpty(sceneName.Trim()));
            _scenes.Add(new Scene(this, sceneName));
        }

        private void RemoveSceneInternal(Scene scene)
        {
            Debug.Assert(_scenes.Contains(scene));
            _scenes.Remove(scene);
        }

        // Load a project from disk.
        public static Project Load(string file)
        {
            Debug.Assert(File.Exists(file));
            return Serializer.FromFile<Project>(file);
        }

        // Hook for tearing down the active project (placeholder).
        public void Unload()
        {
        }

        // Persist a project to its own FullPath.
        public static void Save(Project project)
        {
            Serializer.ToFile(project, project.FullPath);
        }

        [OnDeserialized]
        private void OnDeserialized(StreamingContext context)
        {
            if (_scenes != null)
            {
                Scenes = new ReadOnlyObservableCollection<Scene>(_scenes);
                OnPropertyChanged(nameof(Scenes));
            }
            ActiveScene = Scenes.FirstOrDefault(x => x.IsActive);

            // Append a new scene; undo removes it, redo re-inserts at the same index.
            AddSceneCommand = new RelayCommand<object>(x =>
            {
                AddSceneInternal($"New Scene {_scenes.Count}");
                var newScene = _scenes.Last();
                var sceneIndex = _scenes.Count - 1;

                undoredo.Add(new UndoRedoAction(
                    () => RemoveSceneInternal(newScene),
                    () => _scenes.Insert(sceneIndex, newScene),
                    $"Add {newScene.Name}"));
            });

            // Remove a scene; undo re-inserts at the original position. Disabled
            // when the target is the project's active scene.
            RemoveSceneCommand = new RelayCommand<Scene>(x =>
            {
                var sceneIndex = _scenes.IndexOf(x);
                RemoveSceneInternal(x);

                undoredo.Add(new UndoRedoAction(
                    () => _scenes.Insert(sceneIndex, x),
                    () => RemoveSceneInternal(x),
                    $"Remove {x.Name}"));
            }, x => !x.IsActive);

            UndoCommand = new RelayCommand<object>(x => undoredo.Undo());
            RedoCommand = new RelayCommand<object>(x => undoredo.Redo());
            SaveCommand = new RelayCommand<object>(x => Save(this));
        }

        // Ctor used when creating a brand-new project (not loading from disk).
        // Manually invokes OnDeserialized to set up the read-only wrapper.
        public Project(string name, string path)
        {
            Name = name;
            Path = path;
            OnDeserialized(new StreamingContext());
        }
    }
}
