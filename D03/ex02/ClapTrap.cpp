/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/11 17:56:51 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(
    void )
        : m_iHitPoint(100)
        , m_iMaxHitPoint(100)
        , m_iEnergyPoint(50)
        , m_iMaxEnergyPoint(50)
        , m_iLevel(1)
        , m_sName("CL4P-TP")
        , m_iMeleeAttackDamage(20)
        , m_iRangedAttackDamage(15)
        , m_iArmorDamageReduction(3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: CL4P-TP, Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ClapTrap::ClapTrap(
    const std::string name )
        : m_iHitPoint(100)
        , m_iMaxHitPoint(100)
        , m_iEnergyPoint(100)
        , m_iMaxEnergyPoint(100)
        , m_iLevel(1)
        , m_sName(name)
        , m_iMeleeAttackDamage(30)
        , m_iRangedAttackDamage(20)
        , m_iArmorDamageReduction(5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: CL4P-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ClapTrap::ClapTrap(
    const ClapTrap & model )
{
    std::cout << "\nSet right up, same as CL4P-TP " << model.m_sName << '\n';

    *this = model;
}

ClapTrap::~ClapTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
    // std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
}

ClapTrap &
ClapTrap::operator=(
    const ClapTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    this->m_iHitPoint = model.m_iHitPoint;
    this->m_iMaxHitPoint = model.m_iMaxHitPoint;
    this->m_iEnergyPoint = model.m_iEnergyPoint;
    this->m_iMaxEnergyPoint = model.m_iMaxEnergyPoint;
    this->m_iLevel = model.m_iLevel;
    this->m_sName = model.m_sName;
    this->m_iMeleeAttackDamage = model.m_iMeleeAttackDamage;
    this->m_iRangedAttackDamage = model.m_iRangedAttackDamage;
    this->m_iArmorDamageReduction = model.m_iArmorDamageReduction;

    return *this;
}

std::string
ClapTrap::getName(
    void ) const
{
    return this->m_sName;
}

unsigned int
ClapTrap::getHitPoint(
    void ) const
{
    return this->m_iHitPoint;
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
    std::cout << "\nTake " << this->m_iRangedAttackDamage
        << " damage, then call me in the morning " << target << ".\n";
}

void
ClapTrap::meleeAttack(
    std::string const & target )
{
    std::cout << "\nGet ready for some ClapTrap face time " << target << '!'
        << "\nUp close and personal, " << this->m_iMeleeAttackDamage << " sexy damages.\n";
}

void
ClapTrap::takeDamage(
    unsigned int amount )
{
    std::cout << "\nWhy do I even feel pain?!\n";

    if (this->m_iArmorDamageReduction <= amount) {

        unsigned int damageTaken = amount - this->m_iArmorDamageReduction;

        std::cout << '\n' << damageTaken << " damage taken\n";

        if (this->m_iHitPoint > damageTaken) {
            this->m_iHitPoint -= damageTaken;
        } else {
            this->m_iHitPoint = 0;
        }
    }
    
    std::cout << "\nStill " << this->m_iHitPoint << " left.";
}

void
ClapTrap::beRepaired(
    unsigned int amount )
{
    std::cout << "\nSweet life juice!\n";

    if (this->m_iHitPoint + amount <= this->m_iMaxHitPoint) {
        this->m_iHitPoint += amount;
    } else {
        this->m_iHitPoint = this->m_iMaxHitPoint;
    }

    std::cout << "\nNew life to " << this->m_iHitPoint << "/" << this->m_iMaxHitPoint << ".\n";
}
