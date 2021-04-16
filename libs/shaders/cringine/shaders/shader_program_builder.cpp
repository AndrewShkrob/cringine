#include "shader_program_builder.hpp"

#include <cringine/utils/load_from_file.hpp>

#include <GL/glew.h>

#include <iostream>
#include <utility>
#include <array>

using namespace cringine::shaders;

namespace
{
    void log_shader_error(GLuint shader, GLuint shader_type)
    {
        const short array_size = 512;
        std::array<GLchar, array_size> info_log{};
        std::string shader_type_name;
        glGetShaderInfoLog(shader, array_size, nullptr, info_log.data());
        switch (shader_type) {
            case GL_VERTEX_SHADER:
                shader_type_name = "VERTEX";
                break;
            case GL_FRAGMENT_SHADER:
                shader_type_name = "FRAGMENT";
                break;
            case GL_GEOMETRY_SHADER:
                shader_type_name = "GEOMETRY";
                break;
                [[unlikely]] default : shader_type_name = "UNKNOWN";
        }
        std::cout << "ERROR::SHADER::" << shader_type_name << "::COMPILATION_FAILED\n"
                  << info_log.data() << std::endl;
    }

    void log_shader_program_error(GLuint shader_program)
    {
        const short array_size = 512;
        std::array<GLchar, array_size> info_log{};
        glGetProgramInfoLog(shader_program, array_size, nullptr, info_log.data());
        std::cout << "ERROR::SHADER_PROGRAM::LINK_FAILED\n"
                  << info_log.data() << std::endl;
    }

    std::pair<std::vector<const char*>, std::vector<int>> to_char_array(const std::vector<std::string>& data)
    {
        std::vector<const char*> result;
        std::vector<int> result_lengths;
        result.reserve(data.size());
        result_lengths.reserve(data.size());
        for (const auto& str : data) {
            result.push_back(str.c_str());
            result_lengths.push_back(static_cast<int>(str.size()));
        }
        return {std::move(result), std::move(result_lengths)};
    }

    GLuint compile_shader(const std::vector<std::string>& shader_source, GLuint shader_type)
    {
        auto [shader_data, shader_data_lengths] = to_char_array(shader_source);

        GLuint shader = glCreateShader(shader_type);
        glShaderSource(shader, shader_data.size(), shader_data.data(), shader_data_lengths.data());
        glCompileShader(shader);

        GLint success{};
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (success == GL_FALSE) {
            log_shader_error(shader, shader_type);
        }

        return shader;
    }

    GLuint create_shader_program(const std::vector<std::string>& vertex_shader_data, const std::vector<std::string>& fragment_shader_data)
    {
        GLuint vertex_shader = compile_shader(vertex_shader_data, GL_VERTEX_SHADER);
        GLuint fragment_shader = compile_shader(fragment_shader_data, GL_FRAGMENT_SHADER);
        GLuint shader_program = glCreateProgram();
        glAttachShader(shader_program, vertex_shader);
        glAttachShader(shader_program, fragment_shader);
        glLinkProgram(shader_program);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        GLint success{};
        glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

        if (success == GL_FALSE) {
            log_shader_program_error(shader_program);
        }

        return shader_program;
    }
} // namespace

shader_program_builder& cringine::shaders::shader_program_builder::add_vertex_shader(std::string vertex_shader_path)
{
    m_vertex_shader_path = std::move(vertex_shader_path);
    return *this;
}

shader_program_builder& cringine::shaders::shader_program_builder::add_fragment_shader(std::string fragment_shader_path)
{
    m_fragment_shader_path = std::move(fragment_shader_path);
    return *this;
}

shader cringine::shaders::shader_program_builder::build()
{
    auto vertex_shader = utils::load_from_file(m_vertex_shader_path);
    auto fragment_shader = utils::load_from_file(m_fragment_shader_path);
    return shader(create_shader_program(vertex_shader, fragment_shader));
}
