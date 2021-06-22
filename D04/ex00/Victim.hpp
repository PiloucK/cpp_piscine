/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/22 22:29:30 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim {

public:
    Victim( const std::string & name );
    Victim( const Victim & model );

    virtual ~Victim( void );

    Victim & operator=( const Victim & model );

    const std::string & getName( void ) const;
    virtual void getPolymorphed( void ) const;

protected:
    std::string m_Name;

private:
    Victim( void );

};

std::ostream & operator<<( std::ostream & stream, const Victim & victim );

Victim::Victim(
    const std::string & name )
        : m_Name(name)
{
    std::cout << "Some random victim called " << m_Name << " just appeared!\n";
}

Victim::Victim(
    const Victim & model )
{
    operator=(model);
    std::cout << "Some random victim called " << m_Name << " just appeared!\n";
}

Victim &
Victim::operator=(
    const Victim & model )
{
    this->m_Name = model.getName();

    return (*this);
}

Victim::~Victim(
    void )
{
    std::cout << "Victim " << m_Name << " just died for no apparent reason!\n";
}

const std::string &
Victim::getName(
    void ) const
{
    return (m_Name);
}

void
Victim::getPolymorphed(
    void ) const
{
    std::cout << m_Name << " has been turned into a cute little sheep!\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Victim & victim )
{
    oStream << "I am " << victim.getName() << " and I like otters!\n";

    return (oStream);
}

#endif
