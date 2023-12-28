set_project("GraphicsBox")
set_version("0.0.1")

set_languages("c++17")

add_rules("mode.debug", "mode.release", "plugin.vsxmake.autoupdate")

add_requires("glfw", "glad", "glm", "stb", "spdlog", "assimp")

if is_plat("windows") then
    add_defines("BOX_PLAT_WINDOWS")
end

includes("FRAME")
includes("Sandbox")