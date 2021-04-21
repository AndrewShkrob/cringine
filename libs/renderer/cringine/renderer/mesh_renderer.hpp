#pragma once

#include <cringine/renderer/types/rendered_mesh.hpp>
#include <cringine/renderer/renderer.hpp>

#include <array>

namespace cringine::renderer
{
    class mesh_renderer : public renderer
    {
    public:
        explicit mesh_renderer(types::rendered_mesh& rendered_mesh);

        static constexpr inline std::array<char, 9> UNIFORM_MATERIAL_STRUCT_NAME{"material"};
        static constexpr inline std::array<char, 17> UNIFORM_SPECULAR_TEXTURE_NAME{"specular_texture"};
        static constexpr inline std::array<char, 16> UNIFORM_DIFFUSE_TEXTURE_NAME{"diffuse_texture"};

        void render(cringine::shaders::shader& shader) override;

    private:
        types::rendered_mesh& m_rendered_mesh;
    };
} // namespace cringine::renderer
