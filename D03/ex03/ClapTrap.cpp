/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/02 16:14:17 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(
    const ClapTrap & model )
{
    std::cout << "\nSet right up, same as CL4P-TP " << model.m_Name << '\n';

    *this = model;
}

ClapTrap::ClapTrap(
    const unsigned int hitPoint
    , const unsigned int maxHitPoint
    , const unsigned int energyPoint
    , const unsigned int maxEnergyPoint
    , const unsigned int level
    , const std::string name
    , const unsigned int meleeAttackDamage
    , const unsigned int rangedAttackDamage
    , const unsigned int armorDamageReduction)
        : m_HitPoint(hitPoint)
        , m_MaxHitPoint(maxHitPoint)
        , m_EnergyPoint(energyPoint)
        , m_MaxEnergyPoint(maxEnergyPoint)
        , m_Level(level)
        , m_Name(name)
        , m_MeleeAttackDamage(meleeAttackDamage)
        , m_RangedAttackDamage(rangedAttackDamage)
        , m_ArmorDamageReduction(armorDamageReduction)
{
    std::cout << "\nGot all of its own in me.\n";
}

ClapTrap &
ClapTrap::operator=(
    const ClapTrap & model )
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

ClapTrap::~ClapTrap(
    void )
{
    std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
}

std::string
ClapTrap::getName(
    void ) const
{
    return this->m_Name;
}

unsigned int
ClapTrap::getHitPoint(
    void ) const
{
    return this->m_HitPoint;
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const ClapTrap & ClapTrap )
{
    oStream << "\nCL4P-TP " << ClapTrap.getName() << '(' << ClapTrap.getHitPoint()
        << " hit points left).\n";

    return oStream;
}

void
ClapTrap::rangedAttack(
    std::string const & target )
{
    std::cout << "\nTake " << this->m_RangedAttackDamage
        << " damage, then call me in the morning " << target << ".\n";
}

void
ClapTrap::meleeAttack(
    std::string const & target )
{
    std::cout << "\nGet ready for some ClapTrap face time " << target << '!'
        << "\nUp close and personal, " << this->m_MeleeAttackDamage << " sexy damages.\n";
}

void
ClapTrap::takeDamage(
    unsigned int amount )
{
    std::cout << "\nWhy do I even feel pain?!\n";

    if (this->m_ArmorDamageReduction <= amount) {

        unsigned int damageTaken = amount - this->m_ArmorDamageReduction;

        std::cout << '\n' << damageTaken << " damage taken\n";

        if (this->m_HitPoint > damageTaken) {
            this->m_HitPoint -= damageTaken;
        } else {
            this->m_HitPoint = 0;
        }
    }
    
    std::cout << "\nStill " << this->m_HitPoint << " left.";
}

void
ClapTrap::beRepaired(
    unsigned int amount )
{
    std::cout << "\nSweet life juice!\n";

    if (this->m_HitPoint + amount <= this->m_MaxHitPoint) {
        this->m_HitPoint += amount;
    } else {
        this->m_HitPoint = this->m_MaxHitPoint;
    }

    std::cout << "\nNew life to " << this->m_HitPoint << "/" << this->m_MaxHitPoint << ".\n";
}
