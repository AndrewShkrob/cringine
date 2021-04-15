#pragma once

namespace cringine::event_system::events
{
    class cursor_focus_event
    {
    public:
        virtual void cursor_focus(bool new_state) = 0;
    };

    using cursor_focus_event_ptr = cursor_focus_event*;
} // namespace cringine::event_system::events
