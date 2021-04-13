#pragma once

#include <cringine/event_system/event_system.hpp>

#include <string>
#include <functional>

#include <GLFW/glfw3.h>

namespace cringine
{
    class window : event_system::events::window_resize_event
    {
    public:
        using render_func = std::function<void()>;

        window(int width, int height, std::string title);
        ~window();

        window(const window&) = default;
        window(window&&) = default;

        window& operator=(const window&) = default;
        window& operator=(window&&) = default;

        event_system::event_system_sptr event_system();

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

        void launch(const render_func& render);

    private:
        void window_resize(int new_width, int new_height) override;

    private:
        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow* m_window;
        event_system::event_system_sptr m_event_system;
    };
} // namespace cringine