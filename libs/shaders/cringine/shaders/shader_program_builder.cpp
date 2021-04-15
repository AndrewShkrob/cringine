#include "shader_program_builder.hpp"

#include <iostream>
#include <utility>
#include <array>

#include <cringine/utils/load_from_file.hpp>

using namespace cringine;

namespace
{
    GLuint compile_shader(const char* shader_source, GLuint shader_type)
    {
        GLuint shader = glCreateShader(shader_type);
        glShaderSource(shader, 1, &shader_source, nullptr);
        glCompileShader(shader);

        GLint success{};
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (success == 0) {
            const short array_size = 512;
            std::array<GLchar, array_size> infoLog{};
            glGetShaderInfoLog(shader, array_size, nullptr, infoLog.data());
            std::string shader_type_str = shader_type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
            std::cout << "ERROR::SHADER::" << shader_type_str << "::COMPILATION_FAILED\n"
                      << infoLog.data() << std::endl;
        }

        return shader;
    }

    GLuint create_shader_program(const char* vertex_shader, const char* fragment_shader)
    {
        GLuint vertexShader = compile_shader(vertex_shader, GL_VERTEX_SHADER);
        GLuint fragmentShader = compile_shader(fragment_shader, GL_FRAGMENT_SHADER);
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        GLint success{};
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

        if (success == 0) {
            const short array_size = 512;
            std::array<GLchar, array_size> infoLog{};
            glGetProgramInfoLog(shaderProgram, array_size, nullptr, infoLog.data());
            std::cout << "ERROR::SHADER_PROGRAM::LINK_FAILED\n"
                      << infoLog.data() << std::endl;
        }

        return shaderProgram;
    }
} // namespace

shader_program_builder& cringine::shader_program_builder::add_vertex_shader(std::string vertex_shader_path)
{
    m_vertex_shader_path = std::move(vertex_shader_path);
    return *this;
}

shader_program_builder& cringine::shader_program_builder::add_fragment_shader(std::string fragment_shader_path)
{
    m_fragment_shader_path = std::move(fragment_shader_path);
    return *this;
}

shader_program cringine::shader_program_builder::build()
{
    auto vertex_shader = utils::load_from_file(m_vertex_shader_path);
    auto fragment_shader = utils::load_from_file(m_fragment_shader_path);
    return shader_program(create_shader_program(vertex_shader.c_str(), fragment_shader.c_str()));
}
