/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGlib.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:16:50 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/14 15:35:46 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLIB_HPP
#define IGLIB_HPP

#include <exception>

class IGlib
{
    public:
        virtual ~IGlib(){};
        virtual void startFrame() = 0;
        virtual void endFrame() = 0;
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color) = 0;
        virtual void drawCube() = 0;
        virtual void createWindow() = 0;
        virtual void closeWindow() = 0;
        virtual int retrieveInput() = 0;
        virtual float getDeltaTime() = 0;
        virtual void moveCamera(unsigned int key, float deltaTime) = 0;
};

#endif