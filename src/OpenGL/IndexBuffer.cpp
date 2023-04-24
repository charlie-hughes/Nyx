#include "IndexBuffer.h"

namespace Nyx {

    IndexBuffer::IndexBuffer() {
        glGenBuffers(1, &m_ID);
    }

    void IndexBuffer::Delete() {
        glDeleteBuffers(1, &m_ID);
    }

    void IndexBuffer::SetStaticBuffer(GLsizeiptr size, const void* indices) {
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        //UnBind();
        m_size = size;
    }

    void IndexBuffer::SetDynamicBuffer(GLsizeiptr size, const void* indices) {
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_DYNAMIC_DRAW);
        //UnBind();
        m_size = size;
    }

    void IndexBuffer::SetDynamicBuffer(GLsizeiptr size) {
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        //UnBind();
        m_size = size;
    }

    void IndexBuffer::FillBuffer(const void* indices) {
        Bind();
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, m_size, indices);
        //UnBind();
    }

    void IndexBuffer::Bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void IndexBuffer::UnBind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }





}