#include "PCH.hpp"
#include "GraphicsContext.hpp"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace FRAME
{
    GraphicsContext::GraphicsContext(GLFWwindow* window): m_pHandle(window)
    {
    }

    void GraphicsContext::Init()
    {
        glfwMakeContextCurrent(m_pHandle);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    void GraphicsContext::SwapBuffers()
    {
        glfwSwapBuffers(m_pHandle);
    }
}
