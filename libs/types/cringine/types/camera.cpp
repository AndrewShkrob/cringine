#include "camera.hpp"

#include <cmath>

#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_transform.hpp>

using namespace cringine;

camera::camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_position(position)
    , m_front(DEFAULT_FRONT)
    , m_up(0.0f)
    , m_right(0.0f)
    , m_world_up(up)
    , m_yaw(yaw)
    , m_pitch(pitch)
    , m_movement_speed(DEFAULT_SPEED)
    , m_mouse_sensitivity(DEFAULT_SENSITIVITY)
    , m_zoom(DEFAULT_ZOOM)
{
    update_vectors();
}

glm::mat4 camera::view_matrix() const
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

float camera::zoom() const
{
    return m_zoom;
}

glm::vec3 camera::position() const
{
    return m_position;
}

void camera::process_keyboard(camera::direction direction, float delta_time)
{
    float velocity = m_movement_speed * delta_time;
    switch (direction) {
        case direction::FORWARD:
            m_position += m_front * velocity;
            break;
        case direction::BACKWARD:
            m_position -= m_front * velocity;
            break;
        case direction::LEFT:
            m_position -= m_right * velocity;
            break;
        case direction::RIGHT:
            m_position += m_right * velocity;
            break;
    }
}

void camera::process_mouse_move(float x_offset, float y_offset, bool constrain_pitch)
{
    x_offset *= m_mouse_sensitivity;
    y_offset *= m_mouse_sensitivity;

    m_yaw += x_offset;
    m_pitch += y_offset;

    if (constrain_pitch) {
        m_pitch = std::fmax(m_pitch, PITCH_MIN);
        m_pitch = std::fmin(m_pitch, PITCH_MAX);
    }

    update_vectors();
}

void camera::process_mouse_scroll(float y_offset)
{
    m_zoom -= y_offset;
    m_zoom = std::fmax(m_zoom, ZOOM_MIN);
    m_zoom = std::fmin(m_zoom, ZOOM_MAX);
}

void camera::update_vectors()
{
    glm::vec3 front;
    front[0] = std::cos(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
    front[1] = std::sin(glm::radians(m_pitch));
    front[2] = std::sin(glm::radians(m_yaw)) * std::cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    m_right = glm::normalize(glm::cross(m_front, m_world_up));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}
