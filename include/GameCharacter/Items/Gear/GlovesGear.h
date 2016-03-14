#ifndef GlovesGEAR_H
#define GlovesGEAR_H

#include "GameCharacter/Items/GearItem.h"


class GlovesGear : public GearItem
{
    public:
        GlovesGear(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~GlovesGear();

    protected:

    private:
};

#endif // GlovesGEAR_H
