workspace "Neelam"
	architecture "x64"
	startproject "NeelamEditor"

	configurations { "Debug", "Release" }
	location "."

	-- Compile each project's .cpp files across all CPU cores (MSVC /MP).
	-- Inherited by every project in the workspace.
	flags { "MultiProcessorCompile" }

	-- Edit-and-Continue debug info (/ZI) disables /MP, so use plain /Zi.
	-- Trade: no editing code mid-debug-session, but Debug builds go parallel.
	editandcontinue "Off"

	filter "system:windows"
		systemversion "latest"
	filter {}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-----------------------------------------------------------------------------
-- VULKAN SDK -- CHANGE THIS IF YOUR INSTALL DIFFERS
-----------------------------------------------------------------------------
-- The Vulkan SDK installer sets a VULKAN_SDK environment variable, so that is
-- used automatically when present and the path below is only a fallback.
--
-- Expected layout under this folder:
--     Include\vulkan\vulkan.h     <- headers (plus Volk\ and vma\)
--     Lib\dxcompiler.lib          <- DXC import library (x64)
--     Bin\dxcompiler.dll          <- DXC runtime, copied next to the exe
--
-- vulkan-1.lib is NOT linked: volk LoadLibrary's vulkan-1.dll at runtime
-- (volkInitialize), so only the SDK INCLUDE path is needed for Vulkan itself.
--
-- Normalized to forward slashes so the two spellings of VULKAN_SDK (the env
-- var uses backslashes, the fallback below does not) behave identically.
local vulkanSDK = (os.getenv("VULKAN_SDK") or "C:/VulkanSDK/1.4.350.0"):gsub("\\", "/")

-- cmd's `copy` treats a leading / as a switch, so the post-build below needs
-- the backslash spelling of the same path.
local dxcompilerDll = path.translate(vulkanSDK .. "/Bin/dxcompiler.dll", "\\")

-----------------------------------------------------------------------------
-- AZUL SCRATCH FOLDER
-----------------------------------------------------------------------------
-- Framework.h keeps its memory-tracking scratch files (DLL_COUNT.bin,
-- MemTracker.bin) in <AZUL_PATH>\Azul -- NOT the solution folder.
-- Trace::GetAzulPath() reads the AZUL_PATH user environment variable, so the
-- location is machine-wide and shared by every solution built against this
-- framework.
--
-- DLL_COUNT.bin is a reference count across the loaded DLLs. The first module
-- to start prints the "**  Framework: ... **" banner; the rest just increment.
-- A run that does NOT exit cleanly (Stop Debugging, crash, killed process)
-- never unwinds the count and leaves the file behind, which silently
-- suppresses the banner on every later run. Hence the prebuild wipe.
local azulPath = os.getenv("AZUL_PATH")

--=============================================================================
-- Include-path helper: returns a folder plus EVERY subfolder under it, at ANY
-- depth. Feeding this to includedirs is what lets a header be #included
-- unprefixed no matter how deep it sits -- #include "Instance.h" resolves the
-- same whether the class lives in NeelamEngine/Common or in
-- NeelamEngine/Vulkan/VulkanAPI/Instance.
--
-- This replaces the old one-level-deep loop. The imported Vulkan tree nests
-- three folders down (Vulkan/VulkanAPI/Buffer), which that loop never reached.
--
-- Depth is unlimited and there is no recursion to run away: os.matchdirs walks
-- the tree once and hands back a flat list.
--
-- Skipped: dot-folders (.vs, .git) and build output (obj, bin, x64) -- matched
-- on every path segment, so a nested one is caught too.
--=============================================================================
local function includeTree(root)
	local skipDir = { obj = true, bin = true, x64 = true, intermediate = true }

	local dirs = { root }

	for _, dir in ipairs(os.matchdirs(root .. "/**")) do
		local keep = true

		for segment in dir:gmatch("[^/\\]+") do
			if segment:sub(1, 1) == "." or skipDir[segment:lower()] then
				keep = false
				break
			end
		end

		if keep then
			table.insert(dirs, dir)
		end
	end

	return dirs
end

-- Builds a library (Math, File, AnimTime, Manager) from source as its own DLL.
--   name      : project name / Libs subfolder (e.g. "Math")
--   apiPrefix : export-macro prefix (e.g. "MATH" -> MATH_USE_DLL, MATH_LIBRARY_EXPORTS)
local function defineLibrary(name, apiPrefix)
	project(name)
		location   ("Libs/" .. name)
		language   "C++"
		kind       "SharedLib"
		cppdialect "C++17"
		staticruntime "Off"
		characterset ("MBCS")

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("Libs/%{prj.name}/obj/" .. outputdir .. "/%{prj.name}")

		files {
			"Libs/" .. name .. "/include/**.h",
			"Libs/" .. name .. "/src/**.h",
			"Libs/" .. name .. "/src/**.cpp"
		}

		includedirs {
			"Libs/" .. name .. "/include",
			"Libs/" .. name .. "/src",
			"Framework"
		}

		links { "Framework" }

		-- Precompile the large, force-included Framework.h via pch.h to cut build
		-- time. pch.h is force-included (not Framework.h) so the library sources
		-- compile unchanged -- no need to add #include "pch.h" to each .cpp.
		pchheader "pch.h"
		pchsource ("Libs/" .. name .. "/src/pch.cpp")
		forceincludes { "pch.h" }

		defines {
			apiPrefix .. "_USE_DLL",			-- turn on the dll interface
			apiPrefix .. "_LIBRARY_EXPORTS",	-- this project exports the symbols

			-- FEATURE TIER: memory tracking only. No USE_THREAD_FRAMEWORK and no
			-- USE_VULKAN_FRAMEWORK, so this project never parses volk / VMA and
			-- needs no Vulkan SDK include path. See the tier notes in Framework.h
			-- -- these are per-project defines now, not #defines in the header.
			"MEM_TRACKER_ENABLED",

			'WINDOWS_TARGET_PLATFORM="$(TargetPlatformVersion)"',
			'SOLUTION_DIR=R"($(SolutionDir))"',
			'TOOLS_VERSION=R"($(VCToolsVersion))"',
			'LOCAL_WORKING_DIR=R"($(LocalDebuggerWorkingDirectory))"'
		}

		filter "configurations:Debug"
			runtime "Debug"
			symbols "On"
			defines { "_DEBUG" }

		filter "configurations:Release"
			runtime "Release"
			optimize "On"
			defines { "NDEBUG" }

		filter "action:vs2022"
			toolset "v143"

		filter "action:vs*"
			postbuildcommands {
				'{MKDIR} "%{wks.location}/x64/%{cfg.buildcfg}/"',
				'{COPY} "%{cfg.buildtarget.abspath}" "%{wks.location}/x64/%{cfg.buildcfg}/"'
			}
		filter {}
end

-- Builds a library's unit-test sandbox as a standalone console app.
-- Not linked to the engine/editor; set it as the startup project to run
-- the tests, then switch back to the editor. (A future Dist config can drop these.)
--   name      : test project name  (e.g. "MathTest")
--   apiPrefix : consumed lib's macro prefix (e.g. "MATH")
--   libName   : lib project + Libs subfolder to test (e.g. "Math")
local function defineUnitTest(name, apiPrefix, libName)
	project(name)
		location   ("Libs/" .. libName)
		language   "C++"
		kind       "ConsoleApp"
		cppdialect "C++17"
		staticruntime "Off"
		characterset ("MBCS")

		-- Output the exe into the lib's own folder so it sits next to <lib>.dll;
		-- no copy step needed to run the test standalone.
		targetdir ("bin/" .. outputdir .. "/" .. libName)
		objdir ("Libs/" .. libName .. "/obj/" .. outputdir .. "/%{prj.name}")

		-- Some test suites use "*_Group.cpp" unity files that #include the
		-- individual test .cpp files. Compiling both the group and the file it
		-- includes defines every test twice (LNK2005). So exclude exactly the
		-- files that a group #includes, and compile everything else -- the groups,
		-- main, and support files (e.g. Mat4Test.cpp).
		local testDir = "Libs/" .. libName .. "/Test/"
		local included = {}
		for _, g in ipairs(os.matchfiles(testDir .. "*_Group.cpp")) do
			for inc in (io.readfile(g) or ""):gmatch('#include%s+"([^"]-%.[cC][pP][pP])"') do
				included[inc:match("[^/\\]+$"):lower()] = true
			end
		end
		files { testDir .. "**.h" }
		for _, f in ipairs(os.matchfiles(testDir .. "**.cpp")) do
			if not included[f:match("[^/\\]+$"):lower()] then
				files { f }
			end
		end

		includedirs {
			"Libs/" .. libName .. "/include",
			"Libs/" .. libName .. "/Test",
			"Framework"
		}

		links { "Framework", libName }		-- consume the lib DLL under test

		-- Precompile Framework.h (same rationale as the library helper above).
		pchheader "pch.h"
		pchsource ("Libs/" .. libName .. "/Test/pch.cpp")
		forceincludes { "pch.h" }

		defines {
			apiPrefix .. "_USE_DLL",	-- consume via dllimport
			"_CONSOLE",

			-- FEATURE TIER: memory tracking only (same as the lib under test).
			"MEM_TRACKER_ENABLED",

			'WINDOWS_TARGET_PLATFORM="$(TargetPlatformVersion)"',
			'SOLUTION_DIR=R"($(SolutionDir))"',
			'TOOLS_VERSION=R"($(VCToolsVersion))"',
			'LOCAL_WORKING_DIR=R"($(LocalDebuggerWorkingDirectory))"'
		}

		filter "configurations:Debug"
			runtime "Debug"
			symbols "On"
			defines { "_DEBUG" }

		filter "configurations:Release"
			runtime "Release"
			optimize "On"
			defines { "NDEBUG" }

		filter "action:vs2022"
			toolset "v143"
		filter {}
end

--=============================================================================
-- NeelamEngine -- the engine DLL.
--
-- Holds BOTH halves of the engine now: the component/entity layer that was
-- already here (Common, Component, EngineApi, Utilities, Dll_stuff) and the
-- imported Vulkan renderer (Engine, Game, Source, ThreadManagement, Vulkan,
-- HLSL_Shaders). Folder names are kept exactly as each half had them.
--
-- This is the ONLY project in the Vulkan feature tier -- see the defines block.
--=============================================================================
project "NeelamEngine"
	location "NeelamEngine"
	language "C++"
	kind "SharedLib"
	cppdialect "C++17"
	staticruntime "Off"
	characterset ("MBCS")

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{prj.name}/obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.cpp"
	}

	-- Vulkan/VulkanAPI/Utilities/VulkanImpl.cpp -- the ONE TU that compiles the
	-- volk + VMA bodies -- is picked up by the glob above. It deliberately does
	-- NOT live in the shared "Framework" project: shared items are compiled by
	-- every consumer, and the lib DLLs are not in the Vulkan tier (no
	-- USE_VULKAN_FRAMEWORK, no SDK include path).

	-- Every folder under NeelamEngine/, at any depth, discovered at generate
	-- time. Re-run premake after adding a folder.
	includedirs (includeTree("NeelamEngine"))

	-- External include paths (not part of this project's source tree).
	-- includedirs is additive, so these append to the tree above.
	includedirs {
		"Framework",
		"Libs/Math/include",
		"Libs/File/include",
		"Libs/AnimTime/include",
		"Libs/Manager/include",			-- ManBase / DLink / CompareStrategyBase
		vulkanSDK .. "/Include"			-- <vulkan/vulkan.h>, <Volk/volk.h>, <vma/...>
	}

	-- Framework (shared items) + the source-built libraries. DLL linking is NOT
	-- transitive: any module that directly calls into a DLL needs that DLL's own
	-- import lib, so each one is listed here (and its *_USE_DLL define set below).
	links { "Framework", "Math", "File", "AnimTime", "Manager" }

	-- DXC (DirectX Shader Compiler) -- compiles HLSL to SPIR-V at RUNTIME, which
	-- is what makes the shaders hot-reloadable. Unlike volk this IS a normal
	-- import lib, so link dxcompiler.lib and ship dxcompiler.dll (post-build
	-- below). dxil.dll is only needed for DXIL/DirectX output, not SPIR-V.
	libdirs { vulkanSDK .. "/Lib" }
	links   { "dxcompiler" }

	-- Precompile Framework.h via pch.h to cut build time (same as the libraries).
	pchheader "pch.h"
	pchsource "NeelamEngine/Dll_stuff/pch.cpp"
	forceincludes { "pch.h" }

	-- C4251 "needs to have dll-interface to be used by clients". Engine and Game
	-- are dllexport whole-class, and their members (vk::Window, vk::Swapchain,
	-- Azul::AnimTimer, std::thread inside FileThread, ...) are not individually
	-- exported. That warning exists for a DLL whose consumers are built by
	-- someone else with a different STL/compiler; here every consumer is in this
	-- same solution and built the same way, so it is pure noise.
	disablewarnings { "4251" }

	defines {
		"NEELAM_USE_DLL",		-- this DLL's own API interface is active
		"NEELAM_LIBRARY_EXPORTS",	-- and this project exports it (dllexport)
		"MATH_USE_DLL",			-- consume Math via dllimport
		"FILE_USE_DLL",			-- consume File via dllimport
		"ANIM_TIME_USE_DLL",	-- consume AnimTime via dllimport
		"MANAGER_USE_DLL",		-- consume Manager via dllimport

		-- FEATURE TIER: the engine is the only project in the VULKAN tier, which
		-- is the top one and needs all three (Framework.h enforces that with an
		-- #error). USE_VULKAN_FRAMEWORK is what makes Framework.h include volk +
		-- VMA and expose VK_Try / Validation:: / vk::VulkanAllocator -- so it must
		-- be paired with the SDK include path added above.
		"MEM_TRACKER_ENABLED",
		"USE_THREAD_FRAMEWORK",
		"USE_VULKAN_FRAMEWORK",

		-- Turns on the Win32 half of <vulkan/vulkan.h>: VkWin32SurfaceCreateInfoKHR
		-- and vkCreateWin32SurfaceKHR. Without this, Surface will not compile.
		"VK_USE_PLATFORM_WIN32_KHR",

		-- We use volk: the vk* names are function POINTERS (defined once, in
		-- VulkanImpl.cpp), not import-lib symbols. This suppresses the header's
		-- prototype declarations so they don't clash with volk's pointers.
		"VK_NO_PROTOTYPES",

		'WINDOWS_TARGET_PLATFORM="$(TargetPlatformVersion)"',
		'SOLUTION_DIR=R"($(SolutionDir))"',
		'TOOLS_VERSION=R"($(VCToolsVersion))"',
		'LOCAL_WORKING_DIR=R"($(LocalDebuggerWorkingDirectory))"'
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		defines { "_DEBUG" }

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		defines { "NDEBUG" }

	filter "action:vs2022"
		toolset "v143"

	filter "action:vs*"
		-- Wipe any stale Azul scratch folder before building, so a leftover
		-- DLL_COUNT.bin from a killed run does not suppress the framework banner
		-- (see the AZUL_PATH notes at the top). Both paths are wiped: AZUL_PATH is
		-- where the framework actually looks, and $(SolutionDir) is kept because
		-- that is where it lands if AZUL_PATH is ever unset.
		prebuildcommands {
			'if exist "$(SolutionDir)Azul" rmdir /S /Q "$(SolutionDir)Azul"'
		}

		if azulPath then
			prebuildcommands {
				'if exist "' .. azulPath .. '\\Azul" rmdir /S /Q "' .. azulPath .. '\\Azul"'
			}
		end

		-- dxcompiler.dll goes into the SHARED x64 folder rather than this
		-- project's own OutDir: that folder is what EngineTest (and later the
		-- editor) copies next to its exe, and a DLL is searched for in the
		-- APPLICATION's directory, not the loading DLL's.
		postbuildcommands {
			'{MKDIR} "%{wks.location}/x64/%{cfg.buildcfg}/"',
			'{COPY} "%{cfg.buildtarget.abspath}" "%{wks.location}/x64/%{cfg.buildcfg}/"',
			'copy /Y "' .. dxcompilerDll .. '" "$(SolutionDir)x64\\$(Configuration)\\" >nul'
		}
	filter {}

group "Libs"
	defineLibrary("Math", "MATH")
	defineLibrary("File", "FILE")
	defineLibrary("AnimTime", "ANIM_TIME")
	-- Doubly-linked list + manager pattern + CompareStrategy. Pure container
	-- code (Azul::), no Vulkan -- so it sits in the memory-tracking tier with the
	-- other libs. CameraNodeMan / ShaderObjectNodeMan in the engine derive from
	-- its ManBase / DLink / CompareStrategyBase.
	defineLibrary("Manager", "MANAGER")
group ""

group "Tests"
	defineUnitTest("MathTest", "MATH", "Math")
	defineUnitTest("FileTest", "FILE", "File")

	-- Integration sandbox for the whole engine, and the standalone (no editor)
	-- way to run the Vulkan renderer -- make it the startup project for that.
	-- Links NeelamEngine.dll. Output stays inside the EngineTest folder,
	-- separate from the editor, since this is just a testing setup.
	project "EngineTest"
		location "EngineTest"
		language "C++"
		kind "ConsoleApp"
		cppdialect "C++17"
		staticruntime "Off"
		characterset ("MBCS")

		-- keep this test's build output inside its own folder (not the editor's)
		targetdir ("EngineTest/x64/%{cfg.buildcfg}")
		objdir ("EngineTest/obj/" .. outputdir)

		files {
			"EngineTest/**.h",
			"EngineTest/**.cpp"
		}

		-- go through every subfolder (the engine's and this project's) at ANY
		-- depth and add it as an include dir, so any header is reachable
		-- unprefixed -- Main.cpp says #include "Game.h", not the folder path.
		includedirs (includeTree("NeelamEngine"))
		includedirs (includeTree("EngineTest"))

		includedirs {
			"Framework",
			"Libs/Math/include",
			"Libs/File/include",
			"Libs/AnimTime/include",
			"Libs/Manager/include",
			vulkanSDK .. "/Include"		-- Engine.h pulls in Vulkan types
		}

		-- Link the engine (its NEELAM_API exports produce NeelamEngine.lib).
		-- Math/File/AnimTime/Manager must be linked explicitly too: DLL linking is
		-- NOT transitive -- any module that directly calls into a DLL (e.g. this
		-- test constructing an Azul::Vec3) needs that DLL's own import lib.
		--
		-- dxcompiler is NOT linked here: only the engine calls DXC. This exe just
		-- needs dxcompiler.dll to sit next to it, which the copy step below does.
		links { "Framework", "NeelamEngine", "Math", "File", "AnimTime", "Manager" }

		forceincludes { "Framework.h" }

		-- See the note on the engine project -- Engine/Game are dllimport here.
		disablewarnings { "4251" }

		-- Vulkan IMPLICIT LAYERS -- the "[OBS] graphics-hook.dll loaded..." noise.
		--
		-- Overlay/capture tools register implicit layers under
		-- HKLM\SOFTWARE\Khronos\Vulkan\ImplicitLayers, and the Vulkan loader pulls
		-- every one of them into ANY process that calls vkCreateInstance -- the
		-- tool does not have to be running. That is why OBS lines show up with OBS
		-- closed. Each layer's JSON declares a "disable_environment" key that
		-- switches just that layer off for one process; setting them as DEBUGGER
		-- env vars keeps the change local to running this project from VS.
		--
		-- Uncomment a line to also drop that overlay. Overlays hook
		-- vkQueuePresentKHR, so they are worth eliminating first whenever
		-- present/swapchain behaviour looks strange.
		debugenvs {
			"DISABLE_VULKAN_OBS_CAPTURE=1",				-- VK_LAYER_OBS_HOOK
		--	"DISABLE_VK_LAYER_VALVE_steam_overlay_1=1",	-- Steam overlay
		--	"EOS_OVERLAY_DISABLE_VULKAN_WIN64=1",		-- Epic EOS overlay
		}

		defines {
			"NEELAM_USE_DLL",	-- consume the engine API via dllimport
			"MATH_USE_DLL",
			"FILE_USE_DLL",
			"ANIM_TIME_USE_DLL",
			"MANAGER_USE_DLL",
			"_CONSOLE",

			-- FEATURE TIER: this exe includes Game.h -> Engine.h -> the vk::
			-- headers, so it parses the same Vulkan declarations the engine does
			-- and needs the same three defines. It does not DEFINE any volk/VMA
			-- bodies -- VulkanImpl.cpp lives in the engine DLL and stays there.
			"MEM_TRACKER_ENABLED",
			"USE_THREAD_FRAMEWORK",
			"USE_VULKAN_FRAMEWORK",
			"VK_USE_PLATFORM_WIN32_KHR",
			"VK_NO_PROTOTYPES",

			'WINDOWS_TARGET_PLATFORM="$(TargetPlatformVersion)"',
			'SOLUTION_DIR=R"($(SolutionDir))"',
			'TOOLS_VERSION=R"($(VCToolsVersion))"',
			'LOCAL_WORKING_DIR=R"($(LocalDebuggerWorkingDirectory))"'
		}

		filter "configurations:Debug"
			runtime "Debug"
			symbols "On"
			defines { "_DEBUG" }

		filter "configurations:Release"
			runtime "Release"
			optimize "On"
			defines { "NDEBUG" }

		filter "action:vs2022"
			toolset "v143"

		filter "action:vs*"
			-- copy the engine + lib DLLs and dxcompiler.dll (all gathered in
			-- <solution>/x64/<cfg> by their own post-builds) next to this exe so it
			-- runs from its own folder.
			postbuildcommands {
				'xcopy /Y /D "$(SolutionDir)x64\\$(Configuration)\\*.dll" "$(TargetDir)" > nul'
			}
		filter {}
group ""

group "Shared"
project "Framework"
	location "Framework"
	language "C++"
	kind "SharedItems"

	files {
		"Framework/**.h",
		"Framework/**.hpp",
		"Framework/**.inl",
		"Framework/**.cpp"
	}

	includedirs {
		"Framework"
	}

group ""
externalproject "NeelamEditor"
	location "NeelamEditor"
	uuid (os.uuid("NeelamEditor"))
	kind "WindowedApp"
	language "C#"

	-- The editor loads NeelamEngine.dll via P/Invoke, so there is no compile-time
	-- reference for VS to infer a build order from. Without this, hitting F5 builds
	-- ONLY the editor and the engine DLL is stale (or absent -- e.g. the first
	-- Release build), giving a DllNotFoundException at runtime.
	-- This records a solution-level dependency, which also pulls in
	-- Math/File/AnimTime/Manager through the engine's own references.
	dependson { "NeelamEngine" }
group ""
