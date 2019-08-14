/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:42 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/14 15:31:01 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <dlfcn.h>
#include "graphics/IGlib.hpp"
#include "graphics/KeyCodes.hpp"

typedef IGlib * (*createFunc)(unsigned int width, unsigned int height);

class Game
{
    public:
        Game();
        Game(unsigned int width, unsigned int height);
        Game(Game const &rhs);
        Game &operator=(Game const &rhs);
        ~Game();

        void run();
    private:
        IGlib *glib;
        unsigned int m_width;
        unsigned int m_height;
        bool         m_running;

        void process_input(float deltaTime);
        IGlib *open_glib(const char *path);
};

#endif