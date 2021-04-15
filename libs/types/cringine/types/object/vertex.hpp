#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace cringine::types::object
{
    struct vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texture_coords;
    };
} // namespace cringine::types::object
