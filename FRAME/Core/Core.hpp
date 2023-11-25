#pragma once

#ifdef FRAME_EXPORT
#define FRAME_API __declspec(dllexport)
#else
    #define FRAME_API __declspec(dllimport)
#endif // FRAME_API

#ifdef FRAME_MODE_DEBUG
#define FRAME_ASSERT(x,...){ if (!(x)) { LOG_DEV_ERROR("Assertion Failed:{0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define FRAME_ASSERT(x, ...)
#endif

#define REGISTER_APPLICATION(x)\
Box::Application* Box::CreatApplication()\
{\
    return new Sandbox();\
}
