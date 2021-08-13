/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:15:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/27 19:55:31 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon {

public:
    AWeapon( const std::string & name, int apcost, int damage );
    AWeapon( const AWeapon & model );

    virtual ~AWeapon( void );

    AWeapon & operator=( const AWeapon & model );

    const std::string & getName( void ) const;
    int getAPCost( void ) const;
    int getDamage( void ) const;

    virtual void attack( void ) const = 0;

protected:
    std::string m_Name;
    int m_APCost;
    int m_Damage;

private:
    AWeapon( void );

};

std::ostream & operator<<( std::ostream & stream, const AWeapon & a_Weapon );

AWeapon::AWeapon(
    const std::string & name
    , int apcost
    , int damage )
        : m_Name(name)
        , m_APCost(apcost)
        , m_Damage(damage)
{
}

AWeapon::AWeapon(
    const AWeapon & model )
{
    *this = model;
}

AWeapon::~AWeapon(
    void )
{
}

AWeapon &
AWeapon::operator=(
    const AWeapon & model )
{
    m_Name = model.m_Name;
    m_APCost = model.m_APCost;
    m_Damage = model.m_Damage;

    return *this;
}

const std::string &
AWeapon::getName(
    void ) const
{
    return (m_Name);
}

int
AWeapon::getDamage(
    void ) const
{
    return (m_Damage);
}

int
AWeapon::getAPCost(
    void ) const
{
    return (m_APCost);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const AWeapon & a_Weapon )
{
    oStream << "AWeapon " << a_Weapon.getName() << "\n";

    return (oStream);
}

#endif
