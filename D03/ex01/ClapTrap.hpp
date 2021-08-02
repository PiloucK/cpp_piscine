/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/07 16:37:34 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

private:
    ClapTrap( void );

protected:
    unsigned int m_HitPoint;
    unsigned int m_EnergyPoint;
    std::string m_Name;
    unsigned int m_AttackDamage;

public:
    ClapTrap( const std::string name );
    ClapTrap( const ClapTrap & model );

    virtual ~ClapTrap( void );

    ClapTrap & operator=( const ClapTrap & model );

    virtual void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

};

#endif
