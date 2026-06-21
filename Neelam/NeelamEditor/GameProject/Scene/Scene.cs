using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using NeelamEditor.Common;

namespace NeelamEditor.GameProject
{
    // One scene inside a Project. Currently just a Name; will grow as the scene graph builds.
    [DataContract]
    public class Scene : ViewModelBase
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

        // True if this scene is the project's currently-active one.
        public bool IsActive => Project.ActiveScene == this;

        public Scene(Project project, string name)
        {
            Debug.Assert(project != null);
            Project = project;
            Name = name;
        }
    }
}
