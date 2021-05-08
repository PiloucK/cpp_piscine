/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:48:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/05 15:12:34 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(
    std::string weaponType )
        : type(weaponType)
{
}

Weapon::~Weapon(
    void )
{
}

const std::string&
Weapon::getType(
    void ) const
{
    return this->type;
}

void
Weapon::setType(
    std::string newType )
{
    this->type = newType;
}
