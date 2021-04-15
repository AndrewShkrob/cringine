#include "mesh.hpp"

#include <GL/glew.h>

#include <cstddef>

using namespace cringine::types::object;

mesh::mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures)
    : m_mesh_data(std::make_shared<mesh_data>())
    , m_vao(0)
    , m_vbo(0)
    , m_ebo(0)
{
    m_mesh_data->vertices = std::move(vertices);
    m_mesh_data->indices = std::move(indices);
    m_mesh_data->textures = std::move(textures);

    init();
}

mesh::mesh(const mesh& mesh)
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

mesh::mesh(mesh&& mesh_) noexcept
    : mesh(mesh_)
{
}

void mesh::init()
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, m_mesh_data->vertices.size() * sizeof(mesh_data::vertex_type), m_mesh_data->vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_mesh_data->indices.size() * sizeof(mesh_data::index_type), m_mesh_data->indices.data(), GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(mesh_data::vertex_type), (void*) nullptr);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(mesh_data::vertex_type), (void*) offsetof(mesh_data::vertex_type, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(mesh_data::vertex_type), (void*) offsetof(mesh_data::vertex_type, texture_coords));

    glBindVertexArray(0);
}
