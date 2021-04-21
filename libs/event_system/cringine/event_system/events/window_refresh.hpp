#pragma once

namespace cringine::event_system::events
{
    class window_refresh_event
    {
    public:
        virtual void window_refresh() = 0;
    };

    using window_refresh_event_ptr = window_refresh_event*;
} // namespace cringine::event_system::events
