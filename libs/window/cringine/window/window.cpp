#include "window.hpp"

#include <stdexcept>
#include <utility>

using namespace cringine;

namespace
{
    void init_glfw()
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }

    void terminate_glfw()
    {
        glfwTerminate();
    }

    struct callbacks
    {
        static inline void key_callback_func(GLFWwindow* window, int key, int /*unused*/, int action, int /*unused*/)
        {
            if (key == GLFW_KEY_ESCAPE) {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
            key_callback(key, action);
        }

        static inline void mouse_callback_func(GLFWwindow* /*unused*/, double x_pos, double y_pos)
        {
            mouse_callback(x_pos, y_pos);
        }

        static inline void scroll_callback_func(GLFWwindow* /*unused*/, double x_offset, double y_offset)
        {
            scroll_callback(x_offset, y_offset);
        }

        static window::key_callback_func key_callback;
        static window::mouse_callback_func mouse_callback;
        static window::scroll_callback_func scroll_callback;
    };

    window::key_callback_func callbacks::key_callback{};
    window::mouse_callback_func callbacks::mouse_callback{};
    window::scroll_callback_func callbacks::scroll_callback{};

} // namespace

window::window(int width, int height, std::string title)
    : m_width(width)
    , m_height(height)
    , m_title(std::move(title))
    , m_window(nullptr)
{
    init_glfw();
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        terminate_glfw();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(m_window);
}

window::~window()
{
    terminate_glfw();
}

int window::width() const
{
    return m_width;
}

int window::height() const
{
    return m_height;
}

void window::set_key_callback(key_callback_func callback)
{
    callbacks::key_callback = std::move(callback);
    glfwSetKeyCallback(m_window, callbacks::key_callback_func);
}

void window::set_mouse_callback(mouse_callback_func callback)
{
    callbacks::mouse_callback = std::move(callback);
    glfwSetCursorPosCallback(m_window, callbacks::mouse_callback_func);
}

void window::set_scroll_callback(scroll_callback_func callback)
{
    callbacks::scroll_callback = std::move(callback);
    glfwSetScrollCallback(m_window, callbacks::scroll_callback_func);
}

void window::launch(const render_func& render)
{
    while (glfwWindowShouldClose(m_window) == 0) {
        glfwPollEvents();

        render();

        glfwSwapBuffers(m_window);
    }
}