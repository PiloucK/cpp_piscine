/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:23:21 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 00:17:12 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(
    const std::string name )
        : ClapTrap(name + "_clap_name")
        , FragTrap(name)
        , ScavTrap(name)
{
    m_HitPoint = FragTrap::m_HitPoint;
    m_EnergyPoint = ScavTrap::m_EnergyPoint;
    m_AttackDamage = FragTrap::m_AttackDamage;
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: DI4MONDD-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

DiamondTrap::DiamondTrap(
    const DiamondTrap & model )
        : ClapTrap(model)
        , FragTrap(model)
        , ScavTrap(model)
{
    std::cout << "\nSet right up, same as DI4MOND-TP " << model.m_Name << '\n';
}

DiamondTrap::~DiamondTrap(
    void )
{
    std::cout << "\nI have no imagination no more.\n";
}

DiamondTrap &
DiamondTrap::operator=(
    const DiamondTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    m_HitPoint = model.m_HitPoint;
    m_EnergyPoint = model.m_EnergyPoint;
    m_Name = model.m_Name;
    m_AttackDamage = model.m_AttackDamage;

    return *this;
}

void
DiamondTrap::attack(
    std::string const & target )
{
    std::cout<< "\n" << m_AttackDamage << " times PAN " << target << ".\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const DiamondTrap & a_DiamondTrap )
{
    oStream << "\nDI4MOND-TP " << a_DiamondTrap.getName() << " (" << a_DiamondTrap.getHitPoint()
        << " hit points, " << a_DiamondTrap.getEnergyPoint() << " energy points, "
        << a_DiamondTrap.getAttackDamage() << " attack damage).\n";

    return oStream;
}
