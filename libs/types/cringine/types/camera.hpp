#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace cringine::types
{
    class camera
    {
    public:
        enum class direction
        {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
        };

        static constexpr float DEFAULT_YAW = -90.0f;

        static constexpr float DEFAULT_PITCH = 0.0f;
        static constexpr float PITCH_MIN = -89.0f;
        static constexpr float PITCH_MAX = 89.0f;

        static constexpr float DEFAULT_SPEED = 3.0f;

        static constexpr float DEFAULT_SENSITIVITY = 0.25f;

        static constexpr float DEFAULT_ZOOM = 45.0f;
        static constexpr float ZOOM_MIN = 1.0f;
        static constexpr float ZOOM_MAX = 45.0f;

        static constexpr glm::vec3 DEFAULT_POSITION{0.0f, 0.0f, 0.0f};
        static constexpr glm::vec3 DEFAULT_UP{0.0f, 1.0f, 0.0f};
        static constexpr glm::vec3 DEFAULT_FRONT{0.0f, 0.0f, -1.0f};

        explicit camera(glm::vec3 position = DEFAULT_POSITION, glm::vec3 up = DEFAULT_UP, float yaw = DEFAULT_YAW, float pitch = DEFAULT_PITCH);

        [[nodiscard]] glm::mat4 view_matrix() const;
        [[nodiscard]] float zoom() const;
        [[nodiscard]] glm::vec3 position() const;

        void process_keyboard(camera::direction direction, float delta_time);
        void process_mouse_move(float x_offset, float y_offset, bool constrain_pitch = true);
        void process_mouse_scroll(float y_offset);

    private:
        void update_vectors();

        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_world_up;

        float m_yaw;
        float m_pitch;

        float m_movement_speed;
        float m_mouse_sensitivity;
        float m_zoom;
    };
} // namespace cringine
