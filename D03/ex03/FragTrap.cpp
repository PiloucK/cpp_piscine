/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 16:55:37 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(
    const std::string name )
        : ClapTrap(name)
        , m_HitPoint(100)
        , m_EnergyPoint(100)
        , m_AttackDamage(30)
{
    ClapTrap::m_HitPoint = 100;
    ClapTrap::m_EnergyPoint = 100;
    ClapTrap::m_AttackDamage = 30;
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

FragTrap::FragTrap(
    const FragTrap & model )
        : ClapTrap(model)
{
    std::cout << "\nSet right up, same as FR4G-TP " << model.m_Name << '\n';
}

FragTrap::~FragTrap(
    void )
{
    std::cout << "\nSheeeshh u did good.\n";
}

FragTrap &
FragTrap::operator=(
    const FragTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    m_HitPoint = model.m_HitPoint;
    m_EnergyPoint = model.m_EnergyPoint;
    m_Name = model.m_Name;
    m_AttackDamage = model.m_AttackDamage;

    return *this;
}

void
FragTrap::attack(
    std::string const & target )
{
    std::cout<< "\n" << m_AttackDamage << " times PAN " << target << ".\n";
}

void
FragTrap::highFivesGuys(
    void )
{
    std::cout << "\nGimme da klap ... (pleaaase?)\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const FragTrap & a_FragTrap )
{
    oStream << "\nFR4G-TP " << a_FragTrap.getName() << " (" << a_FragTrap.getHitPoint()
        << " hit points, " << a_FragTrap.getEnergyPoint() << " energy points, "
        << a_FragTrap.getAttackDamage() << " attack damage).\n";

    return oStream;
}
