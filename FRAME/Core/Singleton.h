#pragma once

template<typename  T>
struct Singleton
{
public:
    virtual ~Singleton() = default;
protected:
    Singleton() = default;
private:
    static T m_pInstance;
public:
    static T& GetInstance()
    {
        static T m_pInstance;
        return m_pInstance;
    }
};
