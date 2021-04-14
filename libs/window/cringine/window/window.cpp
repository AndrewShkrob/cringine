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
} // namespace

window::window(const types::configuration::window_configuration& window_config)
    : window(window_config.width, window_config.height, window_config.name)
{
}

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

void window::update() const
{
    glfwPollEvents();
    (void) m_window;
}

void window::render() const
{
    glfwSwapBuffers(m_window);
}

void window::window_resize(int width, int height)
{
    m_width = width;
    m_height = height;
}
