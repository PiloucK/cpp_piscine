/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:04:02 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 09:04:25 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(
    void )
        : Animal("Cat")
{
    std::cout << "Cat default constructor\n";
}

Cat::Cat(
    const Cat & model )
        : Animal(model.m_Type)
{
    std::cout << "Cat copy constructor from model of type: " << m_Type << "\n";
}

Cat::~Cat(
    void )
{
    std::cout << "Cat destructor, " << m_Type << " destroyed\n";
}

Cat &
Cat::operator=(
    const Cat & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;

    return *this;
}

void
Cat::makeSound(
    void ) const
{
    std::cout << "Meow\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Cat & a_Cat )
{
    oStream << a_Cat.getType() << " on the stream\n";

    return (oStream);
}
