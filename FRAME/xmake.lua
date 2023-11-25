target("FRAME")

    if is_mode("debug") then 
        add_defines("FRAME_MODE_DEBUG")
    elseif is_mode("release") then
        add_defines("FRAME_MODE_RELEASE")
    end
    
    add_defines("FRAME_EXPORT")
    set_kind("shared")

    set_pcxxheader("./PCH.hpp")
    
    add_includedirs("./")

    add_files("./**.cpp")
    add_headerfiles("./(**.hpp)")

    add_packages("glfw", "glad", "glm","stb")

target_end()