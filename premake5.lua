workspace "OpenGL"
    architecture "x86_64"
    configurations { "Debug", "Release" }


local projectName = "open.gl"
local projectKind = "ConsoleApp"
local lang = "C++"
local standard = (lang) .. "17"

local srcFiles =
{
    "src/**"
}

local excludeSrcFiles =
{
    "src/lib/**",
    "src/include/**"
}

local srcLinksRelease =
{
    "sfml-system",
    "sfml-window",
    "sfml-graphics",
    "glew32.lib"
}

local srcLinksDebug =
{
    "sfml-system-d",
    "sfml-window-d",
    "sfml-graphics-d",
    "glew32.lib"
}

project (projectName)
    kind "ConsoleApp"
    language (lang)
    cppdialect (standard)
    targetdir "bin/%{cfg.buildcfg}"
    location ("src/")

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"
        libdirs { "src/lib/Debug" }
        links (srcLinksDebug)
    
    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"
        libdirs { "src/lib/Release" }
        links (srcLinksRelease)
    

    filter {}
        files (srcFiles)
        removefiles (excludeSrcFiles)
        includedirs { "src/include/" }

    
