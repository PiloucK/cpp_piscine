/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:56:44 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 17:00:15 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {

public:
    WrongAnimal( void );
    WrongAnimal( const std::string type );
    WrongAnimal( const WrongAnimal & model );

    virtual ~WrongAnimal( void );

    WrongAnimal & operator=( const WrongAnimal & model );

    const std::string & getType( void ) const;

    void makeSound( void ) const;

protected:
    std::string m_Type;
    
private:

};

std::ostream & operator<<( std::ostream & stream, const WrongAnimal & a_WrongAnimal );

#endif
