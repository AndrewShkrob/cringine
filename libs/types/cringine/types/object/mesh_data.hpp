#pragma once

#include <cringine/types/object/vertex.hpp>
#include <cringine/types/object/texture.hpp>

#include <memory>
#include <vector>

namespace cringine::types::object
{
    struct mesh_data
    {
        using vertex_array = std::vector<vertex>;
        using vertex_type = vertex_array::value_type;

        using index_array = std::vector<unsigned int>;
        using index_type = index_array::value_type;

        using texture_array = std::vector<texture>;
        using texture_type = texture_array::value_type;

        vertex_array vertices;
        index_array indices;
        texture_array textures;
    };

    using mesh_data_sptr = std::shared_ptr<mesh_data>;
} // namespace cringine::types::object
