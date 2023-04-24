#include "Shader.h"

namespace Nyx {

    Shader::Shader(const std::string& vertex_path, const std::string& fragment_path) {

        // Load shader source
        std::string vertex_string = GetFileContents(vertex_path);
        std::string fragment_string = GetFileContents(fragment_path);

        const char* vertex_source = vertex_string.c_str();
        const char* fragment_source = fragment_string.c_str();

        // Create vertex shader
        GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_source, NULL);
        glCompileShader(vertex_shader);

        // Create fragment shader
        GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_source, NULL);
        glCompileShader(fragment_shader);

        // Create shader program
        m_ID = glCreateProgram();

        // Attatch shaders
        glAttachShader(m_ID, vertex_shader);
        glAttachShader(m_ID, fragment_shader);

        // Link program
        glLinkProgram(m_ID);

        // Clean up shaders
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

    }

    void Shader::Delete() {
        glDeleteProgram(m_ID);
    }

    void Shader::Activate() {
        glUseProgram(m_ID);
    }

    GLint Shader::GetUniformLocation(std::string uniform_name) {
        return glGetUniformLocation(m_ID, uniform_name.c_str());
    }

}