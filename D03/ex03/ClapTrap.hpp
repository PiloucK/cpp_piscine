/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/08/08 20:13:46 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

public:
    ClapTrap( const std::string name );
    ClapTrap( const ClapTrap & model );

    virtual ~ClapTrap( void );

    ClapTrap & operator=( const ClapTrap & model );

    std::string getName( void ) const;
    unsigned int getHitPoint( void ) const;
    unsigned int getEnergyPoint( void ) const;
    unsigned int getAttackDamage( void ) const;

    virtual void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

private:
    ClapTrap( void );

protected:
    unsigned int m_HitPoint;
    unsigned int m_EnergyPoint;
    std::string m_Name;
    unsigned int m_AttackDamage;

};

std::ostream & operator<<( std::ostream & oStream, const ClapTrap & a_ClapTrap );

#endif
