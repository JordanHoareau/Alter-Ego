#ifndef GEARITEM_H
#define GEARITEM_H

#include "Item.h"
#include "Constants/StatsConstant.h"
#include "Constants/ItemConstant.h"

class GearItem : public Item {
    public:
        GearItem(int id);
    protected:
        int m_category;
        int m_bonus[StatsConstant::CaracsNumber];
};

#endif // GEARITEM_H
