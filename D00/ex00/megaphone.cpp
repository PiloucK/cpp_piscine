/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:09:57 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/01 22:12:35 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int
main (
    int ac,
    char **av)
{

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        for (int i = 1; i < ac; i++) {
            std::string str = av[i];
            for (std::string::iterator p = str.begin(); p != str.end(); p++) {
                *p = std::toupper(*p);
            }
            std::cout << str;
        }
    }

    std::cout << std::endl;

    return (0);
}
