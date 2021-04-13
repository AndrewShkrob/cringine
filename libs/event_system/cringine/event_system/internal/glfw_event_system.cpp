#include "glfw_event_system.hpp"

using namespace cringine::event_system;

namespace
{
    template<class T>
    void remove_by_index(T& container, size_t idx)
    {
    }
} // namespace

glfw_event_system::glfw_event_system(GLFWwindow* window)
    : m_window(window)
{
    init();
}

void glfw_event_system::register_window_close_callback(events::window_close_event_ptr callback)
{
    m_window_close_callbacks.push_back(callback);
}

void glfw_event_system::register_window_resize_callback(events::window_resize_event_ptr callback)
{
    m_window_resize_callbacks.push_back(callback);
}

void glfw_event_system::init()
{
    glfwSetWindowUserPointer(m_window, this);
    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
        auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
        for (auto* callback : self.m_window_close_callbacks) {
            callback->window_close();
        }
    });
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
        for (auto* callback : self.m_window_resize_callbacks) {
            callback->window_resize(width, height);
        }
    });
}