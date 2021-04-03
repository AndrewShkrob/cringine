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

        window(int width, int height, std::string title);
        window(const window&) = default;
        window(window&&) = default;
        ~window();

        window& operator=(const window&) = default;
        window& operator=(window&&) = default;

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

        void launch(const render_func& render);

    private:
        int m_width;
        int m_height;
        std::string m_title;
        GLFWwindow* m_window;
    };
} // namespace cringine