using System.Runtime.Serialization;
using NeelamEditor.Common;

namespace NeelamEditor.Components
{
    // Base class for anything attached to a GameEntity (transform, mesh, light, …).
    // Subclasses must be listed under KnownType on GameEntity so the serializer
    // can resolve them when the components list is deserialized.
    [DataContract]
    public abstract class Component : ViewModelBase
    {
        // Back-reference to the entity holding this component.
        [DataMember]
        public GameEntity Owner { get; private set; }

        public Component(GameEntity owner)
        {
            System.Diagnostics.Debug.Assert(owner != null);
            Owner = owner;
        }

        // Default display label = the concrete type name (e.g. "Transform").
        // GameEntityView's components list binds `{Binding}`, which calls this.
        public override string ToString() => GetType().Name;
    }
}
