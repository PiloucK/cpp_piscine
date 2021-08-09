/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/11 17:57:30 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(
    const std::string name )
        : ClapTrap(name)
{
    m_HitPoint = 100;
    m_EnergyPoint = 50;
    m_AttackDamage = 20;
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: SCA4V-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ScavTrap::ScavTrap(
    const ScavTrap & model )
        : ClapTrap(model)
{
    std::cout << "\nSet right up, same as SC4V-TP " << model.m_Name << '\n';
}

ScavTrap::~ScavTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
}

ScavTrap &
ScavTrap::operator=(
    const ScavTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    m_HitPoint = model.m_HitPoint;
    m_EnergyPoint = model.m_EnergyPoint;
    m_Name = model.m_Name;
    m_AttackDamage = model.m_AttackDamage;

    return *this;
}

void
ScavTrap::attack(
    std::string const & target )
{
    std::cout << "\nGet ready for some ScavTrap face time " << target 
    << "! Up close and personal. " << this->m_AttackDamage << " sexy damages.\n";
}

void
ScavTrap::guardGate(
    void ) const
{
    std::cout << "\nHodor\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const ScavTrap & a_ScavTrap )
{
    oStream << "\nSC4V-TP " << a_ScavTrap.getName() << " (" << a_ScavTrap.getHitPoint()
        << " hit points, " << a_ScavTrap.getEnergyPoint() << " energy points, "
        << a_ScavTrap.getAttackDamage() << " attack damage).\n";

    return oStream;
}
