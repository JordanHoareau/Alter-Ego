#ifndef HEADGEAR_H
#define HEADGEAR_H

#include "GameCharacter/Items/GearItem.h"


class HeadGear : public GearItem
{
    public:
        HeadGear(int id, std::string name, std::string description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~HeadGear();

    protected:

    private:
};

#endif // HEADGEAR_H
