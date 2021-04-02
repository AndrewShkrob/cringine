#pragma once

#include <GL/glew.h>

namespace cringine {
    class shader_program {
    public:
        explicit shader_program(GLuint program);

        void use();

        GLuint program() const;

    private:
        GLuint m_program;
    };
}// namespace cringine