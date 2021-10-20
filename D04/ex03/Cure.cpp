/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:44:37 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 16:43:29 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(
    void )
		: AMateria("cure")
{
}

Cure::Cure(
    const Cure & model )
		: AMateria(model)
{
}

Cure::~Cure(
    void )
{
}

Cure &
Cure::operator=(
    const Cure & model )
{
}

AMateria *
Cure::clone(
	void ) const
{
	return (new Cure());
}

void
Cure::use(
	ICharacter & target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Cure & a_Cure )
{
    oStream << "Object Class Cure of type " << a_Cure.getType() << "\n";

    return (oStream);
}
