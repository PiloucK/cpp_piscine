/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:40 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 16:36:29 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal {

public:
    Dog( void );
    Dog( const Dog & model );

    virtual ~Dog( void );

    Dog & operator=( const Dog & model );

    void makeSound( void ) const;

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Dog & a_Dog );

#endif
