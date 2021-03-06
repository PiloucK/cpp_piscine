/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 17:10:37 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : virtual public ClapTrap {

private:
    FragTrap( void );

protected:
    unsigned int m_HitPoint;
    unsigned int m_EnergyPoint;
    unsigned int m_AttackDamage;

public:
    FragTrap( const std::string name );
    FragTrap( const FragTrap & model );

    virtual ~FragTrap( void );

    FragTrap & operator=( const FragTrap & model );

    virtual void attack( std::string const & target );

    void highFivesGuys( void );

};

std::ostream & operator<<( std::ostream & oStream, const FragTrap & a_FragTrap );

#endif
