/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:36:30 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/07 10:07:32 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class NinjaTrap : public ClapTrap {

private:

public:
    NinjaTrap( void );
    NinjaTrap( const std::string name );
    NinjaTrap( const NinjaTrap & model );

    virtual ~NinjaTrap( void );

    NinjaTrap & operator=( const NinjaTrap & model );

   void ninjaShoebox( const ClapTrap & target ) const ;
   void ninjaShoebox( const FragTrap & target ) const ;
   void ninjaShoebox( const ScavTrap & target ) const ;
   void ninjaShoebox( const NinjaTrap & target ) const ;

};

std::ostream & operator<<( std::ostream & stream, const NinjaTrap & ninjaTrap );

#endif
