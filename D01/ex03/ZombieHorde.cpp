/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:57:48 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/25 14:25:45 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

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
