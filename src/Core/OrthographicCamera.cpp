#include "OrthographicCamera.h"

namespace Nyx
{

    OrthographicCamera::OrthographicCamera(Window* render_target, float scale, glm::vec2 positon, float near, float far) {
        m_render_target = render_target;
        m_scale         = scale;
        m_near          = near;
        m_far           = far;
        m_position      = positon;
    }

    // void OrthographicCamera::Delete() {
        
    // }

    void OrthographicCamera::SetRenderTarget(Window* render_target) {
        m_render_target = render_target;
    }

    void OrthographicCamera::SetScale(float scale) {
        m_scale = std::clamp(scale, 0.1f, 1000.0f);
    }

    void OrthographicCamera::ChangeScale(float change) {
        m_scale += change;
        m_scale = std::clamp(m_scale, 0.1f, 1000.0f);
    }

    void OrthographicCamera::SetPosition(glm::vec2 position) {
        m_position = position;
    }

    void OrthographicCamera::ChangePosition(glm::vec2 change) {
        m_position += change;
    }

    void OrthographicCamera::SetNear(float near) {
        m_near = near;
    }

    void OrthographicCamera::SetFar(float far) {
        m_far = far;
    }

    Window* OrthographicCamera::GetRenderTarget() {
        return m_render_target;
    }

    float OrthographicCamera::GetScale() {
        return m_scale;
    }

    float OrthographicCamera::GetWidth() {
        return (float)m_render_target->GetWidth() / m_scale;
    }

    float OrthographicCamera::GetHeight() {
        return (float)m_render_target->GetHeight() / m_scale;
    }

    glm::vec2 OrthographicCamera::GetPosition() {
        return m_position;
    }

    float   OrthographicCamera::GetNear() {
        return m_near;
    }

    float   OrthographicCamera::GetFar() {
        return m_far;
    }

    glm::mat4 OrthographicCamera::GetProjectionMatrix() {

        float width  = (float)m_render_target->GetWidth();
        float height = (float)m_render_target->GetHeight();
        
        glm::mat4 projection = glm::ortho(0.0f, width / m_scale, 0.0f, height / m_scale, m_near, m_far);
        glm::vec3 translation = { -m_position.x + ( width / 2 ) / m_scale, -m_position.y + ( height / 2 ) / m_scale, -1.0f };

        return glm::translate(projection, translation);
    }
} 
