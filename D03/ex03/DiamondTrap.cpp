/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:23:21 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 21:47:28 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(
    const std::string name )
        : ClapTrap(name + "_clap_name")
        , FragTrap(name + "_clap_name")
        , ScavTrap(name + "_clap_name")
{
    ClapTrap::m_HitPoint = m_HitPoint;
    m_EnergyPoint = ClapTrap::m_EnergyPoint;
    ClapTrap::m_AttackDamage = m_AttackDamage;
    m_Name = name;
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
    m_Name = model.m_Name;

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

    ClapTrap::m_HitPoint = model.ClapTrap::m_HitPoint;
    ClapTrap::m_EnergyPoint = model.ClapTrap::m_EnergyPoint;
    ClapTrap::m_Name = model.ClapTrap::m_Name;
    ClapTrap::m_AttackDamage = model.ClapTrap::m_AttackDamage;

    return *this;
}

void
DiamondTrap::attack(
    std::string const & target )
{
    ScavTrap::attack(target);
}

void
DiamondTrap::whoAmI(
    void ) const
{
    std::cout << ClapTrap::m_Name << "|" << m_Name;
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const DiamondTrap & a_DiamondTrap )
{
    oStream << "\nDI4MOND-TP ";
    a_DiamondTrap.whoAmI();
    oStream << " (" << a_DiamondTrap.getHitPoint()
        << " hit points, " << a_DiamondTrap.getEnergyPoint() << " energy points, "
        << a_DiamondTrap.getAttackDamage() << " attack damage).\n";

    return oStream;
}
