#include "rendered_mesh.hpp"

#include <GL/glew.h>

using namespace cringine::renderer::types;

rendered_mesh::rendered_mesh(object_types::mesh_data::vertex_array vertices, object_types::mesh_data::index_array indices, object_types::mesh_data::texture_array textures)
    : m_mesh_data(std::make_shared<object_types::mesh_data>())
    , m_vao(0)
    , m_vbo(0)
    , m_ebo(0)
{
    m_mesh_data->vertices = std::move(vertices);
    m_mesh_data->indices = std::move(indices);
    m_mesh_data->textures = std::move(textures);

    init();
}

rendered_mesh::rendered_mesh(const rendered_mesh& mesh)
    : m_mesh_data(mesh.m_mesh_data)
    , m_vao(0)
    , m_vbo(mesh.m_vbo)
    , m_ebo(mesh.m_ebo)
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBindVertexArray(0);
}

rendered_mesh::rendered_mesh(rendered_mesh&& mesh) noexcept
    : m_mesh_data(std::move(mesh.m_mesh_data))
    , m_vao(mesh.m_vao)
    , m_vbo(mesh.m_vbo)
    , m_ebo(mesh.m_ebo)
{
    mesh.m_vao = 0;
}

rendered_mesh& rendered_mesh::operator=(const rendered_mesh& mesh)
{
    if (this == &mesh) {
        return *this;
    }
    m_mesh_data = mesh.m_mesh_data;
    m_vbo = mesh.m_vbo;
    m_ebo = mesh.m_ebo;

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBindVertexArray(0);

    return *this;
}

rendered_mesh& rendered_mesh::operator=(rendered_mesh&& mesh) noexcept
{
    std::swap(m_mesh_data, mesh.m_mesh_data);
    std::swap(m_vao, mesh.m_vao);
    std::swap(m_vbo, mesh.m_vbo);
    std::swap(m_ebo, mesh.m_ebo);

    return *this;
}

void rendered_mesh::init()
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, m_mesh_data->vertices.size() * sizeof(object_types::mesh_data::vertex_type), m_mesh_data->vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_mesh_data->indices.size() * sizeof(object_types::mesh_data::index_type), m_mesh_data->indices.data(), GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(object_types::mesh_data::vertex_type), (void*) nullptr);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(object_types::mesh_data::vertex_type), (void*) offsetof(object_types::mesh_data::vertex_type, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(object_types::mesh_data::vertex_type), (void*) offsetof(object_types::mesh_data::vertex_type, texture_coords));

    glBindVertexArray(0);
}
