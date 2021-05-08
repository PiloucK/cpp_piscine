/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:57:19 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 20:51:03 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <sstream>

Brain::Brain(
    void )
{
}

Brain::~Brain(
    void )
{
}

std::string
Brain::identify(
    void ) const
{
    std::stringstream thisAddress;

    thisAddress << "0x" << static_cast<const void*>(this);
    return thisAddress.str();
}
