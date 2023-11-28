#pragma once

#include "PCH.hpp"
#include "Application.hpp"

int main()
{
    auto app = FRAME::CreatApplication();
    app->Init();
    app->Update();
    delete app;
}
