/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:04:02 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 15:10:16 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(
    void )
        : Animal("Cat")
        , m_Brain(new Brain)
{
    std::cout << "Cat default constructor\n";
}

Cat::Cat(
    const Cat & model )
        : Animal(model.m_Type)
        , m_Brain(new Brain(*model.m_Brain))
{
    std::cout << "Cat copy constructor from model of type: " << m_Type << "\n";
}

Cat::~Cat(
    void )
{
    delete m_Brain;

    std::cout << "Cat destructor, " << m_Type << " destroyed\n";
}

Cat &
Cat::operator=(
    const Cat & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;
	*m_Brain = *model.m_Brain;

    return *this;
}

void
Cat::makeSound(
    void ) const
{
    std::cout << "Meow\n";
}

const std::string
Cat::think(
	void ) const
{
	return (m_Brain->bestIdea());
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Cat & a_Cat )
{
    oStream << a_Cat.getType() << " on the stream\n";

    return (oStream);
}
