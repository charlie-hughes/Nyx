#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>


namespace Nyx {


    class Window {

        public:

            void Init(int width, int height, std::string title, bool resisable=true, bool vsync=true);

            void Delete();

            GLFWwindow* GetWindow();

        private:

            GLFWwindow* m_window;

            int         m_width;
            int         m_height;

            int         m_framebuffer_width;
            int         m_framebuffer_height;

            std::string m_title;

            bool        m_resisable;
            bool        m_vsync;

            // Callbacks
            static void FramebufferSizeCallback(GLFWwindow* window, int w, int h);

    };


}