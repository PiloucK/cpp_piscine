/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:36:18 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 15:09:57 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(
    void )
        : Animal("Dog")
        , m_Brain(new Brain)
{
    std::cout << "Dog default constructor\n";
}

Dog::Dog(
    const Dog & model )
        : Animal(model.m_Type)
        , m_Brain(new Brain(*model.m_Brain))
{
    std::cout << "Dog copy constructor from model of type: " << m_Type << "\n";
}

Dog::~Dog(
    void )
{
    delete m_Brain;

    std::cout << "Dog destructor, " << m_Type << " destroyed\n";
}

Dog &
Dog::operator=(
    const Dog & model )
{
    std::cout << "Operator =, type changed from " << m_Type << " to " << model.m_Type << "\n";
    m_Type = model.m_Type;
	*m_Brain = *model.m_Brain;

    return *this;
}

void
Dog::makeSound(
    void ) const
{
    std::cout << "Woof\n";
}

const std::string
Dog::think(
	void ) const
{
	return (m_Brain->bestIdea());
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Dog & a_Dog )
{
    oStream << a_Dog.getType() << " on the stream\n";

    return (oStream);
}
