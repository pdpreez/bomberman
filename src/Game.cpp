/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:23 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/14 11:39:32 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

Game::Game()
:m_width(800), m_height(600)
{

}

Game::Game(unsigned int width, unsigned int height)
:m_width(width), m_height(height)
{

}

Game::Game(Game const &rhs)
{
    *this = rhs;
}

Game &Game::operator=(Game const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Game::~Game()
{

}

void Game::run()
{
    glib = open_glib("./shared/OpenGL.so");
    if (!glib)
        throw std::exception();
    else
    {
        glib->createWindow();
        m_running = true;
    }
    while (m_running)
    {
        process_input();
        glib->startFrame();
        glib->drawCube();
        glib->endFrame();
    }
    glib->closeWindow();
}

IGlib *Game::open_glib(const char *path)
{
    void *handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
    if (!handle)
        return nullptr;
    createFunc func = (createFunc)dlsym(handle, "create_renderer");
    if (!func)
        return nullptr;
    char *errors = dlerror();
    if (errors)
    {
        std::cout << "Dynamic linking error: " << errors << std::endl;
        return nullptr;   
    }
    return (*func)(m_width, m_height);
}

void Game::process_input()
{
    unsigned int key;
    key = glib->retrieveInput();
    if (key == KEY_ESCAPE)
        m_running = false;
}