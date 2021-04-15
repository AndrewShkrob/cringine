#pragma once

#include <cringine/renderer/types/rendered_mesh.hpp>
#include <cringine/renderer/renderer.hpp>

namespace cringine::renderer
{
    class mesh_renderer : public renderer
    {
    public:
        void render(cringine::shaders::shader& shader) override;

    private:
        types::rendered_mesh m_rendered_mesh;
    };
} // namespace cringine::renderer
