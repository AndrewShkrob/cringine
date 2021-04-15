#pragma once

namespace cringine::event_system::input::keys
{
    using key_t = unsigned short;

    [[maybe_unused]] constexpr key_t KEY_AMOUNT = 512;
    [[maybe_unused]] constexpr key_t BUTTON_AMOUNT = 8;

    [[maybe_unused]] const extern key_t KEY_UNKNOWN;
    [[maybe_unused]] const extern key_t KEY_SPACE;
    [[maybe_unused]] const extern key_t KEY_APOSTROPHE;
    [[maybe_unused]] const extern key_t KEY_COMMA;
    [[maybe_unused]] const extern key_t KEY_MINUS;
    [[maybe_unused]] const extern key_t KEY_PERIOD;
    [[maybe_unused]] const extern key_t KEY_SLASH;
    [[maybe_unused]] const extern key_t KEY_0;
    [[maybe_unused]] const extern key_t KEY_1;
    [[maybe_unused]] const extern key_t KEY_2;
    [[maybe_unused]] const extern key_t KEY_3;
    [[maybe_unused]] const extern key_t KEY_4;
    [[maybe_unused]] const extern key_t KEY_5;
    [[maybe_unused]] const extern key_t KEY_6;
    [[maybe_unused]] const extern key_t KEY_7;
    [[maybe_unused]] const extern key_t KEY_8;
    [[maybe_unused]] const extern key_t KEY_9;
    [[maybe_unused]] const extern key_t KEY_SEMICOLON; /* ; */
    [[maybe_unused]] const extern key_t KEY_EQUAL;     /* = */
    [[maybe_unused]] const extern key_t KEY_A;
    [[maybe_unused]] const extern key_t KEY_B;
    [[maybe_unused]] const extern key_t KEY_C;
    [[maybe_unused]] const extern key_t KEY_D;
    [[maybe_unused]] const extern key_t KEY_E;
    [[maybe_unused]] const extern key_t KEY_F;
    [[maybe_unused]] const extern key_t KEY_G;
    [[maybe_unused]] const extern key_t KEY_H;
    [[maybe_unused]] const extern key_t KEY_I;
    [[maybe_unused]] const extern key_t KEY_J;
    [[maybe_unused]] const extern key_t KEY_K;
    [[maybe_unused]] const extern key_t KEY_L;
    [[maybe_unused]] const extern key_t KEY_M;
    [[maybe_unused]] const extern key_t KEY_N;
    [[maybe_unused]] const extern key_t KEY_O;
    [[maybe_unused]] const extern key_t KEY_P;
    [[maybe_unused]] const extern key_t KEY_Q;
    [[maybe_unused]] const extern key_t KEY_R;
    [[maybe_unused]] const extern key_t KEY_S;
    [[maybe_unused]] const extern key_t KEY_T;
    [[maybe_unused]] const extern key_t KEY_U;
    [[maybe_unused]] const extern key_t KEY_V;
    [[maybe_unused]] const extern key_t KEY_W;
    [[maybe_unused]] const extern key_t KEY_X;
    [[maybe_unused]] const extern key_t KEY_Y;
    [[maybe_unused]] const extern key_t KEY_Z;
    [[maybe_unused]] const extern key_t KEY_LEFT_BRACKET;  // [
    [[maybe_unused]] const extern key_t KEY_BACKSLASH;     /* \ */
    [[maybe_unused]] const extern key_t KEY_RIGHT_BRACKET; // ]
    [[maybe_unused]] const extern key_t KEY_GRAVE_ACCENT;  // '
    [[maybe_unused]] const extern key_t KEY_WORLD_1;       // non-US #1
    [[maybe_unused]] const extern key_t KEY_WORLD_2;       // non-US #2
    [[maybe_unused]] const extern key_t KEY_ESCAPE;
    [[maybe_unused]] const extern key_t KEY_ENTER;
    [[maybe_unused]] const extern key_t KEY_TAB;
    [[maybe_unused]] const extern key_t KEY_BACKSPACE;
    [[maybe_unused]] const extern key_t KEY_INSERT;
    [[maybe_unused]] const extern key_t KEY_DELETE;
    [[maybe_unused]] const extern key_t KEY_RIGHT;
    [[maybe_unused]] const extern key_t KEY_LEFT;
    [[maybe_unused]] const extern key_t KEY_DOWN;
    [[maybe_unused]] const extern key_t KEY_UP;
    [[maybe_unused]] const extern key_t KEY_PAGE_UP;
    [[maybe_unused]] const extern key_t KEY_PAGE_DOWN;
    [[maybe_unused]] const extern key_t KEY_HOME;
    [[maybe_unused]] const extern key_t KEY_END;
    [[maybe_unused]] const extern key_t KEY_CAPS_LOCK;
    [[maybe_unused]] const extern key_t KEY_SCROLL_LOCK;
    [[maybe_unused]] const extern key_t KEY_NUM_LOCK;
    [[maybe_unused]] const extern key_t KEY_PRINT_SCREEN;
    [[maybe_unused]] const extern key_t KEY_PAUSE;
    [[maybe_unused]] const extern key_t KEY_F1;
    [[maybe_unused]] const extern key_t KEY_F2;
    [[maybe_unused]] const extern key_t KEY_F3;
    [[maybe_unused]] const extern key_t KEY_F4;
    [[maybe_unused]] const extern key_t KEY_F5;
    [[maybe_unused]] const extern key_t KEY_F6;
    [[maybe_unused]] const extern key_t KEY_F7;
    [[maybe_unused]] const extern key_t KEY_F8;
    [[maybe_unused]] const extern key_t KEY_F9;
    [[maybe_unused]] const extern key_t KEY_F10;
    [[maybe_unused]] const extern key_t KEY_F11;
    [[maybe_unused]] const extern key_t KEY_F12;
    [[maybe_unused]] const extern key_t KEY_F13;
    [[maybe_unused]] const extern key_t KEY_F14;
    [[maybe_unused]] const extern key_t KEY_F15;
    [[maybe_unused]] const extern key_t KEY_F16;
    [[maybe_unused]] const extern key_t KEY_F17;
    [[maybe_unused]] const extern key_t KEY_F18;
    [[maybe_unused]] const extern key_t KEY_F19;
    [[maybe_unused]] const extern key_t KEY_F20;
    [[maybe_unused]] const extern key_t KEY_F21;
    [[maybe_unused]] const extern key_t KEY_F22;
    [[maybe_unused]] const extern key_t KEY_F23;
    [[maybe_unused]] const extern key_t KEY_F24;
    [[maybe_unused]] const extern key_t KEY_F25;
    [[maybe_unused]] const extern key_t KEY_KP_0;
    [[maybe_unused]] const extern key_t KEY_KP_1;
    [[maybe_unused]] const extern key_t KEY_KP_2;
    [[maybe_unused]] const extern key_t KEY_KP_3;
    [[maybe_unused]] const extern key_t KEY_KP_4;
    [[maybe_unused]] const extern key_t KEY_KP_5;
    [[maybe_unused]] const extern key_t KEY_KP_6;
    [[maybe_unused]] const extern key_t KEY_KP_7;
    [[maybe_unused]] const extern key_t KEY_KP_8;
    [[maybe_unused]] const extern key_t KEY_KP_9;
    [[maybe_unused]] const extern key_t KEY_KP_DECIMAL;
    [[maybe_unused]] const extern key_t KEY_KP_DIVIDE;
    [[maybe_unused]] const extern key_t KEY_KP_MULTIPLY;
    [[maybe_unused]] const extern key_t KEY_KP_SUBTRACT;
    [[maybe_unused]] const extern key_t KEY_KP_ADD;
    [[maybe_unused]] const extern key_t KEY_KP_ENTER;
    [[maybe_unused]] const extern key_t KEY_KP_EQUAL;
    [[maybe_unused]] const extern key_t KEY_LEFT_SHIFT;
    [[maybe_unused]] const extern key_t KEY_LEFT_CONTROL;
    [[maybe_unused]] const extern key_t KEY_LEFT_ALT;
    [[maybe_unused]] const extern key_t KEY_LEFT_SUPER;
    [[maybe_unused]] const extern key_t KEY_RIGHT_SHIFT;
    [[maybe_unused]] const extern key_t KEY_RIGHT_CONTROL;
    [[maybe_unused]] const extern key_t KEY_RIGHT_ALT;
    [[maybe_unused]] const extern key_t KEY_RIGHT_SUPER;
    [[maybe_unused]] const extern key_t KEY_MENU;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_1;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_2;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_3;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_4;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_5;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_6;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_7;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_8;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_LEFT;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_RIGHT;
    [[maybe_unused]] const extern key_t MOUSE_BUTTON_MIDDLE;
} // namespace cringine::event_system::input::keys
