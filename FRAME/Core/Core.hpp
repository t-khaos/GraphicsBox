#pragma once

#ifdef FRAME_EXPORT
#define FRAME_API __declspec(dllexport)
#else
    #define FRAME_API __declspec(dllimport)
#endif // FRAME_API


namespace FRAME
{
    template<typename T>
    using Unique = std::unique_ptr<T>;
    template<typename T, typename... Args>
    constexpr Unique<T> CreateUnique(Args&&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Shared = std::shared_ptr<T>;
    template<typename T, typename... Args>
    constexpr Shared<T> CreateShared(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}
