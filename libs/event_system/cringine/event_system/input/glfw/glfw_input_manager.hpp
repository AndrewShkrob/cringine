#pragma once

#include <cringine/event_system/input/input_manager.hpp>

namespace cringine::event_system::input
{
    class glfw_input_manager final : public input_manager
    {
    public:
        glfw_input_manager() = default;
        ~glfw_input_manager() override = default;

        glfw_input_manager(const glfw_input_manager&) = delete;
        glfw_input_manager(glfw_input_manager&&) = delete;

        glfw_input_manager& operator=(const glfw_input_manager&) = delete;
        glfw_input_manager& operator=(glfw_input_manager&&) = delete;

        void cursor_focus(bool new_state) override;
        void cursor_position(double x, double y) override;
        void scroll_input(double dx, double dy) override;
        void keyboard_input(keys::key_t key, int action) override;
        void mouse_button_input(keys::key_t button, int action) override;
    };
}
