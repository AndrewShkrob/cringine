#include "window.hpp"

#include <cringine/event_system/internal/glfw_event_system.hpp>

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
    }

    void terminate_glfw()
    {
        glfwTerminate();
    }

    //    struct callbacks
    //    {
    //        static inline void window_size_callback_func(GLFWwindow* window, int width, int height)
    //        {
    //            _window_size_callback(width, height);
    //            window_size_callback(width, height);
    //        }
    //
    //        static inline void key_callback_func(GLFWwindow* window, int key, int /*unused*/, int action, int /*unused*/)
    //        {
    //            if (key == GLFW_KEY_ESCAPE) {
    //                glfwSetWindowShouldClose(window, GLFW_TRUE);
    //            }
    //            key_callback(key, action);
    //        }
    //
    //        static inline void mouse_callback_func(GLFWwindow* /*unused*/, double x_pos, double y_pos)
    //        {
    //            mouse_callback(x_pos, y_pos);
    //        }
    //
    //        static inline void scroll_callback_func(GLFWwindow* /*unused*/, double x_offset, double y_offset)
    //        {
    //            scroll_callback(x_offset, y_offset);
    //        }
    //
    //        static window::window_sise_callback_func window_size_callback;
    //        static window::window_sise_callback_func _window_size_callback;
    //        static window::key_callback_func key_callback;
    //        static window::mouse_callback_func mouse_callback;
    //        static window::scroll_callback_func scroll_callback;
    //    };
    //
    //    window::window_sise_callback_func callbacks::window_size_callback{};
    //    window::window_sise_callback_func callbacks::_window_size_callback{};
    //    window::key_callback_func callbacks::key_callback{};
    //    window::mouse_callback_func callbacks::mouse_callback{};
    //    window::scroll_callback_func callbacks::scroll_callback{};

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
    m_event_system = std::make_shared<event_system::glfw_event_system>(m_window);
    //    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(m_window);
    m_event_system->register_window_resize_callback(this);
}

window::~window()
{
    terminate_glfw();
}

event_system::event_system_sptr window::event_system()
{
    return m_event_system;
}

int window::width() const
{
    return m_width;
}

int window::height() const
{
    return m_height;
}

void window::launch(const render_func& render)
{
    while (glfwWindowShouldClose(m_window) == 0) {
        glfwPollEvents();

        render();

        glfwSwapBuffers(m_window);
    }
}
void window::window_resize(int width, int height)
{
    m_width = width;
    m_height = height;
}
