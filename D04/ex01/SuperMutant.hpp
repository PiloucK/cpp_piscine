/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/25 21:20:46 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

# include "Enemy.hpp"
# include <iostream>
# include <string>

class SuperMutant : public Enemy {

public:
    SuperMutant( void );
    SuperMutant( int hp );
    SuperMutant( const SuperMutant & model );

    virtual ~SuperMutant( void );

    SuperMutant & operator=( const SuperMutant & model );
    
    virtual void takeDamage( int );

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const SuperMutant & a_SuperMutant );

SuperMutant::SuperMutant(
    int hp )
        : Enemy(hp, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::SuperMutant(
    void )
        : SuperMutant(170)
{
}

SuperMutant::SuperMutant(
    const SuperMutant & model )
        : SuperMutant(model.m_HP)
{
}

SuperMutant::~SuperMutant(
    void )
{
    std::cout << "Aaargh...\n";
}

void
SuperMutant::takeDamage(
    int damage )
{
    damage -= 3;

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
    , const SuperMutant & a_SuperMutant )
{
    oStream << "Super Mutant\n";

    return (oStream);
}

#endif
