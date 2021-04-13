#include <cringine/window/window.hpp>

#include <iostream>

class a : public cringine::event_system::events::window_close_event
{
public:
    void window_close() override
    {
        std::cout << "CLOSE" << std::endl;
    }
};

int main()
{
    cringine::window window(640, 480, "Hello");
    window.event_system()->register_window_close_callback(new a());
    window.launch([&window]() {
        std::cout << window.width() << "x" << window.height() << std::endl;
    });
}