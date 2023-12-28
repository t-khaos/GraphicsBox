#pragma once
#include "Window.hpp"

namespace FRAME
{
    struct FRAME_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Init();
        void Update();

    private:
        std::unique_ptr<Window> m_pWindow;
    };

    extern Application* CreatApplication();
}
