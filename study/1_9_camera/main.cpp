#include <GL/glew.h>

#include <SOIL2.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cringine/shaders/shader_program_builder.hpp>
#include <cringine/types/camera.hpp>
#include <cringine/core/engine.hpp>

#include <cmath>
#include <iostream>
#include <array>

GLuint load_texture(const std::string& img_path)
{
    int width;
    int height;
    unsigned char* image = SOIL_load_image(img_path.c_str(), &width, &height, nullptr, SOIL_LOAD_RGB);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    return texture;
}

GLuint generate_cube_vao()
{
    // clang-format off
    const GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    // clang-format on

    GLuint VBO{};
    GLuint VAO{};

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    return VAO;
}

void move_camera(cringine::types::camera& camera, float delta_time, const std::array<bool, 1024>& keys)
{
    if (keys[GLFW_KEY_W]) {
        camera.process_keyboard(cringine::types::camera::direction::FORWARD, delta_time);
    }
    if (keys[GLFW_KEY_S]) {
        camera.process_keyboard(cringine::types::camera::direction::BACKWARD, delta_time);
    }
    if (keys[GLFW_KEY_A]) {
        camera.process_keyboard(cringine::types::camera::direction::LEFT, delta_time);
    }
    if (keys[GLFW_KEY_D]) {
        camera.process_keyboard(cringine::types::camera::direction::RIGHT, delta_time);
    }
}

int main()
{
    cringine::engine engine({800, 600, "LearnOpenGL"});
    cringine::types::camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, engine.window().width(), engine.window().height());

    cringine::shaders::shader shaderProgram =
        cringine::shaders::shader_program_builder()
            .add_vertex_shader("shaders/shader.vertex")
            .add_fragment_shader("shaders/shader.fragment")
            .build();

    GLuint cubeVAO = generate_cube_vao();
    GLuint texture1 = load_texture("textures/container.jpg");
    GLuint texture2 = load_texture("textures/awesomeface.png");

    std::array<glm::vec3, 10> cubePositions = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)};

    std::array<bool, 1024> keys{false};
    // TODO
    //    window.set_key_callback([&keys](int key, int action) {
    //        if (key >= 0 && key < 1024) {
    //            if (action == GLFW_PRESS) {
    //                keys[key] = true;
    //            } else if (action == GLFW_RELEASE) {
    //                keys[key] = false;
    //            }
    //        }
    //    });
    //
    //    GLfloat lastX = engine.window().width() / 2;
    //    GLfloat lastY = engine.window().height() / 2;
    //
    //    bool firstMouse = true;
    //    window.set_mouse_callback([&](double x_pos, double y_pos) {
    //        if (firstMouse) {
    //            lastX = x_pos;
    //            lastY = y_pos;
    //            firstMouse = false;
    //        }
    //        float x_offset = x_pos - lastX;
    //        float y_offset = lastY - y_pos;
    //        lastX = x_pos;
    //        lastY = y_pos;
    //
    //        camera.process_mouse_move(x_offset, y_offset);
    //    });
    //
    //    window.set_scroll_callback([&camera](double /*x_offset*/, double y_offset) {
    //        camera.process_mouse_scroll(static_cast<float>(y_offset));
    //    });

    GLfloat delta_time = 0.0f;
    GLfloat last_frame = 0.0f;

    engine.start([&]() {
        auto currentFrame = static_cast<float>(glfwGetTime());
        delta_time = currentFrame - last_frame;
        last_frame = currentFrame;
        move_camera(camera, delta_time, keys);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(shaderProgram.id(), "ourTexture1"), 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glUniform1i(glGetUniformLocation(shaderProgram.id(), "ourTexture2"), 1);
        GLfloat mix_val = static_cast<GLfloat>(sin(glfwGetTime())) * 0.5f + 0.5f;
        glUniform1f(glGetUniformLocation(shaderProgram.id(), "mixValue"), mix_val);

        glm::mat4 view = camera.view_matrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera.zoom()), static_cast<float>(engine.window().width()) / static_cast<float>(engine.window().height()), 0.1f, 100.0f);

        GLint modelLoc = glGetUniformLocation(shaderProgram.id(), "model");
        GLint viewLoc = glGetUniformLocation(shaderProgram.id(), "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        GLint projLoc = glGetUniformLocation(shaderProgram.id(), "projection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        shaderProgram.use();

        glBindVertexArray(cubeVAO);
        for (GLuint i = 0; i < 10; i++) {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), cubePositions[i]);
            GLfloat angle = glm::radians((GLfloat) glfwGetTime() * 5.0f * (i + 1));
            const float coef = static_cast<float>(i + 1) / 10.f;
            model = glm::rotate(model, angle, glm::vec3(1.0f * coef, 1.0f * coef, 1.0f * coef));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glBindVertexArray(0);
    });

    return 0;
}
