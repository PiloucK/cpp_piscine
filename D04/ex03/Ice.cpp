/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:43:37 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/21 19:17:11 by Clkuznie         ###   ########.fr       */
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
	(void)model;

	return (*this);
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
