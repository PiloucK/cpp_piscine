/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:55:09 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:04:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

void
randomChump(
    void )
{
    ZombieEvent  customEvent("Default");

    customEvent.setZombieType( Zombie::getAType( rand() % 10 ) );
    
    Zombie* MyZombie =
        customEvent.newZombie( Zombie::getAName( rand() % 10 ) );

    MyZombie->announce();

    delete MyZombie;
}

int
main(
    void )
{
    srand(time(NULL));
    randomChump();

    return 0;
}
