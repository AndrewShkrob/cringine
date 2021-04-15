#pragma once

#include <string>

#include <cringine/graphics/shader_program.hpp>

namespace cringine
{
    class shader_program_builder
    {
    public:
        shader_program_builder& add_vertex_shader(std::string vertex_shader_path);

        shader_program_builder& add_fragment_shader(std::string fragment_shader_path);

        shader_program build();

    private:
        std::string m_vertex_shader_path;
        std::string m_fragment_shader_path;
    };
} // namespace cringine
