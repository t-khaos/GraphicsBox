#include "Bounds.hpp"

float Bounds::GetVolume() const
{
    const glm::vec3 diagonal = GetDiagonal();
    return diagonal.x * diagonal.y * diagonal.z;
}

glm::vec3 Bounds::GetCentre() const
{
    return m_Min + (m_Max - m_Min) / 2.0f;
}

glm::vec3 Bounds::GetDiagonal() const
{
    return m_Max - m_Min;
}

float Bounds::GetSurfaceArea() const
{
    const glm::vec3 diagonal = GetDiagonal();
    return 2.0f * (diagonal.x * diagonal.y + diagonal.x * diagonal.z + diagonal.y * diagonal.z);
}

void Bounds::Combine(const Bounds& box)
{
    m_Min = glm::min(m_Min, box.m_Min);
    m_Max = glm::max(m_Max, box.m_Max);
}

void Bounds::Combine(const glm::vec3& point)
{
    m_Min = glm::min(m_Min, point);
    m_Max = glm::max(m_Max, point);
}

bool Bounds::Overlap(const Bounds& box)
{
    return m_Min.x <= box.m_Max.x && m_Max.x >= box.m_Min.x &&
        m_Min.y <= box.m_Max.y && m_Max.y >= box.m_Min.y &&
        m_Min.z <= box.m_Max.z && m_Max.z >= box.m_Min.z;
}

bool Bounds::Inside(const glm::vec3& point)
{
    return point.x >= m_Min.x && point.x <= m_Max.x &&
        point.y >= m_Min.y && point.y <= m_Max.y &&
        point.z >= m_Min.z && point.z <= m_Max.z;
}