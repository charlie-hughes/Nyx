#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Vertex.h"
#include "../OpenGL/IndexBuffer.h"
#include "../OpenGL/VertexBuffer.h"
#include "../OpenGL/VertexArray.h"

namespace Nyx {

    class Renderer2D {

        public:

            Renderer2D(uint32_t max_quads);
            void Delete();

            void Begin();

            void Clear(glm::vec4 colour={0.0f, 0.0f, 0.0f, 0.0f});

            // Renders the data currently in the buffers
            void Render();

            // Only renders whats already on the gpu
            void StaticRender();

            // Sends newest data to the gpu but doesn't render. To be used with StaticRender
            void PushData();

            // Renders current data and resets, ready to be refilled
            void Flush();

            // Resets buffers
            void End();

            // Draw coloured quad
            void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 colour, float layer=0.0f);

            // Draw textured quad
            void DrawQuad(glm::vec2 position, glm::vec2 size, float texture_index, float layer=0.0f);

            // Get number of quads drawn
            uint32_t GetQuadCount();

            // Get number of draw calls
            uint32_t GetDrawCalls();

            // Print render stats
            void PrintRenderStats();

        private:

            uint32_t              m_max_vertices;
            uint32_t              m_max_quads;
            uint32_t              m_max_indices;

            VertexArray           m_VA;
            VertexBuffer          m_VB;
            IndexBuffer           m_EB;

            std::vector<Vertex>   m_vertices;
            std::vector<uint32_t> m_indices;

            Vertex*               m_vertex_ptr;
            uint32_t              m_num_quads;
            uint32_t*             m_index_ptr;
            uint32_t              m_index_offset;

            uint32_t              m_num_draw_calls;
            uint32_t              m_total_quads;

    };
}