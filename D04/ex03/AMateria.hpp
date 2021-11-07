/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:28 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/11/04 14:06:19 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria {
	
public:
	
	virtual ~AMateria( void );

	const std::string & getType() const;

	virtual AMateria * clone() const = 0;
	virtual void use( ICharacter & target ) = 0;

protected:
	AMateria( const std::string & type );
	AMateria( const AMateria & model );

private:

	std::string m_type;

	AMateria( void );

};

std::ostream & operator << ( std::ostream & stream, const AMateria & a_AMateria );

#endif
