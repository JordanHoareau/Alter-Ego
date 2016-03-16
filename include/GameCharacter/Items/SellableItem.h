#ifndef SELLABLEITEM_H
#define SELLABLEITEM_H

#include "GameCharacter/Items/Item.h"

class SellableItem : public Item
{
    public:
        SellableItem(){}
        SellableItem(const SellableItem& s)
            :   Item(s){
            m_sellvalue = s.m_sellvalue;
            m_buyvalue = s.m_buyvalue;
        }
        SellableItem(int id, sf::String name, sf::String description, int sellvalue, int buyvalue)
            :Item(id,name,description){
            m_sellvalue = sellvalue;
            m_buyvalue = buyvalue;
        }
        int getSellValue(){return m_sellvalue;}
        int getBuyValue(){return m_buyvalue;}
        virtual ~SellableItem();

    protected:

    private:
        int m_sellvalue;
        int m_buyvalue;
};

#endif // SELLABLEITEM_H
