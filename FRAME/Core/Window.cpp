
#include "Window.hpp"
#include "Renderer/GraphicsContext.hpp"

#include <GLFW/glfw3.h>

namespace FRAME
{
    Window::Window(const WindowProps& props)
    {
        Init(props);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
    }

    void Window::Init(const WindowProps& props)
    {
        m_data.Title = props.Title;
        m_data.Width = props.Width;
        m_data.Height = props.Height;
        
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        
        glfwWindowHint(GLFW_SAMPLES, 4);

        m_pWindow = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), props.Title.c_str(),
                                     nullptr, nullptr);

        m_pContext = new GraphicsContext(m_pWindow);
        m_pContext->Init();

        glfwSetWindowUserPointer(m_pWindow, &m_data);

        
    }

    void Window::Shutdown()
    {
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }

}



