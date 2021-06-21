/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/21 17:31:11 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : public Victim {

public:
    virtual void getPolymorphed( void ) const;

private:

};

void
Peon::getPolymorphed(
    void ) const
{
    std::cout << m_Name << " has been turned into a pink pony!\n";
}

#endif
