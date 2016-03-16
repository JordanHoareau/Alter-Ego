#ifndef BreastPlateGEAR_H
#define BreastPlateGEAR_H

#include "GameCharacter/Items/GearItem.h"


class BreastPlateGear : public GearItem
{
    public:
        BreastPlateGear(int id, std::string name, std::string description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   GearItem(id,name,description,sellvalue,buyvalue,unlocklvl,strbonus,agibonus,tghbonus){}
        virtual ~BreastPlateGear();

    protected:

    private:
};

#endif // BreastPlateGEAR_H
