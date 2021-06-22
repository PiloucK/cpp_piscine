/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:15:34 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/22 23:44:53 by clkuznie         ###   ########.fr       */
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
    int m_Damage;
    int m_APCost;

private:
    AWeapon( void );

};

std::ostream & operator<<( std::ostream & stream, const AWeapon & aweapon );

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
    m_Name = model.getName();
    m_APCost = model.getAPCost();
    m_Damage = model.getDamage();

    return *this;
}

const std::string &
AWeapon::getName(
    void ) const
{
    return (m_Name);
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const AWeapon & aweapon )
{
    oStream << "\n";

    return (oStream);
}

#endif
