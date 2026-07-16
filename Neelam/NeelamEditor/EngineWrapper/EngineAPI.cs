using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices;
using NeelamEditor.Components;
using NeelamEditor.EngineStructs;

namespace NeelamEditor.EngineStructs
{
    [StructLayout(LayoutKind.Sequential)]
    class TransformComponentDescriptor
    {
        public Vector3 Position;
        public Vector3 Rotation;                          // Euler angles, in DEGREES
        public Vector3 Scale = new Vector3(1, 1, 1);
    }

    [StructLayout(LayoutKind.Sequential)]
    class GameEntityDescriptor
    {
        public TransformComponentDescriptor Transform = new TransformComponentDescriptor();
    }
}

namespace NeelamEditor.EngineWrapper
{
    static class EngineAPI
    {
        private const string _dll = "NeelamEngine.dll";

        [DllImport(_dll)]
        private static extern int CreateGameEntity(GameEntityDescriptor desc);

        public static int CreateGameEntity(GameEntity entity)
        {
            var desc = new GameEntityDescriptor();

            {
                var c = entity.Components.OfType<Transform>().FirstOrDefault();
                Debug.Assert(c != null);
                desc.Transform.Position = c.Position;
                desc.Transform.Rotation = c.Rotation;
                desc.Transform.Scale = c.Scale;
            }

            return CreateGameEntity(desc);
        }

        [DllImport(_dll)]
        private static extern void RemoveGameEntity(int id);

        public static void RemoveGameEntity(GameEntity entity)
        {
            RemoveGameEntity(entity.EntityId);
        }
    }
}
