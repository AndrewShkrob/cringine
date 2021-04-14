#pragma once

#include <functional>

namespace cringine::event_system::events
{
    using window_close_event = std::function<void()>;
} // namespace cringine::event_system::events
