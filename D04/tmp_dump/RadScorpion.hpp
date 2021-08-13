/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/06 18:16:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include "Enemy.hpp"
# include <iostream>
# include <string>

class RadScorpion : public Enemy {

public:
    RadScorpion( void );
    RadScorpion( const RadScorpion & model );

    virtual ~RadScorpion();

    RadScorpion & operator=( const RadScorpion & model );

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const RadScorpion & a_RadScorpion );

RadScorpion::RadScorpion(
    void )
        : Enemy(80, "Rad Scorpion")
{
    std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(
    const RadScorpion & model )
        : Enemy(model)
{
    std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion(
    void )
{
    std::cout << "* SPROTCH *\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const RadScorpion & a_RadScorpion )
{
    oStream << a_RadScorpion.getType() << "\n";

    return (oStream);
}

#endif
