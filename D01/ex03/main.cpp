/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:58:00 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/05 13:39:55 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int
main(
    void )
{
    int n;
    
    std::cin >> n;

    ZombieHorde myHorde(n);
    myHorde.announce();
    
    return 0;
}