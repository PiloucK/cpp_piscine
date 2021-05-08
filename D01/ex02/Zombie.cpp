/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:55:13 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:22:35 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(
    void )
        : m_sType("Absent")
        , m_sName("Dad")
{
}

Zombie::Zombie(
    std::string type,
    std::string name)
        : m_sType(type)
        , m_sName(name)
{
}

Zombie::~Zombie(
    void )
{
}

void
Zombie::announce(
    void ) const
{
    std::cout << "<" << this->m_sType << " " << this->m_sName
        << ">" << " Boriiiiiiiiiiiing ..." << std::endl;
}

const std::string
Zombie::getAName(
    int index )
{
    return Zombie::sNameArray[index];
}

const std::string
Zombie::getAType(
    int index )
{
    return Zombie::sTypeArray[index];
}

void
Zombie::setName(
    std::string name )
{
    this->m_sName = name;
}

void
Zombie::setType(
    std::string type )
{
    this->m_sType = type;
}

const std::string Zombie::sNameArray[10] = {
    "Julien"
    , "Alice"
    , "Florianne"
    , "Florian"
    , "Lucas"
    , "Badrilla"
    , "Eudald"
    , "Arthur"
    , "Enzo"
    , "Guillaume"
};

const std::string Zombie::sTypeArray[10] = {
    "Muscled"
    , "Perfect"
    , "Entrepreneur"
    , "Benevolent"
    , "Lost"
    , "Young"
    , "Jajaja"
    , "Secret"
    , "Busy"
    , "Trapped"
};
