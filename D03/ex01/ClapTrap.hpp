/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/07 15:22:58 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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
