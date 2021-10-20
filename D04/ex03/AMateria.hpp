/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:28 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 16:48:09 by Clkuznie         ###   ########.fr       */
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
	virtual void use( ICharacter & target );

protected:
	AMateria( const std::string & type );
	AMateria( const AMateria & model );

private:
	std::string m_Type;

	AMateria( void );

};

std::ostream & operator<<( std::ostream & stream, const AMateria & a_AMateria );

#endif
