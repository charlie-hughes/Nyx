// Nyx header //
#include "Nyx.h"

#include <iostream>


int main(int argc, const char** argv) {

    Nyx::InitGLFW();

    Nyx::Window window;
    window.Init(1600, 900, "Nyx", true);

    while (!glfwWindowShouldClose(window.GetWindow())) {

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window.GetWindow());

        glfwPollEvents();

    }

    window.Delete();

    return 0;
}