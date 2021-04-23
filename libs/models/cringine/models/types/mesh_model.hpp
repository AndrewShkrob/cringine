#pragma once

#include <cringine/types/object/mesh_data.hpp>

#include <vector>

namespace cringine::models::types
{
    struct mesh_model
    {
        std::vector<cringine::types::object::mesh_data_sptr> meshes;
        std::vector<cringine::types::object::mesh_data::texture_type> loaded_textures;
    };
} // namespace cringine::models::types
