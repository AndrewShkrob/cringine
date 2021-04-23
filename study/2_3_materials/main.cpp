#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cringine/shaders/shader_program_builder.hpp>
#include <cringine/shaders/shader_data_binder.hpp>
#include <cringine/types/camera.hpp>
#include <cringine/core/engine.hpp>

#include <iostream>
#include <array>

GLuint generate_cube_vao();

template<std::size_t keys_size>
void move_camera(cringine::types::camera& camera, float delta_time, const std::array<bool, keys_size>& keys);

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

    cringine::shaders::shader lightingShader =
        cringine::shaders::shader_program_builder()
            .add_vertex_shader("shaders/lighting.vertex")
            .add_fragment_shader("shaders/lighting.fragment")
            .build();

    cringine::shaders::shader lampShader =
        cringine::shaders::shader_program_builder()
            .add_vertex_shader("shaders/lamp.vertex")
            .add_fragment_shader("shaders/lamp.fragment")
            .build();

    GLuint cubeVAO = generate_cube_vao();
    GLuint lampVAO = generate_cube_vao();
    // TODO
    //    constexpr size_t keys_size = 1024;
    //    std::array<bool, keys_size> keys{false};
    //    window.set_key_callback([&keys](int key, int action) {
    //        if (key >= 0 && key < keys_size) {
    //            if (action == GLFW_PRESS) {
    //                keys.at(key) = true;
    //            } else if (action == GLFW_RELEASE) {
    //                keys.at(key) = false;
    //            }
    //        }
    //    });
    //
    //    GLfloat lastX = window.width() / 2;
    //    GLfloat lastY = window.height() / 2;
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

    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

    engine.start([&]() {
        auto currentFrame = static_cast<float>(glfwGetTime());
        delta_time = currentFrame - last_frame;
        last_frame = currentFrame;
        //        move_camera(camera, delta_time, keys);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::vec3 lightColor;
        lightColor.x = sin(glfwGetTime() * 2.0f);
        lightColor.y = sin(glfwGetTime() * 0.7f);
        lightColor.z = sin(glfwGetTime() * 1.3f);

        glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);

        lightingShader.use();
        cringine::shaders::shader_data_binder lighting_binder(lightingShader);
        lighting_binder.set_uniform_3f("objectColor", 1.0f, 0.5f, 0.31f);
        lighting_binder.set_uniform_3f("lightColor", 1.0f, 1.0f, 1.0f);
        lighting_binder.set_uniform_3f("lightPos", lightPos.x, lightPos.y, lightPos.z);
        lighting_binder.set_uniform_3f("viewPos", camera.position().x, camera.position().y, camera.position().z);
        lighting_binder.set_uniform_3f("material.ambient", 1.0f, 0.5f, 0.31f);
        lighting_binder.set_uniform_3f("material.diffuse", 1.0f, 0.5f, 0.31f);
        lighting_binder.set_uniform_3f("material.specular", 0.5f, 0.5f, 0.5f);
        lighting_binder.set_uniform_1f("material.shininess", 32.0f);
        lighting_binder.set_uniform_3f("light.ambient", ambientColor.r, ambientColor.g, ambientColor.b);
        lighting_binder.set_uniform_3f("light.diffuse", diffuseColor.r, diffuseColor.g, diffuseColor.b);
        lighting_binder.set_uniform_3f("light.specular", 1.0f, 1.0f, 1.0f);

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = camera.view_matrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera.zoom()), static_cast<float>(engine.window().width()) / static_cast<float>(engine.window().height()), 0.1f, 100.0f);

        lighting_binder.set_uniform_matrix4fv("model", 1, GL_FALSE, glm::value_ptr(model));
        lighting_binder.set_uniform_matrix4fv("view", 1, GL_FALSE, glm::value_ptr(view));
        lighting_binder.set_uniform_matrix4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        lampShader.use();
        cringine::shaders::shader_data_binder lamp_binder(lampShader);

        model = glm::translate(glm::mat4(1.0f), lightPos);
        model = glm::scale(model, glm::vec3(0.2f));

        lamp_binder.set_uniform_matrix4fv("model", 1, GL_FALSE, glm::value_ptr(model));
        lamp_binder.set_uniform_matrix4fv("view", 1, GL_FALSE, glm::value_ptr(view));
        lamp_binder.set_uniform_matrix4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(lampVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glBindVertexArray(0);
    });

    return 0;
}

GLuint generate_cube_vao()
{
    const int vertices_count = 36;
    const int data_for_vertex_count = 3 + 3;
    // clang-format off
    const std::array<GLfloat, vertices_count * data_for_vertex_count> vertices = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    // clang-format on

    GLuint VBO{};
    GLuint VAO{};

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    GLsizei value_type_size = sizeof(decltype(vertices)::value_type);
    GLsizei step_size = data_for_vertex_count * value_type_size;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*) (3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    return VAO;
}

template<std::size_t keys_size>
void move_camera(cringine::types::camera& camera, float delta_time, const std::array<bool, keys_size>& keys)
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
