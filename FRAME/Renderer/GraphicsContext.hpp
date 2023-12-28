#pragma once

struct GLFWwindow;

namespace FRAME
{
    struct GraphicsContext
    {
    public:
        GraphicsContext(GLFWwindow* window);
        ~GraphicsContext() = default;

        void Init();
        void SwapBuffers();
    private:
        GLFWwindow* m_pHandle = nullptr;
    };
}
