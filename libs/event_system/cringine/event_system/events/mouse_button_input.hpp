#pragma once

#include <cringine/event_system/input/keys.hpp>

namespace cringine::event_system::events
{
    class mouse_button_input_event
    {
    public:
        virtual void mouse_button_input(input::keys::key_t button, int action) = 0;
    };

    using mouse_button_input_event_ptr = mouse_button_input_event*;
} // namespace cringine::event_system::events
