/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:55:19 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/04 21:02:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"
# include <string>

class ZombieEvent {

private:
    std::string m_sZombieType;
    

public:
    ZombieEvent( std::string sZombieType );
    virtual ~ZombieEvent( void );

    void    setZombieType( std::string type );
    Zombie* newZombie( std::string name );

};

#endif
