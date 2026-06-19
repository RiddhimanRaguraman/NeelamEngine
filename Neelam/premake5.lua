workspace "Neelam"
	architecture "x64"
	startproject "NeelamEditor"

	configurations { "Debug", "Release" }
	location "."

	filter "system:windows"
		systemversion "latest"
	filter {}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"Framework"
	}

	links { "Framework" }

	pchheader "pch.h"
	pchsource "%{prj.name}/pch.cpp"

	forceincludes {
		"Framework.h"
	}

	defines {
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
