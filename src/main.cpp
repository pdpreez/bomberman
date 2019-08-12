/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:03:07 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/12 10:04:09 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

int main()
{
    Game game;
    game.run();
    // void *handle = dlopen("./shared/OpenGL.so", RTLD_NOW | RTLD_GLOBAL);
    // if (!handle)
    //     return 1;
    // createFunc func = (createFunc)dlsym(handle, "create_renderer");
    // if (!func)
    //     return 1;
    // char *errors = dlerror();
    // if (errors)
    // {
    //     std::cout << "Dynamic linking error: " << errors << std::endl;
    //     return 1;   
    // }
    // IGlib *glib = (*func)(800, 600);
    // glib->createWindow();
    // while (1)
    // {
    //     glib->startFrame();
    //     glib->drawSquare(2, 2, {200, 0, 0, 255});
    //     glib->endFrame();
    // }
}