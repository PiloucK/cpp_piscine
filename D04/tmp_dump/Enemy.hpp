/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:24:23 by clkuznie          #+#    #+#             */
/*   Updated: 2021/06/27 19:57:47 by clkuznie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy {

public:
    Enemy( int hp, const std::string & type );
    Enemy( const Enemy & model );

    virtual ~Enemy( void );

    Enemy & operator=( const Enemy & model );

    const std::string & getType( void ) const;
    int getHP( void ) const;

    virtual void takeDamage( int );

protected:
    int m_HP;
    std::string m_Type;
    
private:
    Enemy( void );

};

std::ostream & operator<<( std::ostream & stream, const Enemy & a_Enemy );

Enemy::Enemy(
    int hp
    , const std::string & type )
        : m_HP(hp)
        , m_Type(type)
{
}

Enemy::Enemy(
    const Enemy & model )
        : m_HP(model.m_HP)
        , m_Type(model.m_Type)
{
}

Enemy::~Enemy(
    void )
{
}

Enemy &
Enemy::operator=(
    const Enemy & model )
{
    m_HP = model.m_HP;
    m_Type = model.m_Type;

    return *this;
}

int
Enemy::getHP(
    void ) const
{
    return (m_HP);
}

const std::string &
Enemy::getType(
    void ) const
{
    return (m_Type);
}

void
Enemy::takeDamage(
    int damage )
{
    if (m_HP > damage) {
        m_HP -= damage;
    } else {
        m_HP = 0;
    }
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Enemy & a_Enemy )
{
    oStream << "Enemy " << a_Enemy.getType() << "\n";

    return (oStream);
}

#endif
