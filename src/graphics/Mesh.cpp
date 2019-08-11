/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mesh.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 13:03:41 by ppreez            #+#    #+#             */
/*   Updated: 2019/08/11 13:05:21 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.hpp"

Mesh::Mesh()
{

}

Mesh::Mesh(Mesh const &rhs)
{
    *this = rhs;
}

Mesh &Mesh::operator=(Mesh const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Mesh::~Mesh()
{
    
}