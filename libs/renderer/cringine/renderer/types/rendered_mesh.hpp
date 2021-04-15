#pragma once

#include <cringine/types/object/mesh_data.hpp>

namespace object_types = cringine::types::object;

namespace cringine::renderer::types
{
    class rendered_mesh
    {
    public:
        rendered_mesh(object_types::mesh_data::vertex_array vertices, object_types::mesh_data::index_array indices, object_types::mesh_data::texture_array textures);
        rendered_mesh(const rendered_mesh& mesh);
        rendered_mesh(rendered_mesh&& mesh) noexcept;

        ~rendered_mesh() = default;

        rendered_mesh& operator=(const rendered_mesh& mesh);
        rendered_mesh& operator=(rendered_mesh&&) noexcept;

    private:
        void init();

        object_types::mesh_data_sptr m_mesh_data;
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_ebo;
    };
} // namespace cringine::renderer::types
