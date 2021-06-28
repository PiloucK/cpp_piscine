/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:26:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/28 11:03:48 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

int
main(
    void )
{
    {
        srand(time(NULL));
        
        std::cout << "\n\n============================FragTrap testing============================\n\n";

        std::cout << "First instance, default constructor\n";
        FragTrap    toto;
        std::cout << "toto getname return = " << toto.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Second instance, name constructor\n";
        FragTrap    totoToto("toto");
        std::cout << "totoToto getname return = " << totoToto.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Third instance, copy constructor\n";
        FragTrap    totoCopy(totoToto);
        std::cout << "totoCopy getname return = " << totoCopy.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n-------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n-------------------------------\n";

        std::cout << "melee attack from totoToto :\n";
        totoToto.meleeAttack("Karen");

        std::cout << "\n-------------------------------\n";

        std::cout << "ranged attack from totoToto :\n";
        totoToto.rangedAttack("Karen");

        std::cout << "\n-------------------------------\n";

        std::cout << "take damage from totoToto :\n";
        totoToto.takeDamage(30);
        std::cout << totoToto;
        totoToto.takeDamage(30);
        std::cout << totoToto;
        totoToto.takeDamage(40);
        std::cout << totoToto;
        totoToto.takeDamage(60);
        std::cout << totoToto;
        totoToto.takeDamage(60);
        std::cout << totoToto;

        std::cout << "\n-------------------------------\n";

        std::cout << "be repared from totoToto :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n-------------------------------\n";

        std::cout << "vaulthunter attack from totoToto :\n";
        totoToto.vaulthunter_dot_exe("Karen");
        totoToto.vaulthunter_dot_exe("Karen");
        totoToto.vaulthunter_dot_exe("Karen");
        totoToto.vaulthunter_dot_exe("Karen");
        totoToto.vaulthunter_dot_exe("Karen");
        totoToto.vaulthunter_dot_exe("Karen");

        std::cout << "\n-------------------------------\n";
    }

    {
        srand(time(NULL));
        
        std::cout << "\n\n============================ScavTrap testing============================\n\n";

        std::cout << "First instance, default constructor\n";
        ScavTrap    toto;
        std::cout << "toto getname return = " << toto.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Second instance, name constructor\n";
        ScavTrap    totoToto("toto");
        std::cout << "totoToto getname return = " << totoToto.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Third instance, copy constructor\n";
        ScavTrap    totoCopy(totoToto);
        std::cout << "totoCopy getname return = " << totoCopy.getName() << "\n";

        std::cout << "\n-------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n-------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n-------------------------------\n";

        std::cout << "melee attack from totoToto :\n";
        totoToto.meleeAttack("Karen");

        std::cout << "\n-------------------------------\n";

        std::cout << "ranged attack from totoToto :\n";
        totoToto.rangedAttack("Karen");

        std::cout << "\n-------------------------------\n";

        std::cout << "take damage from totoToto :\n";
        totoToto.takeDamage(30);
        std::cout << totoToto;
        totoToto.takeDamage(30);
        std::cout << totoToto;
        totoToto.takeDamage(40);
        std::cout << totoToto;
        totoToto.takeDamage(60);
        std::cout << totoToto;
        totoToto.takeDamage(60);
        std::cout << totoToto;

        std::cout << "\n-------------------------------\n";

        std::cout << "be repared from totoToto :\n";
        totoToto.beRepaired(40);
        std::cout << totoToto;
        totoToto.beRepaired(80);
        std::cout << totoToto;

        std::cout << "\n-------------------------------\n";

        std::cout << "challenge newcomer from totoToto :\n";
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();
        totoToto.challengeNewcomer();

        std::cout << "\n-------------------------------\n";
    }

    std::cout << "\n-------------------------------\n";

    return 0;
}
