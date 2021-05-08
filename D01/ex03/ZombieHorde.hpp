/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:57:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:37:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include "Zombie.hpp"

class ZombieHorde {

private:
    Zombie* horde;
    const int n;

public:
    ZombieHorde( int n );
    virtual ~ZombieHorde( void );

    void    announce( void ) const;

};

#include <stdlib.h>

ZombieHorde::ZombieHorde(
    int n )
        : n(n)
{
    this->horde = new Zombie[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        this->horde[i].setName( Zombie::getAName( rand() % 10 ) );
        this->horde[i].setType( Zombie::getAType( rand() % 10 ) );
    }

}

ZombieHorde::~ZombieHorde(
    void )
{
    delete [] this->horde;
}

void
ZombieHorde::announce(
    void ) const
{
    for (int i = 0; i < this->n; i++) {
        this->horde[i].announce();
    }
}

#endif
