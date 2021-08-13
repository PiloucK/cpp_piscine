/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:03:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/27 19:20:27 by clkuznie         ###   ########.fr       */
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
    SuperMutant( const SuperMutant & model );

    virtual ~SuperMutant( void );

    SuperMutant & operator=( const SuperMutant & model );
    
    virtual void takeDamage( int );

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const SuperMutant & a_SuperMutant );

SuperMutant::SuperMutant(
    void )
        : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::SuperMutant(
    const SuperMutant & model )
        : Enemy(model)
{
    std::cout << "Gaaah. Me want smash heads!\n";
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
    oStream << a_SuperMutant.getType() << "\n";

    return (oStream);
}

#endif
