#pragma once

#include <cringine/event_system/events/all.hpp>

#include <memory>

namespace cringine::event_system
{
    class event_system
    {
    public:
        [[maybe_unused]] virtual void register_window_close_callback(events::window_close_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_position_callback(events::window_position_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_resize_callback(events::window_resize_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_focus_observer(events::window_focus_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_refresh_observer(events::window_refresh_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_iconify_observer(events::window_iconify_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_window_maximize_observer(events::window_maximize_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_keyboard_input_observer(events::keyboard_input_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_char_input_observer(events::char_input_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_cursor_position_observer(events::cursor_position_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_cursor_focus_observer(events::cursor_focus_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_mouse_button_input_observer(events::mouse_button_input_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_scroll_input_observer(events::scroll_input_event_ptr callback) = 0;
        [[maybe_unused]] virtual void register_path_drop_observer(events::path_drop_event_ptr callback) = 0;
    };

    using event_system_sptr = std::shared_ptr<event_system>;
} // namespace cringine::event_system
