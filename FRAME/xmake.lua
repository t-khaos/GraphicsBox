target("FRAME")

    if is_mode("release") then
        add_defines("NDEBUG")
    end
    
    add_defines("FRAME_EXPORT")
    set_kind("shared")

    set_pcxxheader("./PCH.hpp")
    
    add_includedirs("./")

    add_files("./**.cpp")
    add_headerfiles("./(**.hpp)")
    add_headerfiles("./(**.h)")

    add_packages("glfw", "glad", "glm", "stb", "spdlog", "assimp")

target_end()