/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/25 16:57:15 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(
    const std::string & name )
		: m_Name(name)
{

	for (size_t i = 0; i < 4; i++) {
		m_Inventory[i] = NULL;
	}
}

Character::Character(
    const Character & model )
		: m_Name(model.m_Name)
{

	for (size_t i = 0; i < 4; i++) {
		
		if (model.m_Inventory[i]) {
			m_Inventory[i] = model.m_Inventory[i];
		}
	}
}

Character::~Character(
    void )
{

	for (size_t i = 0; i < 4 ; i++) {
		delete m_Inventory[i];
		m_Inventory[i] = NULL;
	}
}

Character &
Character::operator=(
    const Character & model )
{
	m_Name = model.m_Name;

	for (size_t i = 0; i < 4 && model.m_Inventory[i] ; i++) {
		m_Inventory[i] = model.m_Inventory[i]->clone();
	}

	return (*this);
}

const std::string &
Character::getName(
	void ) const
{
	return (m_Name);
}

void
Character::equip(
	AMateria * m )
{

	if (m) {
		size_t	i = 0;

		while (i < 4 && m_Inventory[i]) {
			++i;
		}

		if (i < 4) {
			m_Inventory[i] = m->clone();
		} else {
			std::cout << "My inventory is full\n" ;
		}
	}
}

void
Character::unequip(
	int idx )
{

	if (idx >= 0 && idx < 4 && m_Inventory[idx]) {
		m_Inventory[idx] = NULL;
	} else {
		std::cout << "Slot index is either invalid or already empty\n";
	}
}

void
Character::use(
	int idx
	, ICharacter & target )
{

	if (idx >= 0 && idx < 4 && m_Inventory[idx]) {
		m_Inventory[idx]->use(target);
	} else {
		std::cout << "Slot index is either invalid or already empty\n";
	}
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Character & a_Character )
{
    oStream << "Object Class Character named " << a_Character.getName() << "\n";

    return (oStream);
}
