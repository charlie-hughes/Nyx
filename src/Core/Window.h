#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>


namespace Nyx {
    
    class Window {

        public:

            Window(int width, int height, const std::string& title, bool resisable=true, bool vsync=true);
            void        Delete();

            // Get
            int         GetWidth();
            int         GetHeight();
            float       GetAspect();
            glm::vec2   GetSize();
            std::string GetTitle();
            GLFWwindow* GetWindow();
            bool        GetWindowShouldClose();

            // Set
            void        SetWidth(int width);
            void        SetHeight(int height);
            void        SetSize(glm::vec2 size);
            void        SetTitle(std::string title);
            void        SetResisable(bool resize);
            void        SetVsync(bool vsync);
            void        Close();

        private:

            GLFWwindow* m_window;

            std::string m_title;

            bool        m_resisable;
            bool        m_vsync;

            // Callbacks
            static void FramebufferSizeCallback(GLFWwindow* window, int w, int h);

    };
}