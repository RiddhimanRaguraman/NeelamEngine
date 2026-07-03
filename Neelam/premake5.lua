workspace "Neelam"
	architecture "x64"
	startproject "NeelamEditor"

	configurations { "Debug", "Release" }
	location "."

	filter "system:windows"
		systemversion "latest"
	filter {}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Builds a Keenan library (Math, File) from source as its own DLL.
--   name      : project name / Libs subfolder (e.g. "Math")
--   apiPrefix : export-macro prefix (e.g. "MATH" -> MATH_USE_DLL, MATH_LIBRARY_EXPORTS)
local function keenanLib(name, apiPrefix)
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
			"Libs/" .. name .. "/src/**.cpp"
		}

		includedirs {
			"Libs/" .. name .. "/include",
			"Framework"
		}

		links { "Framework" }
		forceincludes { "Framework.h" }

		defines {
			apiPrefix .. "_USE_DLL",			-- turn on the dll interface
			apiPrefix .. "_LIBRARY_EXPORTS",	-- this project exports the symbols
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
local function keenanTest(name, apiPrefix, libName)
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

		-- Some Keenan test suites use "*_Group.cpp" unity files that #include the
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
		forceincludes { "Framework.h" }

		defines {
			apiPrefix .. "_USE_DLL",	-- consume via dllimport
			"_CONSOLE",
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

	includedirs {
		"%{prj.name}",
		"Framework",
		"Libs/Math/include",
		"Libs/File/include",
		"Libs/AnimTime/include"
	}

	-- Auto-add every source subfolder of the engine as an include dir,
	-- so new feature folders need no premake edit (skips the obj tree).
	for _, dir in ipairs(os.matchdirs("NeelamEngine/**")) do
		if not dir:find("obj") then
			includedirs { dir }
		end
	end

	-- Framework (shared items) + the source-built Keenan libraries.
	links { "Framework", "Math", "File", "AnimTime" }

	forceincludes {
		"Framework.h"
	}

	defines {
		"MATH_USE_DLL",			-- consume Math via dllimport
		"FILE_USE_DLL",			-- consume File via dllimport
		"ANIM_TIME_USE_DLL",	-- consume AnimTime via dllimport
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
		prebuildcommands {
			'if exist "$(SolutionDir)Azul" rmdir /S /Q "$(SolutionDir)Azul"'
		}
		postbuildcommands {
			'{MKDIR} "%{wks.location}/x64/%{cfg.buildcfg}/"',
			'{COPY} "%{cfg.buildtarget.abspath}" "%{wks.location}/x64/%{cfg.buildcfg}/"'
		}
	filter {}

group "Libs"
	keenanLib("Math", "MATH")
	keenanLib("File", "FILE")
	keenanLib("AnimTime", "ANIM_TIME")
group ""

group "Tests"
	keenanTest("MathTest", "MATH", "Math")
	keenanTest("FileTest", "FILE", "File")
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
group ""
