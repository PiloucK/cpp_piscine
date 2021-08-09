/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:26:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/08/08 20:29:56 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int
main(
    void )
{

std::cout << "\033[1;31m" ;

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

        std::cout << "Third instance, copy constructor (from totoToto)\n";
        ClapTrap    totoCopy(totoToto);
        std::cout << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

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

        std::cout << "totoToto be repaired :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";
    }

    {
        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "First instance, name constructor\n";
        ScavTrap toto("toto");
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Second instance, other name\n";
        ScavTrap    totoToto("totoToto");
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Third instance, copy constructor (from totoToto)\n";
        ScavTrap    totoCopy(totoToto);
        std::cout << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

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
        totoToto.takeDamage(40);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "totoToto be repaired :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "toto guard gate :\n";
        toto.guardGate();

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "ScavTrap as a ClapTrap, virtual verifications :\n";
        ClapTrap *tutu;
        tutu = &toto;
        tutu->attack("Mama");

        std::cout << "\n--------------------------------------------------------\n";
    }

std::cout << "\033[1;34m" ;

    {
        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "First instance, name constructor\n";
        FragTrap toto("toto");
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Second instance, other name\n";
        FragTrap    totoToto("totoToto");
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Third instance, copy constructor (from totoToto)\n";
        FragTrap    totoCopy(totoToto);
        std::cout << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "toto :" << toto << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

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
        totoToto.takeDamage(40);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "totoToto be repaired :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "toto high fives guys :\n";
        toto.highFivesGuys();

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "FragTrap as a ClapTrap, virtual verifications :\n";
        ClapTrap *tutu;
        tutu = &toto;
        tutu->attack("Ken");

        std::cout << "\n--------------------------------------------------------\n";
    }

    std::cout << "\n--------------------------------------------------------\n";

    return 0;
}
