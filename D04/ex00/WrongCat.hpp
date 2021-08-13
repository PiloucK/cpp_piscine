/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:24 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 17:01:39 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal {

public:
    WrongCat( void );
    WrongCat( const WrongCat & model );

    virtual ~WrongCat( void );

    WrongCat & operator=( const WrongCat & model );

    void makeSound( void ) const;

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const WrongCat & a_WrongCat );

#endif
