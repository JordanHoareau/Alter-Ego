#ifndef GEARITEM_H
#define GEARITEM_H

#include "GameCharacter/Items/SellableItem.h"

#include <iostream>

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
        GearItem(int id, std::string name, std::string description, int sellvalue, int buyvalue, int geartype, int unlocklvl, int strbonus, int agibonus, int tghbonus, bool isEmpty = false)
            :   SellableItem(id){
            m_geartype = geartype;
            m_unlocklvl = unlocklvl;
            m_strbonus = strbonus;
            m_agibonus = agibonus;
            m_tghbonus = tghbonus;
            m_isEmpty = isEmpty;
            }
        virtual ~GearItem();
        int getGearType(){return m_geartype;}
        int getUnlockLvl(){return m_unlocklvl;}
        int getStrBonus(){return m_strbonus;}
        int getAgiBonus(){return m_agibonus;}
        int getTghBonus(){return m_tghbonus;}
        bool isEmpty(){return m_isEmpty;}

    protected:

    private:
        int m_geartype;
        int m_unlocklvl;
        int m_strbonus;
        int m_agibonus;
        int m_tghbonus;
        bool m_isEmpty;
};

#endif // GEARITEM_H
