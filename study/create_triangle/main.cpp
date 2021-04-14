#include <GL/glew.h>

#include <cringine/core/engine.hpp>

#include <iostream>

const char* vertex_shader_source = R"(
#version 330 core

layout (location = 0) in vec3 position;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
}
)";

const char* fragment_shader_source = R"(
#version 330 core

out vec4 color;

void main()
{
	color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

GLuint compile_shader(const char* shader_source, GLuint shader_type)
{
    GLuint shader;
    shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::string shader_type_str = shader_type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT";
        std::cout << "ERROR::SHADER::" << shader_type_str << "::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    return shader;
}

GLuint create_shader_program(const char* vertex_shader, const char* fragment_shader)
{
    GLuint vertexShader = compile_shader(vertex_shader, GL_VERTEX_SHADER);
    GLuint fragmentShader = compile_shader(fragment_shader, GL_FRAGMENT_SHADER);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        GLchar infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::LINK_FAILED\n"
                  << infoLog << std::endl;
    }

    return shaderProgram;
}

GLuint generate_triangle_vao()
{
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, -0.5f, 0.0f, 0.0f};

    GLuint VBO;
    GLuint VAO;

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    return VAO;
}

GLuint generate_rect_vao()
{
    GLfloat vertices[] = {
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f};
    GLuint indices[] = {
        0, 1, 3, 1, 2, 3};

    GLuint VBO;
    GLuint VAO;
    GLuint EBO;

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    return VAO;
}

int main()
{
    cringine::engine engine({800, 600, "LearnOpenGL"});

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glViewport(0, 0, engine.window().width(), engine.window().height());

    GLuint shaderProgram = create_shader_program(vertex_shader_source, fragment_shader_source);

    GLuint triangleVAO = generate_triangle_vao();
    GLuint rectVAO = generate_rect_vao();

    engine.start([shaderProgram, triangleVAO, rectVAO]() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(triangleVAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(rectVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    });

    return 0;
}
