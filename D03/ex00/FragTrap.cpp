/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/25 14:22:18 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

FragTrap::FragTrap(
    void )
        : m_iHitPoint(100)
        , m_iMaxHitPoint(100)
        , m_iEnergyPoint(100)
        , m_iMaxEnergyPoint(100)
        , m_iLevel(1)
        , m_sName("FR4G-TP")
        , m_iMeleeAttackDamage(30)
        , m_iRangedAttackDamage(20)
        , m_iArmorDamageReduction(5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP, Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

FragTrap::FragTrap(
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
Designation: FR4G-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

FragTrap::FragTrap(
    const FragTrap & model )
{
    std::cout << "\nSet right up, same as FR4G-TP " << model.m_sName << '\n';

    *this = model;
}

FragTrap::~FragTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
    // std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
}

FragTrap &
FragTrap::operator=(
    const FragTrap & model )
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
FragTrap::getName(
    void ) const
{
    return this->m_sName;
}

unsigned int
FragTrap::getHitPoint(
    void ) const
{
    return this->m_iHitPoint;
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const FragTrap & fragTrap )
{
    oStream << "FR4G-TP " << fragTrap.getName() << '(' << fragTrap.getHitPoint()
        << " hit points left).\n";

    return oStream;
}

void
FragTrap::rangedAttack(
    std::string const & target )
{
    std::cout << "\nTake " << this->m_iRangedAttackDamage
        << " damage, then call me in the morning " << target << ".\n";
}

void
FragTrap::meleeAttack(
    std::string const & target )
{
    std::cout << "\nGet ready for some Fragtrap face time " << target << '!'
        << "\nUp close and personal, " << this->m_iMeleeAttackDamage << " sexy damages.\n";
}

void
FragTrap::takeDamage(
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
    
    std::cout << "\nStill " << this->m_iHitPoint << " left.\n";
}

void
FragTrap::beRepaired(
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

void
FragTrap::vaulthunter_dot_exe(
    std::string const & target )
{
    static const std::string attacks [] = {
        "Gun Wizard"
        , "One Shot Wonder"
        , "Laser Inferno"
        , "Senseless Sacrifice"
        , "Funzerker"
    };

    static const unsigned int damages [] = {
        rand() % 35
        , rand() % 35
        , rand() % 35
        , rand() % 35
        , rand() % 35
    };

    if (this->m_iEnergyPoint >= 25) {
        unsigned int random = rand() % 5;

        std::cout << "\nF to the R to the 4 to the G to the WHAAT!\n";
        std::cout << attacks[random] << " straight in for " << damages[random] << " damages\n";
        std::cout << "Eat that " << target << '\n';

        this->m_iEnergyPoint -= 25;
    } else {
        std::cout << "\nDangit, I'm out! 25 more energy points?!\n";
    }

}
