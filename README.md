# NeelamEngine

Work-in-progress game engine.

- **Runtime:** C++ engine compiled to a DLL (`NeelamEngine.dll`).
- **Editor:** WPF (C#) — `NeelamEditor.exe`.
- **Graphics:** Vulkan (planned).
- **Build:** [premake5](https://premake.github.io/) generates the Visual Studio solution.
- **Target:** Windows for now. Editor will be ported to a Linux-friendly UI stack later (WPF is Windows-only).

## Build

All build scripts live in the `Neelam\` folder. `premake5.exe` is vendored at `Neelam\Vendor\bin\premake\`, so nothing extra to install.

### Generate the solution

```
cd Neelam
UberBuildMe.Bat
```

This cleans previous output and runs premake to produce the IDE files (`Neelam\Neelam.sln` by default).

> **Using a different IDE?** Open `Neelam\UberBuildMe.Bat` and change the premake action on the last line.
> Supported actions include `vs2022`, `vs2019`, `vs2017`, `gmake2`, `codelite`, `xcode4`. See [premake docs](https://premake.github.io/docs/Using-Premake/) for the full list.

### Compile

Open the generated solution/project files in your IDE, set the configuration to `Debug | x64` (or `Release | x64`), and build. `NeelamEditor` is the startup project.

Build output lands in `Neelam\bin\<Config>-windows-x64\`.

### Clean

```
cd Neelam
UberCleanAll.Bat
```

Removes generated solution/project files and intermediate output. Re-run `UberBuildMe.Bat` afterward to regenerate.

## Layout

```
Neelam/
├── NeelamEngine/   # C++ runtime DLL
├── NeelamEditor/   # C# WPF editor
├── Framework/      # shared C++ headers
├── Vendor/         # third-party deps (incl. bundled premake5)
├── premake5.lua    # solution definition
├── UberBuildMe.Bat
└── UberCleanAll.Bat
```

## License

See [LICENSE](LICENSE).
