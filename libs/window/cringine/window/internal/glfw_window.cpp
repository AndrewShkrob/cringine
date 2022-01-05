#include "glfw_window.hpp"

#include "cringine/event_system/internal/glfw_event_system.hpp"

#include <stdexcept>
#include <utility>

namespace cringine::window::internal
{
    namespace
    {
        void init_glfw()
        {
            glfwInit();

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
        }

        void terminate_glfw()
        {
            glfwTerminate();
        }

        GLFWwindow* create_glfw_window(const window_configuration& window_configuration)
        {
            init_glfw();

            GLFWwindow* window = glfwCreateWindow(
                window_configuration.size.width,
                window_configuration.size.height,
                window_configuration.title.c_str(),
                nullptr,
                nullptr);

            if (window == nullptr) {
                terminate_glfw();
                throw std::runtime_error("Failed to create GLFW window");
            }

            if (window_configuration.use_cursor)
            {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }

            glfwMakeContextCurrent(window);

            return window;
        }
    } // namespace

    glfw_window::glfw_window(window_configuration window_config)
        : m_window_configuration(std::move(window_config))
        , m_window(create_glfw_window(m_window_configuration))
    {
        m_event_system = std::make_shared<event_system::glfw_event_system>(m_window);
        m_event_system->register_window_resize_callback(this);
    }

    glfw_window::~glfw_window()
    {
        terminate_glfw();
    }

    event_system::event_system_sptr glfw_window::event_system()
    {
        return m_event_system;
    }

    void glfw_window::set_title(const std::string& title)
    {
        glfwSetWindowTitle(m_window, title.c_str());
    }

    window_size glfw_window::size() const
    {
        return m_window_configuration.size;
    }

    void glfw_window::update()
    {
        glfwPollEvents();
    }

    void glfw_window::render()
    {
        glfwSwapBuffers(m_window);
    }

    void glfw_window::window_resize(window_size window_size)
    {
        m_window_configuration.size = window_size;
    }
} // namespace cringine::window::internal