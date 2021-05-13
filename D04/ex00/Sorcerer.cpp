/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:22:47 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/13 11:24:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <string>
#include <iostream>

Sorcerer::Sorcerer(
    void )
{
}

Sorcerer::Sorcerer(
    const Sorcerer & model )
{
    *this = model;

    std::cout << this->m_name << ", " << this->m_title << ", is born!\n";
}

Sorcerer::Sorcerer(
    const std::string name
    , const std::string title )
        : m_name(name)
        , m_title(title)
{
    std::cout << this->m_name << ", " << this->m_title << ", is born!\n";
}

Sorcerer &
Sorcerer::operator=(
    const Sorcerer & model )
{
    if (this != &model) {
        this->m_name = model.m_name;
        this->m_title = model.m_title;
    }
}

Sorcerer::~Sorcerer(
    void )
{
    std::cout << this->m_name << ", " << this->m_title
        << ", is dead. Consequences will never be the same!\n";
}

const std::string &
Sorcerer::getName(
    void ) const
{
    return (this->m_name);
}

const std::string &
Sorcerer::getTitle(
    void ) const
{
    return (this->m_title);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Sorcerer & sorcerer )
{
    oStream << "I am " << sorcerer.getName() << ", "
        << sorcerer.getTitle() << ", and I like ponies!\n";
}
