#include "shader_data_binder.hpp"

#include <GL/glew.h>

using namespace cringine::shaders;

shader_data_binder::shader_data_binder(shader& shader)
    : m_shader(shader)
{
}

[[maybe_unused]] void shader_data_binder::set_uniform_1f(std::string_view uniform_name, float v0) const
{
    glUniform1f(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2f(std::string_view uniform_name, float v0, float v1) const
{
    glUniform2f(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3f(std::string_view uniform_name, float v0, float v1, float v2) const
{
    glUniform3f(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4f(std::string_view uniform_name, float v0, float v1, float v2, float v3) const
{
    glUniform4f(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1i(std::string_view uniform_name, int v0) const
{
    glUniform1i(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2i(std::string_view uniform_name, int v0, int v1) const
{
    glUniform2i(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3i(std::string_view uniform_name, int v0, int v1, int v2) const
{
    glUniform3i(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4i(std::string_view uniform_name, int v0, int v1, int v2, int v3) const
{
    glUniform4i(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1ui(std::string_view uniform_name, unsigned int v0) const
{
    glUniform1ui(get_uniform_location(uniform_name), v0);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2ui(std::string_view uniform_name, unsigned int v0, unsigned int v1) const
{
    glUniform2ui(get_uniform_location(uniform_name), v0, v1);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3ui(std::string_view uniform_name, unsigned int v0, unsigned int v1, unsigned int v2) const
{
    glUniform3ui(get_uniform_location(uniform_name), v0, v1, v2);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4ui(std::string_view uniform_name, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3) const
{
    glUniform4ui(get_uniform_location(uniform_name), v0, v1, v2, v3);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1fv(std::string_view uniform_name, int count, const float* value) const
{
    glUniform1fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2fv(std::string_view uniform_name, int count, const float* value) const
{
    glUniform2fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3fv(std::string_view uniform_name, int count, const float* value) const
{
    glUniform3fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4fv(std::string_view uniform_name, int count, const float* value) const
{
    glUniform4fv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1iv(std::string_view uniform_name, int count, const int* value) const
{
    glUniform1iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2iv(std::string_view uniform_name, int count, const int* value) const
{
    glUniform2iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3iv(std::string_view uniform_name, int count, const int* value) const
{
    glUniform3iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4iv(std::string_view uniform_name, int count, const int* value) const
{
    glUniform4iv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_1uiv(std::string_view uniform_name, int count, const unsigned int* value) const
{
    glUniform1uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_2uiv(std::string_view uniform_name, int count, const unsigned int* value) const
{
    glUniform2uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_3uiv(std::string_view uniform_name, int count, const unsigned int* value) const
{
    glUniform3uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_4uiv(std::string_view uniform_name, int count, const unsigned int* value) const
{
    glUniform4uiv(get_uniform_location(uniform_name), count, value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2x3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2x3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3x2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix2x4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix2x4fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4x2fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix3x4fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix3x2fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

[[maybe_unused]] void shader_data_binder::set_uniform_matrix4x3fv(std::string_view uniform_name, int count, bool transpose, const float* value) const
{
    glUniformMatrix4x3fv(get_uniform_location(uniform_name), count, static_cast<GLboolean>(transpose), value);
}

int shader_data_binder::get_uniform_location(std::string_view uniform_name) const
{
    return glGetUniformLocation(m_shader.id(), uniform_name.data());
}
