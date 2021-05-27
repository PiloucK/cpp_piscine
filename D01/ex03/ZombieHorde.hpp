/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:57:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/25 14:24:09 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include "Zombie.hpp"
# include <stdlib.h>

class ZombieHorde {

private:
    Zombie* horde;
    const int n;

public:
    ZombieHorde( int n );
    virtual ~ZombieHorde( void );

    void    announce( void ) const;

};

#endif
