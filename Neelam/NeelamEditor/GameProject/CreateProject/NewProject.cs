
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using NeelamEditor.Common;
using NeelamEditor.Utilities;

namespace NeelamEditor.GameProject
{
    // Project-creation template loaded from ProjectTemplates\<Name>\template.xml.
    // [DataMember] fields are persisted; the others (Icon, paths) are populated
    // at runtime from sibling files in the template folder.
    [DataContract]
    public class ProjectTemplate
    {
        // Human-readable name shown in the template list (e.g. "Empty Project").
        [DataMember] public string ProjectType { get; set; }

        // Filename of the .neelam manifest seed inside the template folder.
        [DataMember] public string ProjectFile { get; set; }

        // Folder names to create inside the new project (e.g. .neelam, Content, GameCode).
        [DataMember] public List<string> Folders { get; set; }

        // Runtime-only: bytes of the template's Icon.png and Screenshot.png.
        public byte[] Icon { get; set; }
        public byte[] Screenshot { get; set; }

        // Runtime-only: absolute paths to the template's assets, resolved at load.
        public string IconFilePath { get; set; }
        public string ScreenshotFilePath { get; set; }
        public string ProjectFilePath { get; set; }
    }


    // View-model for the Create Project dialog. Holds form state, validates it,
    // and creates the project folder + files when the user confirms.
    class NewProject : ViewModelBase
    {
        private static readonly string _templatePath = ResolveTemplatePath();

        // A packaged build ships ProjectTemplates next to the exe; a dev build runs out
        // of Neelam\x64\<cfg>\ and reads them straight from the project folder. Probe for
        // the packaged copy first and fall back, so one binary handles both layouts --
        // the old code only knew the dev path and died on startup once installed.
        private static string ResolveTemplatePath()
        {
            var packaged = Path.Combine(AppContext.BaseDirectory, "ProjectTemplates");
            if (Directory.Exists(packaged)) return packaged;

            return Path.GetFullPath(
                Path.Combine(AppContext.BaseDirectory, @"..\..\NeelamEditor\ProjectTemplates"));
        }

        private string _Projectname = "NewProject";
        // Project name entered in the Name field. Triggers validation on change.
        public string ProjectName
        {
            get => _Projectname;
            set
            {
                if (_Projectname != value)
                {
                    _Projectname = value;
                    ValidateProjectPath();
                    OnPropertyChanged(nameof(ProjectName));
                }
            }
        }

        private string _Projectpath = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\NeelamProjects\";
        // Parent folder under which the new project's own folder will be created.
        // Triggers validation on change.
        public string ProjectPath
        {
            get => _Projectpath;
            set
            {
                if (_Projectpath != value)
                {
                    _Projectpath = value;
                    ValidateProjectPath();
                    OnPropertyChanged(nameof(ProjectPath));
                }
            }
        }

        private bool _isValid;
        // Bound to the Create button's IsEnabled. Set by ValidateProjectPath.
        public bool IsValid
        {
            get => _isValid;
            set
            {
                if (_isValid != value)
                {
                    _isValid = value;
                    OnPropertyChanged(nameof(IsValid));
                }
            }
        }

        private string _errorMsg;
        // Shown beneath the form. Empty string means no error.
        public string ErrorMsg
        {
            get => _errorMsg;
            set
            {
                if (_errorMsg != value)
                {
                    _errorMsg = value;
                    OnPropertyChanged(nameof(ErrorMsg));
                }
            }
        }

        // Templates loaded from disk in the constructor.
        private ObservableCollection<ProjectTemplate> _projectTemplates = new ObservableCollection<ProjectTemplate>();
        public ReadOnlyObservableCollection<ProjectTemplate> ProjectTemplates { get; }

        // Runs on every Name/Path change. Sets ErrorMsg + IsValid based on
        // emptiness, illegal characters, or a non-empty target folder.
        private bool ValidateProjectPath()
        {
            var path = ProjectPath;
            if (!Path.EndsInDirectorySeparator(path)) path += @"\";
            path += $@"{ProjectName}\";

            IsValid = false;
            if (string.IsNullOrWhiteSpace(ProjectName.Trim()))
            {
                ErrorMsg = "Type in a project name.";
            }
            else if (ProjectName.IndexOfAny(Path.GetInvalidFileNameChars()) != -1)
            {
                ErrorMsg = "Invalid character(s) used in project name.";
            }
            else if (string.IsNullOrWhiteSpace(ProjectPath.Trim()))
            {
                ErrorMsg = "Select a valid project folder.";
            }
            else if (ProjectPath.IndexOfAny(Path.GetInvalidPathChars()) != -1)
            {
                ErrorMsg = "Invalid character(s) used in project path.";
            }
            else if (Directory.Exists(path) && Directory.EnumerateFileSystemEntries(path).Any())
            {
                ErrorMsg = "Selected project folder already exists and is not empty.";
            }
            else
            {
                ErrorMsg = string.Empty;
                IsValid = true;
            }

            return IsValid;
        }

        // Materializes a new project on disk from the chosen template. Returns
        // the project's folder path on success, empty string on failure/invalid.
        public string CreateProject(ProjectTemplate template)
        {
            ValidateProjectPath();
            if (!IsValid)
            {
                return string.Empty;
            }
            if (!Path.EndsInDirectorySeparator(ProjectPath)) ProjectPath += @"\";
            var path = $@"{ProjectPath}{ProjectName}\";
            try
            {
                // Create the project root and the folders the template asks for.
                if(!Directory.Exists(path)) Directory.CreateDirectory(path);
                foreach (var folder in template.Folders)
                {
                    Directory.CreateDirectory(Path.GetFullPath(Path.Combine(Path.GetDirectoryName(path), folder)));
                }

                // The .neelam metadata folder is hidden so users don't poke at it.
                var dirinfo = new DirectoryInfo(path + @".neelam\");
                dirinfo.Attributes |= FileAttributes.Hidden;
                File.Copy(template.IconFilePath, Path.GetFullPath(Path.Combine(dirinfo.FullName, "Icon.png")));
                File.Copy(template.ScreenshotFilePath, Path.GetFullPath(Path.Combine(dirinfo.FullName, "Screenshot.png")));

                // Read the template's project.neelam, substitute the name/path placeholders,
                // and write it to the new project's root.
                var projectXml = File.ReadAllText(template.ProjectFilePath);
                // projectXml = string.Format(projectXml, ProjectName, ProjectPath);
                // {0}=Name, {1}=Path. Pass the project's own folder (path), not its parent.
                projectXml = string.Format(projectXml, ProjectName, path);
                var projectPath = Path.GetFullPath(Path.Combine(path + $"{ProjectName}{Project.Extension}"));
                File.WriteAllText(projectPath, projectXml);


                return path;
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.Message);
                Logger.Log(MessageTypes.Error, $"Failed to create {ProjectName}");
                throw;
            }
        }

        // Discovers every template.xml under _templatePath, deserializes each,
        // pulls in its Icon/Screenshot bytes, and exposes them via ProjectTemplates.
        public NewProject()
        {
            ProjectTemplates = new ReadOnlyObservableCollection<ProjectTemplate>(_projectTemplates);
            try
            {
                var templatesFiles = Directory.GetFiles(_templatePath, "template.xml", SearchOption.AllDirectories);
                Debug.Assert(templatesFiles.Any());
                foreach (var file in templatesFiles)
                {
                    var template = Serializer.FromFile<ProjectTemplate>(file);
                    template.IconFilePath = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(file), "Icon.png"));
                    template.Icon = File.ReadAllBytes(template.IconFilePath);
                    template.ScreenshotFilePath = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(file), "Screenshot.png"));
                    template.Screenshot = File.ReadAllBytes(template.ScreenshotFilePath);
                    template.ProjectFilePath = Path.GetFullPath(Path.Combine(Path.GetDirectoryName(file), template.ProjectFile));
                    _projectTemplates.Add(template);
                }
                ValidateProjectPath();
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.Message);
                Logger.Log(MessageTypes.Error, $"Failed to read the Template Project data; Check installation of template");
                throw;
            }
        }
    }

}
