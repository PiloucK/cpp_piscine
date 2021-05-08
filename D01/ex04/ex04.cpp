/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:35:40 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 19:38:21 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int
main(
    void )
{
    std::string sHi = "HI THIS IS BRAIN";
    
    std::string* sHiPtr = &sHi;
    std::string& sHiRef = sHi;
    
    std::cout << *sHiPtr << std::endl;
    std::cout << sHiRef << std::endl;

    return 0;
}