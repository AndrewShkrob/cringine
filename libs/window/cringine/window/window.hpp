#pragma once

#include <cringine/event_system/event_system.hpp>
#include <cringine/types/configuration/window_configuration.hpp>

#include <string>
#include <functional>

#include <GLFW/glfw3.h>

namespace cringine
{
    class window
    {
    public:
        explicit window(const types::configuration::window_configuration& window_config);
        window(int width, int height, std::string title);
        ~window();

        window(const window&) = default;
        window(window&&) = default;

        window& operator=(const window&) = default;
        window& operator=(window&&) = default;

        event_system::event_system_sptr event_system();

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

        void update() const;
        void render() const;

    private:
        void window_resize(int new_width, int new_height);

        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow* m_window;
        event_system::event_system_sptr m_event_system;
    };
} // namespace cringine
