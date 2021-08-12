/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:03:14 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 16:45:20 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(
    void )
        : m_Type(" ")
{
    std::cout << "Animal default constructor\n";
}

Animal::Animal(
    const std::string type )
        : m_Type(type)
{
    std::cout << "Animal constructor type (" << m_Type << ") provided\n";
}

Animal::Animal(
    const Animal & model )
        : m_Type(model.m_Type)
{
    std::cout << "Animal copy constructor from model of type: " << m_Type << "\n";
}

Animal::~Animal(
    void )
{
    std::cout << "Animal destructor, " << m_Type << " destroyed\n";
}

Animal &
Animal::operator=(
    const Animal & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;

    return *this;
}

const std::string &
Animal::getType(
    void ) const
{
    return (m_Type);
}

void
Animal::makeSound(
    void ) const
{
    std::cout << '\n';
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Animal & a_Animal )
{
    oStream << a_Animal.getType() << " on the stream\n";

    return (oStream);
}
