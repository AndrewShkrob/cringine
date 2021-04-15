#include "shader.hpp"

#include <GL/glew.h>

using namespace cringine::shaders;

void shader::use() const
{
    glUseProgram(m_id);
}

void shader::disuse() const
{
    glUseProgram(0);
    (void) m_id;
}

unsigned int shader::id() const
{
    return m_id;
}
