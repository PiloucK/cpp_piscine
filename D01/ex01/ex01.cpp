/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:49:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 15:51:52 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void
memoryLeak()
{
    std::string*    panthere = new std::string("String panthere");

    std::cout << *panthere << std::endl;

    delete panthere;
}
