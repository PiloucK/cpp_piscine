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
    void )
        : m_iHitPoint(100)
        , m_iMaxHitPoint(100)
        , m_iEnergyPoint(50)
        , m_iMaxEnergyPoint(50)
        , m_iLevel(1)
        , m_sName("SC4V-TP")
        , m_iMeleeAttackDamage(20)
        , m_iRangedAttackDamage(15)
        , m_iArmorDamageReduction(3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: SCA4V-TP, Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ScavTrap::ScavTrap(
    const std::string name )
        : m_iHitPoint(100)
        , m_iMaxHitPoint(100)
        , m_iEnergyPoint(50)
        , m_iMaxEnergyPoint(50)
        , m_iLevel(1)
        , m_sName(name)
        , m_iMeleeAttackDamage(20)
        , m_iRangedAttackDamage(15)
        , m_iArmorDamageReduction(3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: SCA4V-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ScavTrap::ScavTrap(
    const ScavTrap & model )
{
    std::cout << "\nSet right up, same as SCA4V-TP " << model.m_sName << '\n';

    *this = model;
}

ScavTrap::~ScavTrap(
    void )
{
    std::cout << "\nI feel like an idiot now.\n";
    // std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEAD!\n";
}

ScavTrap &
ScavTrap::operator=(
    const ScavTrap & model )
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
ScavTrap::getName(
    void ) const
{
    return this->m_sName;
}

unsigned int
ScavTrap::getHitPoint(
    void ) const
{
    return this->m_iHitPoint;
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const ScavTrap & scavTrap )
{
    oStream << "\nSCA4V-TP " << scavTrap.getName() << '(' << scavTrap.getHitPoint()
        << " hit points left).\n";
}

void
ScavTrap::rangedAttack(
    std::string const & target )
{
    std::cout << "\nTake " << this->m_iRangedAttackDamage
        << " damage, then call me in the morning " << target << ".\n";
}

void
ScavTrap::meleeAttack(
    std::string const & target )
{
    std::cout << "\nGet ready for some ScavTrap face time " << target << '!'
        << "\nUp close and personal, " << this->m_iMeleeAttackDamage << " sexy damages.\n";
}

void
ScavTrap::takeDamage(
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
ScavTrap::beRepaired(
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
ScavTrap::challengeNewcomer(
    void )
{
    static const std::string challenges [] = {
        "Talk to Claptrap"
        , "Collect 139,377 brown rocks"
        , "Defeat Ug-Thak, Lord of Skags"
        , "Pilfer lost staff of Mount Schuler"
        , "Defeat Destroyer of Worlds"
        , "Dance, dance, baby"
        , "Find stash"
        , "Grab invitations"
        , "Turn on boombox"
        , "Eat pizza"
        , "Enjoy party"
    };

    unsigned int random = rand() % 11;

    std::cout << "Hey! Before you can even enter, you have to " << challenges[random];

}
