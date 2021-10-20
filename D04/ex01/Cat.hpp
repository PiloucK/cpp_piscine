/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:24 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/10/20 15:00:03 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public Animal {

public:
    Cat( void );
    Cat( const Cat & model );

    virtual ~Cat( void );

    Cat & operator=( const Cat & model );

    void makeSound( void ) const;
	const std::string think( void ) const;

protected:

private:
    Brain * m_Brain;

};

std::ostream & operator<<( std::ostream & stream, const Cat & a_Cat );

#endif
