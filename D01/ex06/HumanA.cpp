/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:14:03 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/06 12:07:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(
    std::string name
    , Weapon& weapon )
        : m_sName(name)
        , m_Weapon(&weapon)
{
}

HumanA::~HumanA(
    void )
{
}

void
HumanA::attack(
    void ) const
{
    std::cout << m_sName << " attacks with his "
        << m_Weapon->getType() << std::endl;
}
