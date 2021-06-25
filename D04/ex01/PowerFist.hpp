/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:19:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/25 21:01:17 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

# include "AWeapon.hpp"
# include <iostream>
# include <string>

class PowerFist : public AWeapon {

public:
    PowerFist( void );
    PowerFist( const PowerFist & model );

    virtual ~PowerFist( void );

    PowerFist & operator=( const PowerFist & model );

    virtual void attack( void ) const;

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const PowerFist & a_PowerFist );

PowerFist::PowerFist(
    void )
        : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(
    const PowerFist & model )
        : AWeapon(model)
{
}

PowerFist &
PowerFist::operator=(
    const PowerFist & model )
{
    AWeapon::operator=(model);

    return *this;
}

void
PowerFist::attack(
    void ) const
{
    std::cout << "* pschhh... SBAM! *\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const PowerFist & a_PowerFist )
{
    oStream << "Power Fist " << a_PowerFist.getName() << "\n";

    return (oStream);
}

#endif
