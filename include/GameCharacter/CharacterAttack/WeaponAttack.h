#ifndef WEAPONATTACK_H
#define WEAPONATTACK_H

#include <SFML/Graphics.hpp>
#include "Attack.h"

class WeaponAttack: public Attack
{
    public:
        WeaponAttack();

    protected:

    private:
        sf::String m_weapontype;
};

#endif // WEAPONATTACK_H
