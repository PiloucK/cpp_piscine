/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:40 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 14:59:05 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal {

public:
    Dog( void );
    Dog( const Dog & model );

    virtual ~Dog( void );

    Dog & operator=( const Dog & model );

    void makeSound( void ) const;
	const std::string think( void ) const;

protected:
    
private:
    Brain * m_Brain;

};

std::ostream & operator<<( std::ostream & stream, const Dog & a_Dog );

#endif
