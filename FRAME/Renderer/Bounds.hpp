#pragma once

#include <GLM/glm.hpp>
#include <vector>

struct Bounds
{
private:
    glm::vec3 m_Min;
    glm::vec3 m_Max;

public:
    Bounds() = default;

    Bounds(const glm::vec3& minPos, const glm::vec3& maxPos):
        m_Min(minPos), m_Max(maxPos)
    {
    }

    const glm::vec3& GetMin() const { return m_Min; }
    const glm::vec3& GetMax() const { return m_Max; }

    float GetVolume() const;
    glm::vec3 GetCentre() const;
    glm::vec3 GetDiagonal() const;
    float GetSurfaceArea() const;

    void Combine(const Bounds& box);
    void Combine(const glm::vec3& point);
    bool Overlap(const Bounds& box);
    bool Inside(const glm::vec3& point);
};
