/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyCodes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:27:24 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/11 10:59:42 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_HPP
#define KEYCODES_HPP

enum keys
{
    NONE = -1,
    EXIT = 0,
    OPENGL_KEY = 1,
    SDL_KEY = 2,
    SFML_KEY = 3,
    UP = 100,
    RIGHT = 101,
    DOWN = 102,
    LEFT = 103
};

struct s_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

#endif