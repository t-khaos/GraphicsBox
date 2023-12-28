#include "PCH.hpp"
#include "Application.hpp"

namespace FRAME
{
    Application::Application() = default;

    Application::~Application() = default;

    void Application::Init()
    {
        auto props = WindowProps();
        props.Title = "App";
        props.Width = 800;
        props.Height = 600;
        m_pWindow = std::make_unique<Window>(props);
    }

    void Application::Update()
    {

        while(m_pWindow.get())
        {
            m_pWindow->OnUpdate();
        }
        
    }
}
