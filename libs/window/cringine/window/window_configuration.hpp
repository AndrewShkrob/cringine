#pragma once

#include <string>

namespace cringine::window
{
    struct window_size
    {
        int32_t width = 0;
        int32_t height = 0;
    };

    struct window_configuration
    {
        window_size size{};
        std::string title{};
        bool resizable = false;
        bool use_cursor = false;
    };
} // namespace cringine::window
