/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/11 16:51:36 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap {

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
    ScavTrap( void );
    ScavTrap( const std::string name );
    ScavTrap( const ScavTrap & model );

    virtual ~ScavTrap( void );

    ScavTrap & operator=( const ScavTrap & model );

    std::string getName( void ) const;
    unsigned int getHitPoint( void ) const;
    void rangedAttack( std::string const & target );
    void meleeAttack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void challengeNewcomer( void );

};

std::ostream & operator<<( std::ostream & stream, const ScavTrap & scavTrap );

#endif
