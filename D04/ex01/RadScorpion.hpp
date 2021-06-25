/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/25 21:24:45 by clkuznie         ###   ########.fr       */
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
    RadScorpion( int hp );
    RadScorpion( const RadScorpion & model );

    virtual ~RadScorpion( void );

    RadScorpion & operator=( const RadScorpion & model );
    
    virtual void takeDamage( int );

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const RadScorpion & a_RadScorpion );

RadScorpion::RadScorpion(
    int hp )
        : Enemy(hp, "Super Mutant")
{
    std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(
    void )
        : RadScorpion(80)
{
}

RadScorpion::RadScorpion(
    const RadScorpion & model )
        : RadScorpion(model.m_HP)
{
}

RadScorpion::~RadScorpion(
    void )
{
    std::cout << "* SPROTCH *\n";
}

void
RadScorpion::takeDamage(
    int damage )
{
    if (damage > 0) {
        
        if (m_HP - damage > 0) {
            m_HP -= damage;
        } else {
            m_HP = 0;
        }

    }
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const RadScorpion & a_RadScorpion )
{
    oStream << "Rad Scorpion\n";

    return (oStream);
}

#endif
