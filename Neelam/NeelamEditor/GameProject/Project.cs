using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Windows;
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
        public string FullPath => $"{Path}{Name}{Extension}";

        // Backing storage for scenes; private so the public Scenes is read-only.
        [DataMember(Name = "Scenes")]
        private ObservableCollection<Scene> _scenes = new ObservableCollection<Scene>();

        // Read-only view of scenes exposed to bindings.
        public ReadOnlyObservableCollection<Scene> Scenes { get; private set; }

        // Convenience access to the project currently loaded in the editor shell.
        public static Project Current => Application.Current.MainWindow.DataContext as Project;

        private Scene _activeScene;
        // Scene currently being edited; persisted so the editor can restore focus on reload
        public Scene ActiveScene
        {
            get => _activeScene;
            set
            {
                if(_activeScene != value)
                {
                    _activeScene = value;
                    OnPropertyChanged(nameof(ActiveScene));
                }
            }
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

        // Persist project to its own FullPath.
        public static void Load(Project Prj)
        {
            Serializer.ToFile<Project>(Prj, Prj.FullPath);
        }

        // Called by the serializer after deserialization completes; rebuilds the
        // ReadOnlyObservableCollection wrapper since it isn't persisted itself.
        [OnDeserialized]
        private void OnDeserialized (StreamingContext context)
        {
            if(_scenes != null)
            {
                Scenes = new ReadOnlyObservableCollection<Scene>(_scenes);
                OnPropertyChanged(nameof(Scenes));
            }
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
