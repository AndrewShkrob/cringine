#pragma once

#include <memory>

namespace cringine::event_system::events
{
    class keyboard_input_event
    {
    public:
        virtual void keyboard_input(int key, int ) = 0;
    };

    using window_close_event_ptr = window_close_event*;
} // namespace cringine::event_system::events
