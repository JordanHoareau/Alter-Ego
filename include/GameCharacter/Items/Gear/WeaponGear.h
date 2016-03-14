#ifndef WeaponGEAR_H
#define WeaponGEAR_H

#include "GameCharacter/Items/GearItem.h"


class WeaponGear : public GearItem
{
    public:
        WeaponGear(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~WeaponGear();

    protected:

    private:
};

#endif // WeaponGEAR_H
