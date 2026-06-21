using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using NeelamEditor.Utilities;

namespace NeelamEditor.GameProject
{
    // One entry in the recent-projects list. Serialized to ProjectData.xml.
    [DataContract]
    public class ProjectData
    {
        [DataMember] public string ProjectName { get; set; }

        // Full project folder (e.g. C:\Foo\MyProject\), not the parent.
        [DataMember] public string ProjectPath { get; set; }

        // Last-opened timestamp; drives sort order in the recent list.
        [DataMember] public DateTime Date { get; set; }

        // Absolute path to the project's .neelam manifest. Computed, not stored.
        public string FullPath { get => $@"{ProjectPath}{ProjectName}{Project.Extension}"; }

        // Runtime-only thumbnails loaded from the project's hidden .neelam folder.
        public byte[] Icon { get; set; }
        public byte[] ScreenShot { get; set; }
    }

    // Wrapper so the serializer has a single root element to deserialize.
    [DataContract]
    public class ProjectDataList
    {
        [DataMember]
        public List<ProjectData> projects {  get; set; }
    }

    // Static singleton that owns the recent-projects list and the on-disk file.
    class OpenProject
    {
        // %APPDATA%\NeelamEditor — per-user (Roaming) data folder.
        private static readonly string _applicationDataPath = $@"{Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData)}\NeelamEditor\";
        // Full path to ProjectData.xml; assigned in the static ctor.
        private static readonly string _projectDataPath;

        // Backing store; public Projects exposes a read-only view for binding.
        private static readonly ObservableCollection<ProjectData> _projects = new ObservableCollection<ProjectData>();
        public static ReadOnlyObservableCollection<ProjectData> Projects { get; }

        // Loads ProjectData.xml, sorts newest-first, and drops entries whose
        // project folder no longer exists. Also pulls in icon/screenshot bytes.
        private static void ReadProjectData()
        {
            if(File.Exists(_projectDataPath))
            {
                var projects = Serializer.FromFile<ProjectDataList>(_projectDataPath).projects.OrderByDescending(x => x.Date);
                _projects.Clear();
                foreach (var project in projects)
                {
                    if(File.Exists(project.FullPath))
                    {
                        project.Icon = File.ReadAllBytes($@"{project.ProjectPath}\.neelam\Icon.png");
                        project.ScreenShot = File.ReadAllBytes($@"{project.ProjectPath}\.neelam\ScreenShot.png");
                        _projects.Add(project);
                    }

                }
            }
        }

        // Persists _projects to disk, sorted oldest-first (write order is cosmetic).
        private static void WriteProjectData()
        {
            var projects = _projects.OrderBy(x => x.Date).ToList();
            Serializer.ToFile(new ProjectDataList() { projects = projects}, _projectDataPath);
        }

        // Adds (or refreshes) an entry for the given project and persists.
        // Returns the loaded Project 
        public static Project Open(ProjectData data)
        {
            ReadProjectData();
            var project = _projects.FirstOrDefault(x => x.FullPath == data.FullPath);
            if (project != null)
            {
                project.Date = DateTime.Now;
            }
            else
            {
                project = data;
                project.Date = DateTime.Now;
                _projects.Add(project);
            }
            WriteProjectData();
            return Project.Load(project.FullPath);
        }

        // Ensures the AppData folder exists, sets the file path, and primes the
        // list from disk. Runs once, on first access to the type.
        static OpenProject()
        {
            try
            {
                if (!Directory.Exists(_applicationDataPath)) Directory.CreateDirectory(_applicationDataPath);
                _projectDataPath = $@"{_applicationDataPath}ProjectData.xml";
                Projects = new ReadOnlyObservableCollection<ProjectData>(_projects);
                ReadProjectData();
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.Message);
            }
        }


    }
}
