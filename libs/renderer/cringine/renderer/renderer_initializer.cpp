#include "renderer_initializer.hpp"

#include <GL/glew.h>

#include <iostream>

void cringine::renderer::initialize()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("Failed to initialize GLEW");
    }
}