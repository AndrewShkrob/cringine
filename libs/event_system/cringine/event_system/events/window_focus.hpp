#pragma once

namespace cringine::event_system::events
{
    class window_focus_event
    {
    public:
        virtual void window_focus(bool new_state) = 0;
    };

    using window_focus_event_ptr = window_focus_event*;
} // namespace cringine::event_system::events
