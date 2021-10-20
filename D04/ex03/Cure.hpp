/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:01:20 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/19 15:44:31 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

public:
    Cure( void );
    Cure( const Cure & model );

    virtual ~Cure( void );

    Cure & operator=( const Cure & model );

	AMateria * clone( void ) const;
	void use(ICharacter & target);

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Cure & a_Cure );

#endif
