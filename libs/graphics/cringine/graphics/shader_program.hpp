#pragma once

#include <GL/glew.h>

#include <string>

namespace cringine
{
    class shader_program
    {
    public:
        explicit shader_program(GLuint program);

        void use() const;

        [[nodiscard]] GLuint program() const;

        void set_uniform_1i(const std::string& uniform_name, GLint value) const;

        void set_uniform_1f(const std::string& uniform_name, GLfloat value) const;

        void set_uniform_3f(const std::string& uniform_name, GLfloat v0, GLfloat v1, GLfloat v2) const;

        void set_uniform_matrix4fv(const std::string& uniform_name, GLsizei count, GLboolean transpose, const GLfloat* value) const;

    private:
        [[nodiscard]] GLint get_uniform_location(const std::string& uniform_name) const;

        GLuint m_program;
    };
} // namespace cringine
