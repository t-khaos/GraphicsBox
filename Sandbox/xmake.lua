target("Sandbox")

    set_kind("binary")

    add_includedirs("../FRAME/")
    
    add_files("./**.cpp")
    add_headerfiles("./(**.hpp)")

    add_deps("FRAME")
    add_packages("glfw", "glad", "glm","stb")

target_end()