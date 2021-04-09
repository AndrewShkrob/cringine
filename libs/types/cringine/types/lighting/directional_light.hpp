#pragma once

#include <cringine/types/lighting/light.hpp>

#include <glm/vec3.hpp>

namespace cringine::types::lighting
{
    struct directional_light : light
    {
        static constexpr lighting_type TYPE = lighting_type::DIRECTIONAL;

        glm::vec3 direction{0.0f};
    };
} // namespace cringine::types::lighting
