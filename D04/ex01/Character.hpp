
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"
# include <iostream>
# include <string>

class Character {

public:
    Character( const Character & model );
    Character( const std::string & name );

    ~Character( void );

    Character & operator=( const Character & model );

    const std::string & getName( void ) const;
    int getAP( void ) const;
    const AWeapon * getWeapon( void ) const;

    void recoverAP( void );
    void equip( AWeapon * );
    void attack( Enemy * );

protected:
    std::string m_Name;
    int m_AP;
    AWeapon * m_Weapon;

    
private:
    Character( void );

};

std::ostream & operator<<( std::ostream & stream, const Character & a_Character );

Character::Character(
    const Character & model )
        : m_Name(model.m_Name)
        , m_AP(model.m_AP)
        , m_Weapon(model.m_Weapon)
{
}

Character::Character(
    const std::string & name )
        : m_Name(name)
        , m_AP(40)
        , m_Weapon(NULL)
{
}

Character::~Character(
    void )
{
}

Character &
Character::operator=(
    const Character & model )
{
    m_Name = model.m_Name;
    m_AP = model.m_AP;
    m_Weapon = model.m_Weapon;

    return *this;
}

const std::string &
Character::getName(
    void ) const
{
    return (m_Name);
}


int
Character::getAP(
    void ) const
{
    return (m_AP);
}

const AWeapon *
Character::getWeapon(
    void ) const
{
    return (m_Weapon);
}

void
Character::recoverAP(
    void )
{
    if (m_AP < 30) {
        m_AP += 10;
    } else {
        m_AP = 40;
    }
}

void
Character::equip(
    AWeapon * a_Weapon)
{
    m_Weapon = a_Weapon;
}

void
Character::attack(
    Enemy * a_Enemy )
{
    // (void)a_Enemy;
    if (a_Enemy != NULL && m_Weapon != NULL) {
        int neededAP = m_Weapon->getAPCost();

        if (m_AP >= neededAP) {
            std::cout << m_Name << " attacks " << a_Enemy->getType()
                << " with a " << m_Weapon->getName() << '\n';

            m_Weapon->attack();
            a_Enemy->takeDamage(m_Weapon->getDamage());
            m_AP -= neededAP;
        }
    }
}

std::ostream &
operator<<(
    std::ostream & oStream
    , const Character & a_Character )
{
    oStream << a_Character.getName() << " has " << a_Character.getAP();

    if (a_Character.getWeapon()) {
        oStream << " and wields a " << a_Character.getWeapon()->getName() << "\n";
    } else {
        oStream << " and is unarmed\n";
    }

    return (oStream);
}

#endif
