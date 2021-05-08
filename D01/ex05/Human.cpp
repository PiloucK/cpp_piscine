/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:08:59 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 20:50:53 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include "Brain.hpp"
#include <string>

Human::Human(
    void )
{
}

Human::~Human(
    void )
{
}

std::string
Human::identify(
    void ) const
{
    return this->getBrain().identify();
}

const Brain&
Human::getBrain(
    void ) const
{
    return this->brain;
}
