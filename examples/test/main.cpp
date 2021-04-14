#include <cringine/core/engine.hpp>

#include <iostream>

class a : cringine::event_system::events::window_close_event
{
public:
    void launch()
    {
        cringine::engine engine({800, 600, "Hello"});
        engine.event_system()->register_window_close_callback(this);
        engine.start([&engine]() {
            auto r = (sin(engine.time()) + 1) / 2;
            auto g = (cos(engine.time()) + 1) / 2;
            auto b = r;
            glClearColor(1.0f * r, 1.0f * g, 1.0f * b, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            std::cout << "FPS: " << engine.fps() << " Delta time: " << engine.delta_time() << std::endl;
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
