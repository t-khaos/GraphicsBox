#pragma once
#include "Window.hpp"

namespace FRAME
{
    class FRAME_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Init();
        void Update();

    private:
        Unique<Window> m_pWindow;
    };

    extern Application* CreatApplication();
}
