#include "VertexArray.h"


namespace Nyx {

    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_ID);
    }

    void VertexArray::Delete() {
        glDeleteVertexArrays(1, &m_ID);
    }

    void VertexArray::SetAttribute(VertexBuffer* vertex_buffer, int index, int num_components, GLsizei stride, const void* offset) {
        vertex_buffer->Bind();
        glVertexAttribPointer(index, num_components, GL_FLOAT, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(index);
        vertex_buffer->UnBind();   
    }

    void VertexArray::Bind() {
        glBindVertexArray(m_ID);
    }

    void VertexArray::UnBind() {
        glBindVertexArray(0);
    }

    GLuint VertexArray::ID() {
        return m_ID;
    }


}