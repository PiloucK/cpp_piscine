/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/07 10:33:59 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <stdlib.h>

NinjaTrap::NinjaTrap(
    void )
        : ClapTrap(60, 60, 120, 120, 1, "NINJ4-TP", 60, 5, 0)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP, Hyperion Robot, Class C.\n";
}

NinjaTrap::NinjaTrap(
    const std::string name )
        : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP " << name << ", Hyperion Robot, Class C.\n";
}

NinjaTrap::NinjaTrap(
    const NinjaTrap & model )
        : ClapTrap(model)
{
    std::cout << "\nSet right up, same as NINJ4-TP " << model.m_Name << '\n';

    *this = model;
}

NinjaTrap::~NinjaTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
    // std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
}

NinjaTrap &
NinjaTrap::operator=(
    const NinjaTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    this->m_HitPoint = model.m_HitPoint;
    this->m_MaxHitPoint = model.m_MaxHitPoint;
    this->m_EnergyPoint = model.m_EnergyPoint;
    this->m_MaxEnergyPoint = model.m_MaxEnergyPoint;
    this->m_Level = model.m_Level;
    this->m_Name = model.m_Name;
    this->m_MeleeAttackDamage = model.m_MeleeAttackDamage;
    this->m_RangedAttackDamage = model.m_RangedAttackDamage;
    this->m_ArmorDamageReduction = model.m_ArmorDamageReduction;

    return *this;
}

void
NinjaTrap::ninjaShoebox(
    const ClapTrap & target ) const
{
    std::cout << "\nPouic (ClapTrap)";
}

void
NinjaTrap::ninjaShoebox(
    const FragTrap & target ) const
{
    std::cout << "\nPfiu (FrapTrap)";
}

void
NinjaTrap::ninjaShoebox(
    const ScavTrap & target ) const
{
    std::cout << "\nGromf (ScavTrap)";
}

void
NinjaTrap::ninjaShoebox(
    const NinjaTrap & target ) const
{
    std::cout << "\nSheeesh (NinjaTrap)";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const NinjaTrap & ninjaTrap )
{
    oStream << "\nNINJ4-TP " << ninjaTrap.getName() << '(' << ninjaTrap.getHitPoint()
        << " hit points left).\n";

    return oStream;
}
