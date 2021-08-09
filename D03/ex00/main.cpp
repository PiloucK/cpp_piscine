/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:26:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 22:10:04 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

int
main(
    void )
{

std::cout << "\033[1;34m" ;

    {
        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "First instance, name constructor\n";
        ClapTrap toto("toto");
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Second instance, other name\n";
        ClapTrap    totoToto("totoToto");
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "totoToto attack :\n";
        totoToto.attack("Karen");

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "totoToto take damage :\n";
        totoToto.takeDamage(3);
        std::cout << totoToto;
        totoToto.takeDamage(5);
        std::cout << totoToto;
        totoToto.takeDamage(40);
        std::cout << totoToto;
        totoToto.takeDamage(40);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload = (toto = totoToto):\n";
        toto = totoToto;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "totoToto be repaired :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Third instance, copy constructor (from totoToto)\n";
        ClapTrap    totoCopy(totoToto);
        std::cout << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";
    }

    std::cout << "\n--------------------------------------------------------\n";

    return 0;
}
