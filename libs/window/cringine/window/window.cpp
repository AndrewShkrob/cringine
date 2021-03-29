#include "window.hpp"

#include <exception>
#include <utility>

using namespace cringine;

namespace {
    void init_glfw() {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }

    void terminate_glfw() {
        glfwTerminate();
    }
}// namespace

window::window(int width, int height, std::string title)
    : m_width(width), m_height(height), m_title(std::move(title)) {
    init_glfw();
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        terminate_glfw();
        throw std::exception("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
}

window::~window() {
    terminate_glfw();
}

int window::width() const {
    return m_width;
}

int window::height() const {
    return m_height;
}

void window::launch(const render_func& func) {
    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();

        func();

        glfwSwapBuffers(m_window);
    }
}