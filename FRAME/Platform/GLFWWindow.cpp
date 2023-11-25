#include "GLFWWindow.hpp"

GLFWWindow::GLFWWindow() = default;

GLFWWindow::~GLFWWindow() = default;

void GLFWWindow::Init()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    //MSAA
    glfwWindowHint(GLFW_SAMPLES, 4);
}
