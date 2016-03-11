#ifndef WEAPONITEM_H
#define WEAPONITEM_H

#include "GameCharacter/Items/GearItem.h"
#include <SFML/System/Vector2.hpp>

class WeaponItem : public GearItem
{
    public:
        WeaponItem(int id);
    protected:
    private:
        sf::Vector2i m_dmg;
};

#endif // WEAPONITEM_H
