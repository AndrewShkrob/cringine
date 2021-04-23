#pragma once

#include <cringine/types/object/mesh_data.hpp>

namespace cringine::renderer
{
    class mesh_renderer;
}

namespace cringine::renderer::types
{
    class rendered_mesh
    {
        friend class cringine::renderer::mesh_renderer;

    public:
        explicit rendered_mesh(cringine::types::object::mesh_data_sptr mesh_data);
        [[maybe_unused]] rendered_mesh(const rendered_mesh& mesh);
        [[maybe_unused]] rendered_mesh(rendered_mesh&& mesh) noexcept;

        ~rendered_mesh() = default;

        rendered_mesh& operator=(const rendered_mesh& mesh);
        rendered_mesh& operator=(rendered_mesh&&) noexcept;

    private:
        void init();

        cringine::types::object::mesh_data_sptr m_mesh_data;
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_ebo;
    };
} // namespace cringine::renderer::types
