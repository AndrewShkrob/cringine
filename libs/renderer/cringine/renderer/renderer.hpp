#pragma once

#include <cringine/shaders/shader.hpp>

namespace cringine::renderer
{
    class renderer
    {
    public:
        virtual void render(cringine::shaders::shader& shader) = 0;
    };
} // namespace cringine::renderer