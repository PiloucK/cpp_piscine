/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/02 13:56:07 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap {

private:

public:
    ScavTrap( void );
    ScavTrap( const std::string name );
    ScavTrap( const ScavTrap & model );

    virtual ~ScavTrap( void );

    ScavTrap & operator=( const ScavTrap & model );

    void challengeNewcomer( void );

};

std::ostream & operator<<( std::ostream & stream, const ScavTrap & scavTrap );

#endif
