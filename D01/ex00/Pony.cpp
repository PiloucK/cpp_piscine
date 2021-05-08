/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:53:04 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 15:45:28 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

// Source for fart sound, search: "Proper way to spell a fart"

Pony::Pony(
    std::string where,
    std::string name)
        : m_sFartSound("THPPTPHTPHPHHPH")
        , m_sName(name)
{
    std::cout << "Huuuuuh imma new HORSY " << where << std::endl;
}

Pony::~Pony(
    void )
{
    std::cout << "Huuuuuh imma dead HORSY" << std::endl;
}

void
Pony::CanYouFart(
    void ) const
{
    std::cout << "My hella name is " << this->m_sName <<
        " and yes i hella can *" << this->m_sFartSound << "*" << std::endl;
}
