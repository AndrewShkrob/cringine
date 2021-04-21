#pragma once

namespace cringine::event_system::events
{
    class cursor_position_event
    {
    public:
        virtual void cursor_position(double x, double y) = 0;
    };

    using cursor_position_event_ptr = cursor_position_event*;
} // namespace cringine::event_system::events
