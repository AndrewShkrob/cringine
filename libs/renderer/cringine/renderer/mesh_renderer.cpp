#include "mesh_renderer.hpp"

#include <cringine/shaders/shader_data_binder.hpp>

#include <GL/glew.h>

#include <sstream>

using namespace cringine::renderer;

namespace object_types = cringine::types::object;

mesh_renderer::mesh_renderer(types::rendered_mesh& rendered_mesh)
    : m_rendered_mesh(rendered_mesh)
{
}

void mesh_renderer::render(cringine::shaders::shader& shader)
{
//    shader.use();
    shaders::shader_data_binder binder(shader);
    unsigned int diffuse_texture_idx = 1;
    unsigned int specular_texture_idx = 1;

    std::ostringstream uniform_name;
    for (size_t idx = 0; idx < m_rendered_mesh.m_mesh_data->textures.size(); ++idx) {
        const auto& texture = m_rendered_mesh.m_mesh_data->textures[idx];
        glActiveTexture(GL_TEXTURE0 + idx);
        uniform_name << UNIFORM_MATERIAL_STRUCT_NAME.data() << ".";
        if (texture.type == object_types::texture::texture_type::DIFFUSE) {
            uniform_name << UNIFORM_DIFFUSE_TEXTURE_NAME.data() << diffuse_texture_idx;
            ++diffuse_texture_idx;
        } else if (texture.type == object_types::texture::texture_type::SPECULAR) {
            uniform_name << UNIFORM_SPECULAR_TEXTURE_NAME.data() << specular_texture_idx;
            ++specular_texture_idx;
        }
        binder.set_uniform_1ui(uniform_name.str(), idx);
        glBindTexture(GL_TEXTURE_2D, texture.id);
        uniform_name.clear();
    }

//    shader.disuse();
}
