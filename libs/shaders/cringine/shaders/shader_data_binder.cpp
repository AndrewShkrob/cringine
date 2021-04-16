#include "shader_data_binder.hpp"

#include <GL/glew.h>

using namespace cringine::shaders;

shader_data_binder::shader_data_binder(shader& shader)
    : m_shader(shader)
{
}

[[maybe_unused]] void shader_data_binder::set_uniform_1f(const std::string& uniform_name, float v0) const
{
    glUniform1f(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2f(const std::string& uniform_name, float v0, float v1) const
{
    glUniform2f(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3f(const std::string& uniform_name, float v0, float v1, float v2) const
{
    glUniform3f(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4f(const std::string& uniform_name, float v0, float v1, float v2, float v3) const
{
    glUniform4f(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1i(const std::string& uniform_name, int v0) const
{
    glUniform1i(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2i(const std::string& uniform_name, int v0, int v1) const
{
    glUniform2i(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3i(const std::string& uniform_name, int v0, int v1, int v2) const
{
    glUniform3i(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4i(const std::string& uniform_name, int v0, int v1, int v2, int v3) const
{
    glUniform4i(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1ui(const std::string& uniform_name, unsigned int v0) const
{
    glUniform1ui(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2ui(const std::string& uniform_name, unsigned int v0, unsigned int v1) const
{
    glUniform2ui(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3ui(const std::string& uniform_name, unsigned int v0, unsigned int v1, unsigned int v2) const
{
    glUniform3ui(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4ui(const std::string& uniform_name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) const
{
    glUniform4ui(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1fv(const std::string& uniform_name, int count, const float* value) const
{
    glUniform1fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2fv(const std::string& uniform_name, int count, const float* value) const
{
    glUniform2fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3fv(const std::string& uniform_name, int count, const float* value) const
{
    glUniform3fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4fv(const std::string& uniform_name, int count, const float* value) const
{
    glUniform4fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1iv(const std::string& uniform_name, int count, const int* value) const
{
    glUniform1iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2iv(const std::string& uniform_name, int count, const int* value) const
{
    glUniform2iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3iv(const std::string& uniform_name, int count, const int* value) const
{
    glUniform3iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4iv(const std::string& uniform_name, int count, const int* value) const
{
    glUniform4iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1uiv(const std::string& uniform_name, int count, const unsigned int* value) const
{
    glUniform1uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2uiv(const std::string& uniform_name, int count, const unsigned int* value) const
{
    glUniform2uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3uiv(const std::string& uniform_name, int count, const unsigned int* value) const
{
    glUniform3uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4uiv(const std::string& uniform_name, int count, const unsigned int* value) const
{
    glUniform4uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2x3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2x3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3x2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2x4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2x4fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4x2fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3x4fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4x3fv(const std::string& uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4x3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

int shader_data_binder::get_uniform_location(const std::string& uniform_name) const
{
    return glGetUniformLocation(m_shader.id(), uniform_name.c_str());
}
