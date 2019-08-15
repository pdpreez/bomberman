/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:46:26 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/15 16:11:08 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 0.001f;
const float SENSITIVITY = 0.01f;
const float FOV = 65.0f;


enum CameraMovement
{
    NONE,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    PITCH_DOWN,
    PITCH_UP,
    YAW_LEFT,
    YAW_RIGHT
};

class Camera
{
    public:
        Camera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch);
        Camera(Camera const &rhs);
        Camera &operator=(Camera const &rhs);
        ~Camera();

        float getFOV();
        glm::mat4 get_view_matrix();
        void keyboard_move(CameraMovement dir, float deltaTime);
    private:
        Camera();
        
        glm::vec3 m_pos;
        glm::vec3 m_up;
        glm::vec3 m_front;
        glm::vec3 m_right;
        glm::vec3 m_world_up;
        float m_yaw;
        float m_pitch;
        float m_fov;
        float m_sensitivity;
        float m_movement_speed;
        
        void update_camera_vectors();
};

#endif