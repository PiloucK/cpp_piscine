#include "Enemy.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

int
main(
    void )
{
    Character* me = new Character("me");
    
    std::cout << *me;
    
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    me->equip(pr);
    std::cout << *me;

    me->equip(pf);

    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;

    std::cout << "\n\n============================Extensive testing============================\n\n";

    delete pr;
    delete pf;
    delete me;

    return 0;
}