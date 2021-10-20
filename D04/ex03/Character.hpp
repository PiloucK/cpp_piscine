/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:18:25 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 17:46:44 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {

public:
    Character( const std::string & name );
    Character( const Character & model );

    virtual ~Character( void );

    Character & operator=( const Character & model );

	virtual const std::string & getName() const;

	virtual void equip(AMateria * m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter & target);

protected:

private:
    Character( void );

	std::string		m_Name;
	AMateria *		m_Inventory[4];

};

std::ostream & operator<<( std::ostream & stream, const Character & a_Character );

#endif
