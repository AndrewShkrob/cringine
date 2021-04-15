#pragma once

#include <cringine/types/object/vertex.hpp>
#include <cringine/types/object/texture.hpp>

#include <memory>
#include <vector>

namespace cringine::types::object
{
    class mesh
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

    public:
        mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures);
        mesh(const mesh& mesh);
        mesh(mesh&& mesh) noexcept;

    private:
        void init();

        std::shared_ptr<mesh_data> m_mesh_data;
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_ebo;
    };
} // namespace cringine::types::object
