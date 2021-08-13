/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:23:24 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/12 17:39:31 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(
    void )
{
    std::cout << "Brain default constructor\n";
}

Brain::Brain(
    const std::string model_ideas[100] )
{
    std::cout << "Brain constructor type (" << ideas << ") provided\n";

    for (size_t i = 0; i < 100; i++) {
        ideas[i] = model_ideas[i];
    }
}

Brain::Brain(
    const Brain & model )
{
    std::cout << "Brain copy constructor\n";

    for (size_t i = 0; i < 100; i++) {
        ideas[i] = model.ideas[i];
    }
}

Brain::~Brain(
    void )
{
    std::cout << "Brain destructor\n";
}

Brain &
Brain::operator=(
    const Brain & model )
{
    std::cout << "Operator = copying all the ideas\n";

    for (size_t i = 0; i < 100; i++) {
        ideas[i] = model.ideas[i];
    }

    return *this;
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Brain & a_Brain )
{
    oStream << "A Brain on the stream\n";

    return (oStream);
}
