#include "Transform.hpp"

void Transform::SetPosition(const glm::vec3& position)
{
    if (position == m_Position) return;
    m_Position = position;
    m_TranslationMatrix = glm::identity<glm::mat4>();
    m_TranslationMatrix = glm::translate(m_TranslationMatrix, position);
    _updateModelMatrix();
}

void Transform::SetRotationX(float x)
{
    _setRotation(x - m_Rotation.x, glm::vec3(1, 0, 0));
    m_Rotation.x = x;
}

void Transform::SetRotationY(float y)
{
    _setRotation(y - m_Rotation.y, glm::vec3(0, 1, 0));
    m_Rotation.y = y;
}

void Transform::SetRotationZ(float z)
{
    _setRotation(z - m_Rotation.z, glm::vec3(0, 0, 1));
    m_Rotation.z = z;
}

void Transform::SetScale(const glm::vec3& scale)
{
    if (scale == m_Scale) return;
    m_Scale = scale;
    m_ScaleMatrix = glm::identity<glm::mat4>();
    m_ScaleMatrix = glm::scale(m_ScaleMatrix, scale);
    _updateModelMatrix();
}

void Transform::Translate(const glm::vec3& offset)
{
    if (offset == glm::zero<glm::vec3>()) return;
    m_TranslationMatrix = glm::translate(m_TranslationMatrix, offset);
    m_Position += offset;
    _updateModelMatrix();
}

void Transform::RotateX(float offset)
{
    _setRotation(offset, glm::vec3(1, 0, 0));
    m_Rotation.x += offset;
}

void Transform::RotateY(float offset)
{
    _setRotation(offset, glm::vec3(0, 1, 0));
    m_Rotation.y += offset;
}

void Transform::RotateZ(float offset)
{
    _setRotation(offset, glm::vec3(0, 0, 1));
    m_Rotation.z += offset;
}

void Transform::Scale(const glm::vec3& offset)
{
    if (offset == glm::zero<glm::vec3>()) return;
    m_ScaleMatrix = glm::scale(m_ScaleMatrix, offset);
    m_Scale *= offset;
    _updateModelMatrix();
}

void Transform::_updateModelMatrix()
{
    m_Matrix = m_TranslationMatrix * m_RotationMatrix * m_ScaleMatrix;
    m_Inverse = glm::inverse(m_Matrix);
}

void Transform::_setRotation(float offset, const glm::vec3& axis)
{
    if (std::abs(offset) <= FLT_EPSILON)return;
    glm::mat4 offsetRotationMatrix;
    offsetRotationMatrix = glm::rotate(offsetRotationMatrix, glm::radians(offset), axis);
    m_RotationMatrix = offsetRotationMatrix * m_RotationMatrix;
    _updateModelMatrix();
}
