#pragma once

namespace cringine::event_system::events
{
    class window_maximize_event
    {
    public:
        virtual void window_maximize() = 0;
    };

    using window_maximize_event_ptr = window_maximize_event*;
} // namespace cringine::event_system::events
