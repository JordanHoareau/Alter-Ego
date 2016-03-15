#ifndef SELLABLEITEM_H
#define SELLABLEITEM_H

#include "GameCharacter/Items/Item.h"

class SellableItem : public Item
{
    public:
        SellableItem(){}
        SellableItem(int id, sf::String name, sf::String description, int sellvalue, int buyvalue)
            :Item(id,name,description){
            m_sellvalue = sellvalue;
            m_buyvalue = buyvalue;
        }
        virtual ~SellableItem();

    protected:

    private:
        int m_sellvalue;
        int m_buyvalue;
};

#endif // SELLABLEITEM_H
