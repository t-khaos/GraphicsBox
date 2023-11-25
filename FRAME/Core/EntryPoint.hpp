#pragma once

#include "PCH.hpp"
#include "Application.hpp"

int main()
{
    auto app = Box::CreatApplication();
    app->Init();
    app->Update();
    delete app;
}
