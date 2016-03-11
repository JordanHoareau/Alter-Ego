#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include "Item.h"

class ConsumableItem : public Item {
    public:
        ConsumableItem(int id);
    protected:
    private:
        int m_health; // example
};

#endif // CONSUMABLEITEM_H
