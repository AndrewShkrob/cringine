#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace cringine::types::object
{
    struct texture
    {
        enum class type
        {
            DIFFUSE,
            SPECULAR
        };

        unsigned int id;
        type type;
    };
} // namespace cringine::types::object
