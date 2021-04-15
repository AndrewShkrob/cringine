#pragma once

namespace cringine::event_system::events
{
    class char_input_event
    {
    public:
        virtual void char_input(unsigned int character) = 0;
    };

    using char_input_event_ptr = char_input_event*;
} // namespace cringine::event_system::events
