using System.Numerics;
using System.Runtime.Serialization;

namespace NeelamEditor.Components
{
    // Position / Rotation / Scale of a GameEntity. Every entity has one of these.
    // System.Numerics.Vector3 is a value type, so equality compares component-wise.
    [DataContract]
    public class Transform : Component
    {
        [DataMember]
        private Vector3 _position;
        public Vector3 Position
        {
            get => _position;
            set
            {
                if (_position != value)
                {
                    _position = value;
                    OnPropertyChanged(nameof(Position));
                }
            }
        }

        [DataMember]
        private Vector3 _rotation;
        public Vector3 Rotation
        {
            get => _rotation;
            set
            {
                if (_rotation != value)
                {
                    _rotation = value;
                    OnPropertyChanged(nameof(Rotation));
                }
            }
        }

        [DataMember]
        private Vector3 _scale;
        public Vector3 Scale
        {
            get => _scale;
            set
            {
                if (_scale != value)
                {
                    _scale = value;
                    OnPropertyChanged(nameof(Scale));
                }
            }
        }

        public Transform(GameEntity owner) : base(owner) { }
    }
}
