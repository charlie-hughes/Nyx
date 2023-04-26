#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include "../Utils/FileToString.h"

namespace Nyx {

    class Shader {

        public:

            Shader(const std::string& vertex_shader, const std::string& fragment_shader);
            void Delete();

            void Activate();

            GLint GetUniformLocation(const char* uniform_name);

            void SendMVP(const char* name, glm::mat4 matrix);

        private:

            GLuint m_ID;

    };



}