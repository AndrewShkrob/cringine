#include "engine.hpp"

using namespace cringine;
using namespace cringine::types;

// TEMPORARY
#include <cringine/event_system/input/glfw/glfw_input_manager.hpp>
// !TEMPORARY

engine::engine(const configuration::window_configuration& window_config)
    : m_window(window_config)
    , m_event_system(m_window.event_system())
    , m_input_manager(std::make_shared<event_system::input::glfw_input_manager>())
{
    init_event_system();
}

void engine::start(const render_func& func)
{
    m_stop = false;
    loop(func);
}

event_system::event_system_sptr engine::event_system()
{
    return m_event_system;
}

double engine::delta_time() const
{
    return m_fps_counter.delta_time();
}

int engine::fps() const
{
    return m_fps_counter.fps();
}

double engine::time() const
{
    return m_fps_counter.time();
}

const window & engine::window() const
{
    return m_window;
}

void engine::window_close()
{
    m_stop = true;
}

void engine::init_event_system()
{
    m_event_system->register_window_close_callback(this);
    m_input_manager->bind_to_event_system(m_event_system);
}

void engine::loop(const render_func& func)
{
    m_running = true;
    while (!m_stop) {
        m_input_manager->update_states();
        m_window.update();
        if (m_stop) {
            break;
        }
        m_fps_counter.tick();
        func();

        m_window.render();
    }
    m_running = false;
}
