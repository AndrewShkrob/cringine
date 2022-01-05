#include "engine.hpp"

#include <cringine/renderer/renderer_initializer.hpp>

using namespace cringine;

engine::engine(const window::window_sptr window)
    : m_window(window)
    , m_event_system(m_window->event_system())
{
    cringine::renderer::initialize();
    init_event_system();
}

void engine::start(const render_func& func)
{
    m_stop = false;
    loop(func);
}

void engine::stop()
{
    m_stop = true;
}

event_system::event_system_sptr engine::event_system()
{
    return m_event_system;
}

const event_system::input::input_manager& engine::input_manager() const
{
    return m_input_manager;
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

const window::window_sptr& engine::window() const
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
    m_input_manager.bind_to_event_system(m_event_system);
}

void engine::loop(const render_func& func)
{
    m_running = true;
    while (!m_stop) {
        m_input_manager.update_states();
        m_window->update();
        if (m_stop) {
            break;
        }
        m_fps_counter.tick();
        func();

        m_window->render();
    }
    m_running = false;
}
