#include "../src/Nyx.h"

#include <iostream>

int main(int argc, const char** argv) {

    Nyx::InitGLFW();

    Nyx::Window window;
    window.Init(1600, 900, "Nyx");

    Nyx::Shader defualt_shader("/Users/charliehughes/Desktop/GameDev/Nyx/Nyx/sandbox/shaders/vertex.vert", "/Users/charliehughes/Desktop/GameDev/Nyx/Nyx/sandbox/shaders/fragment.frag");

    GLfloat verts[12] = {
        -0.5f, -0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };

    uint32_t indices[6] = {0, 1, 2, 1, 3, 2};

    Nyx::VertexArray va;
    Nyx::VertexBuffer vb;
    Nyx::IndexBuffer eb;

    va.Bind();
    vb.Bind();
    vb.SetStaticBuffer(sizeof(verts), verts);

    va.SetAttribute(&vb, 0, 3, sizeof(GLfloat)*3, (void*)0);

    eb.Bind();
    eb.SetStaticBuffer(sizeof(indices), indices);

    vb.UnBind();
    va.UnBind();
    eb.UnBind();

    while (!window.GetWindowShouldClose()) {

        glClear(GL_COLOR_BUFFER_BIT);

        defualt_shader.Activate();

        va.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.GetWindow());

        glfwPollEvents();
    }

    std::cout << "\nCleaning Up...\n";

    defualt_shader.Delete();
    window.Delete();
    Nyx::TerminateGLFW();

    return 0;
}