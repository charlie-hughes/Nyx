#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Nyx {

    class IndexBuffer {

        public:

            IndexBuffer();
            void Delete();

            void SetStaticBuffer(GLsizeiptr size, const void* indices);
            void SetDynamicBuffer(GLsizeiptr size, const void* indices);
            void SetDynamicBuffer(GLsizeiptr size);

            void FillBuffer(const void* data);

            void Bind();
            void UnBind();

        private:

            GLuint     m_ID;

            GLsizeiptr m_size;

    };

}