/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/02 16:16:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <stdlib.h>

ScavTrap::ScavTrap(
    void )
        : ClapTrap(100, 100, 50, 50, 1, "SC4V-TP", 20, 15, 3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: SCA4V-TP, Hyperion Robot, Class C.\n";
}


ScavTrap::ScavTrap(
    const std::string name )
        : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: SCA4V-TP " << name << ", Hyperion Robot, Class C.\n";
}

ScavTrap::ScavTrap(
    const ScavTrap & model )
        : ClapTrap(model)
{
    std::cout << "\nSet right up, same as SCA4V-TP " << model.m_Name << '\n';

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

std::ostream &
operator<<(
    std::ostream & oStream
    , const ScavTrap & scavTrap )
{
    oStream << "\nSCA4V-TP " << scavTrap.getName() << '(' << scavTrap.getHitPoint()
        << " hit points left).\n";

    return oStream;
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

    std::cout << "Hey! Before you can even enter, you have to " << challenges[random] << '\n';

}
