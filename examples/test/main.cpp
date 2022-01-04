#include <cringine/core/engine.hpp>
#include <cringine/models/model_loader.hpp>
#include <cringine/renderer/types/rendered_mesh.hpp>
#include <cringine/renderer/mesh_renderer.hpp>
#include <cringine/renderer/renderer_utils.hpp>
#include <cringine/shaders/shader_program_builder.hpp>
#include <cringine/shaders/shader_data_binder.hpp>
#include <cringine/types/camera.hpp>
#include <cringine/window/window_builder.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace cringine::event_system::input::keys;

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

class a : cringine::event_system::events::window_close_event,
          cringine::event_system::events::cursor_position_event
{
public:
    explicit a() = default;

    void init()
    {
        cringine::window::window_builder window_builder;
        window_builder
            .set_size({800, 600})
            .set_title("Hello")
            .set_resizable(false)
            .set_use_cursor(false);
        m_engine = std::make_unique<cringine::engine>(window_builder.build());
        m_camera = cringine::types::camera(glm::vec3(0.0f, 0.0f, 3.0f));

        m_engine->event_system()->register_window_close_callback(this);
        m_engine->event_system()->register_cursor_position_callback(this);

        m_model = std::make_unique<model>(std::string(RESOURCES) + "models/backpack/backpack.obj");
    }

    void launch()
    {
        cringine::shaders::shader shader = cringine::shaders::shader_program_builder()
                                               .add_fragment_shader(std::string(RESOURCES) + "shaders/3_3_models/model.fragment")
                                               .add_vertex_shader(std::string(RESOURCES) + "shaders/3_3_models/model.vertex")
                                               .build();

        cringine::renderer::enable_depth_buffer();
        cringine::renderer::set_clear_color(0.05f, 0.05f, 0.05f, 1.0f);
        cringine::shaders::shader_data_binder shader_binder(shader);
        std::ostringstream title;
        m_engine->start([&, this]() {
            cringine::renderer::clear();

            shader.use();
            glm::mat4 projection = glm::perspective(m_camera.zoom(), (float) 800 / (float) 600, 0.1f, 100.0f);
            glm::mat4 view = m_camera.view_matrix();
            shader_binder.set_uniform_matrix4fv("projection", 1, false, glm::value_ptr(projection));
            shader_binder.set_uniform_matrix4fv("view", 1, false, glm::value_ptr(view));

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
            model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

            shader_binder.set_uniform_matrix4fv("model", 1, false, glm::value_ptr(model));

            m_model->render(shader);

            keyboard_input();

            title.str("");
            title.clear();
            title << "FPS: " << std::setfill('0') << std::setw(5) << m_engine->fps() << " Delta time: " << m_engine->delta_time();
            m_engine->window()->set_title(title.str());
        });
    }

    void window_close() override
    {
        std::cout << "CLOSE" << std::endl;
    }

    void keyboard_input()
    {
        if (m_engine->input_manager().is_key_released(KEY_ESCAPE)) {
            m_engine->stop();
        }

        if (m_engine->input_manager().is_key_down(KEY_W)) {
            m_camera.process_keyboard(cringine::types::camera::direction::FORWARD, m_engine->delta_time());
        }
        if (m_engine->input_manager().is_key_down(KEY_S)) {
            m_camera.process_keyboard(cringine::types::camera::direction::BACKWARD, m_engine->delta_time());
        }
        if (m_engine->input_manager().is_key_down(KEY_A)) {
            m_camera.process_keyboard(cringine::types::camera::direction::LEFT, m_engine->delta_time());
        }
        if (m_engine->input_manager().is_key_down(KEY_D)) {
            m_camera.process_keyboard(cringine::types::camera::direction::RIGHT, m_engine->delta_time());
        }
    }

    void cursor_position(double x, double y) override
    {
        if (m_first_move) {
            m_last_x = x;
            m_last_y = y;
            m_first_move = false;
        }

        double x_offset = x - m_last_x;
        double y_offset = m_last_y - y;

        m_last_x = x;
        m_last_y = y;

        m_camera.process_mouse_move(static_cast<float>(x_offset), static_cast<float>(y_offset));
    }

private:
    std::unique_ptr<cringine::engine> m_engine;
    cringine::types::camera m_camera;
    std::unique_ptr<model> m_model;

    double m_last_x = 0;
    double m_last_y = 0;
    bool m_first_move = true;
};

int main()
{
    a a;
    a.init();
    a.launch();
    return 0;
}
