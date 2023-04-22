#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Nyx {

    class VertexBuffer {

        public:

            VertexBuffer();
            void Delete();

            void SetStaticBuffer(GLsizeiptr size, const void* data);
            void SetDynamicBuffer(GLsizeiptr size, const void* data);
            void SetDynamicBuffer(GLsizeiptr size);

            void FillBuffer(const void* data);

            void Bind();
            void UnBind();

            GLuint ID();
            GLsizeiptr Size();

        private:

            GLuint     m_ID;

            GLsizeiptr m_size = 0;
    };
}