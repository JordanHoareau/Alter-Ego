#ifndef LegsGEAR_H
#define LegsGEAR_H

#include "GameCharacter/Items/GearItem.h"


class LegsGear : public GearItem
{
    public:
        LegsGear(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~LegsGear();

    protected:

    private:
};

#endif // LegsGEAR_H
