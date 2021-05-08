/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:15:33 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/05 16:01:37 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {

private:
    const std::string m_sName;
    Weapon *m_Weapon;

public:
    HumanB( std::string name );
    virtual ~HumanB( void );

    void attack( void ) const;
    void setWeapon( Weapon& newWeapon );

};

#endif
