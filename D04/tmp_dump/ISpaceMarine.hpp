/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:07:26 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/07 14:52:01 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SPACE_MARINE_HPP
# define I_SPACE_MARINE_HPP

class ISpaceMarine {

public:
    virtual ~ISpaceMarine() {}

    virtual ISpaceMarine * clone( void ) const = 0;
    virtual void battleCry( void ) const = 0;
    virtual void rangedAttack( void ) const = 0;
    virtual void meleeAttack( void ) const = 0;

};

#endif
