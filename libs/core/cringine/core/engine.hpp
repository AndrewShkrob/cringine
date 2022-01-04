#pragma once

#include <cringine/window/window.hpp>
#include <cringine/event_system/events/window_close.hpp>
#include <cringine/event_system/event_system.hpp>
#include <cringine/event_system/input/input_manager.hpp>
#include <cringine/utils/fps_counter.hpp>

namespace cringine
{
    class engine : cringine::event_system::events::window_close_event
    {
    public:
        using render_func = std::function<void()>;

        explicit engine(window::window_sptr window);

        void start(const render_func& func);

        void stop();

        event_system::event_system_sptr event_system();

        [[nodiscard]] double delta_time() const;

        [[nodiscard]] int fps() const;

        [[nodiscard]] double time() const;

        [[nodiscard]] const window::window_sptr& window() const;

        [[nodiscard]] const event_system::input::input_manager& input_manager() const;

    private:
        void window_close() override;

        void init_event_system();

        void loop(const render_func& func);

        bool m_running = false;
        bool m_stop = true;

        window::window_sptr m_window;
        event_system::event_system_sptr m_event_system;
        event_system::input::input_manager m_input_manager;
        utils::fps_counter m_fps_counter;
    };
} // namespace cringine
