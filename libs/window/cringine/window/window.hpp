#pragma once

#include <cringine/event_system/event_system.hpp>

#include <memory>

namespace cringine::window
{
    class window
    {
    public:
        virtual ~window() = default;

        virtual event_system::event_system_sptr event_system() = 0;

        virtual void set_title(const std::string& title) = 0;

        virtual void update() = 0;
        virtual void render() = 0;
    };

    using window_sptr = std::shared_ptr<window>;
} // namespace cringine::window