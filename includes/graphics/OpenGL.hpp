/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:23:26 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/11 12:36:26 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_HPP
#define OPENGL_HPP

#include <iostream>

#include "KHR/khrplatform.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "IGlib.hpp"
#include "Shader.hpp"
#include "KeyCodes.hpp"

class Shader;

class OpenGL: public IGlib
{
    public:
        OpenGL(unsigned int width, unsigned int height);
        OpenGL(OpenGL const &rhs);
        OpenGL &operator=(OpenGL const &rhs);
        virtual ~OpenGL();
        
        virtual void startFrame();
        virtual void endFrame();
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color);
        virtual void createWindow();
        virtual void closeWindow();
        virtual int retrieveInput();
    private:
        OpenGL();
        GLFWwindow *m_window;
        Shader *m_shader;
        unsigned int m_width;
        unsigned int m_height;
        unsigned int m_vertexArray;
        unsigned int m_vertexBuffer;
        unsigned int m_elementBuffer;

        void initialise();
        static void error_callback(int error, const char *description);
};

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height);
}

#endif