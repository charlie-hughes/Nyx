#include "Window.h"

namespace Nyx {

    Window::Window(int width, int height, const std::string& title, bool resisable, bool vsync) {

        m_title     = title;

        m_resisable = resisable;
        m_vsync     = vsync;

        // Log action
        std::cout << "\nCreating GLFW window:\n" << "\tTitle  -> " << title << "\n\tWidth  -> " << width << "\n\tHeight -> " << height << "\n\n"; 

        // Create GLFW window
        Window::m_window = glfwCreateWindow(width, height, m_title.c_str(), NULL, NULL);

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
        int framebuffer_width;
        int framebuffer_height;

        glfwGetFramebufferSize(m_window, &framebuffer_width, &framebuffer_height);
        glViewport(0, 0, framebuffer_width, framebuffer_height);

        // Set callbacks
        glfwSetFramebufferSizeCallback(m_window, FramebufferSizeCallback);

    }

    void Window::Delete() {
        glfwDestroyWindow(m_window);
    }

    // Get Functions
    int Window::GetWidth() {
        int width;
        glfwGetWindowSize(m_window, &width, nullptr);
        return width;
    }

    int Window::GetHeight() {
        int height;
        glfwGetWindowSize(m_window, nullptr, &height);
        return height;
    }

    glm::vec2 Window::GetSize() {
        int width, height;
        glfwGetWindowSize(m_window, &width, &height);
        return { width, height };
    }

    std::string Window::GetTitle() {
        return m_title;
    }

    GLFWwindow* Window::GetWindow() {
        return m_window;
    }

    bool Window::GetWindowShouldClose() {
        return glfwWindowShouldClose(m_window);
    }

    // Set Functions
    void Window::SetWidth(int width) {
        glfwSetWindowSize(m_window, width, GetHeight());
    }

    void Window::SetHeight(int height) {
        glfwSetWindowSize(m_window, GetWidth(), height);
    }

    void Window::SetSize(glm::vec2 size) {
        glfwSetWindowSize(m_window, (int)size.x, (int)size.y);
    }

    void Window::SetTitle(std::string title) {
        glfwSetWindowTitle(m_window, title.c_str());
    }

    void Window::SetResisable(bool resize) {
        glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, resize);
    }

    void Window::SetVsync(bool vsync) {
        glfwSwapInterval(vsync);
    }

    void Window::Close() {
        glfwSetWindowShouldClose(m_window, 1);
    }

    // Callbacks
    void Window::FramebufferSizeCallback(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
    }

}