/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:51:36 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/20 16:15:54 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/Camera.hpp"

Camera::Camera()
{}

Camera::Camera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch)
:m_pos(pos), 
m_up(up),
m_front(glm::vec3(0.0f, 0.0f, -1.0f)), 
m_world_up(up),
m_yaw(yaw), 
m_pitch(pitch),
m_fov(FOV),
m_sensitivity(SENSITIVITY),
m_movement_speed(SPEED)
{
    update_camera_vectors();   
}

Camera::Camera(Camera const &rhs)
{
    *this = rhs;
}

Camera &Camera::operator=(Camera const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Camera::~Camera()
{
    
}

glm::vec3 Camera::getPosition()
{
    return m_pos;
}

glm::mat4 Camera::get_view_matrix()
{
    return glm::lookAt(m_pos, m_pos + m_front, m_up);
}

void Camera::update_camera_vectors()
{
    glm::vec3 f;

    (void)m_sensitivity;
    f.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    f.y = sin(glm::radians(m_pitch));
    f.z = sin(glm::radians(m_yaw) * cos(glm::radians(m_pitch)));
    
    m_front = glm::normalize(f);
    m_right = glm::normalize(glm::cross(m_front, m_world_up));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}

float Camera::getFOV()
{
    return m_fov;
}

void Camera::keyboard_move(CameraMovement dir, float deltaTime)
{
    (void)deltaTime;
    float speed = 15;
    float velocity = m_movement_speed;
    if (dir == FORWARD)
        m_pos += m_front * velocity;
    else if (dir == BACKWARD)
        m_pos -= m_front * velocity;
    else if (dir == LEFT)
        m_pos -= m_right * velocity;
    else if (dir == RIGHT)
        m_pos += m_right * velocity;
    else if (dir == UP)
        m_pos += m_up * velocity;
    else if (dir == DOWN)
        m_pos -= m_up * velocity;
    else if (dir == YAW_LEFT)
        m_yaw -=  speed * velocity;
    else if (dir == YAW_RIGHT)
        m_yaw +=  speed * velocity;
    else if (dir == PITCH_UP)
        m_pitch -=  speed * velocity;
    else if (dir == PITCH_DOWN)
        m_pitch +=  speed * velocity;
    if (m_pitch > 89.0f)
        m_pitch = 89.0f;
    if (m_pitch < -89.0f)
        m_pitch = -89.0f;
    update_camera_vectors();
}