using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeelamEditor.GameProject
{
    public class Scene : ViewModelBase
    {
        private string _name = "NewProject";
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

        public Project Project { get; private set; }

        public Scene(Project project, string name)
        {
            Debug.Assert(project != null);

        }
    }
}
