#include "../src/Nyx.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv) {

    Nyx::InitGLFW();

    Nyx::Window window(1600, 900, "Nyx");
    
    std::string shader_loc = "/Users/charliehughes/Desktop/GameDev/Nyx/Nyx/sandbox/shaders/";
    Nyx::Shader default_shader(shader_loc + "vertex.vert", shader_loc + "fragment.frag");

    Nyx::OrthographicCamera camera(&window);

    Nyx::Renderer2D renderer;

    while (!window.GetWindowShouldClose()) {

        // Setup renderer
        renderer.Clear({0.0f, 0.0f, 0.0f, 1.0f});
        renderer.Begin();

        default_shader.Activate();
        default_shader.SendMVP("u_MVP", camera.GetProjectionMatrix());

        // Draw
        renderer.DrawQuad({-3.75f, 1.0f}, {3.0f, 4.0f}, {0.7f, 0.2f, 0.25f, 1.0f}); // Red quad
        renderer.DrawQuad({3.0f, -1.5f}, {2.5f, 2.5f}, {0.2f, 0.2f, 0.6f, 1.0f}); // Blue quad

        for (int y = 0; y < 27; y++) {
            for (int x = 0; x < 48; x++) {
                float colour_multiple = (x + y) % 2 + 2;
                renderer.DrawQuad({-24.5+x, -13+y}, {1.0f, 1.0f}, {0.2f*colour_multiple, 0.2f*colour_multiple, 0.2f*colour_multiple, 1.0f}, -0.1f);
            }
        }

        renderer.Flush();
        renderer.PrintRenderStats();

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