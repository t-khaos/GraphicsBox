#pragma once

#include <GLFW/glfw3.h>

class GLFWWindow
{
private:
    GLFWwindow* m_pWindow = nullptr;

public:
    GLFWWindow();
    ~GLFWWindow();
    void Init();
};
