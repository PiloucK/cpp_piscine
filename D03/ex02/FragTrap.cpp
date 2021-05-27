/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/27 14:19:41 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(
    void )
        : ClapTrap(100, 100, 100, 100, 1, "FR4G-TP", 30, 20, 5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP, Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

FragTrap::FragTrap(
    const std::string name )
        : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
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
    oStream << "\nFR4G-TP " << fragTrap.getName() << '(' << fragTrap.getHitPoint()
        << " hit points left).\n";
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
    
    std::cout << "\nStill " << this->m_iHitPoint << " left.";
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
        unsigned int randomAttack = rand() % 5;

        std::cout << "\nF to the R to the 4 to the G to the WHAAT!\n";

        std::cout << attacks[randomAttack] << " straight in for " << damages[randomAttack] << " damages\n";

        this->m_iEnergyPoint -= 25;
    } else {
        std::cout << "\nDangit, I'm out! 25 more energy points?! You talking to me?!\n";
    }

}
