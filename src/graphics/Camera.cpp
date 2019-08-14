/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:51:36 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/14 11:48:17 by ppreez           ###   ########.fr       */
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

glm::mat4 Camera::get_view_matrix()
{
    return glm::lookAt(m_pos, m_pos + m_front, m_up);
}

void Camera::update_camera_vectors()
{
    glm::vec3 f;

    (void)m_sensitivity;
    (void)m_movement_speed;
    f.x = cos(glm::radians(m_yaw) * cos(glm::radians(m_pitch)));
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