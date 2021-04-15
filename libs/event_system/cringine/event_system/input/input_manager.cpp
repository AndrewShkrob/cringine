#include "input_manager.hpp"

using namespace cringine::event_system::input;

void input_manager::bind_to_event_system(event_system_sptr event_system)
{
    event_system->register_cursor_focus_callback(this);
    event_system->register_cursor_position_callback(this);
    event_system->register_keyboard_input_callback(this);
    event_system->register_mouse_button_input_callback(this);
    event_system->register_scroll_input_callback(this);
}

void input_manager::update_states()
{
    update_key_states();
    update_button_states();
    update_scroll_delta();
}

[[nodiscard, maybe_unused]] bool input_manager::is_cursor_focused() const
{
    return m_cursor_focus;
}

[[nodiscard, maybe_unused]] std::pair<double, double> input_manager::cursor_position() const
{
    return std::make_pair(m_cursor_x, m_cursor_y);
}

[[nodiscard, maybe_unused]] double input_manager::cursor_position_x() const
{
    return m_cursor_x;
}

[[nodiscard, maybe_unused]] double input_manager::cursor_position_y() const
{
    return m_cursor_y;
}

[[nodiscard, maybe_unused]] std::pair<double, double> input_manager::scroll_delta() const
{
    return std::make_pair(m_scroll_delta_x, m_scroll_delta_y);
}

[[nodiscard, maybe_unused]] double input_manager::scroll_delta_x() const
{
    return m_scroll_delta_x;
}

[[nodiscard, maybe_unused]] double input_manager::scroll_delta_y() const
{
    return m_scroll_delta_y;
}

[[nodiscard, maybe_unused]] bool input_manager::is_key_pressed(keys::key_t key) const
{
    return m_key_current_states.at(key) && !m_key_previous_states.at(key);
}

[[nodiscard, maybe_unused]] bool input_manager::is_key_released(keys::key_t key) const
{
    return !m_key_current_states.at(key) && m_key_previous_states.at(key);
}

[[nodiscard, maybe_unused]] bool input_manager::is_key_down(keys::key_t key) const
{
    return m_key_current_states.at(key);
}

[[nodiscard, maybe_unused]] bool input_manager::is_key_up(keys::key_t key) const
{
    return !m_key_current_states.at(key);
}

[[nodiscard, maybe_unused]] bool input_manager::is_mouse_button_pressed(keys::key_t button) const
{
    return m_button_current_states.at(button) && !m_button_previous_states.at(button);
}

[[nodiscard, maybe_unused]] bool input_manager::is_mouse_button_released(keys::key_t button) const
{
    return !m_button_current_states.at(button) && m_button_previous_states.at(button);
}

[[nodiscard, maybe_unused]] bool input_manager::is_mouse_button_down(keys::key_t button) const
{
    return m_button_current_states.at(button);
}

[[nodiscard, maybe_unused]] bool input_manager::is_mouse_button_up(keys::key_t button) const
{
    return !m_button_current_states.at(button);
}

void input_manager::update_key_states()
{
    for (auto i = 0u; i < keys::KEY_AMOUNT; ++i) {
        m_key_previous_states.at(i) = m_key_current_states.at(i);
    }
}

void input_manager::update_button_states()
{
    for (auto i = 0u; i < keys::BUTTON_AMOUNT; ++i) {
        m_button_previous_states.at(i) = m_button_current_states.at(i);
    }
}

void input_manager::update_scroll_delta()
{
    m_scroll_delta_x = m_scroll_delta_y = 0;
}

void input_manager::cursor_focus(bool new_state)
{
    m_cursor_focus = new_state;
}

void input_manager::cursor_position(double x, double y)
{
    m_cursor_x = x;
    m_cursor_y = y;
}

void input_manager::scroll_input(double dx, double dy)
{
    m_scroll_delta_x = dx;
    m_scroll_delta_y = dy;
}

void input_manager::keyboard_input(keys::key_t key, bool new_state)
{
    m_key_current_states.at(key) = new_state;
}

void input_manager::mouse_button_input(keys::key_t button, bool new_state)
{
    m_button_current_states.at(button) = new_state;
}
