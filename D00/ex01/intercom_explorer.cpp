/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercom_explorer.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:20:37 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/02 19:51:09 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CIntercomContact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

int
main(
    void)
{
    CIntercomContact contact[8];
    std::string     input;
    int             i;

    i = 0;

    while (42) {
        if (i == 8) {
            i = 0;
        }

        std::getline(std::cin, input);
        
        if (input == "SEARCH") {
            for (int j = 0; j < CIntercomContact::GetContactCount(); j++) {
                std::cout << std::right << std::setw(10) << j + 1 << "|";
                contact[j].PrintPreview();
                std::cout << std::endl;
            }

            int input_index;
            while (1) {
                std::cout << "You can now choose the contact you want to know about";
                std::cout << std::endl << "Just type the right index: ";
                std::getline(std::cin, input);
                input_index = std::atoi(input.c_str());
                if (input_index > 0 && input_index <= CIntercomContact::GetContactCount()) {
                    std::cout << std::endl;
                    contact[input_index - 1].PrintComplete();
                    std::cout << std::endl;
                    break ;
                }
                std::cout << "Aim BETTAH, the contact does not exist" << std::endl;
            }
        }
        else if (input == "ADD") {
            contact[i].FillInformations();
            i++;
        }
        else if (input == "EXIT") {
            break ;
        }
    }

    return (0);
}
