#include <GL/glew.h>

#include <cringine/window/window.hpp>

#include <iostream>

int main() {
    cringine::window window(800, 600, "LearnOpenGL");

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glViewport(0, 0, window.width(), window.height());

    window.launch([]() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    });

    return 0;
}