/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:59:46 by clkuznie          #+#    #+#             */
/*   Updated: 2021/05/06 12:06:37 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {

private:
    const std::string m_sName;
    Weapon* m_Weapon;

public:
    HumanA( std::string name, Weapon& weapon );
    virtual ~HumanA( void );

    void attack( void ) const;

};

#endif
