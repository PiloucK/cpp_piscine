/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:45:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 16:39:04 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(
    const std::string & type )
        : m_Type(type)
{
}

AMateria::AMateria(
    const AMateria & model )
        : m_Type(model.m_Type)
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
    return (m_Type);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const AMateria & a_AMateria )
{
    oStream << "Object Class AMateria of type " << a_AMateria.getType() << "\n";

    return (oStream);
}
