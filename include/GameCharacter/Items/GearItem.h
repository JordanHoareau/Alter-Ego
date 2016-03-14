#ifndef GEARITEM_H
#define GEARITEM_H

#include "GameCharacter/Items/SellableItem.h"


class GearItem : public SellableItem
{
    public:
        GearItem(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   SellableItem(id,name,description,sellvalue,buyvalue){
            m_unlocklvl = unlocklvl;
            m_strbonus = strbonus;
            m_agibonus = agibonus;
            m_tghbonus = tghbonus;
            }
        virtual ~GearItem();

    protected:

    private:
        int m_unlocklvl;
        int m_strbonus;
        int m_agibonus;
        int m_tghbonus;
};

#endif // GEARITEM_H
