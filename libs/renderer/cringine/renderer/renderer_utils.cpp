#include "renderer_utils.hpp"

#include <GL/glew.h>

void cringine::renderer::enable_depth_buffer()
{
    glEnable(GL_DEPTH_TEST);
}

void cringine::renderer::set_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void cringine::renderer::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}