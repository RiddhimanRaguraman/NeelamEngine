using System.Diagnostics;
using System.Runtime.Serialization;
using NeelamEditor.Common;

namespace NeelamEditor.Components
{

    interface IMSComponent { }

    // Base class for anything attached to a GameEntity (transform, mesh, light, …).
    // Subclasses must be listed under KnownType on GameEntity so the serializer
    // can resolve them when the components list is deserialized.
    [DataContract]
    abstract class Component : ViewModelBase
    {
        // Back-reference to the entity holding this component.
        [DataMember]
        public GameEntity Owner { get; private set; }

        // Build the multi-selection proxy for this component type. Each concrete
        // component returns its matching MS* view-model (e.g. Transform → MSTransform),
        // which the inspector edits across every selected entity at once.
        public abstract IMSComponent GetMultiselectionComponent(MSEntity msEntity);

        public Component(GameEntity owner)
        {
            Debug.Assert(owner != null);
            Owner = owner;
        }

        // Default display label = the concrete type name (e.g. "Transform").
        public override string ToString() => GetType().Name;
    }

    // Multi-selection proxy for one component type. Mirrors MSEntity: it snapshots
    // the same-typed component from every selected entity (SelectedComponents), shows
    // mixed values as blank, and writes edits back to all of them.
    abstract class MSComponent<T> : ViewModelBase, IMSComponent where T : Component
    {
        // While false, a property change came from a refresh (reading the entities),
        // not the user — so it must not write back and cause a feedback loop.
        private bool _enableUpdates = true;

        public List<T> SelectedComponents { get; }

        // Push a changed inspector value out to every selected component.
        protected abstract bool UpdateComponents(string propertyName);

        // Pull the shared/mixed value in from the selected components.
        protected abstract bool UpdateMSComponents();

        public void Refresh()
        {
            _enableUpdates = false;
            UpdateMSComponents();
            _enableUpdates = true;
        }

        public MSComponent(MSEntity msEntity)
        {
            Debug.Assert(msEntity?.SelectedEntities?.Any() == true);
            SelectedComponents = msEntity.SelectedEntities.Select(entity => entity.GetComponent<T>()).ToList();
            PropertyChanged += (s, e) => { if (_enableUpdates) UpdateComponents(e.PropertyName); };
        }
    }
}


