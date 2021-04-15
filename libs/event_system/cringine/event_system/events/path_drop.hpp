#pragma once

#include <string>
#include <vector>

namespace cringine::event_system::events
{
    class path_drop_event
    {
    public:
        virtual void path_drop(const std::vector<std::string>& paths) = 0;
    };

    using path_drop_event_ptr = path_drop_event*;
} // namespace cringine::event_system::events
