/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:07:07 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/27 14:16:54 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap {

private:

public:
    FragTrap( void );
    FragTrap( const std::string name );
    FragTrap( const FragTrap & model );

    virtual ~FragTrap( void );

    FragTrap & operator=( const FragTrap & model );

    void vaulthunter_dot_exe( std::string const & target );

};

std::ostream & operator<<( std::ostream & stream, const FragTrap & fragTrap );

#endif
