#pragma once

#include <cringine/types/object/mesh_data.hpp>

#include <vector>

namespace cringine::models::types
{
    struct mesh_model
    {
        std::vector<cringine::types::object::mesh_data_sptr> meshes;
    };
} // namespace cringine::models::types
