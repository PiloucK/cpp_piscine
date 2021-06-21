/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:29:45 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/21 17:30:55 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include "Victim.hpp"
# include <iostream>
# include <string>

class Sorcerer
{

public:
    Sorcerer( const std::string & name, const std::string & title );
    Sorcerer( const Sorcerer & model );

    virtual ~Sorcerer( void );

    Sorcerer & operator=( const Sorcerer & model );

    const std::string & getName( void ) const;
    const std::string & getTitle( void ) const;
    void polymorph( const Victim & victim ) const;

protected:
    const std::string m_Name;
    const std::string m_Title;
    
private:
    Sorcerer( void );

};

std::ostream & operator<<( std::ostream & stream, const Sorcerer & sorcerer );

Sorcerer::Sorcerer(
    const std::string & name
    , const std::string & title )
        : m_Name(name)
        , m_Title(title)
{
    std::cout << m_Name << ", " << m_Title << ", is born!\n";
}

Sorcerer::~Sorcerer(
    void )
{
    std::cout << m_Name << ", " << m_Title << ", is dead. Consequences will never be the same!\n";
}

const std::string &
Sorcerer::getName(
    void ) const
{
    return (m_Name);
}

const std::string &
Sorcerer::getTitle(
    void ) const
{
    return (m_Title);
}

void
Sorcerer::polymorph(
    const Victim & victim ) const
{
    victim.getPolymorphed();
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Sorcerer & sorcerer )
{
    std::cout << "I am " << sorcerer.getName() <<  ", " << sorcerer.getTitle() << " and I like ponies!\n";
}

#endif
