#include "window_builder.hpp"

#include <cringine/window/internal/glfw_window.hpp>

namespace cringine::window
{
    window_builder& window_builder::set_size(const window_size& window_size)
    {
        window_configuration.size = window_size;
        return *this;
    }

    window_builder& window_builder::set_title(const std::string &title)
    {
        window_configuration.title = title;
        return *this;
    }

    window_builder& window_builder::set_resizable(bool resizable)
    {
        window_configuration.resizable = resizable;
        return *this;
    }

    window_builder& window_builder::set_use_cursor(bool use_cursor)
    {
        window_configuration.use_cursor = use_cursor;
        return *this;
    }

    window_sptr window_builder::build()
    {
        return std::make_shared<internal::glfw_window>(window_configuration);
    }
}