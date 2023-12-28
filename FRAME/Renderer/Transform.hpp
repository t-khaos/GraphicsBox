#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

struct Transform
{
private:
    glm::mat4 m_Matrix;
    glm::mat4 m_Inverse;

    glm::mat4 m_TranslationMatrix;
    glm::mat4 m_RotationMatrix;
    glm::mat4 m_ScaleMatrix;

    glm::vec3 m_Position;
    glm::vec3 m_Rotation;
    glm::vec3 m_Scale = glm::vec3{1, 1, 1};

public:
    Transform() = default;

    //getter
    const glm::vec3& GetPosition() const { return m_Position; }
    const glm::vec3& GetScale() const { return m_Scale; }
    float GetRotationX() const { return m_Rotation.x; }
    float GetRotationY() const { return m_Rotation.y; }
    float GetRotationZ() const { return m_Rotation.z; }

    glm::mat4 GetModelMatrix() const { return m_Matrix; }

    glm::mat4 GetModelMatrixInverse() const { return m_Inverse; }

    //setter
    void SetPosition(const glm::vec3& position);
    void SetRotationX(float x);
    void SetRotationY(float y);
    void SetRotationZ(float z);
    void SetScale(const glm::vec3& scale);

    //
    void Translate(const glm::vec3& offset);
    void RotateX(float offset);
    void RotateY(float offset);
    void RotateZ(float offset);
    void Scale(const glm::vec3& offset);

private:
    void _updateModelMatrix();
    void _setRotation(float offset, const glm::vec3& axis);
};
