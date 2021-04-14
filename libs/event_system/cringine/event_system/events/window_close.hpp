#pragma once

namespace cringine::event_system::events
{
    class window_close_event
    {
    public:
        virtual void window_close() = 0;
    };

    using window_close_event_ptr = window_close_event*;
} // namespace cringine::event_system::events
