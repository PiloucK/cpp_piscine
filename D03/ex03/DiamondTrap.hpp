/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:23:34 by Clkuznie          #+#    #+#             */
/*   Updated: 2021/08/09 00:15:03 by Clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap {

private:
    DiamondTrap( void );

    std::string m_Name; 

public:
    DiamondTrap( const std::string name );
    DiamondTrap( const DiamondTrap & model );

    virtual ~DiamondTrap( void );

    DiamondTrap & operator=( const DiamondTrap & model );

    void attack( std::string const & target );

};

std::ostream & operator<<( std::ostream & oStream, const DiamondTrap & a_DiamondTrap );

#endif
