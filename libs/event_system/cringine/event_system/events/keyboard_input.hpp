#pragma once

#include <cringine/event_system/input/keys.hpp>

namespace cringine::event_system::events
{
    class keyboard_input_event
    {
    public:
        virtual void keyboard_input(input::keys::key_t key, int action) = 0;
    };

    using keyboard_input_event_ptr = keyboard_input_event*;
} // namespace cringine::event_system::events
