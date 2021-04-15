#pragma once

#include <cringine/shaders/shader.hpp>

namespace cringine::shaders
{
    enum class shader_uniform_type
    {
        Matrix2fv,
        Matrix3fv,
        Matrix4fv,
        Matrix2x3fv,
        Matrix3x2fv,
        Matrix2x4fv,
        Matrix4x2fv,
        Matrix3x4fv,
        Matrix4x3fv,
    };
} // namespace cringine::shaders