#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "GameCharacter/Items/GearItem.h"
#include "GameCharacter/Items/ConsumableItem.h"
#include "GameCharacter/Items/QuestItem.h"
#include "Constants/ItemConstant.h"

class Inventory
{
    public:
        Inventory(){}
        virtual ~Inventory();

    protected:

    private:
        int m_gold;
        std::vector<GearItem> m_gearslots;
        std::vector<ConsumableItem> m_consumableslots;
        std::vector<QuestItem> m_questslots;
        GearItem m_gear[ItemConstant::GearTypesNumber];
};

#endif // INVENTORY_H
