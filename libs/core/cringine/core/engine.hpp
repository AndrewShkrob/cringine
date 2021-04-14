#pragma once

#include <cringine/window/window.hpp>
#include <cringine/event_system/events/window_close.hpp>
#include <cringine/event_system/event_system.hpp>
#include <cringine/event_system/input/input_manager.hpp>
#include <cringine/types/configuration/window_configuration.hpp>
#include <cringine/utils/fps_counter.hpp>

namespace cringine
{
    class engine
    {
    public:
        using render_func = std::function<void()>;

        explicit engine(const types::configuration::window_configuration& window_config);

        void start(const render_func& func);

        event_system::event_system_sptr event_system();

        [[nodiscard]] double delta_time() const;

        [[nodiscard]] int fps() const;

        [[nodiscard]] double time() const;

    protected:
        void window_close();

    private:
        void init_event_system();

        void loop(const render_func& func);

        bool m_running = false;
        bool m_stop = true;

        window m_window;
        event_system::event_system_sptr m_event_system;
        event_system::input::input_manager m_input_manager;
        utils::fps_counter m_fps_counter;
    };
} // namespace cringine
