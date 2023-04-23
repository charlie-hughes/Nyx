#include "VertexBuffer.h"

namespace Nyx {

    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &m_ID);
    }

    void VertexBuffer::Delete() {
        glDeleteBuffers(1, &m_ID);
    }

    void VertexBuffer::SetStaticBuffer(GLsizeiptr size, const void* data) {
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        UnBind();
        m_size = size;
    }

    void VertexBuffer::SetDynamicBuffer(GLsizeiptr size, const void* data) {
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
        //UnBind();
        m_size = size;
    }

    void VertexBuffer::SetDynamicBuffer(GLsizeiptr size) {
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        //UnBind();
        m_size = size;
    }

    void VertexBuffer::FillBuffer(const void* data) {
        if (m_size == 0) {
            std::cout << "\nBuffer " << m_ID << " could not be filled\n";
            return;
        }
        
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, 0, m_size, data);
        UnBind();
    }

    void VertexBuffer::Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void VertexBuffer::UnBind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLuint VertexBuffer::ID() {
        return m_ID;
    }

    GLsizeiptr VertexBuffer::Size() {
        return m_size;
    }
}