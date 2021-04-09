#pragma once

#include <glm/vec3.hpp>

namespace cringine::types::lighting
{
    struct light
    {
        enum class lighting_type : short
        {
            DIRECTIONAL = 0,
            POINT,
            SPOT
        };

        glm::vec3 ambient_color{0.0f};
        glm::vec3 diffuse_color{0.0f};
        glm::vec3 specular_color{0.0f};
    };
} // namespace cringine::types::lighting
