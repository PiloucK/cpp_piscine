/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:31:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/07 15:23:06 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <stdlib.h>

ClapTrap::ClapTrap(
    const std::string name )
        : m_HitPoint(10)
        , m_EnergyPoint(10)
        , m_Name(name)
        , m_AttackDamage(0)
{
    std::cout << "\nBooting sequence complete. Hello! I am your new steward bot. \
Designation: CL4P-TP " << name << ", Hyperion Robot, Class C. Please adjust factory settings to \
meet your needs before deployment.\n";
}

ClapTrap::ClapTrap(
    const ClapTrap & model )
        : m_HitPoint(model.m_HitPoint)
        , m_EnergyPoint(model.m_EnergyPoint)
        , m_Name(model.m_Name)
        , m_AttackDamage(model.m_AttackDamage)
{
    std::cout << "\nSet right up, same as CL4P-TP " << model.m_Name << '\n';
}

ClapTrap::~ClapTrap(
    void )
{
    std::cout << "\nI'M DEAD I'M DEAD OHMYGOD I'M DEEEAAaa...\n";
}

ClapTrap &
ClapTrap::operator=(
    const ClapTrap & model )
{
    std::cout << "\nIt's about to get magical!\n";

    m_HitPoint = model.m_HitPoint;
    m_EnergyPoint = model.m_EnergyPoint;
    m_Name = model.m_Name;
    m_AttackDamage = model.m_AttackDamage;

    return *this;
}

void
ClapTrap::attack(
    std::string const & target )
{
    std::cout << "\nTake " << m_AttackDamage
        << " damage, then call me in the morning " << target << ".\n";
}

void
ClapTrap::takeDamage(
    unsigned int amount )
{
    std::cout << "\nWhy do I even feel pain?!\n";

    std::cout << '\n' << amount << " damage taken\n";

    if (m_HitPoint > amount) {
        m_HitPoint -= amount;
    } else {
        m_HitPoint = 0;
    }

    std::cout << "\nStill " << m_HitPoint << " left.\n";
}

void
ClapTrap::beRepaired(
    unsigned int amount )
{
    std::cout << "\nSweet life juice!\n";

    m_HitPoint += amount;

    std::cout << "\nNew life to " << m_HitPoint << ".\n";
}
