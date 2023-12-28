#pragma once

#ifdef FRAME_EXPORT
    #define FRAME_API __declspec(dllexport)
#else
    #define FRAME_API __declspec(dllimport)
#endif // FRAME_API
