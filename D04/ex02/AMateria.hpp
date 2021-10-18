/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:28 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/18 18:12:37 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {
	
public:
	AMateria( const std::string & type );
	AMateria( const AMateria & model );
	
	virtual ~AMateria( void );

	const std::string & getType() const;

	virtual AMateria * clone() const = 0;
	virtual void use( ICharacter & target );

protected:
	std::string m_Type;

private:
	AMateria( void );

};

std::ostream & operator<<( std::ostream & stream, const AMateria & a_AMateria );

#endif

AMateria::AMateria(
    const std::string & type )
        : m_Type(type)
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
