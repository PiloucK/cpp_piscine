/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:55:22 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:01:39 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <string>
#include <iostream>

ZombieEvent::ZombieEvent(
    std::string sZombieType )
    : m_sZombieType(sZombieType)
{
}

ZombieEvent::~ZombieEvent()
{
}

void
ZombieEvent::setZombieType(
    std::string type )
{
    this->m_sZombieType = type;
}

Zombie*
ZombieEvent::newZombie(
    std::string name )
{
    return (new Zombie( this->m_sZombieType, name ));
}
