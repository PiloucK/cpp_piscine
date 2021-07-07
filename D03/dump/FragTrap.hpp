/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/10 16:46:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap {

private:
    unsigned int m_iHitPoint;
    unsigned int m_iMaxHitPoint;
    unsigned int m_iEnergyPoint;
    unsigned int m_iMaxEnergyPoint;
    unsigned int m_iLevel;
    std::string m_sName;
    unsigned int m_iMeleeAttackDamage;
    unsigned int m_iRangedAttackDamage;
    unsigned int m_iArmorDamageReduction;

public:
    FragTrap( void );
    FragTrap( const std::string name );
    FragTrap( const FragTrap & model );

    virtual ~FragTrap( void );

    FragTrap & operator=( const FragTrap & model );

    std::string getName( void ) const;
    unsigned int getHitPoint( void ) const;
    void rangedAttack( std::string const & target );
    void meleeAttack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void vaulthunter_dot_exe( std::string const & target );

};

std::ostream & operator<<( std::ostream & stream, const FragTrap & fragTrap );

#endif
