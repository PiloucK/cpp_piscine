/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:45:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/04 14:05:38 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(
    const std::string & type )
        : m_type(type)
{
}

AMateria::AMateria(
    const AMateria & model )
        : m_type(model.m_type)
{
}

AMateria::~AMateria(
    void )
{
}

const std::string &
AMateria::getType(
    void ) const
{
    return (m_type);
}

std::ostream &
operator << (
    std::ostream & oStream
    , const AMateria & a_AMateria )
{
    oStream << "Object Class AMateria of type " << a_AMateria.getType() << "\n";

    return (oStream);
}
