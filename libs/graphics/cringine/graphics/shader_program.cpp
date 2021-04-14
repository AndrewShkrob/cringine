#include "shader_program.hpp"

using namespace cringine;

shader_program::shader_program(GLuint program)
    : m_program(program)
{
}

void shader_program::use() const
{
    glUseProgram(m_program);
}

GLuint shader_program::program() const
{
    return m_program;
}

void shader_program::set_uniform_1i(const std::string& uniform_name, GLint value) const
{
    GLint uniform_location = get_uniform_location(uniform_name);
    glUniform1i(uniform_location, value);
}

void shader_program::set_uniform_1f(const std::string& uniform_name, GLfloat value) const
{
    GLint uniform_location = get_uniform_location(uniform_name);
    glUniform1f(uniform_location, value);
}

void shader_program::set_uniform_3f(const std::string& uniform_name, GLfloat v0, GLfloat v1, GLfloat v2) const
{
    GLint uniform_location = get_uniform_location(uniform_name);
    glUniform3f(uniform_location, v0, v1, v2);
}

void shader_program::set_uniform_matrix4fv(const std::string& uniform_name, GLsizei count, GLboolean transpose, const GLfloat* value) const
{
    GLint uniform_location = get_uniform_location(uniform_name);
    glUniformMatrix4fv(uniform_location, count, transpose, value);
}

GLint shader_program::get_uniform_location(const std::string& uniform_name) const
{
    return glGetUniformLocation(m_program, uniform_name.c_str());
}
