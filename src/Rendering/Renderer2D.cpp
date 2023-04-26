#include "Renderer2D.h"

namespace Nyx {

    Renderer2D::Renderer2D(uint32_t max_quads) {
        m_max_vertices = max_quads * 4;
        m_max_quads    = max_quads;
        m_max_indices  = max_quads * 6;

        // Resize Vertex and Index vectors
        m_vertices.reserve(m_max_vertices);
        m_indices.reserve(m_max_indices);

        m_vertex_ptr = m_vertices.data();
        m_index_ptr = m_indices.data();

        m_index_offset = 0;
        m_num_quads = 0;

        // Render stats
        m_num_draw_calls = 0;
        m_total_quads = 0;

        m_VA = VertexArray();
        m_VB = VertexBuffer();
        m_EB = IndexBuffer();

        // Bind buffers
        m_VA.Bind();
        m_VB.Bind();
        m_EB.Bind();

        // Create vertex buffer
        m_VB.SetDynamicBuffer(sizeof(Vertex) * m_max_vertices);

        // Create index buffer
        m_EB.SetDynamicBuffer(sizeof(uint32_t) * m_max_indices);

        // Set vertex attributes
        m_VA.SetAttribute(&m_VB, 0, 3, sizeof(Vertex), (void*)offsetof(Vertex, position)); // Position
        m_VA.SetAttribute(&m_VB, 1, 4, sizeof(Vertex), (void*)offsetof(Vertex, colour)); // Colour
        m_VA.SetAttribute(&m_VB, 2, 2, sizeof(Vertex), (void*)offsetof(Vertex, tex_coord)); // Uv
        m_VA.SetAttribute(&m_VB, 3, 1, sizeof(Vertex), (void*)offsetof(Vertex, tex_index)); // Texture index

        // Unbind buffers
        m_VB.UnBind();
        m_VA.UnBind();
        m_EB.UnBind();

        // Enable depth sorting
        glEnable(GL_DEPTH_TEST);
    }

    void Renderer2D::Delete() {
        m_EB.Delete();
        m_VB.Delete();
        m_VA.Delete();
    }

    void Renderer2D::Begin() {
        m_vertex_ptr = m_vertices.data();
        m_index_ptr  = m_indices.data();

        m_num_quads = 0;
        m_index_offset = 0;

        // Render stats
        m_num_draw_calls = 0;
        m_total_quads = 0;
    }

    void Renderer2D::Clear(glm::vec4 colour) {
        glClearColor(colour.x, colour.y, colour.z, colour.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer2D::Resize(uint32_t max_quads) {
        m_max_vertices = max_quads * 4;
        m_max_quads    = max_quads;
        m_max_indices  = max_quads * 6;

        // Clear vertex and index vectors
        m_vertices.clear();
        m_indices.clear();

        // Resize Vertex and Index vectors
        m_vertices.reserve(m_max_vertices);
        m_indices.reserve(m_max_indices);

        m_vertex_ptr = m_vertices.data();
        m_index_ptr = m_indices.data();

        m_index_offset = 0;
        m_num_quads = 0;

        // Render stats
        m_num_draw_calls = 0;
        m_total_quads = 0;

        // Bind buffers
        m_VA.Bind();
        m_VB.Bind();
        m_EB.Bind();

        // Create vertex buffer
        m_VB.SetDynamicBuffer(sizeof(Vertex) * m_max_vertices);

        // Create index buffer
        m_EB.SetDynamicBuffer(sizeof(uint32_t) * m_max_indices);

        // Set vertex attributes
        m_VA.SetAttribute(&m_VB, 0, 3, sizeof(Vertex), (void*)offsetof(Vertex, position)); // Position
        m_VA.SetAttribute(&m_VB, 1, 4, sizeof(Vertex), (void*)offsetof(Vertex, colour)); // Colour
        m_VA.SetAttribute(&m_VB, 2, 2, sizeof(Vertex), (void*)offsetof(Vertex, tex_coord)); // Uv
        m_VA.SetAttribute(&m_VB, 3, 1, sizeof(Vertex), (void*)offsetof(Vertex, tex_index)); // Texture index

        // Unbind buffers
        m_VB.UnBind();
        m_VA.UnBind();
        m_EB.UnBind();
    }

    void Renderer2D::Render() {
        m_VA.Bind();

        m_VB.FillBuffer(m_vertices.data());
        m_EB.FillBuffer(m_indices.data());

        glDrawElements(GL_TRIANGLES, m_index_ptr - m_indices.data(), GL_UNSIGNED_INT, 0);

        m_VA.UnBind();

        // Render stats
        m_num_draw_calls++;
        m_total_quads += m_num_quads;
    }

    void Renderer2D::StaticRender() {
        m_VA.Bind();

        glDrawElements(GL_TRIANGLES, m_index_ptr - m_indices.data(), GL_UNSIGNED_INT, 0);
        
        m_VA.UnBind();

        // Render stats
        m_num_draw_calls = 1;
        m_total_quads = m_num_quads;
    }

    void Renderer2D::PushData() {
        m_VA.Bind();

        m_VB.FillBuffer(m_vertices.data());
        m_EB.FillBuffer(m_indices.data());
    }

    void Renderer2D::Flush() {
        Render();

        m_num_quads = 0;
        m_index_offset = 0;

        m_vertex_ptr = m_vertices.data();
        m_index_ptr  = m_indices.data();
        
    }

    void Renderer2D::End() {
        
    }

    void Renderer2D::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 colour, float layer) {

        if (m_num_quads == m_max_quads) {
            Flush();
        }

        // Top left
        m_vertex_ptr->position = { position.x - size.x / 2, position.y + size.y / 2, layer};
        m_vertex_ptr->colour = colour;
        m_vertex_ptr->tex_coord = { 0.0f, 1.0f };
        m_vertex_ptr->tex_index = 0.0f;
        m_vertex_ptr++;

        // Top right
        m_vertex_ptr->position = { position.x + size.x / 2, position.y + size.y / 2, layer};
        m_vertex_ptr->colour = colour;
        m_vertex_ptr->tex_coord = { 1.0f, 1.0f };
        m_vertex_ptr->tex_index = 0.0f;
        m_vertex_ptr++;

        // Bottom right
        m_vertex_ptr->position = { position.x + size.x / 2, position.y - size.y / 2, layer};
        m_vertex_ptr->colour = colour;
        m_vertex_ptr->tex_coord = { 1.0f, 0.0f };
        m_vertex_ptr->tex_index = 0.0f;
        m_vertex_ptr++;

        // Bottom left
        m_vertex_ptr->position = { position.x - size.x / 2, position.y - size.y / 2, layer};
        m_vertex_ptr->colour = colour;
        m_vertex_ptr->tex_coord = { 0.0f, 0.0f };
        m_vertex_ptr->tex_index = 0.0f;
        m_vertex_ptr++;

        // Increment quad count
        m_num_quads++;

        // Add indices for quad
        *(m_index_ptr + 0) = 0 + m_index_offset;
        *(m_index_ptr + 1) = 1 + m_index_offset;
        *(m_index_ptr + 2) = 2 + m_index_offset;
        *(m_index_ptr + 3) = 2 + m_index_offset;
        *(m_index_ptr + 4) = 3 + m_index_offset;
        *(m_index_ptr + 5) = 0 + m_index_offset;

        m_index_ptr    += 6;
        m_index_offset += 4;
    }

    uint32_t Renderer2D::GetQuadCount() {
        return m_total_quads;
    }

    uint32_t Renderer2D::GetDrawCalls() {
        return m_num_draw_calls;
    }

    void Renderer2D::PrintRenderStats() {
        std::cout << "Rendered " << GetQuadCount() << " quads in " << GetDrawCalls() << " draw calls" << std::setw(20) << "\r" << std::flush;
    }

}