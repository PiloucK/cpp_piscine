/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:49:28 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/18 18:08:05 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class ICharacter {
	
public:
	ICharacter( void );
	ICharacter( const std::string & type );
	ICharacter( const ICharacter & model );
	
	virtual ~ICharacter( void );

	ICharacter & operator=( const ICharacter & model );
	const std::string & getType() const;

	virtual ICharacter * clone() const = 0;
	virtual void use( ICharacter & target );

protected:
	std::string m_Type;

private:

};

std::ostream & operator<<( std::ostream & stream, const ICharacter & a_ICharacter );

#endif
