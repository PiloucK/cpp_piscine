/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:26:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/14 08:48:24 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

int
main(
    void )
{
    {
        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "First instance, default constructor\n";
        FragTrap    toto;
        std::cout << "toto getname return = " << toto.getName() << "\n";

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Second instance, name constructor\n";
        FragTrap    totoToto("toto");
        std::cout << "totoToto getname return = " << totoToto.getName() << "\n";

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Third instance, copy constructor\n";
        FragTrap    totoCopy(totoToto);
        std::cout << "totoCopy getname return = " << totoCopy.getName() << "\n";

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload << :\n";
        std::cout << "totoToto :" << totoToto << "totoCopy :" << totoCopy;

        std::cout << "\n--------------------------------------------------------\n";

        std::cout << "Operator overload = (toto = totoCopy):\n";
        toto = totoCopy;
        std::cout << "toto to std output\n";
        std::cout << toto;

        std::cout << "\n--------------------------------------------------------\n";
    }

    std::cout << "\n--------------------------------------------------------\n";

    return 0;
}