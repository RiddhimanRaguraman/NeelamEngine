using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace NeelamEditor.Common
{
    // MVVM base. Inherit when a class needs to notify the UI on property changes.
    // IsReference=true so DataContractSerializer can round-trip object graphs with cycles.
    [DataContract(IsReference = true)]
    public class ViewModelBase : INotifyPropertyChanged
    {
        // WPF bindings subscribe to this to refresh when a property mutates.
        public event PropertyChangedEventHandler PropertyChanged;

        // Call from a property setter after the backing field is updated.
        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
