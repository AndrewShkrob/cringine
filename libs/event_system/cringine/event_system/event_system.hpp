#pragma once

#include <cringine/event_system/events/all.hpp>

namespace cringine::event_system
{
    class event_system
    {
    public:
        virtual void register_window_close_callback(events::window_close_event callback) = 0;

        virtual void register_window_resize_callback(events::window_resize_event callback) = 0;
    };

    using event_system_sptr = std::shared_ptr<event_system>;
} // namespace cringine::event_system
