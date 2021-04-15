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

        void register_window_resize_callback(events::window_resize_event_ptr callback) override;

    private:
        void init();

        GLFWwindow* m_window;
        utils::observer<events::window_close_event> m_window_close_observer;
        utils::observer<events::window_resize_event> m_window_resize_observer;
    };
} // namespace cringine::event_system
