/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:51:36 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/12 13:05:51 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/Camera.hpp"

Camera::Camera()
{}

Camera::Camera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch)
:m_pos(pos), 
m_up(up), 
m_front(glm::vec3(0.0f, 0.0f, -1.0f)), 
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

void Camera::update_camera_vectors()
{
    
}