/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:19:52 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/25 20:59:02 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include "AWeapon.hpp"
# include <iostream>
# include <string>

class PlasmaRifle : public AWeapon {

public:
    PlasmaRifle( void );
    PlasmaRifle( const PlasmaRifle & model );

    virtual ~PlasmaRifle( void );

    PlasmaRifle & operator=( const PlasmaRifle & model );

    virtual void attack( void ) const;

protected:
    
private:

};

std::ostream & operator<<( std::ostream & stream, const PlasmaRifle & a_PlasmaRifle );

PlasmaRifle::PlasmaRifle(
    void )
        : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(
    const PlasmaRifle & model )
        : AWeapon(model)
{
}

PlasmaRifle &
PlasmaRifle::operator=(
    const PlasmaRifle & model )
{
    AWeapon::operator=(model);

    return *this;
}

void
PlasmaRifle::attack(
    void ) const
{
    std::cout << "* piouuu piouuu piouuu *\n";
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const PlasmaRifle & a_PlasmaRifle )
{
    oStream << "Plasma Rifle " << a_PlasmaRifle.getName() << "\n";

    return (oStream);
}

#endif
