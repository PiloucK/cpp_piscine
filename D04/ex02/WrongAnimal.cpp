/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:55:57 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 16:58:50 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(
    void )
        : m_Type(" ")
{
    std::cout << "WrongAnimal default constructor\n";
}

WrongAnimal::WrongAnimal(
    const std::string type )
        : m_Type(type)
{
    std::cout << "WrongAnimal constructor type (" << m_Type << ") provided\n";
}

WrongAnimal::WrongAnimal(
    const WrongAnimal & model )
        : m_Type(model.m_Type)
{
    std::cout << "WrongAnimal copy constructor from model of type: " << m_Type << "\n";
}

WrongAnimal::~WrongAnimal(
    void )
{
    std::cout << "WrongAnimal destructor, " << m_Type << " destroyed\n";
}

WrongAnimal &
WrongAnimal::operator=(
    const WrongAnimal & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;

    return *this;
}

const std::string &
WrongAnimal::getType(
    void ) const
{
    return (m_Type);
}

void
WrongAnimal::makeSound(
    void ) const
{
    std::cout << "...\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const WrongAnimal & a_WrongAnimal )
{
    oStream << a_WrongAnimal.getType() << " on the stream\n";

    return (oStream);
}
