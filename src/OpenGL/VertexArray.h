#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"

namespace Nyx {

    class VertexArray {

        public:

            VertexArray();
            void Delete();

            void SetAttribute(VertexBuffer* vertex_buffer, int index, int num_components, GLsizei stride, const void* offset);

            void Bind();
            void UnBind();

            GLuint ID();

        private:

            GLuint m_ID;

    };
}
