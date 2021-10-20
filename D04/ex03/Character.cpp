/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 18:01:55 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(
    const std::string & name )
		: m_Name(name)
		, m_Inventory({NULL, NULL, NULL, NULL})
{
}

Character::Character(
    const Character & model )
		: m_Name(model.m_Name)
		, m_Inventory({
			model.m_Inventory[0]->clone()
			, model.m_Inventory[1]->clone()
			, model.m_Inventory[2]->clone()
			, model.m_Inventory[3]->clone()
		})
{
}

Character::~Character(
    void )
{
}

Character &
Character::operator=(
    const Character & model )
{
	m_Name = model.m_Name;

	for (size_t i = 0; i < 4 && model.m_Inventory[i] ; i++) {
		m_Inventory[i] = model.m_Inventory[i]->clone();
	}
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

		if (i < 4 && !m_Inventory[i]) {
			m_Inventory[i] = m->clone();
		}
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
