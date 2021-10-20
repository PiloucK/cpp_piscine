/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:43:37 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 16:44:58 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(
    void )
		: AMateria("ice")
{
}

Ice::Ice(
    const Ice & model )
		: AMateria(model)
{
}

Ice::~Ice(
    void )
{
}

Ice &
Ice::operator=(
    const Ice & model )
{
}

AMateria *
Ice::clone(
	void ) const
{
	return (new Ice());
}

void
Ice::use(
	ICharacter & target )
{
	std::cout << "* shouts an ice bolt at " << target.getName() << " *\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Ice & a_Ice )
{
    oStream << "Object Class Ice of type " << a_Ice.getType() << "\n";

    return (oStream);
}
