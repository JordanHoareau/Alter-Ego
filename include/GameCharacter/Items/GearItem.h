#ifndef GEARITEM_H
#define GEARITEM_H

#include "GameCharacter/Items/SellableItem.h"


class GearItem : public SellableItem
{
    public:
        GearItem(){}
        GearItem(const GearItem& g)
            :   SellableItem(g){
            m_geartype = g.m_geartype;
            m_unlocklvl = g.m_unlocklvl;
            m_strbonus = g.m_strbonus;
            m_agibonus = g.m_agibonus;
            m_tghbonus = g.m_tghbonus;
        }
        GearItem(int id, sf::String name, sf::String description, int sellvalue, int buyvalue, int geartype, int unlocklvl, int strbonus, int agibonus, int tghbonus)
            :   SellableItem(id,name,description,sellvalue,buyvalue){
            m_geartype = geartype;
            m_unlocklvl = unlocklvl;
            m_strbonus = strbonus;
            m_agibonus = agibonus;
            m_tghbonus = tghbonus;
            }
        virtual ~GearItem();
        int getGearType(){return m_geartype;}
        int getUnlockLvl(){return m_unlocklvl;}
        int getStrBonus(){return m_strbonus;}
        int getAgiBonus(){return m_agibonus;}
        int getTghBonus(){return m_tghbonus;}

    protected:

    private:
        int m_geartype;
        int m_unlocklvl;
        int m_strbonus;
        int m_agibonus;
        int m_tghbonus;
};

#endif // GEARITEM_H
