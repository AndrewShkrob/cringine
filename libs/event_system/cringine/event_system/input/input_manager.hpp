#pragma once

#include <cringine/event_system/input/keys.hpp>

namespace cringine::event_system::input
{
    class input_manager
    {
    public:
    private:
        std::array<bool, keys::KEY_AMOUNT> m_key_states{false};
    };
} // namespace cringine::event_system::input
