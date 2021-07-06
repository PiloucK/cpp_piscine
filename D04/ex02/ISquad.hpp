/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:07:26 by clkuznie          #+#    #+#             */
/*   Updated: 2021/07/06 18:20:30 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SQUAD_HPP
# define I_SQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad {
    
public:
    virtual ~ISquad() {}

    virtual int getCount( void ) const = 0;
    virtual ISpaceMarine * getUnit( int ) const = 0;
    virtual int push( ISpaceMarine * ) = 0;

};

#endif
