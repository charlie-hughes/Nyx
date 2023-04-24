#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"

namespace Nyx {

    class OrthographicCamera {

        public:

            OrthographicCamera(Window *render_target, float scale=100.0f, glm::vec2 positon={0.0f, 0.0f}, float near=0.01f, float far=10.0f);
            // void   Delete();

            // Set
            void      SetRenderTarget(Window* render_target);
            void      SetScale(float scale);
            void      ChangeScale(float change);
            void      SetPosition(glm::vec2 position);
            void      ChangePosition(glm::vec2 change);
            void      SetNear(float near);
            void      SetFar(float far);


            // Get
            Window*   GetRenderTarget();
            float     GetScale();
            float     GetWidth();
            float     GetHeight();
            glm::vec2 GetPosition();
            float     GetNear();
            float     GetFar();
            glm::mat4 GetProjectionMatrix();

        private:

            Window*   m_render_target;

            float     m_near;
            float     m_far;

            float     m_scale;

            glm::vec2 m_position;
    };
}