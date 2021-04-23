#pragma once

#include <cringine/types/object/mesh_data.hpp>
#include <cringine/models/types/mesh_model.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>

namespace cringine::models::internal
{
    class assimp_model_loader
    {
    public:
        assimp_model_loader& set_model_path(std::string model_file_path);

        types::mesh_model import();

    private:
        void process_node(aiNode* node, const aiScene* scene);
        cringine::types::object::mesh_data_sptr process_mesh(aiMesh* mesh, const aiScene* scene);
        cringine::types::object::mesh_data::texture_array load_material_textures(
            aiMaterial* mat, aiTextureType type, cringine::types::object::texture::texture_type texture_type);

        std::string m_model_file_path;
        std::string m_model_directory_path;

        types::mesh_model m_result_model;
    };
} // namespace cringine::models::internal
