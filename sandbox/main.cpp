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

    Nyx::Renderer2D renderer(16);
    
    while (!window.GetWindowShouldClose()) {

        glClear(GL_COLOR_BUFFER_BIT);

        default_shader.Activate();

        glUniformMatrix4fv(default_shader.GetUniformLocation("u_MVP"), 1, GL_FALSE, glm::value_ptr(camera.GetProjectionMatrix()));

        renderer.Begin();

        for (int i = 0; i < 16; i++) {
           renderer.DrawQuad({-7.5f+i,  1.0f}, {1.0f, 1.0f}, {i/8.0, i/16.0, i/16.0, 1.0f}); 
           renderer.DrawQuad({-7.5f+i,  0.0f}, {1.0f, 1.0f}, {i/16.0, i/8.0, i/16.0, 1.0f}); 
           renderer.DrawQuad({-7.5f+i, -1.0f}, {1.0f, 1.0f}, {i/16.0, i/16.0, i/8.0, 1.0f}); 
        }
        
        renderer.Render();

        std::cout << "Rendered " << renderer.GetQuadCount() << " quads in " << renderer.GetDrawCalls() << " draw calls" << std::setw(20) << "\r" << std::flush;

        glfwSwapBuffers(window.GetWindow());

        glfwPollEvents();
    }

    std::cout << "\n\nCleaning Up...\n";

    renderer.Delete();
    default_shader.Delete();
    window.Delete();

    Nyx::TerminateGLFW();

    return 0;
}