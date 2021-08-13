/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:04:02 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 17:02:47 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(
    void )
        : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor\n";
}

WrongCat::WrongCat(
    const WrongCat & model )
        : WrongAnimal(model.m_Type)
{
    std::cout << "WrongCat copy constructor from model of type: " << m_Type << "\n";
}

WrongCat::~WrongCat(
    void )
{
    std::cout << "WrongCat destructor, " << m_Type << " destroyed\n";
}

WrongCat &
WrongCat::operator=(
    const WrongCat & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;

    return *this;
}

void
WrongCat::makeSound(
    void ) const
{
    std::cout << "Meow\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const WrongCat & a_WrongCat )
{
    oStream << a_WrongCat.getType() << " on the stream\n";

    return (oStream);
}
