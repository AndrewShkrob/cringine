#pragma once

#include <functional>

namespace cringine::event_system::events
{
    using window_resize_event = std::function<void(int width, int height)>;
} // namespace cringine::event_system::events
