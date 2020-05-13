workspace "Arcjet"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Arcjet/vendor/GLFW/include"

include "Arcjet/vendor/GLFW"

project "Arcjet"
	location "Arcjet"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ajpch.h"
	pchsource "Arcjet/src/ajpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AJ_PLATFORM_WINDOWS",
			"AJ_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AJ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AJ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AJ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Arcjet/vendor/spdlog/include",
		"Arcjet/src"
	}

	links
	{
		"Arcjet"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AJ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AJ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AJ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AJ_DIST"
		optimize "On"