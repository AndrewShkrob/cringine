#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cringine/graphics/shader_program_builder.hpp>
#include <cringine/graphics/camera.hpp>
#include <cringine/window/window.hpp>

#include <iostream>
#include <array>

GLuint generate_cube_vao();

template<std::size_t keys_size>
void move_camera(cringine::camera& camera, float delta_time, const std::array<bool, keys_size>& keys);

int main()
{
    cringine::window window(800, 600, "LearnOpenGL");
    cringine::camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, window.width(), window.height());

    cringine::shader_program shaderProgram =
        cringine::shader_program_builder().add_vertex_shader("shaders/shader.vertex").add_fragment_shader("shaders/shader.fragment").build();

    cringine::shader_program lightShader =
        cringine::shader_program_builder().add_vertex_shader("shaders/light.vertex").add_fragment_shader("shaders/light.fragment").build();

    GLuint cubeVAO = generate_cube_vao();
    GLuint lightVAO = generate_cube_vao();

    constexpr size_t keys_size = 1024;
    std::array<bool, keys_size> keys{false};
    window.set_key_callback([&keys](int key, int action) {
        if (key >= 0 && key < keys_size) {
            if (action == GLFW_PRESS) {
                keys.at(key) = true;
            } else if (action == GLFW_RELEASE) {
                keys.at(key) = false;
            }
        }
    });

    GLfloat lastX = window.width() / 2;
    GLfloat lastY = window.height() / 2;

    bool firstMouse = true;
    window.set_mouse_callback([&](double x_pos, double y_pos) {
        if (firstMouse) {
            lastX = x_pos;
            lastY = y_pos;
            firstMouse = false;
        }
        float x_offset = x_pos - lastX;
        float y_offset = lastY - y_pos;
        lastX = x_pos;
        lastY = y_pos;

        camera.process_mouse_move(x_offset, y_offset);
    });

    window.set_scroll_callback([&camera](double /*x_offset*/, double y_offset) {
        camera.process_mouse_scroll(static_cast<float>(y_offset));
    });

    GLfloat delta_time = 0.0f;
    GLfloat last_frame = 0.0f;

    GLint objectColorLoc = glGetUniformLocation(shaderProgram.program(), "objectColor");
    GLint lightColorLoc = glGetUniformLocation(shaderProgram.program(), "lightColor");

    GLint modelLoc = glGetUniformLocation(shaderProgram.program(), "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram.program(), "view");
    GLint projLoc = glGetUniformLocation(shaderProgram.program(), "projection");

    GLint modelLightLoc = glGetUniformLocation(lightShader.program(), "model");
    GLint viewLightLoc = glGetUniformLocation(lightShader.program(), "view");
    GLint projLightLoc = glGetUniformLocation(lightShader.program(), "projection");

    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

    window.launch([&]() {
        auto currentFrame = static_cast<float>(glfwGetTime());
        delta_time = currentFrame - last_frame;
        last_frame = currentFrame;
        move_camera(camera, delta_time, keys);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.use();

        glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
        glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);

        GLfloat angle = glm::radians((GLfloat) glfwGetTime() * 5.0f);
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(1.0f, 1.0f, 1.0f));
        glm::mat4 view = camera.view_matrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera.zoom()), static_cast<float>(window.width()) / static_cast<float>(window.height()), 0.1f, 100.0f);

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        lightShader.use();

        model = glm::translate(glm::mat4(1.0f), lightPos);
        model = glm::scale(model, glm::vec3(0.2f));

        glUniformMatrix4fv(modelLightLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLightLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLightLoc, 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glBindVertexArray(0);
    });

    return 0;
}

GLuint generate_cube_vao()
{
    // clang-format off
    const std::array<GLfloat, 36 * 3> vertices = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
    // clang-format on

    GLuint VBO{};
    GLuint VAO{};

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(decltype(vertices)::value_type), (GLvoid*) nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    return VAO;
}

template<std::size_t keys_size>
void move_camera(cringine::camera& camera, float delta_time, const std::array<bool, keys_size>& keys)
{
    if (keys[GLFW_KEY_W]) {
        camera.process_keyboard(cringine::camera::direction::FORWARD, delta_time);
    }
    if (keys[GLFW_KEY_S]) {
        camera.process_keyboard(cringine::camera::direction::BACKWARD, delta_time);
    }
    if (keys[GLFW_KEY_A]) {
        camera.process_keyboard(cringine::camera::direction::LEFT, delta_time);
    }
    if (keys[GLFW_KEY_D]) {
        camera.process_keyboard(cringine::camera::direction::RIGHT, delta_time);
    }
}