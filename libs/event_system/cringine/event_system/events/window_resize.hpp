#pragma once

#include <cringine/window/window_configuration.hpp>

namespace cringine::event_system::events
{
    class window_resize_event
    {
    public:
        virtual void window_resize(window::window_size) = 0;
    };

    using window_resize_event_ptr = window_resize_event*;
} // namespace cringine::event_system::events
