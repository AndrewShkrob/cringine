#pragma once

#include <string>
#include <functional>

#include <GLFW/glfw3.h>

namespace cringine
{
    class window
    {
    public:
        using render_func = std::function<void()>;
        using key_callback_func = std::function<void(int key, int action)>;
        using mouse_callback_func = std::function<void(double x_pos, double y_pos)>;
        using scroll_callback_func = std::function<void(double x_offset, double y_offset)>;

        window(int width, int height, std::string title);
        window(const window&) = default;
        window(window&&) = default;
        ~window();

        window& operator=(const window&) = default;
        window& operator=(window&&) = default;

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

        void set_key_callback(key_callback_func callback);
        void set_mouse_callback(mouse_callback_func callback);
        void set_scroll_callback(scroll_callback_func callback);

        void launch(const render_func& render);

    private:
        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow* m_window;
    };
} // namespace cringine