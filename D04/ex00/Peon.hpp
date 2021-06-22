/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/22 23:47:56 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : public Victim {

public:
    Peon( const std::string & name );
    Peon( const Peon & model );

    virtual ~Peon( void );

    Peon & operator=( const Peon & model );

    const std::string & getName( void ) const;
    virtual void getPolymorphed( void ) const;

private:
    Peon( void );

};


Peon::Peon(
    const std::string & name )
        : Victim(name)
{
    std::cout << "Zog zog.\n";
}


Peon::Peon(
    const Peon & model )
        : Victim(model)
{
    *this = model;
}


Peon::~Peon(
    void )
{
    std::cout << "Bleuark...\n";
}


Peon &
Peon::operator=(
    const Peon & model )
{
    m_Name = model.getName();

    return *this;
}


void
Peon::getPolymorphed(
    void ) const
{
    std::cout << m_Name << " has been turned into a pink pony!\n";
}


#endif
