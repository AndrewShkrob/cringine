#include "assimp_model_loader.hpp"

#include <cringine/utils/load_from_file.hpp>

#include <iostream>

using namespace cringine::models::internal;
using namespace cringine::models;

namespace object_data = cringine::types::object;

assimp_model_loader& assimp_model_loader::set_model_path(std::string model_file_path)
{
    m_model_file_path = std::move(model_file_path);
    m_model_directory_path = m_model_file_path.substr(0, m_model_file_path.find_last_of('/'));
    return *this;
}

types::mesh_model assimp_model_loader::import()
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(m_model_file_path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mRootNode == nullptr) {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return {};
    }

    process_node(scene->mRootNode, scene);

    return m_result_model;
}

void assimp_model_loader::process_node(aiNode* node, const aiScene* scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        m_result_model.meshes.push_back(process_mesh(mesh, scene));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        process_node(node->mChildren[i], scene);
    }
}

object_data::mesh_data_sptr assimp_model_loader::process_mesh(aiMesh* mesh, const aiScene* scene)
{
    object_data::mesh_data_sptr mesh_ptr = std::make_shared<object_data::mesh_data>();

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        object_data::mesh_data::vertex_type vertex;
        vertex.position = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
        vertex.normal = {mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};
        if (mesh->mTextureCoords[0] != nullptr) {
            vertex.texture_coords = {mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y};
        }
        mesh_ptr->vertices.push_back(vertex);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            mesh_ptr->indices.push_back(face.mIndices[j]);
        }
    }

//    if (mesh->mMaterialIndex >= 0) {
//        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
//        object_data::mesh_data::texture_array diffuse_maps = load_material_textures(material, aiTextureType_DIFFUSE, object_data::texture::texture_type::DIFFUSE);
//        std::move(std::begin(diffuse_maps), std::end(diffuse_maps), std::back_inserter(mesh_ptr->textures));
//        object_data::mesh_data::texture_array specular_maps = load_material_textures(material, aiTextureType_SPECULAR, object_data::texture::texture_type::SPECULAR);
//        std::move(std::begin(specular_maps), std::end(specular_maps), std::back_inserter(mesh_ptr->textures));
//    }

    return mesh_ptr;
}

object_data::mesh_data::texture_array assimp_model_loader::load_material_textures(
    aiMaterial* mat, aiTextureType type, object_data::texture::texture_type texture_type)
{
    object_data::mesh_data::texture_array textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        object_data::mesh_data::texture_type texture;
        texture.id = cringine::utils::texture_from_file(m_model_directory_path + "/" + str.C_Str());
        texture.type = texture_type;
        textures.push_back(texture);
    }
    return std::move(textures);
}