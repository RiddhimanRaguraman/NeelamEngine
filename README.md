# NeelamEngine

A from-scratch game engine: a C++ runtime compiled to a DLL, driven by a WPF editor,
rendering with Vulkan. Work in progress.

- **Runtime:** C++ engine compiled to `NeelamEngine.dll` — Vulkan renderer + a
  data-oriented entity/component layer + a threaded shader hot-reload system.
- **Editor:** WPF (C#) — `NeelamEditor.exe`. Talks to the engine over a small
  `extern "C"` / P/Invoke surface and **hosts the live Vulkan viewport** via a native
  child window (`HwndHost`).
- **Graphics:** Vulkan 1.3 — dynamic rendering, timeline-semaphore frame pacing, VMA
  memory, and runtime HLSL→SPIR-V compilation (DXC) with live shader hot-reload.
- **Build:** [premake5](https://premake.github.io/) generates the Visual Studio solution.
- **Target:** Windows. The editor is WPF (Windows-only); the engine's platform layer is
  isolated to one class so a cross-platform port is a single seam.

## Features

- **Vulkan renderer** — Vulkan 1.3 `dynamicRendering`/`synchronization2`, a single
  timeline semaphore pacing 2 frames in flight, VMA-backed device allocation (with GPU
  leak tracking), and swapchain recreation on resize.
- **Runtime shaders + hot reload** — HLSL is compiled to SPIR-V at runtime with DXC and
  reloaded on save, implemented as an **actor model**: dedicated file-watcher, compile,
  and render threads pass work over lock-free circular command queues, keeping disk I/O
  and compilation off the frame while all Vulkan work stays on one thread.
- **Data-oriented ECS** — entities are ids (`generation | index`); components are stored
  by value in packed, contiguous arrays.
- **STL-free, zero-leak** — hand-rolled containers instead of `std::vector`/`deque`; the
  memory-tracking harness reports a clean run.
- **Editor** — project browser, scene/entity tree, a Transform inspector with drag-to-
  scrub number fields, undo/redo, and a dark theme.
- **CI/CD** — a GitHub Actions pipeline builds the C++ engine and publishes the editor as
  a self-contained Windows release.

## Requirements

- Windows 10/11
- Visual Studio 2022 (toolset `v143`) with the C++ and .NET desktop workloads
- .NET 8 SDK (the editor targets `net8.0-windows`)
- [Vulkan SDK](https://vulkan.lunarg.com/) — the build reads `VULKAN_SDK` (only the
  include path is needed; the loader is pulled in at runtime via volk)

## Build

All build scripts live in the `Neelam\` folder. `premake5.exe` is vendored at
`Neelam\Vendor\bin\premake\`, so nothing extra to install.

### Generate the solution

```
cd Neelam
UberBuildMe.Bat
```

This cleans previous output and runs premake to produce the IDE files
(`Neelam\Neelam.sln` by default).

> **premake regeneration only happens here.** A plain rebuild in the IDE does **not**
> re-run premake — so after adding, moving, or deleting a file, re-run `UberBuildMe.Bat`
> or the new file won't be compiled/linked.

> **Using a different IDE?** Open `Neelam\UberBuildMe.Bat` and change the premake action
> on the last line. Supported actions include `vs2022`, `vs2019`, `gmake2`, `codelite`,
> `xcode4`. See the [premake docs](https://premake.github.io/docs/Using-Premake/).
> The editor is a C# project, so MSBuild (from Visual Studio) is required to build it.

### Compile

Open the generated solution in Visual Studio, set the configuration to `Debug | x64` (or
`Release | x64`), and build. `NeelamEditor` is the startup project; it declares a
dependency on `NeelamEngine`, so the engine DLL builds first and lands beside the editor.

- Per-project output: `Neelam\bin\<Config>-windows-x64\<Project>\`
- Engine + library DLLs are gathered into `Neelam\x64\<Config>\`, next to `NeelamEditor.exe`.

To run the renderer **without** the editor, set `EngineTest` as the startup project — a
console sandbox that brings the engine up standalone.

### Clean

```
cd Neelam
UberCleanAll.Bat
```

Removes generated solution/project files and intermediate output. Re-run
`UberBuildMe.Bat` afterward to regenerate.

## Layout

```
Neelam/
├── NeelamEngine/   # C++ runtime DLL: Vulkan renderer, ECS, threading
├── NeelamEditor/   # C# WPF editor (hosts the Vulkan viewport, P/Invokes the engine)
├── EngineTest/     # console sandbox: unit tests + the no-editor way to run the renderer
├── Libs/           # source-built libraries: Math, File, AnimTime, Manager (each a DLL)
├── Framework/      # shared C++ header, force-included everywhere
├── Vendor/         # third-party deps (incl. bundled premake5)
├── premake5.lua    # solution definition (single source of truth)
├── UberBuildMe.Bat
└── UberCleanAll.Bat
```

## License

See [LICENSE](LICENSE).
