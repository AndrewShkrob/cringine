#include "glfw_input_manager.hpp"

#include <GLFW/glfw3.h>

using namespace cringine::event_system::input;

void glfw_input_manager::cursor_focus(bool new_state)
{
    m_cursor_focus = new_state;
}

void glfw_input_manager::cursor_position(double x, double y)
{
    m_cursor_x = x;
    m_cursor_y = y;
}

void glfw_input_manager::scroll_input(double dx, double dy)
{
    m_scroll_delta_x = dx;
    m_scroll_delta_y = dy;
}

void glfw_input_manager::keyboard_input(keys::key_t key, int action)
{
    m_key_current_states.at(key) = (action == GLFW_PRESS || action == GLFW_REPEAT);
}

void glfw_input_manager::mouse_button_input(keys::key_t button, int action)
{
    m_button_current_states.at(button) = action == GLFW_PRESS;
}
