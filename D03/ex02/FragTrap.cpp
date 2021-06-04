/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/02 16:07:25 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <stdlib.h>

FragTrap::FragTrap(
    void )
        : ClapTrap(100, 100, 100, 100, 1, "FR4G-TP", 30, 20, 5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP, Hyperion Robot, Class C.\n";
}

FragTrap::FragTrap(
    const std::string name )
        : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: FR4G-TP " << name << ", Hyperion Robot, Class C.\n";
}

FragTrap::FragTrap(
    const FragTrap & model )
        : ClapTrap(model)
{
    std::cout << "\nSet right up, same as FR4G-TP " << model.m_Name << '\n';

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
    , const FragTrap & fragTrap )
{
    oStream << "\nFR4G-TP " << fragTrap.getName() << '(' << fragTrap.getHitPoint()
        << " hit points left).\n";

    return oStream;
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

    if (this->m_EnergyPoint >= 25) {
        unsigned int randomAttack = rand() % 5;

        std::cout << "\nF to the R to the 4 to the G to the WHAAT!\n";

        std::cout << attacks[randomAttack] << " straight in for " << damages[randomAttack] << " damages to you, " << target << "\n";

        this->m_EnergyPoint -= 25;
    } else {
        std::cout << "\nDangit, I'm out! Need 25 more energy points?!\n";
    }

}
