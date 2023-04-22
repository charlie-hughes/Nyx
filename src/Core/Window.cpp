#include "Window.h"

namespace Nyx {

    void Window::Init(int width, int height, std::string title, bool resisable, bool vsync) {

        Window::m_width = width;
        Window::m_height = height;
        Window::m_title = title;

        Window::m_resisable = resisable;
        Window::m_vsync = vsync;

        // Create GLFW window
        Window::m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

        if (!m_window) {
            glfwTerminate();
            std::cout << "Could not create GLFW window\n";
        }

        // Make window current context
        glfwMakeContextCurrent(m_window);

        // Resize and Vsync
        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, m_resisable);
        glfwSwapInterval(m_vsync);

        gladLoadGL();

        // Create viewport
        glfwGetFramebufferSize(m_window, &m_framebuffer_width, &m_framebuffer_height);
        glViewport(0, 0, m_framebuffer_width, m_framebuffer_height);

        // Set callbacks
        glfwSetFramebufferSizeCallback(m_window, FramebufferSizeCallback);

    }

    void Window::Delete() {
        glfwDestroyWindow(m_window);
    }

    GLFWwindow* Window::GetWindow() {
        return m_window;
    }

    void Window::FramebufferSizeCallback(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
    }

}