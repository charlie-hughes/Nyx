#pragma once

#include <glm/glm.hpp>

namespace Nyx {

    struct Vertex {

        glm::vec3 position;
        glm::vec4 colour;
        glm::vec2 tex_coord;
        float     tex_index;

    };

}