using System.Diagnostics;
using System.IO;
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

        // Subfolder holding the native DLLs in a packaged build. Dev builds leave them
        // beside the exe (premake's postbuildcommands gather them into x64\<cfg>\), so
        // this folder simply won't exist there and normal probing applies.
        private const string _nativeDir = "Engine";

        [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        private static extern bool SetDllDirectory(string lpPathName);

        // Teach the OS loader about the Engine\ subfolder. This has to be the Win32 call
        // rather than a managed resolver: NeelamEngine.dll imports Math/File/AnimTime, and
        // those get resolved by the OS loader, which never consults a DllImportResolver.
        // SetDllDirectory inserts into the process-wide search order, so the whole
        // dependency chain resolves out of one folder.
        private static void AddNativeProbePath()
        {
            var dir = Path.Combine(AppContext.BaseDirectory, _nativeDir);
            if (!Directory.Exists(dir)) return;

            if (!SetDllDirectory(dir))
            {
                Debug.WriteLine($"SetDllDirectory({dir}) failed: {Marshal.GetLastWin32Error()}");
            }
        }

        // The runtime resolves a [DllImport] lazily, on the first call. That first call
        // drags in NeelamEngine.dll plus Math/File/AnimTime and the debug CRT -- on
        // whatever thread asked for it, which is the UI thread. Loading the module up
        // front on a worker keeps that cost off the first Add Entity click and off the
        // project-load path (Scene.OnDeserialized activates entities, and each activation
        // is a CreateGameEntity call). The OS refcounts the module, so the DllImport that
        // follows finds it already resident.
        public static void Preload()
        {
            // Synchronous: SetDllDirectory is process-global, so it must land before any
            // engine module load races it.
            AddNativeProbePath();

            Task.Run(() =>
            {
                try
                {
                    NativeLibrary.Load(_dll, typeof(EngineAPI).Assembly, null);
                }
                catch (Exception ex)
                {
                    // Not fatal: the real DllImport will surface a proper DllNotFoundException
                    // at the call site if the engine is genuinely missing.
                    Debug.WriteLine($"Engine preload failed: {ex.Message}");
                }
            });
        }

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
