/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:48:48 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/05 15:12:43 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

private:
    std::string     type;

public:
    Weapon( std::string weaponType );
    virtual ~Weapon( void );

    const std::string&     getType( void ) const;
    void    setType( std::string newType );

};

#endif
