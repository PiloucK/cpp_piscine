/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:24 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 09:04:21 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal {

public:
    Cat( void );
    Cat( const Cat & model );

    virtual ~Cat( void );

    Cat & operator=( const Cat & model );

    void makeSound( void ) const;

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const Cat & a_Cat );

#endif
