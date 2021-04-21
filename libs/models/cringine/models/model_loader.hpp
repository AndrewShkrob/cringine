#pragma once

#include <cringine/models/types/mesh_model.hpp>

#include <string>

namespace cringine::models
{
    types::mesh_model load_model(std::string model_path);
}
