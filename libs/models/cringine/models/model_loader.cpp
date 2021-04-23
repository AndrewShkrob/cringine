#include "model_loader.hpp"

#include <cringine/models/internal/assimp_model_loader.hpp>

using namespace cringine::models;

types::mesh_model cringine::models::load_model(std::string model_path)
{
    return internal::assimp_model_loader().set_model_path(std::move(model_path)).import();
}
