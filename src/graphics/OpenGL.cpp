/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:59:07 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/16 11:21:49 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/OpenGL.hpp"

 // Constructors 

OpenGL::OpenGL()
:m_camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), YAW, PITCH)
{
    initialise();
}

OpenGL::OpenGL(unsigned int width, unsigned int height)
:m_camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), YAW, PITCH),
m_width(width), m_height(height)
{
    initialise();
}

OpenGL::OpenGL(OpenGL const &rhs)
:m_camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), YAW, PITCH)
{
    *this = rhs;
}

OpenGL &OpenGL::operator=(OpenGL const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

OpenGL::~OpenGL()
{
    delete m_shader;
    glfwTerminate();
}

// Private methods

void OpenGL::initialise()
{
    if (!glfwInit())
        throw std::exception();
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwSetErrorCallback(error_callback);
    m_delta_time = 0.0f;
    m_last_frame = 0.0f;
    
}

void OpenGL::error_callback(int error, const char *description)
{
    std::cout << "OpenGL error: " << error << std::endl;
    std::cout << "OpenGL error: " << description << std::endl;
}

int g_key = -1;

void OpenGL::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    (void)window;
    (void)scancode;
    (void)mods;
    (void)action;
    // if (action == GLFW_PRESS || action == GLFW_REPEAT)
    // {
        g_key = key;
    // }
}

// Public methods

void OpenGL::createWindow()
{
    int height, width;
    

    float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

    // float vertices[] = 
    // {
    //      1.0,  1.0,
    //      1.0,  0.0,
    //      0.0,  0.0,
    //      0.0,  1.0
    // };
    

    // unsigned int indices[] =
    // {
    //     0, 1, 3,
    //     1, 2, 3
    // };


    m_window = glfwCreateWindow(m_width, m_height, "Bomberman", nullptr, nullptr);
    if (!m_window)
        throw std::exception();
    glfwMakeContextCurrent(m_window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glEnable(GL_DEPTH_TEST);
    glfwGetFramebufferSize(m_window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetKeyCallback(m_window, key_callback);
    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GLFW_TRUE);
    m_shader = new Shader("./shaders/vertex.vs", "./shaders/fragment.fs");

    if (m_shader->m_errors)
    {
        glfwTerminate();
        exit(1);
    }
    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    // glGenBuffers(1, &m_elementBuffer);

    glBindVertexArray(m_vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBuffer);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void *)0);
    glEnableVertexAttribArray(0);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void *)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

}

void OpenGL::closeWindow()
{
    glfwTerminate();
}

// int OpenGL::retrieveInput()
// {
//     int key = g_key;
//     if (g_key != 0)
//     {
//         g_key = 0;
//         return key;
//     }
//     return g_key;
// }


void OpenGL::startFrame()
{
    float currentFrame = glfwGetTime();
    m_delta_time -= currentFrame - m_last_frame;
    m_last_frame = currentFrame;
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_shader->use();
    glBindVertexArray(m_vertexArray);
}

void OpenGL::endFrame()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void OpenGL::drawSquare(unsigned int x, unsigned int y, struct s_color color)
{
    float r = static_cast<float>(color.r) / 255;
    float g = static_cast<float>(color.g) / 255;
    float b = static_cast<float>(color.b) / 255;
    m_shader->setVec3("color", r, g, b);
    m_shader->setVec3("pos", x, y, 0.0);
    m_shader->use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGL::drawCube()
{
    glm::mat4 proj = glm::perspective(glm::radians(m_camera.getFOV()), (float)m_width / (float)m_height, 0.1f, 100.0f) ;
    m_shader->setMat4("proj", proj);

    glm::mat4 view = m_camera.get_view_matrix();
    m_shader->setMat4("view", view);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    m_shader->setMat4("model", model);
    
    m_shader->setVec3("color", 1.0f, 0.0f, 1.0f);
    m_shader->use();
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void OpenGL::moveCamera(unsigned int key, float deltaTime)
{
    CameraMovement dir = NONE;
    if (key == KEY_UP)
        dir = UP;
    else if (key == KEY_DOWN)
        dir = DOWN;
    else if (key == KEY_LEFT)
        dir = YAW_LEFT;
    else if (key == KEY_RIGHT)
        dir = YAW_RIGHT;
    else if (key == KEY_W)
        dir = FORWARD;
    else if (key == KEY_A)
        dir = LEFT;
    else if (key == KEY_S)
        dir = BACKWARD;
    else if (key == KEY_D)
        dir = RIGHT;
    else if (key == KEY_R)
        dir = PITCH_UP;
    else if (key == KEY_F)
        dir = PITCH_DOWN;
    if (dir != NONE)
        m_camera.keyboard_move(dir, deltaTime);
}

float OpenGL::getDeltaTime()
{
    return m_delta_time;
}

extern "C"
{
    IGlib *create_renderer(unsigned int width, unsigned int height)
    {
        return new OpenGL(width, height);
    }
}

int OpenGL::retrieveInput(int key)
{
    key = convert_keys(key);
    if (glfwGetKey(m_window, key) == GLFW_PRESS)
        return KEY_PRESSED;
    else
        return -1;
}

int OpenGL::convert_keys(int key)
{
    switch (key)
    {
        case KEY_SPACE:         return GLFW_KEY_SPACE;
        case KEY_APOSTROPHE:    return GLFW_KEY_APOSTROPHE;
        case KEY_COMMA:         return GLFW_KEY_COMMA;
        case KEY_PERIOD:        return GLFW_KEY_MINUS;
        case KEY_FWD_SLASH:     return GLFW_KEY_SLASH;
        case KEY_0:             return GLFW_KEY_0;
        case KEY_1:             return GLFW_KEY_1;
        case KEY_2:             return GLFW_KEY_2;
        case KEY_3:             return GLFW_KEY_3;
        case KEY_4:             return GLFW_KEY_4;
        case KEY_5:             return GLFW_KEY_5;
        case KEY_6:             return GLFW_KEY_6;
        case KEY_7:             return GLFW_KEY_7;
        case KEY_8:             return GLFW_KEY_8;
        case KEY_9:             return GLFW_KEY_9;
        case KEY_SEMICOLON:     return GLFW_KEY_SEMICOLON;
        case KEY_EQUAL:         return GLFW_KEY_EQUAL;
        case KEY_A:             return GLFW_KEY_A;
        case KEY_B:             return GLFW_KEY_B;
        case KEY_C:             return GLFW_KEY_C;
        case KEY_D:             return GLFW_KEY_D;
        case KEY_E:             return GLFW_KEY_E;
        case KEY_F:             return GLFW_KEY_F;
        case KEY_G:             return GLFW_KEY_G;
        case KEY_H:             return GLFW_KEY_H;
        case KEY_I:             return GLFW_KEY_I;
        case KEY_J:             return GLFW_KEY_J;
        case KEY_K:             return GLFW_KEY_K;
        case KEY_L:             return GLFW_KEY_L;
        case KEY_M:             return GLFW_KEY_M;
        case KEY_N:             return GLFW_KEY_N;
        case KEY_O:             return GLFW_KEY_O;
        case KEY_P:             return GLFW_KEY_P;
        case KEY_Q:             return GLFW_KEY_Q;
        case KEY_R:             return GLFW_KEY_R;
        case KEY_S:             return GLFW_KEY_S;
        case KEY_T:             return GLFW_KEY_T;
        case KEY_U:             return GLFW_KEY_U;
        case KEY_V:             return GLFW_KEY_V;
        case KEY_W:             return GLFW_KEY_W;
        case KEY_X:             return GLFW_KEY_X;
        case KEY_Y:             return GLFW_KEY_Y;
        case KEY_Z:             return GLFW_KEY_Z;
        case KEY_LEFT_BRACKET:  return GLFW_KEY_LEFT_BRACKET;
        case KEY_BACK_SLASH:    return GLFW_KEY_BACKSLASH;
        case KEY_RIGHT_BRACKET: return GLFW_KEY_RIGHT_BRACKET;
        case KEY_GRAVE_ACCENT:  return GLFW_KEY_GRAVE_ACCENT;
        case KEY_ESCAPE:        return GLFW_KEY_ESCAPE;
        case KEY_ENTER:         return GLFW_KEY_ENTER;
        case KEY_TAB:           return GLFW_KEY_TAB;
        case KEY_BACKSPACE:     return GLFW_KEY_BACKSPACE;
        case KEY_INSERT:        return GLFW_KEY_INSERT;
        case KEY_DELETE:        return GLFW_KEY_DELETE;
        case KEY_RIGHT:         return GLFW_KEY_RIGHT;
        case KEY_LEFT:          return GLFW_KEY_LEFT;
        case KEY_DOWN:          return GLFW_KEY_DOWN;
        case KEY_UP:            return GLFW_KEY_UP;
        case KEY_PAGE_UP:       return GLFW_KEY_PAGE_UP;
        case KEY_PAGE_DOWN:     return GLFW_KEY_PAGE_DOWN;
        case KEY_HOME:          return GLFW_KEY_HOME;
        case KEY_END:           return GLFW_KEY_END;
        case KEY_CAPS_LOCK:     return GLFW_KEY_CAPS_LOCK;
        case KEY_SCROLL_LOCK:   return GLFW_KEY_SCROLL_LOCK;
        case KEY_NUM_LOCK:      return GLFW_KEY_NUM_LOCK;
        case KEY_PRINT_SCREEN:  return GLFW_KEY_PRINT_SCREEN;
        case KEY_PAUSE:         return GLFW_KEY_PAUSE;
        case KEY_F1:            return GLFW_KEY_F1;
        case KEY_F2:            return GLFW_KEY_F2;
        case KEY_F3:            return GLFW_KEY_F3;
        case KEY_F4:            return GLFW_KEY_F4;
        case KEY_F5:            return GLFW_KEY_F5;
        case KEY_F6:            return GLFW_KEY_F6;
        case KEY_F7:            return GLFW_KEY_F7;
        case KEY_F8:            return GLFW_KEY_F8;
        case KEY_F9:            return GLFW_KEY_F9;
        case KEY_F10:           return GLFW_KEY_F10;
        case KEY_F11:           return GLFW_KEY_F11;
        case KEY_F12:           return GLFW_KEY_F12;
        case KEY_F13:           return GLFW_KEY_F13;
        case KEY_F14:           return GLFW_KEY_F14;
        case KEY_F15:           return GLFW_KEY_F15;
        case KEY_F16:           return GLFW_KEY_F16;
        case KEY_F17:           return GLFW_KEY_F17;
        case KEY_F18:           return GLFW_KEY_F18;
        case KEY_F19:           return GLFW_KEY_F19;
        case KEY_KP_0:          return GLFW_KEY_KP_0;
        case KEY_KP_1:          return GLFW_KEY_KP_1;
        case KEY_KP_2:          return GLFW_KEY_KP_2;
        case KEY_KP_3:          return GLFW_KEY_KP_3;
        case KEY_KP_4:          return GLFW_KEY_KP_4;
        case KEY_KP_5:          return GLFW_KEY_KP_5;
        case KEY_KP_6:          return GLFW_KEY_KP_6;
        case KEY_KP_7:          return GLFW_KEY_KP_7;
        case KEY_KP_8:          return GLFW_KEY_KP_8;
        case KEY_KP_9:          return GLFW_KEY_KP_9;
        case KEY_KP_DECIMAL:    return GLFW_KEY_KP_DECIMAL;
        case KEY_KP_DIVIDE:     return GLFW_KEY_KP_DIVIDE;
        case KEY_KP_MULTIPLY:   return GLFW_KEY_KP_MULTIPLY;
        case KEY_KP_SUBTRACT:   return GLFW_KEY_KP_SUBTRACT;
        case KEY_KP_ADD:        return GLFW_KEY_KP_ADD;
        case KEY_KP_ENTER:      return GLFW_KEY_KP_ENTER;
        case KEY_KP_EQUAL:      return GLFW_KEY_KP_EQUAL;
        case KEY_LEFT_SHIFT:    return GLFW_KEY_LEFT_SHIFT;
        case KEY_LEFT_CONTROL:  return GLFW_KEY_LEFT_CONTROL;
        case KEY_LEFT_SUPER:    return GLFW_KEY_LEFT_SUPER;
        case KEY_RIGHT_SHIFT:   return GLFW_KEY_RIGHT_SHIFT;
        case KEY_RIGHT_CONTROL: return GLFW_KEY_RIGHT_CONTROL;
        case KEY_RIGHT_ALT:     return GLFW_KEY_RIGHT_ALT;
        case KEY_RIGHT_SUPER:   return GLFW_KEY_RIGHT_SUPER;
        case KEY_MENU:          return GLFW_KEY_MENU;
        default:                return -1;
    }
    

}