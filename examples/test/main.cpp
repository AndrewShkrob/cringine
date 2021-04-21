#include <cringine/core/engine.hpp>
#include <cringine/models/model_loader.hpp>
#include <cringine/renderer/types/rendered_mesh.hpp>
#include <cringine/renderer/mesh_renderer.hpp>
#include <cringine/shaders/shader_program_builder.hpp>
#include <cringine/shaders/shader_data_binder.hpp>
#include <cringine/types/camera.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <cmath>

class model
{
public:
    explicit model(std::string model_path)
        : m_model(cringine::models::load_model(std::move(model_path)))
    {
        m_mesh_renderer.reserve(m_model.meshes.size());
        m_rendered_mesh.reserve(m_model.meshes.size());
        for (cringine::types::object::mesh_data_sptr mesh : m_model.meshes) {
            m_rendered_mesh.emplace_back(mesh);
            m_mesh_renderer.emplace_back(m_rendered_mesh.back());
        }
    }

    void render(cringine::shaders::shader& shader)
    {
        for (auto& renderer : m_mesh_renderer) {
            renderer.render(shader);
        }
    }

private:
    std::vector<cringine::renderer::mesh_renderer> m_mesh_renderer;
    std::vector<cringine::renderer::types::rendered_mesh> m_rendered_mesh;
    cringine::models::types::mesh_model m_model;
};

class a : cringine::event_system::events::window_close_event
{
public:
    void launch()
    {
        cringine::engine engine({800, 600, "Hello"});

        auto m = model(std::string(RESOURCES) + "models/backpack/backpack.obj");
        cringine::shaders::shader s = cringine::shaders::shader_program_builder()
                                          .add_fragment_shader(std::string(RESOURCES) + "shaders/3_3_models/model.fragment")
                                          .add_vertex_shader(std::string(RESOURCES) + "shaders/3_3_models/model.vertex")
                                          .build();
        cringine::shaders::shader_data_binder binder(s);

        cringine::types::camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

        engine.event_system()->register_window_close_callback(this);
        glEnable(GL_DEPTH_TEST);


        engine.start([&]() {
            glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            s.use();
            glm::mat4 projection = glm::perspective(camera.zoom(), (float) 800 / (float) 600, 0.1f, 100.0f);
            glm::mat4 view = camera.view_matrix();
            binder.set_uniform_matrix4fv("projection", 1, false, glm::value_ptr(projection));
            binder.set_uniform_matrix4fv("view", 1, false, glm::value_ptr(view));

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
            model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

            binder.set_uniform_matrix4fv("model", 1, false, glm::value_ptr(model));

            m.render(s);

            if (engine.input_manager().is_key_pressed(cringine::event_system::input::keys::KEY_A)) {
                std::cout << "FPS: " << engine.fps() << " Delta time: " << engine.delta_time() << std::endl;
            }
        });
    }

    void window_close() override
    {
        std::cout << "CLOSE" << std::endl;
    }
};

int main()
{
    a().launch();
    return 0;
}
