#pragma once

#include "PCH.hpp"

struct GLFWwindow;

namespace FRAME
{
    struct GraphicsContext;
    
    struct WindowProps
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;
    };

    struct Window
    {
    public:
        Window(const WindowProps& props);
        ~Window() = default;

        void OnUpdate();

        uint32_t GetWidth() { return m_data.Width; }
        uint32_t GetHeight() { return m_data.Height; }

        void* GetNativeWindow() { return m_pWindow; }

    private:
        void Init(const WindowProps& props);
        void Shutdown();

        GLFWwindow* m_pWindow = nullptr;
        GraphicsContext* m_pContext = nullptr;

        struct WindowData
        {
            std::string Title;
            uint32_t Width;
            uint32_t Height;
        };
        WindowData m_data;
    };
}
