#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include "../Utils/FileToString.h"

namespace Nyx {

    class Shader {

        public:

            Shader(const std::string& vertex_shader, const std::string& fragment_shader);
            void Delete();

            void Activate();

        private:

            GLuint m_ID;

    };



}