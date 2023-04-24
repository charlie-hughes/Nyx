#include "../src/Nyx.h"

#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>

int main(int argc, const char** argv) {

    Nyx::InitGLFW();

    Nyx::Window window(1600, 900, "Nyx");
    
    std::string shader_loc = "/Users/charliehughes/Desktop/GameDev/Nyx/Nyx/sandbox/shaders/";
    Nyx::Shader default_shader(shader_loc + "vertex.vert", shader_loc + "fragment.frag");

    Nyx::OrthographicCamera camera(&window);

    GLfloat verts[12] = {
        -0.5f, -0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };

    uint32_t indices[6] = {0, 1, 2, 1, 3, 2};

    Nyx::VertexArray  va;
    Nyx::VertexBuffer vb;
    Nyx::IndexBuffer  eb;

    va.Bind();
    vb.Bind();
    vb.SetDynamicBuffer(sizeof(verts), verts);

    va.SetAttribute(&vb, 0, 3, sizeof(GLfloat)*3, (void*)0);

    eb.Bind();
    eb.SetStaticBuffer(sizeof(indices), indices);

    vb.UnBind();
    va.UnBind();
    eb.UnBind();

    while (!window.GetWindowShouldClose()) {

        glClear(GL_COLOR_BUFFER_BIT);

        default_shader.Activate();

        glUniformMatrix4fv(default_shader.GetUniformLocation("u_MVP"), 1, GL_FALSE, glm::value_ptr(camera.GetProjectionMatrix()));

        va.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.GetWindow());

        glfwPollEvents();
    }

    std::cout << "\nCleaning Up...\n";

    va.Delete();
    vb.Delete();
    eb.Delete();

    default_shader.Delete();
    window.Delete();

    Nyx::TerminateGLFW();

    return 0;
}