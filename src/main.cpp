/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 11:03:07 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/11 12:04:26 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/OpenGL.hpp"
#include <dlfcn.h>

typedef IGlib * (*createFunc)(unsigned int width, unsigned int height);

int main()
{
    void *handle = dlopen("./shared/OpenGL.so", RTLD_NOW | RTLD_GLOBAL);
    if (!handle)
        return 1;
    createFunc func = (createFunc)dlsym(handle, "create_renderer");
    if (!func)
        return 1;
    char *errors = dlerror();
    if (errors)
    {
        std::cout << "Dynamic linking error: " << errors << std::endl;
        return 1;   
    }
    IGlib *glib = (*func)(800, 600);
    glib->createWindow();
    while (1)
    {
        glib->startFrame();
        glib->endFrame();
    }
}