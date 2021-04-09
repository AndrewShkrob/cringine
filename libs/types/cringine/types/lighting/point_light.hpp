#pragma once

#include <cringine/types/lighting/light.hpp>

#include <glm/vec3.hpp>

namespace cringine::types::lighting
{
    struct point_light : public light
    {
        static constexpr lighting_type TYPE = lighting_type::POINT;

        glm::vec3 position{0.0f};

        /// Kc for attenuation coefficient
        float constant{1.0f};
        /// Kl for attenuation coefficient
        float linear{0.0f};
        /// Kq for attenuation coefficient
        float quadratic{0.0f};
    };
} // namespace cringine::types::lighting
