#pragma once

#include <cringine/window/window_configuration.hpp>
#include <cringine/window/window.hpp>

namespace cringine::window
{
    class window_builder
    {
    public:
        window_builder& set_size(const window_size& window_size);

        window_builder& set_title(const std::string &title);

        window_builder& set_resizable(bool resizable);

        window_builder& set_use_cursor(bool use_cursor);

        window_sptr build();
    private:
        window_configuration window_configuration;
    };
}