#ifndef GOLD_H
#define GOLD_H

#include "GameCharacter/Items/PricedItem.h"


class Gold : public PricedItem
{
    public:
        Gold();
    protected:
    private:
        const int m_price = 1;
};

#endif // GOLD_H
