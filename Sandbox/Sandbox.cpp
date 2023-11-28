#include "FRAME.hpp"

class Sandbox : public FRAME::Application
{
public:
    Sandbox()
    {
        std::cout << "Sandbox";
    }

    ~Sandbox() = default;
};

FRAME::Application* FRAME::CreatApplication()
{
    return new Sandbox();
}
