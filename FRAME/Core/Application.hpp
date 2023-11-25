#pragma once

#include "PCH.hpp"

namespace Box
{
    class FRAME_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Init();
        void Update();
    };

    extern Application* CreatApplication();
}
