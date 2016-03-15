#ifndef BootsGEAR_H
#define BootsGEAR_H

#include "GameCharacter/Items/GearItem.h"


class BootsGear : public GearItem
{
    public:

        BootsGear(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~BootsGear();

    protected:

    private:
};

#endif // BootsGEAR_H
