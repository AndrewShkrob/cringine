#include "glfw_event_system.hpp"

using namespace cringine::event_system;

glfw_event_system::glfw_event_system(GLFWwindow* window)
    : m_window(window)
{
    init();
}

void glfw_event_system::register_window_close_callback(events::window_close_event_ptr callback)
{
    m_window_close_observer.add_observer(callback);
}

void glfw_event_system::register_window_position_callback(events::window_position_event_ptr callback)
{
    m_window_position_observer.add_observer(callback);
}

void glfw_event_system::register_window_resize_callback(events::window_resize_event_ptr callback)
{
    m_window_resize_observer.add_observer(callback);
}

void glfw_event_system::register_window_focus_callback(events::window_focus_event_ptr callback)
{
    m_window_focus_observer.add_observer(callback);
}

void glfw_event_system::register_window_refresh_callback(events::window_refresh_event_ptr callback)
{
    m_window_refresh_observer.add_observer(callback);
}

void glfw_event_system::register_window_iconify_callback(events::window_iconify_event_ptr callback)
{
    m_window_iconify_observer.add_observer(callback);
}

void glfw_event_system::register_window_maximize_callback(events::window_maximize_event_ptr callback)
{
    m_window_maximize_observer.add_observer(callback);
}

void glfw_event_system::register_keyboard_input_callback(events::keyboard_input_event_ptr callback)
{
    m_keyboard_input_observer.add_observer(callback);
}

void glfw_event_system::register_char_input_callback(events::char_input_event_ptr callback)
{
    m_char_input_observer.add_observer(callback);
}

void glfw_event_system::register_cursor_position_callback(events::cursor_position_event_ptr callback)
{
    m_cursor_position_observer.add_observer(callback);
}

void glfw_event_system::register_cursor_focus_callback(events::cursor_focus_event_ptr callback)
{
    m_cursor_focus_observer.add_observer(callback);
}

void glfw_event_system::register_mouse_button_input_callback(events::mouse_button_input_event_ptr callback)
{
    m_mouse_button_input_observer.add_observer(callback);
}

void glfw_event_system::register_scroll_input_callback(events::scroll_input_event_ptr callback)
{
    m_scroll_input_observer.add_observer(callback);
}

void glfw_event_system::register_path_drop_callback(events::path_drop_event_ptr callback)
{
    m_path_drop_observer.add_observer(callback);
}

void glfw_event_system::init()
{
    glfwSetWindowUserPointer(m_window, this);
    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
        auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
        self.m_window_close_observer.notify(&events::window_close_event::window_close);
    });
    glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int x, int y) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_window_position_observer.notify(&events::window_position_event::window_position, x, y);
    });
    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
        self.m_window_resize_observer.notify(&events::window_resize_event::window_resize, width, height);
    });
    glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_window_focus_observer.notify(&events::window_focus_event::window_focus, static_cast<bool>(focused));
    });
    glfwSetWindowRefreshCallback(m_window, [](GLFWwindow* window) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_window_refresh_observer.notify(&events::window_refresh_event::window_refresh);
    });
    glfwSetWindowIconifyCallback(m_window, [](GLFWwindow* window, [[maybe_unused]] int focused) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_window_iconify_observer.notify(&events::window_iconify_event::window_iconify);
    });
    glfwSetWindowMaximizeCallback(m_window, [](GLFWwindow* window, [[maybe_unused]] int focused) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_window_maximize_observer.notify(&events::window_maximize_event::window_maximize);
    });
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_keyboard_input_observer.notify(&events::keyboard_input_event::keyboard_input, static_cast<input::keys::key_t>(key), action);
    });
    glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int character) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_char_input_observer.notify(&events::char_input_event::char_input, character);
    });
    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_cursor_position_observer.notify(&events::cursor_position_event::cursor_position, x, y);
    });
    glfwSetCursorEnterCallback(m_window, [](GLFWwindow* window, int entered) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_cursor_focus_observer.notify(&events::cursor_focus_event::cursor_focus, static_cast<bool>(entered));
    });
    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_mouse_button_input_observer.notify(&events::mouse_button_input_event::mouse_button_input, static_cast<input::keys::key_t>(button), action);
    });
    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double dx, double dy) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_scroll_input_observer.notify(&events::scroll_input_event::scroll_input, dx, dy);
    });
    glfwSetDropCallback(m_window, [](GLFWwindow* window, int count, const char** paths) {
      auto& self = *static_cast<glfw_event_system*>(glfwGetWindowUserPointer(window));
      self.m_path_drop_observer.notify(&events::path_drop_event::path_drop, count, paths);
    });
}
