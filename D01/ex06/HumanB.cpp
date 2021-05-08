/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:14:58 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/05 16:02:23 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(
    std::string name )
        : m_sName(name)
        , m_Weapon()
{
}

HumanB::~HumanB(
    void )
{
}

void
HumanB::attack(
    void ) const
{
    std::cout << m_sName << " attacks with his "
        << m_Weapon->getType() << std::endl;
}

void
HumanB::setWeapon(
    Weapon& newWeapon )
{
    this->m_Weapon = &newWeapon;
}
