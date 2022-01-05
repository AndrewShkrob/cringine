#pragma once

#include <cringine/window/window.hpp>
#include <cringine/event_system/event_system.hpp>
#include <cringine/window/window_configuration.hpp>

#include <string>
#include <functional>

#ifdef __APPLE__
    #define GLFW_INCLUDE_GLCOREARB
#endif

#include "GLFW/glfw3.h"

namespace cringine::window::internal
{
    class glfw_window final : public window, event_system::events::window_resize_event
    {
    public:
        explicit glfw_window(window_configuration window_config);
        ~glfw_window() override;

        event_system::event_system_sptr event_system() override;

        void set_title(const std::string& title) override;

        [[nodiscard]] window_size size() const;

        void update() override;
        void render() override;

    private:
        void window_resize(window_size window_size) override;

        window_configuration m_window_configuration;
        GLFWwindow* m_window;
        event_system::event_system_sptr m_event_system;
    };
} // namespace cringine::window::internal
