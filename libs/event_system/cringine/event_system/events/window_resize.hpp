#pragma once

#include <functional>

namespace cringine::event_system::events
{
    class window_resize_event
    {
    public:
        virtual void window_resize(int width, int height) = 0;
    };

    using window_resize_event_ptr = window_resize_event*;
} // namespace cringine::event_system::events
