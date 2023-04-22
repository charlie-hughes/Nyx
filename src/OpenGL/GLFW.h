#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Nyx {

    static void InitGLFW() {

        std::cout << "Initialising GLFW\n";

        if (!glfwInit()) {
            std::cout << "Could not init GLFW\n";
            return;
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        

        // use forward compatability if using apple
        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
    }

    static void TerminateGLFW() {
        glfwTerminate();
    }


}
