/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:53:25 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/13 11:28:20 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

private:
    unsigned int m_HitPoint;
    unsigned int m_MaxHitPoint;
    unsigned int m_EnergyPoint;
    unsigned int m_MaxEnergyPoint;
    unsigned int m_Level;
    std::string m_Name;
    unsigned int m_MeleeAttackDamage;
    unsigned int m_RangedAttackDamage;
    unsigned int m_ArmorDamageReduction;

public:
    ClapTrap( void );
    ClapTrap( const std::string name );
    ClapTrap( const unsigned int hitPoint
        , const unsigned int maxHitPoint
        , const unsigned int energyPoint
        , const unsigned int maxEnergyPoint
        , const unsigned int level
        , const std::string name
        , const unsigned int meleeAttackDamage
        , const unsigned int rangedAttackDamage
        , const unsigned int armorDamageReduction);
    ClapTrap( const ClapTrap & model );

    virtual ~ClapTrap( void );

    ClapTrap & operator=( const ClapTrap & model );

    std::string getName( void ) const;
    unsigned int getHitPoint( void ) const;

    void rangedAttack( std::string const & target );
    void meleeAttack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

};

std::ostream & operator<<( std::ostream & stream, const ClapTrap & clapTrap );

#endif
