#pragma once

#include <string>
#include <functional>

#include <GLFW/glfw3.h>

namespace cringine {
    class window {
    public:
        using render_func = std::function<void()>;

        window(int width, int height, std::string title);
        ~window();

        [[nodiscard]] int width() const;
        [[nodiscard]] int height() const;

        void launch(const render_func& func);

    private:
        int m_width;
        int m_height;
        const std::string m_title;
        GLFWwindow *m_window;
    };
}// namespace cringine