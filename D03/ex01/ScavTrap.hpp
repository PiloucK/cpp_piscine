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

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap {

private:
    ScavTrap( void );

public:
    ScavTrap( const std::string name );
    ScavTrap( const ScavTrap & model );

    virtual ~ScavTrap( void );

    ScavTrap & operator=( const ScavTrap & model );

    virtual void attack( std::string const & target );

    void guardGate( void ) const;

};

#endif
