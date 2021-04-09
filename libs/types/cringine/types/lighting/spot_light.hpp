#pragma once

#include <cringine/types/lighting/light.hpp>

#include <glm/vec3.hpp>

namespace cringine::types::lighting
{
    struct spot_light : public light
    {
        static constexpr lighting_type TYPE = lighting_type::SPOT;

        glm::vec3 position{0.0f};
        glm::vec3 direction{0.0f};

        float cut_off_angle{0.0f};
        float outer_cut_off_angle{0.0f};
    };
} // namespace cringine::types::lighting
