#include "FRAME.hpp"

class Sandbox : public Box::Application
{
public:
    Sandbox()
    {
        std::cout << "Sandbox";
    }

    ~Sandbox() = default;
};

REGISTER_APPLICATION(Sandbox)
