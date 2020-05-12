workspace "Arcjet"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		"%{prj.name}/vendor/spdlog/include"
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