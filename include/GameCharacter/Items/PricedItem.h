#ifndef PRICEDITEM_H
#define PRICEDITEM_H

#include "GameCharacter/Items/Item.h"


class PricedItem : public Item
{
    public:
        PricedItem();
    protected:
    private:
        int m_price;
};

#endif // PRICEDITEM_H
