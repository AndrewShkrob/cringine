#pragma once

#include <cringine/event_system/input/keys.hpp>

#include <functional>

namespace cringine::event_system::events
{
    using keyboard_input_event = std::function<void(input::key_t, int action)>;
} // namespace cringine::event_system::events
