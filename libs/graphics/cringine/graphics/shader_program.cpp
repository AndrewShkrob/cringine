#include "shader_program.hpp"

using namespace cringine;

cringine::shader_program::shader_program(GLuint program)
    : m_program(program) {}

void cringine::shader_program::use() {
    glUseProgram(m_program);
}

GLuint cringine::shader_program::program() const {
    return m_program;
}