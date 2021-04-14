#pragma once

namespace cringine::event_system::events
{
    class scroll_input_event
    {
    public:
        virtual void scroll_input(double dx, double dy) = 0;
    };

    using scroll_input_event_ptr = scroll_input_event*;
} // namespace cringine::event_system::events
