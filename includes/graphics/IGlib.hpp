/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGlib.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:16:50 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/11 10:59:14 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLIB_HPP
#define IGLIB_HPP

#include <exception>

#define KEY_QUIT 0
#define KEY_UP 100;
#define KEY_RIGHT 101;
#define KEY_DOWN 102;
#define KEY_LEFT 103;

class IGlib
{
    public:
        virtual ~IGlib(){};
        virtual void startFrame() = 0;
        virtual void endFrame() = 0;
        virtual void drawSquare(unsigned int x, unsigned int y, struct s_color color) = 0;
        virtual void createWindow() = 0;
        virtual void closeWindow() = 0;
        virtual int retrieveInput() = 0;
};

#endif