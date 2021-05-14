/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/14 08:25:22 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(
    void )
        : m_HitPoint(100)
        , m_MaxHitPoint(100)
        , m_EnergyPoint(50)
        , m_MaxEnergyPoint(50)
        , m_Level(1)
        , m_Name("CL4P-TP")
        , m_MeleeAttackDamage(20)
        , m_RangedAttackDamage(15)
        , m_ArmorDamageReduction(3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: CL4P-TP, Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ClapTrap::ClapTrap(
    const std::string name )
        : m_HitPoint(100)
        , m_MaxHitPoint(100)
        , m_EnergyPoint(100)
        , m_MaxEnergyPoint(100)
        , m_Level(1)
        , m_Name(name)
        , m_MeleeAttackDamage(30)
        , m_RangedAttackDamage(20)
        , m_ArmorDamageReduction(5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: CL4P-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

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
}

ClapTrap::~ClapTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
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
