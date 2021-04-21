#pragma once

#include <string>

namespace cringine::types::object
{
    struct texture
    {
        enum class texture_type
        {
            DIFFUSE,
            SPECULAR
        };

        unsigned int id;
        texture_type type;
        std::string path;
    };
} // namespace cringine::types::object
