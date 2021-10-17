/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:57:54 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/17 15:40:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {

public:
    Animal( void );
    Animal( const std::string type );
    Animal( const Animal & model );

    virtual ~Animal( void );

    Animal & operator=( const Animal & model );

    const std::string & getType( void ) const;

    virtual void makeSound( void ) const = 0;

protected:
    std::string m_Type;
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Animal & a_Animal );

#endif
