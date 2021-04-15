#pragma once

#include <cringine/event_system/input/keys.hpp>
#include <cringine/event_system/event_system.hpp>

#include <array>

namespace cringine::event_system::input
{
    class input_manager : protected events::cursor_focus_event, protected events::cursor_position_event,
                          protected events::keyboard_input_event, protected events::mouse_button_input_event,
                          protected events::scroll_input_event
    {
    public:
        void bind_to_event_system(event_system_sptr event_system);

        void update_states();

        [[nodiscard, maybe_unused]] bool is_cursor_focused() const;
        [[nodiscard, maybe_unused]] std::pair<double, double> cursor_position() const;
        [[nodiscard, maybe_unused]] double cursor_position_x() const;
        [[nodiscard, maybe_unused]] double cursor_position_y() const;
        [[nodiscard, maybe_unused]] std::pair<double, double> scroll_delta() const;
        [[nodiscard, maybe_unused]] double scroll_delta_x() const;
        [[nodiscard, maybe_unused]] double scroll_delta_y() const;
        [[nodiscard, maybe_unused]] bool is_key_pressed(keys::key_t key) const;
        [[nodiscard, maybe_unused]] bool is_key_released(keys::key_t key) const;
        [[nodiscard, maybe_unused]] bool is_key_down(keys::key_t key) const;
        [[nodiscard, maybe_unused]] bool is_key_up(keys::key_t key) const;
        [[nodiscard, maybe_unused]] bool is_mouse_button_pressed(keys::key_t button) const;
        [[nodiscard, maybe_unused]] bool is_mouse_button_released(keys::key_t button) const;
        [[nodiscard, maybe_unused]] bool is_mouse_button_down(keys::key_t button) const;
        [[nodiscard, maybe_unused]] bool is_mouse_button_up(keys::key_t button) const;

    private:
        void update_key_states();
        void update_button_states();
        void update_scroll_delta();

    protected:
        void cursor_focus(bool new_state) override;
        void cursor_position(double x, double y) override;
        void scroll_input(double dx, double dy) override;
        void keyboard_input(keys::key_t key, bool new_state) override;
        void mouse_button_input(keys::key_t button, bool new_state) override;

    private:
        bool m_cursor_focus = true;
        double m_cursor_x = 0;
        double m_cursor_y = 0;
        double m_scroll_delta_x = 0;
        double m_scroll_delta_y = 0;

        std::array<bool, keys::KEY_AMOUNT> m_key_current_states{false};
        std::array<bool, keys::KEY_AMOUNT> m_key_previous_states{false};

        std::array<bool, keys::BUTTON_AMOUNT> m_button_current_states{false};
        std::array<bool, keys::BUTTON_AMOUNT> m_button_previous_states{false};
    };

    using input_manager_sptr = std::shared_ptr<input_manager>;
} // namespace cringine::event_system::input
