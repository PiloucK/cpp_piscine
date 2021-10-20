/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:01:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 16:51:11 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

public:
    Ice( void );
    Ice( const Ice & model );

    virtual ~Ice( void );

    Ice & operator=( const Ice & model );

	AMateria * clone( void ) const;
	void use(ICharacter & target);

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Ice & a_Ice );

#endif