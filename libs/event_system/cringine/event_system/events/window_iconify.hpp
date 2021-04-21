#pragma once

namespace cringine::event_system::events
{
    class window_iconify_event
    {
    public:
        virtual void window_iconify() = 0;
    };

    using window_iconify_event_ptr = window_iconify_event*;
} // namespace cringine::event_system::events
