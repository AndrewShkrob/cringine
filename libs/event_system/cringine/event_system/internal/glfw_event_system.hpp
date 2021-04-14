#pragma once

#include <cringine/event_system/event_system.hpp>
#include <cringine/utils/observer.hpp>

#include <GLFW/glfw3.h>

namespace cringine::event_system
{
    class glfw_event_system : public event_system
    {
    public:
        explicit glfw_event_system(GLFWwindow* window);
        virtual ~glfw_event_system() = default;

        glfw_event_system(const glfw_event_system&) = delete;
        glfw_event_system(glfw_event_system&&) = default;

        glfw_event_system& operator=(glfw_event_system&) = delete;
        glfw_event_system& operator=(glfw_event_system&&) = default;

        void register_window_close_callback(events::window_close_event_ptr callback) override;
        void register_window_position_callback(events::window_position_event_ptr callback) override;
        void register_window_resize_callback(events::window_resize_event_ptr callback) override;
        void register_window_focus_observer(events::window_focus_event_ptr callback) override;
        void register_window_refresh_observer(events::window_refresh_event_ptr callback) override;
        void register_window_iconify_observer(events::window_iconify_event_ptr callback) override;
        void register_window_maximize_observer(events::window_maximize_event_ptr callback) override;
        void register_keyboard_input_observer(events::keyboard_input_event_ptr callback) override;
        void register_char_input_observer(events::char_input_event_ptr callback) override;
        void register_cursor_position_observer(events::cursor_position_event_ptr callback) override;
        void register_cursor_focus_observer(events::cursor_focus_event_ptr callback) override;
        void register_mouse_button_input_observer(events::mouse_button_input_event_ptr callback) override;
        void register_scroll_input_observer(events::scroll_input_event_ptr callback) override;
        void register_path_drop_observer(events::path_drop_event_ptr callback) override;

    private:
        void init();

        GLFWwindow* m_window;
        utils::observer<events::window_close_event> m_window_close_observer;
        utils::observer<events::window_position_event> m_window_position_observer;
        utils::observer<events::window_resize_event> m_window_resize_observer;
        utils::observer<events::window_focus_event> m_window_focus_observer;
        utils::observer<events::window_refresh_event> m_window_refresh_observer;
        utils::observer<events::window_iconify_event> m_window_iconify_observer;
        utils::observer<events::window_maximize_event> m_window_maximize_observer;
        utils::observer<events::keyboard_input_event> m_keyboard_input_observer;
        utils::observer<events::char_input_event> m_char_input_observer;
        utils::observer<events::cursor_position_event> m_cursor_position_observer;
        utils::observer<events::cursor_focus_event> m_cursor_focus_observer;
        utils::observer<events::mouse_button_input_event> m_mouse_button_input_observer;
        utils::observer<events::scroll_input_event> m_scroll_input_observer;
        utils::observer<events::path_drop_event> m_path_drop_observer;
    };
} // namespace cringine::event_system
