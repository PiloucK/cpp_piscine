/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:38 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/21 19:13:18 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(
    void )
{

	for (size_t i = 0; i < 4; i++) {
		m_learnedMaterias[i] = NULL;
	}
}

MateriaSource::MateriaSource(
    const MateriaSource & model )
{

	for (size_t i = 0; i < 4; i++) {
		
		if (model.m_learnedMaterias[i]) {
			m_learnedMaterias[i] = model.m_learnedMaterias[i];
		}
	}
}

MateriaSource::~MateriaSource(
    void )
{

	for (size_t i = 0; i < 4 ; i++) {
		delete m_learnedMaterias[i];
		m_learnedMaterias[i] = NULL;
	}
}

MateriaSource &
MateriaSource::operator=(
    const MateriaSource & model )
{

	for (size_t i = 0; i < 4 && model.m_learnedMaterias[i] ; i++) {

		if (model.m_learnedMaterias[i]) {
			m_learnedMaterias[i] = model.m_learnedMaterias[i]->clone();
		}
	}

	return (*this);
}

void
MateriaSource::learnMateria(
	AMateria * m )
{

	if (m) {
		size_t	i = 0;

		while (i < 4 && m_learnedMaterias[i]) {
			++i;
		}

		if (i < 4) {
			m_learnedMaterias[i] = m->clone();
		} else {
			std::cout << "Can't lear more, too smart\n" ;
		}
	}
}

AMateria *
MateriaSource::createMateria(
	const std::string & type )
{

	for (size_t i = 0; i < 4; i++) {

		if (m_learnedMaterias[i] && m_learnedMaterias[i]->getType() == type) {
			return (m_learnedMaterias[i]->clone());
		}
	}
	
	std::cout << "Don't actually know this Materia\n";

	return (NULL);
}
